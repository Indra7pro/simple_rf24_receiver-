# 🎯 simple_rf24_receiver-

A **simple 6-channel RF receiver** based on the **STM32** microcontroller and **nRF24L01** wireless receiver.

This receiver is designed to work with the [simple_rf24_transmitter](https://github.com/Indra7pro/simple_rf24_transmitter) project and is ideal for controlling RC vehicles, robotic arms, and other remote-controlled systems.

---

## 📦 Features

- ✅ Built using **STM32** (any compatible board)
- ✅ Wireless data reception via **nRF24L01**
- ✅ Supports **6 channels**:
  - 4 PWM channels for **servo motors**
  - 2 digital outputs for **led/relay**
- ✅ Compatible with custom struct-based data transmission
- ✅ Easy to expand or customize

---

## 🧰 Hardware Requirements

| Component       | Quantity |
|----------------|----------|
| STM32 Board (e.g., Blue Pill) | 1        |
| nRF24L01 Module | 1        |
| Servo Motors    | Up to 4  |
| Load (LEDs, Relays, etc.) for digital output | 2        |
| Power Supply    | As required (3.3v for STM32) |

---

## 🔌 Wiring Overview

| RF24 Pin | STM32 Pin (example) |
|----------|---------------------|
| VCC      | 3.3V                |
| GND      | GND                 |
| CE       | PB13                |
| CSN      | PB14                |
| SCK      | PA5 (SPI1_SCK)      |
| MISO     | PA6 (SPI1_MISO)     |
| MOSI     | PA7 (SPI1_MOSI)     |

> 💡 You may need to adjust the pins in your code according to your board's configuration.

---

## 🧠 Data Handling

The receiver expects a `struct` matching the format sent by the transmitter:

```cpp
struct dt {
  int j1;
  int j2;
  int j3;
  int j4;
  bool b1;
  bool b2;
};
