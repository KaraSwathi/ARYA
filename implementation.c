#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>
int pos = 0;
Servo servo_9;
int moisture = 0;
int seconds = 0;
Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  servo_9.attach(9, 500, 2500);
  lcd_1.begin(16, 2);
}

void loop()
{
  
  digitalWrite(A0, HIGH);
  delay(10); 
  moisture = analogRead(A1);
  digitalWrite(A0, LOW);
  Serial.println(moisture);
 
  if (moisture < 300) 
  {
    lcd_1.setCursor(0, 1);
    lcd_1.print("Water the plant.");
    seconds += 1;
    Serial.println("SOIL IS DRY, WATER THE PLANT");
    for (pos = 0; pos <= 180; pos += 1)
    {
    servo_9.write(pos);
    delay(15); 
    }
    for (pos = 180; pos >= 0; pos -= 1) 
    {
    servo_9.write(pos);
    delay(15); 
    }
  }
  else
  {
    lcd_1.setCursor(0, 1);
    lcd_1.print("Plant is hydrated");
  }
    
  delay(100); 
}