/*
Circuit:
We need to read an analog voltage on A0, so place a pot with the outer legs going to 5V and GND, respectively, and the wiper (middle leg) going to A0
-make sure to set your Serial Monitor to 115200 baud rate
*/

//include the library
#include <eRCaGuy_analogReadXXbit.h>

//instantiate an object of this library class; call it "adc"
eRCaGuy_analogReadXXbit adc;

//Global constants
//constants required to determine the voltage at the pin
const float MAX_READING_10_bit = 1023.0;
const float MAX_READING_11_bit = 2046.0;
const float MAX_READING_12_bit = 4092.0;
const float MAX_READING_13_bit = 8184.0;
const float MAX_READING_14_bit = 16368.0;
const float MAX_READING_15_bit = 32736.0;
const float MAX_READING_16_bit = 65472.0;
const float MAX_READING_17_bit = 130944.0;
const float MAX_READING_18_bit = 261888.0;
const float MAX_READING_19_bit = 523776.0;
const float MAX_READING_20_bit = 1047552.0;
const float MAX_READING_21_bit = 2095104.0;

void setup() 
{
  Serial.begin(115200);
  Serial.println(F("Oversampling example to get 10-bit to 21-bit resolution using a 10-bit ADC on an Arduino"));
  Serial.println("Ultra Basic demo");
  Serial.println(""); //add a line space
}

void loop() 
{
  //local variables
  int pin = A0; //analogRead pin
  int bits_of_precision = 16; //must be a value between 10 and 21
  int num_samples = 1;
  
  //take a reading on pin A0
  float analog_reading = adc.analogReadXXbit(pin,bits_of_precision,num_samples); //get the avg. of [num_samples] 16-bit readings 
  
  //output results
  Serial.print("analog_reading = ");
  Serial.println(analog_reading);
  Serial.print("Voltage = ");
  Serial.print(5.0*analog_reading/MAX_READING_16_bit,5); //display up to 5 digits of precision
  Serial.println("V");
  Serial.println("");
  
  //wait a bit before taking another reading
  delay(500);
}
