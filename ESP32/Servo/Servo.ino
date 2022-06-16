#include <Servo.h>

Servo servo; //Servoオブジェクトを作成

void setup() {
  servo.attach(15); //PWMの制御線をD15以外に接続している場合はここの数字を変更する

}

void loop() {
  servo.write(0);
  delay(2000);
  servo.write(45);
  delay(2000);
  servo.write(90);
  delay(2000);
  servo.write(135);
  delay(2000);
  servo.write(180);
  delay(2000);
  servo.write(135);
  delay(2000);
  servo.write(90);
  delay(2000);
  servo.write(45);
  delay(2000);
}
