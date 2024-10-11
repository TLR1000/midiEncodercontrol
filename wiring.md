# Wiring Description for MIDI Tempo Controller with Rotary Encoder

### Components:
- MIDI Chassis Connector
- LOLIN D1 Mini V4.0.0
- Rotary Encoder (with push button)
- MIDI Output Connector

### Pin Assignments:

#### LOLIN D1 Mini V4.0.0:
- **GPIO 14 (D5)**: Rotary Encoder Pin A (CLK)
- **GPIO 12 (D6)**: Rotary Encoder Pin B (DT)
- **GPIO 13 (D7)**: Rotary Encoder Push Button (SW)
- **TX (D7)**: MIDI Output Pin 5 (via 220Ω resistor)
- **GND**: MIDI Output Pin 2
- **5V**: MIDI Output Pin 4 (via 220Ω resistor)

### Rotary Encoder:
- **Pin A (CLK)**: Connect to GPIO 14 (D5) on LOLIN D1 Mini.
- **Pin B (DT)**: Connect to GPIO 12 (D6) on LOLIN D1 Mini.
- **Switch (SW)**: Connect to GPIO 13 (D7) on LOLIN D1 Mini with an internal pull-up resistor.

### MIDI Output Connector (Chassis Connector):
- **Pin 5**: Connect to TX (D7) on LOLIN D1 Mini via a 220Ω resistor.
- **Pin 2**: Connect to GND on LOLIN D1 Mini.
- **Pin 4**: Connect to 5V on LOLIN D1 Mini via a 220Ω resistor.

### Power Supply:
- **5V and GND**: Use the onboard 5V and GND pins from the LOLIN D1 Mini to power the MIDI output.

### MIDI Chassis Connector:
- **Pin 5**: Connects to MIDI Output Pin 5.
- **Pin 2**: Connects to MIDI Output Pin 2 (GND).
- **Pin 4**: Connects to MIDI Output Pin 4 (5V).

### Notes:
- The rotary encoder is used to adjust the BPM value.
- Pressing the encoder's push button resets the BPM to the default value of 100.
- The MIDI output sends clock signals at a baud rate of 31250 bps to synchronize other MIDI devices.
- Ensure all GND connections are properly connected to avoid communication issues.
