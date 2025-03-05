# Bluetooth-Controlled Motor Driver

## Overview
This project uses an Arduino to control a motor driver (L298N or similar) via a Bluetooth module. Commands sent from a Bluetooth-enabled device control the movement of the motors.

## Components Required
- Arduino Board
- Bluetooth Module (HC-05 or HC-06)
- Motor Driver Module (L293d or similar)
- DC Motors
- Power Supply (Battery pack or adapter)
- Connecting Wires

## Pin Configuration
- **Bluetooth Module**
  - RX -> Arduino Pin 10
  - TX -> Arduino Pin 11
- **Motor Driver**
  - ENA -> Pin 3 (Speed control for motor A)
  - IN1 -> Pin 5
  - IN2 -> Pin 6
  - IN3 -> Pin 9
  - IN4 -> Pin 10
  - ENB -> Pin 11 (Speed control for motor B)

## Installation and Usage
1. Connect the components as per the pin configuration.
2. Upload the `Arduino` code to the board.
3. Pair your Bluetooth module with a mobile device.
4. Use a Bluetooth serial terminal app to send commands.

## Command List
- **F**: Move Forward
- **B**: Move Backward
- **L**: Turn Left
- **R**: Turn Right
- **S**: Stop Motors

## Code Explanation
- The Arduino listens for commands from the Bluetooth module.
- Upon receiving a command, the corresponding function is executed to move the motors.
- `analogWrite()` controls motor speed, while `digitalWrite()` controls direction.

## License
This project is open-source and free to use for educational purposes.

