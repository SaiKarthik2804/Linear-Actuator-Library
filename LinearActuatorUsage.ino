#include "LinearActuator.h"

LinearActuator L1;

int speedinput;

void setup() 
 {
  Serial.begin(115200);
  L1.init(25, 26, 27, 34);      // Forward stroke pwm pin, Reverse stroke pwm pin, Potentiometer pin
  L1.set_state(HIGH);           // enable (HIGH) or disable (LOW) the linear actuator 
  //L1.set_limits(162, 3243);   // Limits the range of linear actuation (min,max) [raw potentiometer limits from get_raw_pos()]
  //L1.set_end_limit_threshold(2); // set a threshold(input range 0-100) for a cushioning effect to end limts
  L1.set_alpha(0.1);            // Setting alpha value (default value = 0.1) for exponential moving average value of raw potentiometer feedback value of linear actuator
  //Serial.print(L1.ema());     // ema() Returns exponential moving average value of raw potentiometer feedback value of linear actuator
  L1.move_actuator(0);          // takes in speed ranging from  -100 to 100 , 0 to stop the actuator.
 }

void loop() 
 {
  Serial_input();
  L1.move_actuator(speedinput); // takes in speed ranging from  -100 to 100.
  Serial.print(speedinput);     // prints speed input in serial monitor.
  Serial.print("==");
  Serial.println(L1.get_raw_pos()); // prints raw analog position (use this info to set limits for linear actuator)
 }

void Serial_input()
 {
  if(Serial.available())
   {
    speedinput = Serial.parseInt();Serial.read();
   }
 }
