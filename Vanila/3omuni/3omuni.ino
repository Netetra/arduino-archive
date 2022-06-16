#include <PS4BT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>


USB Usb;
BTD Btd(&Usb);
PS4BT PS4(&Btd, PAIR);//初期接続
//PS4BT PS4(&Btd);//二回目以降

int powpin[3] = {2,4,5};
int dirpin[3] = {26,32,38};

int r = 0 ;
void power(int k,double *powerResult);

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(dirpin[i], OUTPUT);
    pinMode(powpin[i], OUTPUT);
  }
   
   Serial.begin(115200);

#if !defined(__MIPSEL__)
  while (!Serial); 
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1);
  }
 
  Serial.print(F("\r\nPS4 Bluetooth Library Started"));

}

void loop() {
  Usb.Task();
    
if(PS4.connected()){
    double x = PS4.getAnalogHat(LeftHatX) - 127;
    double y = PS4.getAnalogHat(LeftHatY) - 127;
    double k = atan2(x,y);
    double m[3];
    power(k,x,y,m);
    
    /*for(int j =0;j<3;j++){
        Serial.print(m[j]);
        Serial.print(",");
      if(j==2){
        Serial.print(k);
        Serial.print("\n");
      }
    }*/
    
    if(x>10||x<-10||y>10||y<-10){
      for(int i=0;i<3;i++){
      if(m[i]<-10){
        analogWrite(powpin[i],-1*m[i]);
        digitalWrite(dirpin[i],HIGH);
        
      }
      else if(m[i]>10){
        analogWrite(powpin[i],m[i]);
        digitalWrite(dirpin[i],LOW);
        }
      }
    }
    else{
       for(int i=0;i<3;i++){
      if(m[i]<10){
        analogWrite(powpin[i],0);
        digitalWrite(dirpin[i],LOW);
        }
      } 
    }
  }
}
void power(int k,double x,double y,double *powerResult){
   powerResult[0] =(x + r*k);
   powerResult[1] =1.8*((-x/2) + y*(sqrt(3)/2) + r*k);
   powerResult[2] =1.8*((-x/2) - y*(sqrt(3)/2) + r*k);
}
