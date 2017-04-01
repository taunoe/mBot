#include "MeMCore.h"


MeUltrasonicSensor kAndur(PORT_3);

MeDCMotor motorParem(M1);
MeDCMotor motorVasak(M2);

uint8_t motorSpeed = 100;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float kaugus = kAndur.distanceCm();
  Serial.print("Kaugus: ");
  Serial.print(kaugus );
  Serial.println(" cm");
  delay(100);

  motorParem.run(motorSpeed);
  motorVasak.run(-motorSpeed);
  if (kaugus < 10){
      motorParem.stop();
      motorVasak.stop();
      //tagasi käik
      motorParem.run(-motorSpeed);
      motorVasak.run(motorSpeed);
      delay(10);
      motorParem.run(motorSpeed);
      motorVasak.run(motorSpeed);
      delay(500);
    }
   

}
