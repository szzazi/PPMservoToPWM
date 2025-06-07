# PPMservoToPWM

This Arduino-based project converts a PPM signal (commonly used in RC systems) into individual PWM signals suitable for driving servos or other PWM-controlled devices.

## Features

- Supports decoding PPM signal and generating corresponding PWM outputs
- Suitable for RC applications or embedded control systems
- Designed to work with AVR-based Arduino boards (e.g., Nano, Uno)

## File Structure

- `PpmToPwm.ino` – Main Arduino sketch
- `servoReader.h` – Reads and interprets the incoming PPM signal
- `HBridgeController.h` – Optional motor control logic (can be adapted for custom use)

## Requirements

- Arduino board (tested with Nano)
- PPM signal source (e.g., RC receiver)
- Arduino IDE

## Installation

1. Clone or download this repository.
2. Open `PpmToPwm/PpmToPwm.ino` with the Arduino IDE.
3. Connect your PPM input to the configured pin (check `servoReader.h`).
4. Upload the sketch to your Arduino board.
5. Connect your servos or motor controllers to the PWM output pins.

## Usage

Once uploaded, the Arduino board will decode the incoming PPM signal and generate PWM signals on the designated output pins. These can control servos, motors, or other compatible devices.

## Customization

- Adjust the number of channels or pulse timing in `servoReader.h`.
- Extend functionality via `HBridgeController.h` if needed for motor control.

## License

This project is open-source and provided under the MIT License.

---

Feel free to contribute or modify it for your specific hardware setup.
