Sooner Offroad Telemetry & Embedded Systems (Baja SAE)
_____________________________________________________________________________________________________________________________________
Overview

This repository contains embedded systems code and testing scripts developed for the University of Oklahoma competition team, Sooner Offroad Baja SAE, during the 2024–2025 design cycle.
The goal of this project was to design and test a wireless telemetry system that could send real-time data from the vehicle to a remote receiver.
We didn’t finish the car in time for competition, but this repo shows the actual work that was done — including testing, failed attempts, and partial systems that did work.

Update (April 2, 2026): We carried this into the next design cycle, and using what we learned here, we were able to get a consistent working system.
_____________________________________________________________________________________________________________________________________
Project Objectives

Develop an embedded telemetry system
Interface sensors (load/strain using HX711)
Transmit data wirelessly (NRF24L01 and some LoRa testing)
Test how reliable communication is as distance increases
Build something the next team could actually use and improve
_____________________________________________________________________________________________________________________________________
My Contributions

Wrote Arduino-based code for sensor reading and communication
Set up and calibrated the HX711 load cell amplifier
Built and tested wireless transmit/receive scripts
Ran range tests and troubleshooting on RF modules
Debugged both hardware and software issues (a lot of trial and error)
Documented what worked and what didn’t so the next iteration would be easier
_____________________________________________________________________________________________________________________________________
Technologies Used

Languages: C++ (Arduino)

Microcontrollers: Arduino Nano

Communication:
NRF24L01 (main focus)
LoRa (early testing)

Sensors & ICs:
HX711 (load cell amplifier)

Tools:
Arduino IDE
Serial monitor for debugging
Multimeter for hardware checks
_____________________________________________________________________________________________________________________________________
System Architecture

[Sensor / Load Cell]
↓
HX711
↓
Microcontroller (Arduino)
↓
Wireless Module (NRF24 / LoRa)
↓
Base Station Receiver (PC-connected MCU)
↓
Serial Output / Logging
_____________________________________________________________________________________________________________________________________
Testing & Results

What worked:
Got communication between nodes working at short range
Successfully read and transmitted sensor data in controlled tests

What didn’t:
Signal reliability dropped off quickly with distance
Couldn’t get consistent performance past very short range (~15 ft)
Medium/long range (0.1 miles+) was not reliable

Main issues:
Power stability on battery setups
RF inconsistency depending on environment and setup
Not enough time to fully redesign hardware
_____________________________________________________________________________________________________________________________________
Repository Structure

/HX711_basic_example → basic load cell tests
/hx711 → HX711 integration code
/calibrationFactor → calibration scripts
/basic_tx / basic_rx → NRF24 communication
/nrf_testing_script → RF testing code
/voltageRead → power monitoring
_____________________________________________________________________________________________________________________________________
Project Status

**Incomplete / Experimental

We got parts of the system working, but not to the level needed for full vehicle integration.
A lot of the remaining issues were hardware-related, and fixing them would have required parts and time we didn’t have before the end of the 2025–2026 school year.
The team didn’t compete that season because the vehicle wasn’t finished.
_____________________________________________________________________________________________________________________________________
What I Learned

Things don’t work the first time — especially in embedded systems
Hardware + software together is way harder than just writing code
RF communication is not plug-and-play, it takes real testing
Debugging means checking everything: wiring, power, code, assumptions
Keeping track of what you tried matters more than you think
_____________________________________________________________________________________________________________________________________
Future Improvements

Move fully to LoRa for better range
Add a structured data packet system
Add onboard logging (SD card or similar)
Improve power regulation
Eventually build a real-time telemetry dashboard
_____________________________________________________________________________________________________________________________________
Acknowledgments

Sooner Offroad Baja SAE Team
University of Oklahoma College of Engineering
_____________________________________________________________________________________________________________________________________
Contact

If you have questions or want to talk about the project, feel free to reach out.
