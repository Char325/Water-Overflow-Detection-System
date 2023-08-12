
# Water Overflow Detection and SMS Alert System

This Arduino sketch is designed to monitor water levels and send SMS alerts based on the water level reading. It uses a GSM module to send SMS messages to a predefined mobile number when the water level reaches specific thresholds.

## Components Used
- Arduino UNO board (compatible with SoftwareSerial)
- GSM module (SIM800L or similar)
- Water level sensor (analog sensor connected to pin A0)
- Power control pin (pin 7)
- Buzzer (connected to pin 11)

## Setup
1. Connect the GSM module to the Arduino using SoftwareSerial on pins 9 and 10.
2. Connect the water level sensor to the analog input A0.
3. Connect the power control pin (pin 7) to control the power supply of the water level sensor.
4. Connect a buzzer to pin 11 to provide an audible alert.

## How it Works
1. The sketch initializes the SoftwareSerial for communication with the GSM module and the Serial for debugging purposes.
2. The `sendSMS` function is defined to send SMS messages. Modify the phone number and messages in this function as needed.
3. In the `loop` function, the water level is read from the analog input (A0) after powering the sensor.
4. Based on the water level reading, the sketch takes the following actions:
   - If the water level is high (value >= 400), it sends a "Water level maximum. Cut off water supply." SMS.
   - If the water level is medium (350 <= value <= 150), it activates the buzzer for 5 seconds and sends a "Water level medium" SMS.
   - If the water level is low (value <= 150), it sends a "Water level low" SMS.
5. The power control pin is used to turn the sensor on and off to conserve power when not actively reading the water level.

## Thresholds
- Water Level High: Reading >= 400
- Water Level Medium: 350 <= Reading <= 150
- Water Level Low: Reading <= 150

## Usage
1. Upload the sketch to the Arduino board.
2. Make sure the components are correctly connected.
3. When the water level reaches a specific threshold, the sketch will send an SMS alert to the predefined phone number.

## Note
- Make sure to replace the mobile number in the `sendSMS` function with the desired recipient's number.
- Adjust the water level thresholds in the `loop` function as needed for your specific application.

**Note**: Ensure you have the necessary libraries installed to use the SoftwareSerial and tone functions.

*This sketch is intended as a basic example and may need modifications based on the specific hardware and use case.*
