# Smart Keychain

Krishna Bansal, Jitesh Jain

This is a simple project to build a smart keychain that will help you to locate your keys with ease. The project uses an ESP8266 board and an active buzzer to make a sound when the keys are nearby.

## Contents

- [Components Required](#components-required)
- [Schematic Diagram](#schematic-diagram)
- [Circuit Diagram](#circuit-diagram)
- [Software Setup](#software-setup)
- [How It Works](#how-it-works)
- [Usage Instructions](#usage-instructions)

## Components Required

### Hardware

- ESP8266 board
- Active Buzzer
- Jumper Wires
- USB Cable
- Battery

### Software

- Arduino IDE
- Ubidots account for data publishing and hosting the webpage
- Libraries:
  - UbidotsESPMQTT.h
  - pitches.h

## Schematic Diagram

![block](images/block.svg)

### Making the Connections

1. Connect the VCC of the active buzzer to the 3.3V of the ESP8266 board.
2. Connect the GND of the active buzzer to the GND of the ESP8266 board.
3. Connect the I/O of the active buzzer to the D8 pin of the ESP8266 board.
4. Connect the RST to the D0 of the ESP8266 board to enable sleep mode.

We don't show the battery connections in the schematic diagram. Please refer to the [circuit diagram](#circuit-diagram) for more information.

## Circuit Diagram

![circuit](images/circuit.png)

## Software Setup

1. Create an account on the Ubidots website (<https://ubidots.com/>).
2. Create a new device (named **"nodemcu"**) on the Ubidots platform and add new variables (**"toggle"**, **"tune_to_play"**). Take note of the following values:
    - TOKEN: your Ubidots token.
    - WIFI_NAME: your WiFi network's name.
    - WIFI_PASSWORD: your WiFi network's password.
3. Open the Arduino IDE and install the required libraries.
4. Copy and paste the code from [src/code.ino](src/code.ino) into a new sketch.
5. Replace the following values in the code with your own:
    - TOKEN
    - WIFI_NAME
    - WIFI_PASSWORD
6. Upload the code to the ESP8266 board.
7. Open the Serial Monitor to see the status of the board.
8. Control the smartkey using the webpage hosted on Ubidots.

## How it Works

The ESP8266 based smartkey has a buzzer which can be activated by clicking on the toggle button on a webpage hosted on the internet using Ubidots. The ESP8266 board is connected to the WiFi. The webpage also contains various choices of different sounds to play upon activation of the buzzer.

## Usage Instructions

1. Connect your computer or mobile device to the WiFi network.
2. Log in to your Ubidots account.
3. Open the webpage hosted on the internet using Ubidots.
4. Activate the buzzer using the toggle button on the webpage.

## Acknowledgements
