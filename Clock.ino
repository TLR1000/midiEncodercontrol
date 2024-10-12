#simple code to send clock messages for tempo control

#include <MIDI.h>
#include <Encoder.h>

// Constants
#define DEFAULT_TEMPO 100     // Default BPM
#define MIDI_TX_PIN D7        // TX pin used for MIDI communication
#define MIN_BPM 10            // Min BPM
#define MAX_BPM 1000          // Max BPM
#define ENCODER_PIN_A 14      // Pin A (CLK) for rotary encoder      // Pin A for rotary encoder
#define ENCODER_PIN_B 12      // Pin B (DT) for rotary encoder      // Pin B for rotary encoder

// Variables
unsigned long bpm = DEFAULT_TEMPO;
Encoder encoder(ENCODER_PIN_A, ENCODER_PIN_B);  // Rotary encoder instance (with switch support on pin 13)  // Rotary encoder instance
long lastEncoderPosition = 0;

// MIDI Setup
MIDI_CREATE_INSTANCE(HardwareSerial, Serial, MIDI);  // Use hardware Serial for MIDI

// Send MIDI Clock
void sendMidiClock() {
  unsigned long interval = 60000 / bpm / 24;
  static unsigned long lastMidiTime = 0;
  unsigned long currentTime = millis();

  if (currentTime - lastMidiTime >= interval) {
    MIDI.sendRealTime(midi::Clock);
    lastMidiTime = currentTime;
  }
}

// Adjust BPM using rotary encoder
void adjustBPM() {
  long newEncoderPosition = encoder.read() / 4;  // Adjust for better resolution and stability
  if (newEncoderPosition != lastEncoderPosition) {
    long change = lastEncoderPosition - newEncoderPosition;
    bpm += change;
    if (bpm < MIN_BPM) bpm = MIN_BPM;
    if (bpm > MAX_BPM) bpm = MAX_BPM;
    lastEncoderPosition = newEncoderPosition;
  }
}

void setup() {
  pinMode(13, INPUT_PULLUP);  // Set switch pin as input with pull-up resistor
  Serial.begin(31250);  // Initialize MIDI at 31250 baud using the TX pin
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop() {
  if (digitalRead(13) == LOW) {
    bpm = DEFAULT_TEMPO;  // Reset BPM to default when switch is pressed
  }
  sendMidiClock();
  adjustBPM();
}
