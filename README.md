# ESP32 Push Button LED Toggle

A basic ESP32 project that demonstrates push button control of an LED using GPIO 4 and GPIO 5. The LED toggles its state each time the push button is pressed. The first press turns the LED ON, and the next press turns the LED OFF.

## 📌 Project Overview

This project demonstrates the basic use of ESP32 GPIO programming, digital input, and digital output control.

The ESP32 continuously monitors the push button and performs the following operations:

- Detects the push button press
- Turns the LED ON when the button is pressed once
- Keeps the LED ON until the button is pressed again
- Turns the LED OFF when the button is pressed again
- Repeats the process for every button press

## 🛠️ Components Required

- ESP32 Development Board
- LED
- Push Button
- 220Ω Resistor
- Breadboard
- Jumper Wires
- USB Cable

## 🔌 Circuit Connection

| ESP32 Pin | Connection |
|-----------|------------|
| GPIO 4 | LED Anode (+) through 220Ω resistor |
| GND | LED Cathode (-) |
| GPIO 5 | Push Button |
| GND | Push Button |

The push button uses the ESP32's internal pull-up resistor through `INPUT_PULLUP`.

### CIRCUIT DIAGRAM

![CIRCUIT DIAGRAM](circuit_diagram_pushbutton_led.jpeg)

## ⚙️ How It Works

### 1. Define the LED and Button Pins

    #define LED 4
    #define BUTTON 5

GPIO 4 is assigned to the LED, and GPIO 5 is assigned to the push button.

### 2. Configure the GPIO Pins

    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);

GPIO 4 is configured as an output pin so that the ESP32 can control the LED.

GPIO 5 is configured as an input using `INPUT_PULLUP`, which enables the ESP32's internal pull-up resistor.

### 3. Read the Push Button

    bool buttonState = digitalRead(BUTTON);

The ESP32 reads the current state of the push button.

When the button is not pressed, the input reads `HIGH`.

When the button is pressed, the input reads `LOW`.

### 4. Detect the Button Press

    if (lastButtonState == HIGH && buttonState == LOW)

This condition detects a new button press by checking when the button changes from `HIGH` to `LOW`.

### 5. Toggle the LED State

    ledState = !ledState;

The `!` operator changes the LED state:

- `false` → `true`
- `true` → `false`

Therefore, every new button press changes the LED to the opposite state.

### 6. Control the LED

    digitalWrite(LED, ledState);

The ESP32 writes the current LED state to GPIO 4.

- `HIGH` → LED ON
- `LOW` → LED OFF

The same process repeats continuously inside the `loop()` function.

## 🔄 Working Sequence

    Button Press 1 → LED ON
    Button Press 2 → LED OFF
    Button Press 3 → LED ON
    Button Press 4 → LED OFF
    Button Press 5 → LED ON

The LED changes its state every time the push button is pressed.

## 🎥 Project Demonstration

The working demonstration shows the LED turning ON with the first button press and turning OFF with the next button press.

### Working Video

[▶️ Watch the ESP32 Push Button LED Toggle Demonstration](https://drive.google.com/file/d/1yXmRQgmU2qiEu2kc-9mOQIB69ylA67dh/view?usp=drivesdk)

## 📚 Concepts Learned

- ESP32 GPIO
- Digital Input
- Digital Output
- Push Button Interfacing
- LED Interfacing
- `pinMode()`
- `digitalRead()`
- `digitalWrite()`
- `INPUT_PULLUP`
- Button State Detection
- LED State Toggle
- Basic Arduino Programming

## 🚀 Future Improvements

- Add multiple push buttons
- Control multiple LEDs
- Implement software debouncing
- Control LED brightness using PWM
- Control the LED through Wi-Fi
- Create a web-based LED control system
