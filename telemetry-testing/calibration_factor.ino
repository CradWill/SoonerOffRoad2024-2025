#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 3;  // Connect DT to pin 3
const int LOADCELL_SCK_PIN = 2;   // Connect SCK to pin 2

HX711 scale;

long baseline = 0;      // The baseline (tare) value
float scaleFactor = 0;  // To be calculated

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  // Wait until the HX711 is ready
  while (!scale.is_ready()) {
    Serial.println("HX711 not found. Check wiring.");
    delay(1000);
  }

  Serial.println("Place the scale in an unloaded state (no weight).");
  delay(5000);  // Give time to place the scale in a no-load state

  // Tare the scale (i.e., find the baseline)
  baseline = scale.read();
  Serial.print("Baseline (tare) value: ");
  Serial.println(baseline);

  Serial.println("Now place a known weight on the scale.");
  delay(10000);  // Give time to add a known weight to the scale

  // Read the new value with the known weight applied
  long readingWithWeight = scale.read();
  Serial.print("Raw reading with known weight: ");
  Serial.println(readingWithWeight, 9);


 Serial.println("Enter the known weight (in kg):");
  while (Serial.available() == 0) {}        // Wait for input
  float knownWeight = Serial.parseFloat();


 scaleFactor = knownWeight / (readingWithWeight - baseline);
 Serial.print("Scale factor: ");
 Serial.println(scaleFactor, 10);
}

void loop() {
  // Just continuously display the tare and scale factor values for reference
  long currentReading = scale.read();
  float weight = (currentReading - baseline) * scaleFactor;

  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" kg");

  delay(1000);  // Print the weight every second
}
