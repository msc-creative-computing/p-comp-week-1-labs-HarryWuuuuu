#include <FastLED.h>
#include <Adafruit_Sensor.h>
#include <Servo.h>

//PIR Sensor
int PIRSensor = 8;
int pinStateCurrent = LOW;

//LED Strip
#define NUMBER 7
CRGB leds[NUMBER];

//Press Sensor
int Press_Pin0 = A0;
int Press_Pin1 = A1;
int Press_Pin2 = A2;
int Press_Pin3 = A3;
int Press_Pin4 = A4;
//press value detect
int PressValue0 = 0;
int PressValue1 = 0;
int PressValue2 = 0;
int PressValue3 = 0;
int PressValue4 = 0;

//Servo Motor
int servoPin0 = 9;
int servoPin1 = 10;
int servoPin2 = 11;
int servoPin3 = 12;
int servoPin4 = 13;
Servo Servo0;
Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;

//Vibration Motor
int VibrationPin0 = 0;
int VibrationPin1 = 1;
int VibrationPin2 = 2;

void setup() {
  Serial.begin(9600);

  //PIR Sensor
  pinMode(PIRSensor, INPUT);

  //LED Strip
  FastLED.addLeds<NEOPIXEL, 3>(leds, NUMBER);
  FastLED.addLeds<NEOPIXEL, 4>(leds, NUMBER);
  FastLED.addLeds<NEOPIXEL, 5>(leds, NUMBER);
  FastLED.addLeds<NEOPIXEL, 6>(leds, NUMBER);
  FastLED.addLeds<NEOPIXEL, 7>(leds, NUMBER);

  //attach servo motor
  Servo0.attach(servoPin0);
  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);
  Servo3.attach(servoPin3);
  Servo4.attach(servoPin4);

  //vibration motor output
  pinMode(VibrationPin0, OUTPUT);
  pinMode(VibrationPin1, OUTPUT);
  pinMode(VibrationPin2, OUTPUT);

}
                              
void loop() {

  //PIR Sensor
  pinStateCurrent = digitalRead(PIRSensor);
  if(pinStateCurrent == HIGH){
    digitalWrite(VibrationPin0, HIGH);
    digitalWrite(VibrationPin1, HIGH);
    digitalWrite(VibrationPin2, HIGH);
    }else{
      digitalWrite(VibrationPin0, LOW);
      digitalWrite(VibrationPin1, LOW);
      digitalWrite(VibrationPin2, LOW);
      }
      
  //get press value
  PressValue0 = analogRead(Press_Pin0);
  PressValue1 = analogRead(Press_Pin1);
  PressValue2 = analogRead(Press_Pin2);
  PressValue3 = analogRead(Press_Pin3);
  PressValue4 = analogRead(Press_Pin4);
  //display press value
  Serial.print("PressValue0(800): ");
  Serial.println(PressValue0);  //760-150
  Serial.print("PressValue1(500): ");
  Serial.println(PressValue1);  //750-450
  Serial.print("PressValue2(450): ");
  Serial.println(PressValue2);  //1000-650
  Serial.print("PressValue3(920): ");
  Serial.println(PressValue3);  //600-300
  Serial.print("PressValue4(600): ");
  Serial.println(PressValue4);  //800-440
  Serial.println(" ");

  //use press sensor to control servo motor
  //PressSensor0 control ServoMotor0
  if(PressValue0 < 800){
    leds[0] = 0x8DF4A4;
    leds[1] = 0x000000;
    leds[2] = 0x000000;
    leds[3] = 0x000000;
    leds[4] = 0x000000;
    leds[5] = 0x000000;
    FastLED.show();
    //open servo motor   
    Servo0.write(0);
    delay(800);
    Servo0.write(180);
    delay(800);
    }
    //PressSensor1 control ServoMotor1
  if(PressValue1 < 600){
    leds[0] = 0x000000;
    leds[1] = 0x6D4FD8;
    leds[2] = 0x000000;
    leds[3] = 0x000000;
    leds[4] = 0x000000;
    leds[5] = 0x000000;
    FastLED.show();
    //open servo motor
    Servo1.write(0);
    delay(800);
    Servo1.write(180);
    delay(800);
    }
    //PressSensor2 control ServoMotor2
  if(PressValue2 < 450){
    leds[0] = 0x000000;
    leds[1] = 0x000000;
    leds[2] = 0xF5926E;
    leds[3] = 0x000000;
    leds[4] = 0x000000;
    leds[5] = 0x000000;
    FastLED.show();
    //open servo motor
    Servo2.write(0);
    delay(800);
    Servo2.write(180);
    delay(800);
    }
    //PressSensor3 control ServoMotor3
  if(PressValue3 < 920){
    leds[0] = 0x000000;
    leds[1] = 0x000000;
    leds[2] = 0x000000;
    leds[3] = 0x000000;
    leds[4] = 0xC139CE;
    leds[5] = 0x000000;
    FastLED.show();
    //open servo motor
    Servo3.write(0);
    delay(800);
    Servo3.write(180);
    delay(800);
    }
    //PressSensor4 control ServoMotor4
  if(PressValue4 < 600){
    leds[0] = 0x000000;
    leds[1] = 0x000000;
    leds[2] = 0x000000;
    leds[3] = 0x000000;
    leds[4] = 0x000000;
    leds[5] = 0xC3268A;
    FastLED.show();
    //open servo motor
    Servo4.write(0);
    delay(800);
    Servo4.write(180);
    delay(800);
    }

   delay(500);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
