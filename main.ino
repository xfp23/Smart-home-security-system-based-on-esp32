'''Ardiuno
#Ardiuno IDE 下的智能安全系统设计
##主程序
###初始化
#include "head.h"

//定义舵机引脚：控制门窗
const int door=13;
const int window=5;


//定义超声波传感器引脚：
const int trig=18;
const int ehoc=19;

//定义红外传感器引脚：
const int serson_out=34;
const int serson_door=35;
const int serson_window=33;


//定义蜂鸣器引脚：
const int speaker=16;

float stance;
void setup(){
  pinMode(door,OUTPUT);
  pinMode(window,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(ehoc,INPUT);
  pinMode(speaker,OUTPUT);
  pinMode(serson_out,INPUT);
  pinMode(serson_door,INPUT);
  pinMode(serson_window,INPUT);
  const int pin[]={door,window,trig,ehoc,speaker};
  for(int i=0;i<5;i++){
    digitalWrite(pin[i],LOW);
    }
     Serial.begin(9600);
  }


 void loop(){
  static uint people=0;//计数器
  volatile bool serson_out_state=digitalRead(serson_out);//此传感器感应物体为低电平
    volatile bool serson_door_state=digitalRead(serson_door);//此传感器感应到物体为低电平
     volatile bool serson_window_state=digitalRead(serson_window);//此传感器感应到物体为低电平
     
                
    //进门操作：
    if(serson_out_state==LOW){
       people++;
       bee(speaker,220,1);
      delay(1000);
      bobato(door,1500);
      delay(1000);
      if((serson_window_state)==LOW)
      bobato(window,450);
      delay(2000);
      bobato(door,800);
      delay(5000);
      }
      //出门操作：
      
      if(serson_door_state==HIGH){
        delay(2000);
        if(serson_door_state==HIGH){
          bobato(door,800);
          if(people>0)
          people--;
          bee(speaker,714,1);
          }
          if(serson_window_state==HIGH&&people==0) 
          {
             bobato(window,1500); 
            }
        }
        if(people==0){
           stance=ultrasounds(trig,ehoc);
                Serial.print(stance);
                Serial.print("CM");
                Serial.println();
                delay(2000);
          if(stance<(ROOM-BODY)){
          bee(speaker,714,10);
            if(serson_door_state==HIGH)
              bobato(door,800);
              if((serson_window_state)==HIGH)
              bobato(window,1500);
              delay(1000);
            }
          }
 }
  
