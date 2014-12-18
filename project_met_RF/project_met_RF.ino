/*
  NRF24L01+:
     1 - GND
     2 - VCC 3.3V !!! NOT 5V
     3 - CE to Arduino pin 9
     4 - CSN to Arduino pin 10
     5 - SCK to Arduino pin 13
     6 - MOSI to Arduino pin 11
     7 - MISO to Arduino pin 12
     8 - UNUSED
     
  SCT013:
     GND to Arduino GND
     VCC to Arduino Uno +5V (3.3V due)
     Clamp Wire to Arduino A0
*/


/*-----( Import needed libraries )-----*/
#include <EmonLib.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN   9
#define CSN_PIN 10

const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe

/*-----( Declare objects )-----*/
EnergyMonitor emon1;                   // Create an instance
RF24 radio(CE_PIN, CSN_PIN);           // Create a Radio

int Current[1];
 
void setup()
{  
  Serial.begin(9600);
  emon1.current(0, 60);             // Current: input pin, calibration.
  
  radio.begin();
  radio.openWritingPipe(pipe);
}
 
void loop()
{
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  Current[1] = Irms;
  radio.write(Current,sizeof(Current));
  
  Serial.print(Irms*230.0);	       // Apparent power
  Serial.print(" ");
  Serial.println(Irms);		       // Irms
}
