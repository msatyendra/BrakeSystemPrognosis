
# Firmware for Brake System Prognosis Project

This directory contains the embedded C firmware developed for the Brake System Prognosis project, running on the SAM V71 Xplained Ultra board using FreeRTOS.

---

## 📂 Folder Structure

- **FreeRTOS/** – FreeRTOS kernel files
- **drivers/** – Drivers for I2C, SPI, ADC, CAN-FD interfaces
- **tasks/** – FreeRTOS task files for each sensor and CAN transmission
- **config/** – Configuration files (clock, FreeRTOS, peripheral pin mappings)
- **project_files/** – Microchip Studio project files
- **main.c** – Main application file
- **README.md** – This documentation file

---

## 🛠️ Tools and Environment

- **Microcontroller:** ATSAMV71Q21 (SAM V71 Xplained Ultra Board)
- **IDE:** Microchip Studio (formerly Atmel Studio)
- **RTOS:** FreeRTOS
- **Protocols Used:** I2C, SPI, ADC, CAN/CAN-FD
- **Programming Language:** Embedded C

---

## 🚀 How to Build and Flash

1. Open Microchip Studio.
2. Open the `.atsln` solution file inside the `project_files/` directory.
3. Connect the SAM V71 Xplained Ultra board via USB.
4. Build the project (F7 key or Build menu).
5. Flash the project using the on-board debugger (EDBG).

✅ No external debugger required.

---

## 📡 Sensor Interface Details

| Sensor | Protocol | MCU Pin Mapping |
|:------|:----------|:----------------|
| MAX31855 (Brake Disc Temp) | SPI | SPI0 (MISO, MOSI, SCK, SS) |
| MLH100PGL06A (Brake Fluid Pressure) | ADC | Analog Input (e.g., AD0) |
| MPU6050 (Vibration) | I2C | TWIHS0 (SCL, SDA) |
| MLX90393 (Brake Pad Wear) | I2C | TWIHS0 (SCL, SDA) |

- **CAN-FD Bus** is used to transmit processed sensor data to the AI unit.

---

## 📋 Notes

- Ensure correct sensor voltage levels (3.3V or 5V) are matched.
- FreeRTOS tasks prioritize time-critical data acquisition (sensor reading tasks) higher than communication tasks.
- All sensor readings are transmitted periodically over CAN-FD in a compressed frame.

---

## ✍️ Author

**Satyendra Maurya**  
M.Tech – Automotive Electronics, BITS Pilani (WILP)  
BITS ID: 2023HT65067
