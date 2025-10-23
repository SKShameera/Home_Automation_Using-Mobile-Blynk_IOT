# 🏠 IoT-Based Home Automation System

This project is a **simulated IoT-based Home Automation System** developed as part of the **Emertxe Training Program**.  
It demonstrates how household appliances like lights, temperature, and water systems can be **monitored and controlled remotely** using the **Blynk IoT mobile app** and **PicsimLab simulator**.

---

## 📋 Project Overview

The **Home Automation System** enables users to control and monitor their home environment using IoT technology.  
The system simulates real-world devices such as lights, heaters, coolers, and a water tank through **Arduino** and **Blynk integration**.

### 🎯 Objectives
- Automate the control of **lighting**, **temperature**, and **water tank level**.
- Simulate a smart home using **PicsimLab** and **Blynk IoT App**.
- Display real-time data on both **CLCD** and **mobile widgets**.
- Implement **automatic threshold controls** for safety and efficiency.

---

## ⚙️ Features

### 🌞 Garden Light Control
- Uses an **LDR sensor** to detect ambient light.
- Automatically adjusts **LED brightness** based on sunlight availability.

### 🌡️ Temperature Control System
- Uses **LM35 temperature sensor** to read temperature.
- Controls **heater and cooler** via Blynk mobile app buttons.
- Displays temperature on **CLCD** and **Blynk gauge widget**.
- **Threshold control:** Heater turns off automatically if temperature exceeds 35°C.

### 💧 Water Tank Management
- Simulates tank water level through **serial communication**.
- Controls **inlet and outlet valves** via Blynk button widgets.
- Displays water level on **CLCD** and **Blynk gauge widget**.
- **Automatic control:** Inlet valve turns off when the tank is full.

---

## 🧠 System Architecture

### 🧩 Hardware Components (Simulated)
- Arduino (in PicsimLab)
- LDR Sensor
- LM35 Temperature Sensor
- Heater (Resistor)
- Cooler (DC Motor or Fan)
- CLCD Display
- Serial Tank (for water simulation)

### 📱 Software Components
- **PicsimLab Simulator** – To simulate Arduino and sensors.
- **Blynk IoT Mobile App** – To control and monitor devices remotely.
- **Arduino IDE** – For coding and uploading firmware.

---

## 🔗 Functional Flow

1. **Sensors** (LDR, LM35, Serial Tank) collect environmental data.  
2. Data is displayed on **CLCD** and **Blynk app widgets**.  
3. **User inputs** via the Blynk app (buttons) control the devices.  
4. **Automation rules** manage heater and inlet valve thresholds automatically.  
5. **Notifications** are sent to Blynk virtual terminal for alerts (e.g., “Temperature above 35°C”, “Tank full”).  

---

## 📲 User Interface (Blynk App)

- **Button Widgets:** Control Heater, Cooler, Inlet, and Outlet valves.  
- **Gauge Widgets:** Display Temperature and Water Tank Volume.  
- **Terminal Widget:** Show system alerts and notifications.

---

## 🧾 Results & Outcome

- Successfully simulated a **smart home system** with automation and IoT control.  
- Enabled **remote monitoring** of environmental parameters.  
- Gained hands-on experience in:
  - Arduino-based IoT systems
  - Sensor interfacing and serial communication
  - Blynk integration and dashboard design

---

## 🧩 Future Enhancements
- Integrate **real hardware** sensors and actuators.
- Add **voice control** using Google Assistant or Alexa.
- Enable **data logging and analytics** for performance insights.

---

## 📚 Tools & Technologies Used
| Tool/Technology | Purpose |
|------------------|----------|
| Arduino IDE | Programming the microcontroller |
| PicsimLab | Simulation of hardware components |
| Blynk App | IoT control and monitoring |
| CLCD | Display system data locally |
| Serial Communication | Data exchange between modules |

---

## 📅 Developed Under
**Emertxe Information Technologies Pvt. Ltd.**  
Training Project: *IoT-Based Home Automation Solution*  
**Version:** 0.1  
**Revision Date:** 08-06-2022  

---

## 👩‍💻 Author
**[Your Name]**  
IoT & Embedded Systems Enthusiast  
📍 [Your Location]  
📧 [Your Email]  

---

## 🏷️ Tags
`#IoT` `#Arduino` `#Blynk` `#Automation` `#SmartHome` `#EmbeddedSystems` `#PicsimLab` `#Emertxe` `#TechProject`

---
