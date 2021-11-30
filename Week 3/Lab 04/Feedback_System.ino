// C++ code
//
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
