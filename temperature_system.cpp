#include "temperature_system.h"
#include "Arduino.h"
#include "main.h"


float temperature;
void init_temperature_system(void)
{
   //setting heater and cooler GPIO pins as output pins
   pinMode(HEATER, OUTPUT); 
   pinMode(COOLER, OUTPUT); 
    
}

float read_temperature(void)
{
  //read the temperature sensor return the temperature
  temperature = (((analogRead(A0) * (float)5/1024)) / (float) 0.01);
  return temperature;

   
}

void cooler_control(bool control)// reciving the state of the button on the mobile blynk app
{
   if(control)
   {
    //turn on the cooler -> assign digital value 1 to the cooler gpio pin
    digitalWrite( COOLER, 1);

   }
   else
   {
    // off 
    digitalWrite( COOLER, 0);

   }
}
void heater_control(bool control)
{
  if(control)
   {
    //turn on the cooler -> assign digital value 1 to the cooler gpio pin
    digitalWrite( HEATER, 1);

   }
   else
   {
    // off 
    digitalWrite( HEATER, 0);
   }
    
}
