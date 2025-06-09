# SpiderClip Sensor Platform

*Arduino Nano 33 BLE sketch acting as BLE Peripheral (sensor) in the SpiderClip network.*

## Overview

The **SpiderClip Sensor Platform** firmware turns an Arduino Nano 33 BLE into a BLE Peripheral that provides real-time sensor data. It reads heart-rate and confidence/oxygen metrics from a DFRobot heart-rate module and 3-axis acceleration from the on‑board LSM6DS3 IMU, then advertises these as six BLE characteristics for any BLE Central to consume.

## Characteristics

| UUID                                   | Characteristic | Description                        |
| -------------------------------------- | -------------- | ---------------------------------- |
| `19B10001-E8F2-537E-4F6C-D104768A1212` | Confidence     | Sensor confidence level (0–100)    |
| `19B10001-E8F2-537E-4F6C-D104768A1213` | Oxygen         | Blood oxygen saturation percentage |
| `19B10001-E8F2-537E-4F6C-D104768A1214` | HeartRate      | Heart rate (beats per minute)      |
| `19B10001-E8F2-537E-4F6C-D104768A1215` | Acceleration X | X-axis acceleration (milli‑g)      |
| `19B10001-E8F2-537E-4F6C-D104768A1216` | Acceleration Y | Y-axis acceleration (milli‑g)      |
| `19B10001-E8F2-537E-4F6C-D104768A1217` | Acceleration Z | Z-axis acceleration (milli‑g)      |

The service UUID is `19B10000-E8F2-537E-4F6C-D104768A1214` and the device advertises as **SpiderClip\_Sensor**.

## Dependencies

* **Arduino Nano 33 BLE** (nRF52840)
* **ArduinoBLE** library
* **DFRobot\_Heartrate** library
* **Arduino\_LSM6DS3** library (built‑in with Arduino)

Install the libraries via **Sketch → Include Library → Manage Libraries...** in the Arduino IDE.

## Wiring

* **Heart-rate module** connected to:

  * Signal pin → `A0` (configured as `heartratePin`)
  * Power and ground → `5V`/`GND` (controlled by `PowerPin` GPIO 12)
* **IMU** is on‑board; no external wiring required.

## Installation & Upload

1. **Clone** or **download** this repository.
2. **Open** `SpiderClip_SensorPlatform.ino` in the Arduino IDE.
3. **Select** board: **Tools → Board → Arduino Nano 33 BLE**.
4. **Select** port: **Tools → Port →** your device’s COM port.
5. Click the **Upload** button.

## Usage

1. Open **Serial Monitor** at **9600 baud**.
2. Power on the board. You should see:

   ```text
   Sensor-Plattform gestartet
   BLE Sensor Peripheral aktiv
   ```
3. The device will advertise as **SpiderClip\_Sensor** and serve six characteristics.
4. Any BLE Central (e.g. SpiderClip Communication Interface) can connect and read live values.

## Customization

* **Local name**: change `BLE.setLocalName("...")` to advertise a custom name.
* **Service/characteristic UUIDs**: modify the UUID strings in the code to your own.
* **Sampling rate**: adjust the `delay(100)` at the end of the loop for faster or slower updates.
* **Power control**: change `PowerPin` logic to suit different sensor modules.

## Troubleshooting

* **BLE not starting**: verify `BLE.begin()` returns true and your board is Arduino Nano 33 BLE.
* **No characteristics visible**: ensure the service and characteristics are added before calling `BLE.advertise()`.
* **Sensor data missing**: check heart‑rate module wiring and confirm `IMU.begin()` succeeds.

## More Information

Detailed setup guides, advanced configurations, and troubleshooting tips are available at:

> [https://d-queck.github.io/SpiderClip\_SetUp/](https://d-queck.github.io/SpiderClip_SetUp/)
