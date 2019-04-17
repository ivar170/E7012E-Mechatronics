#include <PID_v1.h>                     
#include <Servo.h>                      //include the servo library

Servo SteeringServo;                    // Servo object Servo
Servo MotorServo;                       // Servo object Motorcontroll

float angle = 0.75;                      // Steering angle -1 is left 0 is straigth and 1 is right. X100 for % 
float mps = 0.75;                        // Engine speed where 0 is standing still and 1 is full throttle

void setup() {
  Serial.begin(9600);                        // Sets the data rate in bits per second (baud) for serial data transmission.
  MotorSetup();                              // Engine function to tab for setup
  ServoSetup();                              // Servo function to tab for setup
  Serial.println("Setup completed!");
  delay(1000);
}
void loop() {
  //SetSpeed(mps);                               //Makes function for running the motortab        
  SetSteering(angle);                            //Makes function for running the servotab
  angle = 0.5;
  SetSteering(angle);
  
  delay(3000);                              //demonstration time of 3 sek until reset below                      
  MotorServo.writeMicroseconds(1200);       //set speed to 0
  SteeringServo.writeMicroseconds(1550);    //set steering straight 
  delay(2000);                              //Keep it zero for 2 sek until showing desierd values again.
}

  
