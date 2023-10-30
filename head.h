'''c++
#常量以及函数定义
  #include "Arduino.h"
#ifndef HIGH
#define HIGH 1
#endif
#ifndef LOW
#define LOW 0
#endif
/***********************************************************************************************************************************************************/

#ifdef uint
#define uint unsigned int
#endif
#ifdef uchar
#define uchar unsigned char
#endif

/************************************************************************************************************************************************************/
//区分人跟动物的身高：
#define BODY 3.0
#define ROOM 24.66
/************************************************************************************************************************************************************/
  float ultrasounds(const int trig,const int ehoc) {
   float cm = 0;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  cm = pulseIn(ehoc, HIGH) / 58.0;
  return cm;
}
/**********************************************************************************************************************************************************/
//舵机控制：(本次项目推荐值：800(关门),1500(开门),开窗450,关窗1300)pwm值
void bobato(const int pin, uint pwm) {
  if(pwm>770){
  for (uint i = 770; i < pwm; i+=2) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(i); 
    digitalWrite(pin, LOW);
    delay(10);
  }}
  else
  {
for (uint i=400; i<pwm; i+=2) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(i); 
    digitalWrite(pin, LOW);
    delay(10);
  }
    }
  
}
