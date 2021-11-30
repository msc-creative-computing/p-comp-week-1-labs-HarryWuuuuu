## Table of Contents
* [Project Introduction](#project-introduction)
* [Circuit Diagram](#circuit-diagram)
* [Photo Recording](#photo-recording)
* [Code](#code)
* [Final Effect](#final-effect)

## Project Introduction
I use led and LDR to build a feedback system. When the led becomes dark, ldr will trigger and make the led gradually brighter. When the led becomes brighter, the ldr will trigger again to make the led dim again. This cycle continues.

## Circuit Diagram
![Tinkercad](https://github.com/msc-creative-computing/p-comp-week-1-labs-HarryWuuuuu/blob/d3cab25bbbffe9df5db6c6d0d524c546159b88ca/Week%203/Lab%2004/Tinkercad.png)

## Photo Recording
![Recording1](https://github.com/msc-creative-computing/p-comp-week-1-labs-HarryWuuuuu/blob/717da91badcab923e151406bad2cbc8d96ca650e/Week%203/Lab%2004/Feedback%20System.png)

## Code
```c
int led = 11;
int LDR = A0;

int brightness = 0;
int fadeAmount = 20;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop()
{
  int ldrStatus = analogRead(LDR);
  Serial.println(ldrStatus);

  analogWrite(led, brightness);

//  Serial.println(brightness); 
//  Serial.print("/t"); 
  if (ldrStatus <= 20) {
    brightness +=fadeAmount;
   
//    Serial.print("Its DARK, Turn on the LED : ");
//    Serial.println(ldrStatus);

  } else{
    brightness -= fadeAmount;
    
//    Serial.print("Its BRIGHT, Turn off the LED : ");
//    Serial.println(ldrStatus);
  }
  delay(500);
}
```

## Final Effect
https://vimeo.com/651403453
