#include "EmonLib.h"                   // Include Emon Library
//#include "eRCaGuy_analogReadXXbit.h"
EnergyMonitor emon1;                   // Create an instance
 
void setup()
{  
  
  Serial.begin(9600);
 
  emon1.current(2, 60);             // Current: input pin, calibration.
  //calibration is explained bellow
}
 
void loop()
{
  //analogReadXXbit(12);
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  
  // read the input on analog pin 5:
  //int sensorValue = analogRead(A5);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
 // float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  

  //Serial.print(Irms*230.0);	       // Apparent power
  Serial.print("Stroom: ");
  Serial.print(Irms);
  Serial.println(" A");		       // Irms
  //Serial.print(" ");
  //Serial.println(voltage);
}
