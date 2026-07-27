/* Core/Src/uart_shell.c */

#include "uart_shell.h"
#include "ultrasonic.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Private handles */
static UART_HandleTypeDef *_huart = NULL;
static EV_HandleTypeDef *_ev = NULL;
static ADAS_HandleTypeDef *_adas = NULL;
static Fault_HandleTypeDef *_flt = NULL;

/* Ring buffer */
static RingBuf_t _rb;
static char _cmd[SHELL_CMD_SIZE];
static uint8_t _cmd_idx = 0;

/* Ring buffer functions */
static void rb_push(uint8_t b)
{
    if (_rb.count < SHELL_BUF_SIZE)
    {
        _rb.buf[_rb.head] = b;
        _rb.head = (_rb.head + 1) % SHELL_BUF_SIZE;
        _rb.count++;
    }
}

static uint8_t rb_pop(uint8_t *b)
{
    if (_rb.count == 0)
        return 0;

    *b = _rb.buf[_rb.tail];
    _rb.tail = (_rb.tail + 1) % SHELL_BUF_SIZE;
    _rb.count--;

    return 1;
}

/* UART transmit */
static void shell_tx(const char *s)
{
    HAL_UART_Transmit(_huart, (uint8_t *)s, strlen(s), HAL_MAX_DELAY);
}

/* Print system status */
void print_status(void)
{
    char buf[128];

    const char *mode_str[] =
    {
        "ECO",
        "NORMAL",
        "SPORT"
    };

    const char *alarm_str[] =
    {
        "NONE",
        "ADVISORY",
        "WARNING",
        "CRITICAL"
    };

    shell_tx("\r\n========== EV ADAS ==========\r\n");

    sprintf(buf,"Speed      : %.1f km/h\r\n",_ev->speed_kmh);
    shell_tx(buf);

    sprintf(buf,"SOC        : %.1f %%\r\n",_ev->soc);
    shell_tx(buf);

    sprintf(buf,"Torque     : %.1f Nm\r\n",_ev->motor_torque);
    shell_tx(buf);

    sprintf(buf,"Motor Temp : %.1f C\r\n",_ev->motor_temp);
    shell_tx(buf);

    sprintf(buf,"Range      : %.1f km\r\n",_ev->range_km);
    shell_tx(buf);

    sprintf(buf,"Drive Mode : %s\r\n",mode_str[_ev->drive_mode]);
    shell_tx(buf);

    shell_tx("\r\n----- ADAS -----\r\n");

    sprintf(buf,"Front      : %.1f cm\r\n",_adas->front_cm);
    shell_tx(buf);

    sprintf(buf,"Left       : %.1f cm\r\n",_adas->left_cm);
    shell_tx(buf);

    sprintf(buf,"Right      : %.1f cm\r\n",_adas->right_cm);
    shell_tx(buf);

    sprintf(buf,"TTC        : %.2f s\r\n",_adas->ttc_sec);
    shell_tx(buf);

    sprintf(buf,"Collision  : %d\r\n",_adas->collision_warn);
    shell_tx(buf);

    sprintf(buf,"Alarm      : %s\r\n",alarm_str[_adas->alarm_priority]);
    shell_tx(buf);

    shell_tx("=============================\r\n> ");
}

/* Command parser */
static void process_cmd(char *cmd)
{
    char arg1[32];
    float value;

    memset(arg1,0,sizeof(arg1));

    if(sscanf(cmd,"mode %31s",arg1)==1)
    {
        if(!strcmp(arg1,"eco"))
            EV_SetDriveMode(_ev,DRIVE_MODE_ECO);

        else if(!strcmp(arg1,"normal"))
            EV_SetDriveMode(_ev,DRIVE_MODE_NORMAL);

        else if(!strcmp(arg1,"sport"))
            EV_SetDriveMode(_ev,DRIVE_MODE_SPORT);

        else
        {
            shell_tx("Invalid Mode\r\n> ");
            return;
        }

        shell_tx("OK\r\n> ");
        return;
    }

    if(sscanf(cmd,"speed set %f",&value)==1)
    {
        EV_InjectSpeed(_ev,value);
        shell_tx("OK\r\n> ");
        return;
    }

    if(sscanf(cmd,"soc set %f",&value)==1)
    {
        EV_InjectSOC(_ev,value);
        shell_tx("OK\r\n> ");
        return;
    }

    if(sscanf(cmd,"temp set %f",&value)==1)
    {
        EV_InjectMotorTemp(_ev,value);
        shell_tx("OK\r\n> ");
        return;
    }
    /* Front obstacle */
    if (sscanf(cmd, "front %f", &value) == 1)
    {
        _adas->front_cm = CLAMP(value, 2.0f, 400.0f);
        shell_tx("Front Distance Updated\r\n> ");
        return;
    }

    /* Left obstacle */
    if (sscanf(cmd, "left %f", &value) == 1)
    {
        _adas->left_cm = CLAMP(value, 2.0f, 400.0f);
        shell_tx("Left Distance Updated\r\n> ");
        return;
    }

    /* Right obstacle */
    if (sscanf(cmd, "right %f", &value) == 1)
    {
        _adas->right_cm = CLAMP(value, 2.0f, 400.0f);
        shell_tx("Right Distance Updated\r\n> ");
        return;
    }

    /* Obstacle command (Front) */
    if (sscanf(cmd, "obstacle %f", &value) == 1)
    {
        _adas->front_cm = CLAMP(value, 2.0f, 400.0f);
        shell_tx("OK\r\n> ");
        return;
    }

    if (!strcmp(cmd, "obstacle clear"))
    {
        _adas->front_cm = 400.0f;
        shell_tx("Obstacle Cleared\r\n> ");
        return;
    }

    /* Fault Injection */
    if (sscanf(cmd, "fault inject %31s", arg1) == 1)
    {
        if (!strcmp(arg1, "motor"))
        {
            EV_InjectMotorTemp(_ev, 95.0f);
            shell_tx("Motor Overheat Injected\r\n> ");
        }
        else if (!strcmp(arg1, "soc"))
        {
            EV_InjectSOC(_ev, 1.0f);
            shell_tx("Low SOC Injected\r\n> ");
        }
        else if (!strcmp(arg1, "col"))
        {
            _adas->collision_warn = 2;
            shell_tx("Collision Injected\r\n> ");
        }
        else
        {
            shell_tx("Use : motor | soc | col\r\n> ");
        }
        return;
    }

    /* Clear Fault */
    if (!strcmp(cmd, "fault clear"))
    {
        Fault_Clear(_flt, _ev);
        shell_tx("Fault Cleared\r\n> ");
        return;
    }

    /* Status */
    if (!strcmp(cmd, "status"))
    {
        print_status();
        return;
    }

    /* Reset */
    if (!strcmp(cmd, "reset"))
    {
        shell_tx("Resetting...\r\n");
        HAL_Delay(100);
        NVIC_SystemReset();
    }

    /* Help */
    if (!strcmp(cmd, "help") || !strcmp(cmd, "?"))
    {
        shell_tx(
        "\r\nAvailable Commands\r\n"
        "mode eco\r\n"
        "mode normal\r\n"
        "mode sport\r\n"
        "speed set <value>\r\n"
        "soc set <value>\r\n"
        "temp set <value>\r\n"
        "front <cm>\r\n"
        "left <cm>\r\n"
        "right <cm>\r\n"
        "obstacle <cm>\r\n"
        "obstacle clear\r\n"
        "fault inject motor\r\n"
        "fault inject soc\r\n"
        "fault inject col\r\n"
        "fault clear\r\n"
        "status\r\n"
        "reset\r\n"
        "help\r\n> ");

        return;
    }

    shell_tx("Unknown Command\r\n> ");
}
/* ── Shell_Init ─────────────────────────────────────────────── */
void Shell_Init(UART_HandleTypeDef *huart,
                EV_HandleTypeDef *ev,
                ADAS_HandleTypeDef *adas,
                Fault_HandleTypeDef *flt)
{
    _huart = huart;
    _ev    = ev;
    _adas  = adas;
    _flt   = flt;

    memset(&_rb, 0, sizeof(_rb));
    _cmd_idx = 0;

    shell_tx("\r\n=================================\r\n");
    shell_tx("     EV ADAS SYSTEM READY\r\n");
    shell_tx("=================================\r\n");
    shell_tx("Type 'help' for available commands\r\n");
    shell_tx("> ");
}

/* ── Shell_PushByte ─────────────────────────────────────────── */
void Shell_PushByte(uint8_t byte)
{
    rb_push(byte);
}

/* ── Shell_Process ──────────────────────────────────────────── */
void Shell_Process(void)
{
    uint8_t byte;

    while (rb_pop(&byte))
    {
        /* Echo received character */
        HAL_UART_Transmit(_huart, &byte, 1, HAL_MAX_DELAY);

        switch (byte)
        {
        case '\r':
        case '\n':

            if (_cmd_idx > 0)
            {
                _cmd[_cmd_idx] = '\0';

                shell_tx("\r\n");

                process_cmd(_cmd);

                _cmd_idx = 0;
            }
            else
            {
                shell_tx("\r\n> ");
            }

            break;

        case '\b':
        case 0x7F:

            if (_cmd_idx > 0)
            {
                _cmd_idx--;

                shell_tx("\b \b");
            }

            break;

        default:

            if (_cmd_idx < (SHELL_CMD_SIZE - 1))
            {
                _cmd[_cmd_idx++] = (char)byte;
            }

            break;
        }
    }
}
