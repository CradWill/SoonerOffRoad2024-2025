#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 3;  // Connect DT to pin 3
const int LOADCELL_SCK_PIN = 2;   // Connect SCK to pin 2

HX711 scale;

const float V_ref = 5.0;  // Reference voltage (adjust if using 3.3V system)
const long max_ADC_value = 8388607;  // Max ADC value for 24-bit signed integer

long baseline = 0;     // The baseline (tare) value
float scaleFactor = -0.0000242123; // Set this to your calculated scale factor

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

  // You can skip the known weight input part now since you already have the scale factor
  Serial.print("Using scale factor: ");
  Serial.println(scaleFactor);
}

void loop() {
  // Get the raw ADC value from the HX711
  long rawValue = scale.read();
  
  // Calculate the corresponding voltage
   float baselineVoltage = (baseline / (float)max_ADC_value) * V_ref;
   float currentVoltage = (rawValue / (float)max_ADC_value) * V_ref;

   float voltageDifference = currentVoltage - baselineVoltage;

  // Calculate the weight in kilograms
  float weightInKg = (rawValue - baseline) * scaleFactor;

  // Convert weight to pounds (1 kg = 2.20462 lbs)
  float weightInLbs = weightInKg * 2.20462;

  // Display weight in kilograms and pounds
  Serial.print("Weight: ");
  Serial.print(weightInKg);
  Serial.print(" kg | ");
  Serial.print(weightInLbs);
  Serial.println(" lbs");

  // Display the voltage
  Serial.print("Voltage: ");
  Serial.print(voltageDifference, 6);  // 6 decimal places for voltage
  Serial.println(" V");

  delay(1000);  // Update every second
}
