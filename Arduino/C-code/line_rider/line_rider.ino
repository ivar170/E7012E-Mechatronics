#include <Servo.h>

Servo SteeringServo;     // Servo object Servo
Servo MotorServo;

// Steering
int ServoValue;           // Analog input value Servo
int ServoPin = 9;         // Control pin for steering servo motor
int maxPulseSteering = 1800;
int minPulseSteering = 1300;

// Speed
int ServoMotorValue;
int ServoMotorPin = 8;    // Control pin for motor servo
int minPulseMotor = 0;
int maxPulseMotor = 1000;

int steeringPos = A0;
float oldAngle = 0.0;

void setup() {

  Serial.begin(9600);   // Setup a serial connection for debugging.

  // initialize the steering servo signal pin as an OUTPUT
  //(pin, min pulse width, max pulse width in microseconds)
  // set servo at 90 degrees from 0-180
  pinMode(ServoPin, OUTPUT);                      
  SteeringServo.attach(ServoPin,minPulseSteering,maxPulseSteering);       
  SteeringServo.writeMicroseconds(1550);                  

  MotorServo.attach(ServoMotorPin, minPulseMotor, maxPulseMotor);
  MotorServo.writeMicroseconds(500);
  Serial.println("Setup completed!");
  delay(1000);
}

void loop() {
  pinMode(A0,INPUT);
  
  SetSteering(-0.5);
  SetSteering(0.0);
  SetSpeed(1.0);
  SetSteering(1.0);
  SetSteering(0.0);
  SetSpeed(0.5);
}
