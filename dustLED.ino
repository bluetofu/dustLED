#include <LiquidCrystal.h>

int dustPin=0;
float dustVal=0;
float dustDensity = 0;
 
int ledPower=10;
int delayTime=280;
int delayTime2=40;
float offTime=9680;
int ledPin = 7;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
 Serial.begin(9600);
  pinMode(ledPower,OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(ledPin, OUTPUT);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop() {
  digitalWrite(ledPower,LOW); // power on the LED
  delayMicroseconds(delayTime);

  dustVal=analogRead(dustPin); // read the dust value via pin 5 on the sensor
  delayMicroseconds(delayTime2);

  digitalWrite(ledPower,HIGH); // turn the LED off
  delayMicroseconds(offTime);
 
  delay(1000);
  dustDensity = 0.17*(dustVal*0.0049)-0.1;
  
  if( (dustDensity > 0.20) && (dustDensity < 0.40 ) ){ 
    analogWrite(ledPin ,70);
  }
  if (dustDensity >= 0.40){ 
    analogWrite(ledPin ,225);
  }
  else{ 
    analogWrite(ledPin ,0);
  }

 lcd.setCursor(0, 1);
 lcd.clear();
 lcd.print("Dust density(mg/m3) = ");
 lcd.setCursor(1, 2); 
 lcd.print(dustDensity);
 Serial.println(dustDensity);
 delay(100);
}
