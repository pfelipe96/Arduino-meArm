#include <Servo.h>

int pinHook = 3;
int pinRight = 4;

char receiveBluetooth;
char teclaOne = 'A';
char teclaTwo = 'B';
char teclaDownRight = 'C';
char teclaUpRight = 'D';

float valueControl;
Servo servoHook, servoRight;

void setup(){
  Serial.begin(9600);
  servoHook.attach(pinHook);
  servoRight.attach(pinRight);
}

void loop() {
  while(Serial.available() > 0){
    receiveBluetooth = Serial.read();
    
    if(teclaOne == receiveBluetooth){
        openHook();
        Serial.println("LED Vermelho ligado !");
    }else if(teclaTwo == receiveBluetooth){
        closeHook();
        Serial.println("LED Vermelho ligado !");
    }else if(teclaDownRight == receiveBluetooth){
        forUp();
        Serial.println("LED Vermelho ligado !");
    }else if(teclaDownRight == receiveBluetooth){
        forDown();
        Serial.println("LED Vermelho ligado !");
    }
  }
}

void openHook(){
  servoHook.write(50);
}

void closeHook(){
  servoHook.write(120);
}

void forUp(){
  smoothUp();
}

void forDown(){
  smoothDown();
}

void smoothDown(){
  int value = 50;
  while(value != 120){
    servoRight.write(value);
    value = value + 5;
    delay(100);
  }
}

void smoothUp(){
  int value = 110;
  while(value != 20){
    servoRight.write(value);
    value = value - 5;
    delay(100);
  }
}

