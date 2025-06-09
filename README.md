# SpiderClip\_Sensors

*Arduino Nano 33 BLE sketch for SpiderClip sensor BLE service.*

## Overview

This firmware implements a Bluetooth Low Energy (BLE) peripheral on an Arduino Nano 33 BLE board. It reads data from a heart-rate sensor and the on-board 3‑axis IMU, then exposes six BLE characteristics for remote monitoring:

| Characteristic UUID                    | Name           | Description                         |
| -------------------------------------- | -------------- | ----------------------------------- |
| `19B10001-E8F2-537E-4F6C-D104768A1212` | Confidence     | Sensor confidence level (0–100)     |
| `19B10001-E8F2-537E-4F6C-D104768A1213` | Oxygen         | Blood oxygen level (%)              |
| `19B10001-E8F2-537E-4F6C-D104768A1214` | HeartRate      | Heart rate value (beats per minute) |
| `19B10001-E8F2-537E-4F6C-D104768A1215` | Acceleration X | X‑axis acceleration (in milli‑g)    |
| `19B10001-E8F2-537E-4F6C-D104768A1216` | Acceleration Y | Y‑axis acceleration (in milli‑g)    |
| `19B10001-E8F2-537E-4F6C-D104768A1217` | Acceleration Z | Z‑axis acceleration (in milli‑g)    |

## Dependencies

* **Arduino Nano 33 BLE** (or any Arduino board with nRF52840)
* **ArduinoBLE** library
* **DFRobot\_Heartrate** library
* **Arduino\_LSM6DS3** (built‑in IMU support)

Install via **Sketch → Include Library → Manage Libraries...** in the Arduino IDE.

## Hardware Connections

1. **Heart‑rate sensor** on pin `A0` (configured as `heartratePin`).
2. **Power control** on pin `12` (enabled at startup).
3. **IMU** is on‑board; no wiring required.

## Installation & Upload

1. Clone or download this repository.
2. Open `SpiderClip_Sensors.ino` in the Arduino IDE.
3. Select **Tools → Board → Arduino Nano 33 BLE**.
4. Select the correct **Port** under **Tools → Port**.
5. Click **Upload**.

## How It Works

* On startup, the sketch powers the sensor module and initializes serial, BLE, the IMU, and the heart‑rate sensor.
* It sets up a custom BLE service (`19B10000-E8F2-537E-4F6C-D104768A1214`) and adds six integer characteristics.
* During each loop, the code:

  1. Waits for a BLE central to connect.
  2. Continuously reads heart‑rate and acceleration.
  3. Writes the latest values into the corresponding BLE characteristics.
  4. Logs data to `Serial` for debugging.
* When the central disconnects, it resumes advertising.

## Customization

* Change UUIDs or characteristic properties in the sketch header.
* Adjust sensor sampling rates by modifying `delay()` values.

## Troubleshooting

* **Header not found**: ensure `ArduinoBLE.h` is installed and listed under **Sketch → Include Library**.
* **BLE not advertising**: verify the board is powered and the IMU initialized successfully.
* **No sensor data**: check wiring to the heart‑rate sensor and that `heartratePin` matches.

## More Information

Detailed setup guides and advanced documentation are available on our website:

> [https://d-queck.github.io/SpiderClip\_SetUp/](https://d-queck.github.io/SpiderClip_SetUp/)
