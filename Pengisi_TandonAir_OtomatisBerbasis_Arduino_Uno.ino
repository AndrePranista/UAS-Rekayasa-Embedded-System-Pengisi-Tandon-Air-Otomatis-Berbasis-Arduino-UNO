#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define trigPin 9
#define echoPin 10
#define relay 8
int ketinggian;

void setup(){
  Serial.begin (9600);

  lcd.init();
  lcd.backlight();
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (relay,OUTPUT);
  digitalWrite(relay, LOW);
}

void loop(){
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println(" cm");
  
  lcd.setCursor(0,0);
  lcd.print("Ketingian Air");
  lcd.setCursor(0,1); 
  lcd.print(ketinggian);
  lcd.setCursor(3,1);
  lcd.print("cm");
  delay(500);
  lcd.clear();
  
  ketinggian = 14-distance;
if(ketinggian >= 13){
    digitalWrite(relay, HIGH);
    delay (3000);
  }
 if(ketinggian < 3){
    digitalWrite(relay,LOW);
    delay (500);
  }
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
