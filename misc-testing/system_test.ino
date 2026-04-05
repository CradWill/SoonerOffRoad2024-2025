#include "HX711.h"

#define DOUT  2
#define CLK  3



HX711 scale1;


float calibration_factor = -700000; // set up calibration factor here


void setup() {
  Serial.begin(9600);
//  Serial.println("HX711 calibration sketch");
//  Serial.println("Remove all weight from scale");
//  Serial.println("After readings begin, place known weight on scale");
//  Serial.println("Press + or a to increase calibration factor");
//  Serial.println("Press - or z to decrease calibration factor");

  scale1.begin(DOUT, CLK);
  scale1.set_scale();
  scale1.tare(); //Reset the scale to 0



// long zero_factor = scale1.read_average(); //Get a baseline reading
// long zero_factor = scale2.read_average();
//  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
//  Serial.println(zero_factor);
}

void loop() {

  scale1.set_scale(calibration_factor); //Adjust to this calibration factor


//  Serial.print("Reading: ");
Serial.print("SG Left : ");
  Serial.print(scale1.get_units(), 5);
  Serial.print("  ||   SG Right (compensate) : ");
  
  //Serial.println(" lbs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
//  Serial.print(" calibration_factor: ");
//  Serial.print(calibration_factor);
//  Serial.println();

  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 10;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 10;
  }
  delay(100);
}