# 🚗 EV Dashboard & ADAS Warning System using STM32

A Real-Time **Electric Vehicle (EV) Dashboard** and **Advanced Driver Assistance System (ADAS)** developed using the **STM32F103C8T6 (Blue Pill)** microcontroller. The project simulates EV parameters, monitors vehicle status, and provides collision warnings through UART communication and a Python-based dashboard.

---

## 📌 Project Overview

This project was developed as part of my **Embedded Systems Internship at Emertxe**. It demonstrates embedded firmware development, real-time sensor monitoring, UART communication, and EV dashboard visualization using STM32 and Python.

---

## ✨ Features

- 🚘 Real-Time EV Dashboard
- ⚠️ Advanced Driver Assistance System (ADAS)
- 📈 Speed Monitoring
- 🔋 State of Charge (SOC) Monitoring
- 🌡️ Motor Temperature Monitoring
- ⚙️ Torque & Range Calculation
- 🚨 Forward Collision Warning (FCW)
- 🔄 Blind Spot Detection (BSD)
- ⏱️ Time-to-Collision (TTC)
- 📡 UART Communication
- 📊 Python Dashboard Visualization
- ⚡ Fault Detection & Warning Alerts

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

```text
EV-ADAS-Dashboard-STM32/
│
├── Core/
│   ├── Inc/
│   ├── Src/
│   └── startup/
│
├── Driver/
│   ├── CMSIS/
│   └── STM32F1xx_HAL_Driver/
│
├── Screenshots/
│   ├── picsimlab_connection.png
│   ├── python_dashboard.png
│   ├── internship_certificate.png
│   └── README.md
│
├── ev_dash.ioc
├── ev_dash.py
├── STM32F103C8TX_FLASH.ld
├── README.md
├── LICENSE
└── .gitignore
```

---

## 🚘 Dashboard Parameters

The EV Dashboard monitors the following parameters in real time:

- Vehicle Speed
- State of Charge (SOC)
- Motor Temperature
- Torque
- Estimated Driving Range
- Accelerator Position
- Brake Position

---

## ⚠️ ADAS Features

The project implements several Advanced Driver Assistance System (ADAS) features:

- Forward Collision Warning (FCW)
- Blind Spot Detection (BSD)
- Time-to-Collision (TTC)
- Obstacle Detection using Ultrasonic Sensors
- Buzzer Alerts
- LED Warning Indicators

---

## 🔄 Communication

The STM32 firmware communicates with the Python Dashboard using the UART communication protocol.

### Data Flow

```
STM32 Blue Pill
        │
        ▼
UART Communication
        │
        ▼
Tera Term / Python Dashboard
        │
        ▼
Real-Time EV Dashboard
```

---

## 🖥️ Simulation Environment

The complete project is simulated using:

- STM32 Blue Pill (Simulated)
- PICSimLab
- Tera Term
- Python Dashboard

---

## 📸 Project Screenshots

The **Screenshots** folder contains:

- 🛠️ PICSimLab hardware simulation and connections
- 📊 Python Dashboard displaying live EV parameters
- 🎓 Emertxe Internship Completion Certificate

Refer to the **Screenshots** folder for detailed images and descriptions.

---

## 🚀 How to Run

1. Open the project in **STM32CubeIDE**.
2. Build the firmware.
3. Load the project in **PICSimLab** (or flash it to an STM32 Blue Pill board).
4. Connect UART to **Tera Term** or run the Python Dashboard.
5. Execute `ev_dash.py`.
6. Monitor EV parameters and ADAS warnings in real time.

---

## 🎯 Learning Outcomes

Through this project, I gained practical experience in:

- Embedded C Programming
- STM32 Firmware Development
- GPIO, ADC, Timers, UART
- UART Communication
- Embedded System Debugging
- Automotive Electronics
- ADAS Concepts
- Python Serial Communication
- Real-Time Data Visualization

---

## 🎓 Internship

This project was developed during my **Embedded Systems Internship at Emertxe**.

---

## 👩‍💻 Author

**Hemalatha S**

Electronics and Communication Engineering (ECE)

Interested in:

- Embedded Systems
- Firmware Development
- Automotive Electronics
- Internet of Things (IoT)

---

## 📄 License

This project is licensed under the **MIT License**.

---

## ⭐ Support

If you found this project useful, please consider giving it a ⭐ on GitHub.
