#include "LinearActuator.h"

LinearActuator L1;

int speedinput;

void setup() 
 {
  Serial.begin(115200);
  L1.init(26, 27, 34);        // Forward stroke pwm pin, Reverse stroke pwm pin, Potentiometer pin
  L1.set_stoke_length(304.8); // 12 inch stroke length in mm
  L1.calibrate();             // calibrates and prints limits values
  L1.set_limits(162, 3243);   // calibrated limits using calibrate() function
  L1.get_raw_pos();           // returns raw analog input value from potentiometer feedback.
  L1.get_pos();               // returns stroke length position value.
  L1.move_actuator(0);        // takes in speed ranging from  -100 to 100 , 0 to stop the actuator.
 }

void loop() 
 {
  Serial_input();
  L1.move_actuator(speedinput); // takes in speed ranging from  -100 to 100.
  Serial.print(speedinput);
  Serial.print("==");
  Serial.println(L1.get_pos());
 }

void Serial_input()
 {
  if(Serial.available())
   {
    speedinput = Serial.parseInt();Serial.read();
   }
 }
