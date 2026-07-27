# 🚗 EV Dashboard & ADAS Warning System using STM32

A Real-Time **Electric Vehicle (EV) Dashboard** and **Advanced Driver Assistance System (ADAS)** developed using the **STM32F103C8T6 (Blue Pill)** microcontroller. The project simulates EV parameters, monitors vehicle status, and provides collision warnings through UART communication and a Python-based dashboard.

---

## 📌 Project Overview

This project was developed as part of my **Embedded Systems Internship at Emertxe**. It demonstrates embedded firmware development, real-time sensor monitoring, UART communication, and EV dashboard visualization using STM32 and Python.

---

## ✨ Features

- Real-Time EV Dashboard
- Advanced Driver Assistance System (ADAS)
- Speed Monitoring
- State of Charge (SOC) Monitoring
- Motor Temperature Monitoring
- Torque & Range Calculation
- Forward Collision Warning (FCW)
- Blind Spot Detection (BSD)
- Time-to-Collision (TTC)
- UART Communication
- Python Dashboard Visualization
- Fault Detection & Warning Alerts

---

## 🛠️ Technologies & Tools

- STM32CubeIDE
- Embedded C
- STM32F103C8T6 (Blue Pill)
- PICSimLab
- Tera Term
- Python
- Matplotlib
- PySerial
- UART Communication Protocol

---

## 📁 Project Structure

```
EV-ADAS-Dashboard-STM32/
│── Core/
│   ├── Inc/
│   ├── Src/
│   └── startup/
│
│── Drivers/
│   ├── CMSIS/
│   └── STM32F1xx_HAL_Driver/
│
│── ev_dash.ioc
│── ev_dash.py
│── STM32F103C8TX_FLASH.ld
│── README.md
```

---

## 🚘 Dashboard Parameters

- Vehicle Speed
- State of Charge (SOC)
- Motor Temperature
- Torque
- Estimated Driving Range
- Accelerator Position
- Brake Position

---

## ⚠️ ADAS Features

- Forward Collision Warning (FCW)
- Blind Spot Detection (BSD)
- Time-to-Collision (TTC)
- Obstacle Detection using Ultrasonic Sensors
- Buzzer & LED Alerts

---

## 🔄 Communication

The STM32 firmware communicates with the Python Dashboard through the **UART protocol**.

**Data Flow:**

STM32 → UART → Tera Term / Python Dashboard

---

## 🖥️ Simulation Environment

- STM32 Blue Pill (Simulated)
- PICSimLab
- UART Terminal (Tera Term)
- Python Dashboard

---

## 📸 Project Screenshots

You can add screenshots of:

- Python Dashboard
- PICSimLab Simulation
- UART Output
- ADAS Warning Display
- Internship Certificate

---

## 🚀 How to Run

1. Open the project in STM32CubeIDE.
2. Build and flash the firmware (or simulate using PICSimLab).
3. Connect UART to Tera Term or the Python Dashboard.
4. Run `ev_dash.py`.
5. Monitor EV parameters and ADAS warnings in real time.

---

## 🎓 Internship

This project was developed during my **Embedded Systems Internship at Emertxe**.

---

## 👩‍💻 Author

**Hemalatha S**

Electronics and Communication Engineering (ECE)

Interested in Embedded Systems, Firmware Development, Automotive Electronics, and IoT.

---

## 📄 License

This project is shared for learning and portfolio purposes.
