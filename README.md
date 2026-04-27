# Leaf Sync — Smart Monitoring System

> A hidden IoT-based personal safety device disguised as a decorative plant.  
> Silent activation. Instant alerts. Audio evidence. No suspicion.

---

## Overview

Leaf Sync is a smart personal safety system concealed inside an ordinary artificial flower pot. It uses a dual-trigger capacitive touch mechanism to activate — preventing false alarms while remaining fast enough for emergencies. Once triggered, it simultaneously sends an SOS alert to a guardian's phone and begins recording surrounding audio as evidence.

---

## The Problem

People in vulnerable situations — women living alone, elderly individuals, anyone in a sudden indoor emergency — often cannot reach their phones or call for help in time.

Current solutions fail because:

- Phones are hard to grab during a sudden threat
- Visible panic buttons can be spotted and disabled
- Traditional alerts collect no audio or visual evidence
- Multi-step app-based systems are too slow under panic
- Single-controller devices bottleneck when multitasking

**The core gap:** No existing system combines hidden activation, instant alerting, and audio evidence collection in a single discreet everyday object.

---

## Solution

Leaf Sync hides inside a decorative flower pot. A natural two-step touch gesture triggers the system — no unlocking a phone, no visible button, no suspicion. The moment it activates, an SOS alert is sent and audio recording begins, simultaneously.

---

## How It Works

```
1. User taps the flower pot body
2. User touches the hidden leaf sensor
3. Dual-trigger confirmed — system activates

         Simultaneously:

   ESP8266                        ESP32
   sends SOS alert          starts audio recording
   via Blynk over Wi-Fi     via INMP441 microphone
         |                         |
   Guardian's phone          Audio saved to
   receives alert            SD card as evidence
```

---

## Features

**Discreet Design**  
Electronics are fully embedded inside an artificial flower pot. Indistinguishable from any decorative plant.

**Dual-Trigger Activation**  
Tap the pot, then touch the hidden leaf. Two intentional gestures prevent false alarms without slowing down real ones.

**Instant SOS Alert**  
ESP8266 sends a push notification to the guardian's Blynk app within seconds of activation.

**Audio Evidence**  
INMP441 I2S microphone records surrounding audio and saves it to a microSD card for retrieval.

**Dual Controller Architecture**  
ESP32 handles recording. ESP8266 handles alerting. Tasks are separated to eliminate bottlenecks and ensure both run without delay.

**No App Needed to Trigger**  
Activation is entirely physical. The Blynk app is only on the guardian's side.

---

## Hardware Components

| Component | Purpose |
|---|---|
| ESP32 | Audio recording and processing |
| ESP8266 | Wi-Fi alerting via Blynk |
| INMP441 I2S Microphone | Audio evidence recording |
| MicroSD Card Module | Audio file storage |
| Capacitive Touch Sensors (x2) | Dual-trigger activation |
| Artificial Flower Pot | Device enclosure |
| Power Supply | System power |

---

## Circuit Connections

**ESP32 — INMP441 Mic (I2S)**

| INMP441 | ESP32 |
|---|---|
| VDD | 3.3V |
| GND | GND |
| SD | GPIO 32 |
| SCK | GPIO 14 |
| WS | GPIO 15 |

**ESP32 — SD Card Module (SPI)**

| SD Module | ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| MOSI | GPIO 23 |
| MISO | GPIO 19 |
| SCK | GPIO 18 |
| CS | GPIO 5 |

---

## Software & Tools

| Tool | Purpose |
|---|---|
| Arduino IDE | Firmware development |
| Blynk IoT Platform | Real-time push notifications |
| I2S Library | INMP441 microphone interface |
| SD Library | SD card read/write |
| ESP8266WiFi Library | Wi-Fi connectivity |

---

## Setup & Installation

**Prerequisites**
- Arduino IDE
- Blynk app installed on guardian's phone
- Wi-Fi credentials

**1. Clone the repository**

**2. Flash ESP8266**  
Select board and flash.

**3. Flash ESP32**  

**4. Set up Blynk**  
Create a project in the Blynk app, add a Notification widget, and copy the Auth Token into the ESP8266 code.

**5. Assemble and test**  
Wire components per the circuit table, place inside the pot, power on, and test activation.

---

## Challenges

- Synchronizing ESP32 and ESP8266 to trigger simultaneously without latency
- Tuning INMP441 I2S settings for clear audio inside an enclosed pot
- Designing a dual-touch sequence that is fast but intentional
- Fitting all components neatly within a small decorative pot
- Maintaining system stability during simultaneous Wi-Fi and audio operations

---

## Future Scope

- GPS integration for outdoor use and live location sharing
- Cloud audio upload to Google Drive or Firebase automatically
- Camera module for visual evidence alongside audio
- Deep sleep modes for extended battery life
- Multi-guardian alerts to notify several contacts at once

