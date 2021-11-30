## Table of Contents
* [Project Instruction](#project-introduction)
* [Circuit Diagram](#circuit-diagram)
* [Photo Recording](#photo-recording)
* [Code](#code)
* [Final Effect](#final-effect)

## Project Introduction
Due to the inspiration of Squid Game, I design an "puppet" to detect human movement. I install the PIR move sensor, led and buzzer on the puppet.
### Game Rules
Players need to stop their movement before the PIR sensor detects them. If they are detected, the led will light and buzzer will sound. (But it seems that I'm always detected by sensor.)

## Circuit Diagram
![Tinkercad](https://github.com/msc-creative-computing/p-comp-week-1-labs-HarryWuuuuu/blob/69bc29c0c00ad343c35397aadeaa887dd16e48a6/Week%202/Lab%204/Tinkercad.png
)

## Photo Recording
![Recording1](https://github.com/msc-creative-computing/p-comp-week-1-labs-HarryWuuuuu/blob/6e0189ddcfa36e4528839e55c2adf8524dd55708/Week%202/Lab%204/Recording1.png
)
![Recording2](https://github.com/msc-creative-computing/p-comp-week-1-labs-HarryWuuuuu/blob/6e0189ddcfa36e4528839e55c2adf8524dd55708/Week%202/Lab%204/Recording2.png
)

## Code
```c
const int PIN_TO_SENSOR = 2;   // the pin that OUTPUT pin of sensor is connected to
int pinStateCurrent   = LOW; // current state of pin
int pinStatePrevious  = LOW; // previous state of pin

int Led_Pin = 13; //led display
int buzzer = 9;   //buzzer set

void setup() {
  Serial.begin(9600);            // initialize serial
  pinMode(PIN_TO_SENSOR, INPUT); // set arduino pin to input mode to read value from OUTPUT pin of sensor
  pinMode(Led_Pin, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  pinStatePrevious = pinStateCurrent; // store old state
  pinStateCurrent = digitalRead(PIN_TO_SENSOR);   // read new state
  
  if (pinStatePrevious == LOW && pinStateCurrent == HIGH) {   // pin state change: LOW -> HIGH
    digitalWrite(Led_Pin, HIGH);  //turn on LED
    tone(buzzer, 1000);   //turn on buzzer
    delay(500);       //only work 0.5s
    noTone(buzzer);   //mute buzzer
    delay(500);
    
    Serial.println("Motion detected!");
    // TODO: turn on alarm, light or activate a device ... here
  }
  else
  if (pinStatePrevious == HIGH && pinStateCurrent == LOW) {   // pin state change: HIGH -> LOW
    digitalWrite(Led_Pin, LOW);   // turn off LED
    
    Serial.println("Motion stopped!");
    // TODO: turn off alarm, light or deactivate a device ... here
  }
}
```

## Final Effect
https://vimeo.com/651382607
