## Table of Contents
* [Project Instruction](#project-instruction)
* [Circuit Diagram](#circuit-diagram)
* [Photo Recording](#photo-recording)
* [Code](#code)
* [Final Effect](#final-effect)

## Project Instruction
This is a group project. Our group consists of `Hao Wu(me)`, `Yansong Wang`, `Lingyu Guo` and `Yiting Jia`. We plan to use finger to control puppet's finger, and each finger will triger different music.
I am mainly responsible for `coding`， and assist in assembling the pressure sensor and designing the arrangement of the circuit.

## Circuit Diagram
<img width="1421" alt="Tinkercad" src="https://user-images.githubusercontent.com/91842476/143964425-d173fd3a-ad54-4556-bf9d-59df3285c318.png">

## Photo Recording
![Recording1](https://github.com/msc-creative-computing/p-comp-week-1-labs-HarryWuuuuu/blob/869fb305c350a5c8e035ee38d742154022bec7a6/Week%206/Recording1.JPG)
![Recording2](https://github.com/msc-creative-computing/p-comp-week-1-labs-HarryWuuuuu/blob/869fb305c350a5c8e035ee38d742154022bec7a6/Week%206/Recording2.JPG)
![Recording3](https://github.com/msc-creative-computing/p-comp-week-1-labs-HarryWuuuuu/blob/869fb305c350a5c8e035ee38d742154022bec7a6/Week%206/Recording3.JPG)
![Recording4](https://github.com/msc-creative-computing/p-comp-week-1-labs-HarryWuuuuu/blob/869fb305c350a5c8e035ee38d742154022bec7a6/Week%206/Recording4.JPG)

## Code
```c
#include "pitches.h"
//set chord
int melody0[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int melody1[] = {
  NOTE_B0, NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1
};
int melody2[] = {
  NOTE_B2, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_F5, NOTE_A5, NOTE_D6, NOTE_B5
};
int melody3[] = {
  NOTE_E6, NOTE_F6, NOTE_C7, NOTE_E7, NOTE_F7, NOTE_B7, NOTE_C8, NOTE_CS8
};
//set duration of each tone
int noteDurations[] = {
  4, 8, 7, 3, 1, 6, 9, 2
};
//set pressure sensor pin
int pin0 = A0;
int pin1 = A1;
int pin2 = A2;
int pin3 = A3;
//initialize press sensor value
int sensorValue0 = 0;
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;

//set led pin
int Led_Pin0 = 10;
int Led_Pin1 = 11;
int Led_Pin2 = 12;
int Led_Pin3 = 13;

//music function
void music0(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];  //set sound duration
    tone(9, melody0[thisNote], noteDuration);            //turn on buzzer
    int pauseBetweenNotes = noteDuration * 1.30;        //set delay time
    delay(pauseBetweenNotes);
    noTone(9);                                          //mute buzzer
  }
}
void music1(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];  //set sound duration
    tone(9, melody1[thisNote], noteDuration);            //turn on buzzer
    int pauseBetweenNotes = noteDuration * 1.30;        //set delay time
    delay(pauseBetweenNotes);
    noTone(9);                                          //mute buzzer
  }
}
void music2(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];  //set sound duration
    tone(9, melody2[thisNote], noteDuration);            //turn on buzzer
    int pauseBetweenNotes = noteDuration * 1.30;        //set delay time
    delay(pauseBetweenNotes);
    noTone(9);                                          //mute buzzer
  }
}
void music3(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];  //set sound duration
    tone(9, melody3[thisNote], noteDuration);            //turn on buzzer
    int pauseBetweenNotes = noteDuration * 1.30;        //set delay time
    delay(pauseBetweenNotes);
    noTone(9);                                          //mute buzzer
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(Led_Pin0, OUTPUT); 
  pinMode(Led_Pin1, OUTPUT);
  pinMode(Led_Pin2, OUTPUT);
  pinMode(Led_Pin3, OUTPUT);
}

void loop() {
  Serial.print("pin0: ");
  Serial.println(sensorValue0);

  Serial.print("pin1: ");
  Serial.println(sensorValue1);  
  
  Serial.print("pin2: ");
  Serial.println(sensorValue2);

  Serial.print("pin3: ");
  Serial.println(sensorValue3);
  
  //A0
  sensorValue0 = analogRead(pin0);
  if(sensorValue0 < 500){
      digitalWrite(Led_Pin0, HIGH);
      delay(10);
      music0();
      
    }else
    digitalWrite(Led_Pin0, LOW);

  //A1
  sensorValue1 = analogRead(pin1);
  if(sensorValue1 < 550){
      digitalWrite(Led_Pin1, HIGH);
      delay(10);
      music1();
    }else
    digitalWrite(Led_Pin1, LOW);

  //A2
  sensorValue2 = analogRead(pin2);
  if(sensorValue2 < 500){
      digitalWrite(Led_Pin2, HIGH);
      delay(10);
      music2();
    }else
    digitalWrite(Led_Pin2, LOW);

  //A3
  sensorValue3 = analogRead(pin3);
  if(sensorValue3 < 500){
      digitalWrite(Led_Pin3, HIGH);
      delay(10);
      music3();
    }else
    digitalWrite(Led_Pin3, LOW);

    
    delay(30);
} 
```
## Final Effect
https://youtu.be/G7_KSMHOJaE
