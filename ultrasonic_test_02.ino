#include "MeMCore.h"

MeUltrasonicSensor kAndur(PORT_3);
MeRGBLed led(PORT_7);
uint8_t punane=0;
uint8_t roheline=0;
uint8_t sinine=0;

MeDCMotor motorParem(M1);
MeDCMotor motorVasak(M2);

uint8_t motorSpeed = 100;
long juhunumber;

void setup() {
  Serial.begin(9600);
}

void loop() {

  float kaugus = kAndur.distanceCm();
  Serial.print("Kaugus: ");
  Serial.print(kaugus );
  Serial.println(" cm");
  delay(100);

  juhunumber = random(0, 2);
  Serial.println(juhunumber);

  led.setColorAt(0,00,50,0);
  led.show();
  
      motorParem.run(motorSpeed);
      motorVasak.run(-motorSpeed);
      if (kaugus < 15){
        led.setColorAt(0,50,0,0);
        led.show();
      motorParem.stop();
      motorVasak.stop();
      //tagasi käik
      motorParem.run(-motorSpeed);
      motorVasak.run(motorSpeed);
      delay(500);
      if (juhunumber < 1){
        led.setColorAt(0,0,0,50);
        led.show();
        motorParem.run(-motorSpeed);
        motorVasak.run(-motorSpeed);
        Serial.println("vaiksem");
        }else{
        motorParem.run(motorSpeed);
        motorVasak.run(motorSpeed);
        Serial.println("suurem");
        }
      
      delay(500);
      }
}
