# simplest code to send pgm change command

#include <MIDI.h>

// Constants
#define MIDI_TX_PIN D7        // TX pin used for MIDI communication
#define ENCODER_SWITCH_PIN 13 // Pin for rotary encoder switch (SW)
#define PROGRAM_NUMBER 5      // Program number to send (0-127)
#define MIDI_CHANNEL 11        // MIDI channel to send the program change (1-16)

// MIDI Setup
MIDI_CREATE_INSTANCE(HardwareSerial, Serial, MIDI);  // Use hardware Serial for MIDI

// Handle encoder switch press to send Program Change
void handleEncoderSwitch() {
  if (digitalRead(ENCODER_SWITCH_PIN) == LOW) {
    MIDI.sendProgramChange(PROGRAM_NUMBER, MIDI_CHANNEL);
    delay(200);  // Debounce delay
  }
}

void setup() {
  pinMode(ENCODER_SWITCH_PIN, INPUT_PULLUP);  // Set switch pin as input with pull-up resistor

  Serial.begin(31250);  // Initialize MIDI at 31250 baud using the TX pin
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop() {
  handleEncoderSwitch();
}
