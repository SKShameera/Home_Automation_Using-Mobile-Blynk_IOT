/*************************************************************
Title         :   Home automation using blynk
Description   :   To control light's brigntness with brightness,monitor temperature , monitor water level in the tank through blynk app
Pheripherals  :   Arduino UNO , Temperature system, LED, LDR module, Serial Tank, Blynk cloud, Blynk App.
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPL3DTEY1a1X"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "itpKoxNL_cVVrP39QOBHUxGDanGWwIS4"



// Comment this out to disable prints 

#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
#include "ldr.h"
#include "main.h"
#include "temperature_system.h"


#include "serial_tank.h"

//char auth[] = BLYNK_AUTH_TOKEN;
bool heater_sw,inlet_sw,outlet_sw, cooler_sw;
//unsigned int tank_volume;

//creating object called timer to update the temperature on blynk app at particular period
BlynkTimer timer;

 // set the LCD address to 0x27 for a 16 chars and 2 line display

// This function is called every time the Virtual Pin 0 state changes
/*To turn ON and OFF cooler based virtual PIN value*/
BLYNK_WRITE(COOLER_V_PIN)
{
  //read the changed val on the pin
  cooler_sw = param.asInt();

  //based on the pin val control the heater and cooler
  cooler_control(cooler_sw);
  if(cooler_sw)
  {
    lcd.setCursor(6, 0);
    lcd.print("CLR_ON ");

  }
  else
  {
    lcd.setCursor(6, 0);
    lcd.print("CLR_OFF");

  }
  
}
/*To turn ON and OFF heater based virtual PIN value*/
BLYNK_WRITE(HEATER_V_PIN )
{
    //read the changed val on the pin
  heater_sw = param.asInt();

  //based on the pin val control the heater and cooler
  heater_control(heater_sw);
  if(heater_sw)
  {
    lcd.setCursor(6, 0);
    lcd.print("HTR_ON ");

  }
  else
  {
    lcd.setCursor(6, 0);
    lcd.print("HTR_OFF");

  }
  
}
/*To turn ON and OFF inlet vale based virtual PIN value*/
BLYNK_WRITE(INLET_V_PIN)
{
  inlet_sw = param.asInt();
  if(inlet_sw)
  {
    enable_inlet();
    lcd.setCursor(7, 1);
    lcd.print("IN_FL_ON ");

  }
  else
  {
    disable_inlet();
    lcd.setCursor(7, 1);
    lcd.print("IN_FL_OFF ");

  }
  
}
/*To turn ON and OFF outlet value based virtual switch value*/
BLYNK_WRITE(OUTLET_V_PIN)
{
  outlet_sw = param.asInt();
  if(outlet_sw)
  {
    enable_outlet();
    lcd.setCursor(7, 1);
    lcd.print("OT_FL_ON ");

  }
  else
  {
    disable_outlet();
    lcd.setCursor(7, 1);
    lcd.print("OT_FL_OFF ");

  }
  
}
/* To display temperature and water volume as gauge on the Blynk App*/  
void update_temperature_reading()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  //send temperature to blynk app on pin v1
  Blynk.virtualWrite(TEMPERATURE_GAUGE, read_temperature() );

  Blynk.virtualWrite(WATER_VOL_GAUGE, volume() );
  
}

/*To turn off the heater if the temperature raises above 35 deg C*/
void handle_temp(void)
{
  // read the temperature and compare it with 35 and if heater is on
  if(read_temperature() > 35 && heater_sw)
  {
    heater_sw = 0;
    heater_control(0);
    Blynk.virtualWrite(HEATER_V_PIN, 0 );
    //print notification on the clcd
    lcd.setCursor(6, 0);
    lcd.print("HTR_ON");


  }

  // turn off the heater and button on the blynk app also off
  
}

/*To control water volume above 2000ltrs*/
void handle_tank(void)
{
  //if volume of water more than 2000, inlet value app also off
  if(volume() < 2000 && inlet_sw == 0)
  {
    inlet_sw = 1;
    enable_inlet();
    Blynk.virtualWrite(INLET_V_PIN, 1 );
    //print notification on the clcd
    lcd.setCursor(7, 1);
    lcd.print("IN_FL_ON ");


  }

} 

void setup(void)
{
  init_ldr();
  //initialize temperature system
  init_temperature_system();
  //connect arduino to blynk cloud
  Blynk.begin(BLYNK_AUTH_TOKEN);

  //initialse CLCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.home();
  lcd.setCursor(0, 0);
  lcd.print("Home Automation");
  delay(1000);
  lcd.clear();
  //initialize the serial tank
  init_serial_tank();


  // update temperature on blynk every one sec, cannot send more 10 val in 1 sec
  timer.setInterval(1000, update_temperature_reading);
    
}

float tem;
unsigned int volume_water;
void loop(void) 
{
  //control the heater and cooler from the blynk app
  Blynk.run(); //button heater -> v0, cooler -> v2
  timer.run();
  brightness_control();
  // READ THE TEMPERATURE FROM TEMPERATURE SENSOR LM35
  tem = read_temperature();
  //send the temperature to the blynk app on virtual pin v1
  // if temperature increases more than 35
  handle_temp();
  handle_tank();


//reading the volume
  volume_water = volume();
//displaying it on the clcd
  lcd.setCursor(0, 1);
  lcd.print(volume_water);

  lcd.setCursor(0, 0);
  lcd.print(tem);
      
}
