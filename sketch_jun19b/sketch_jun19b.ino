#include <SimpleDHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int pinDHT11 = 5;
int sensorPin = A0;
SimpleDHT11 dht11(pinDHT11);
LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  Serial.begin(115200);
}


void loop()
{
  lcd.init(); 
  int sensorValue = analogRead(sensorPin);
  lcd.setCursor(0,0);
  lcd.print("cds = ");
  lcd.print(sensorValue);
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  lcd.setCursor(1,1);
  lcd.print("T = ");
  lcd.print(((int)temperature));
  lcd.print(",H = ");
  lcd.print(((int)humidity));
  delay(1500);
}
