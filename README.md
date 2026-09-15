# Automated Train Protection System (Front-Obstacle Detection)

**Official Project Title:** Trains Protection System from Front Obstacles

A railway safety prototype developed to detect obstacles in front of a train and provide automated warning and model-train stopping functions to reduce the risk of collisions.

## Project Overview

The project presents an academic prototype for protecting train movement from obstacles located on the railway track.

The system uses an ultrasonic sensor installed at the front of the locomotive model to detect obstacles ahead. When an obstacle is detected according to the predefined conditions of the prototype, the system provides visual and audible warnings and can activate the motor control circuit to stop the model train.

The project also includes a railway signaling model based on infrared (IR) sensors. The IR sensors detect the movement of the train through different sections of the track and control the sequence of railway semaphore indications.

The project demonstrates the integration of obstacle detection, microcontrollers, motor control, railway signaling, and warning systems within an academic railway model.

## Project Objectives

- Detect obstacles located in front of the train.
- Provide visual and audible warnings when an obstacle is detected.
- Control the movement of the model train according to the detected obstacle condition.
- Demonstrate an emergency stopping function using an H-Bridge motor control circuit.
- Implement a railway signal sequence using IR sensors.
- Demonstrate automated monitoring and warning for railway movement protection.
- Integrate sensors, microcontrollers, railway signals, and motor control in an academic railway model.

## System Description

The prototype consists of two main sections:

1. **Train / Locomotive Protection System**
2. **Railway Track and Signaling System**

The locomotive uses an Arduino Uno to process the ultrasonic sensor data and control the warning and motor functions.

The railway track uses an Arduino Mega to process the IR sensor inputs and control the railway signals and station warning devices.

## Main Components

### Train / Locomotive

- Arduino Uno
- Ultrasonic Sensor
- H-Bridge DC Motor Driver
- DC Motor
- Yellow LED
- Red LED
- Buzzer
- Lithium Batteries
- Connecting Wires

### Railway Track and Signaling

- Arduino Mega
- IR Sensors
- Railway Signals / Semaphores
- Green, Yellow, and Red LEDs
- Station Warning LEDs
- Buzzer
- Railway Track Model
- Locomotive Model
- MDF Wooden Base
- Connecting Wires

## How the System Works

### 1. Front-Obstacle Detection

The ultrasonic sensor is installed at the front of the locomotive model.

The sensor sends ultrasonic waves toward the railway path and receives the reflected waves from objects in front of the train.

The distance to the detected obstacle is calculated based on the time required for the ultrasonic wave to travel to the obstacle and return to the sensor.

The basic distance relationship is:

`Distance = (Speed × Time) / 2`

The division by two accounts for the outgoing and returning path of the ultrasonic wave.

### 2. Warning and Train Protection

When an obstacle is detected according to the programmed conditions, the system provides visual and audible warnings using LEDs and a buzzer.

When the obstacle reaches the defined danger condition, the control system can activate the H-Bridge motor control circuit to stop the model train.

### 3. Railway Signal Sequence

IR sensors are installed along the railway model to detect the movement of the train between different sections.

The sensors are used to control the sequence of the railway semaphores.

The model includes green, yellow, and red signal indications representing different railway movement conditions.

### 4. Station Warning System

The railway model also includes a station warning system using LEDs and a buzzer.

The warning devices are activated according to the programmed sequence when the train approaches the station area.

## Control System

The project uses two Arduino microcontrollers:

### Arduino Uno

The Arduino Uno is installed on the locomotive model and is responsible for:

- Processing ultrasonic sensor measurements.
- Detecting front obstacles.
- Controlling warning LEDs.
- Activating the buzzer.
- Controlling the DC motor through the H-Bridge circuit.

### Arduino Mega

The Arduino Mega is installed on the railway track model and is responsible for:

- Processing IR sensor inputs.
- Controlling railway semaphore indications.
- Managing the signal sequence.
- Controlling the station warning LEDs and buzzer.

## Railway Signaling

The prototype contains four railway semaphore models with three main indications:

- **Green**
- **Yellow**
- **Red**

The signal sequence changes according to the position and movement of the train detected by the IR sensors.

This provides an academic demonstration of automated railway signaling and train movement protection.

## Hardware and Software

### Hardware

- Arduino Uno
- Arduino Mega
- Ultrasonic Sensor
- IR Sensors
- H-Bridge DC Motor Driver
- DC Motor
- LEDs
- Buzzers
- Railway Signal Models
- Locomotive Model
- Railway Track Model
- Batteries
- Connecting Wires

### Software

- Arduino IDE
- Arduino Programming
- Embedded Control Logic

## Project Development

The prototype was developed through several stages:

1. Designing the railway model layout.
2. Preparing and painting the track base.
3. Installing the railway track and supporting structure.
4. Installing the railway signals and sensors.
5. Building the locomotive model.
6. Installing the ultrasonic obstacle detection system.
7. Connecting the Arduino Uno and Arduino Mega.
8. Implementing the motor control circuit.
9. Programming the railway signal sequence.
10. Integrating the complete system and testing its operation.

## Project Features

- Front-obstacle detection.
- Real-time obstacle monitoring.
- Visual warning indications.
- Audible warning using a buzzer.
- Model train stopping function.
- IR-based railway signal sequencing.
- Arduino-based control.
- Integration of train protection and railway signaling concepts.

## Future Development

The current prototype focuses on obstacle detection on straight railway sections.

Future development may include:

- Improving obstacle detection performance.
- Extending the system to railway curves and different track layouts.
- Improving detection under different environmental conditions.
- Developing more advanced train braking control.
- Integrating additional railway communication and monitoring technologies.
- Developing the prototype toward a more advanced railway safety system.

## Project Information

**Project Title:** Automated Train Protection System (Front-Obstacle Detection)

**Official Project Title:** Trains Protection System from Front Obstacles

**Institution:** Higher Institute for Transport Technology (HITT)

**Specialization:** Railway Signals Control Systems Technology

**Academic Year:** 2023–2024

**Project Year:** 2024

## Team Members

1. Ibrahim Mohamed Ibrahim
2. Ahmed Mohamed Mohey El-Din
3. Khaled Mahmoud Ali Sahsah
4. Ahmed Tamer Samir
5. Khaled Mesbah Hassan
6. Mohamed Ramdan Elkhrashe
7. Karim Mohamed Abdallah
8. Ibrahim Ahmed Atwa

## Author

**Ahmed Mohamed Mohey El-Din**

Higher Institute for Transport Technology (HITT)

Railway Signals Control Systems Technology

---

*This repository presents an academic railway safety prototype developed as a second-year project at the Higher Institute for Transport Technology.*
