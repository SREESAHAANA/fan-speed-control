//sound based an on/ off 
#include <EveryTimer.h> 
#define PERIOD_MS 1000  EveryTimer timer; bool active = true; 
#define mic A0 #define fan int count,sec,act=0; void setup() { 
  // put your setup code here, to run once: 
Serial.begin(9600); pinMode(mic,INPUT); pinMode(fan,OUTPUT); 
  timer.Every(PERIOD_MS, action); 
} void loop() { 
  // put your main code here, to run repeatedly: 
Serial.print("Mic :"); 
Serial.println(analogRead(mic)); 
if(analogRead(mic)<=1020){count++;while(analogRead(mic)<=1020){Serial.print("wait");delay(1000);} } if(count==1){analogWrite(fan,50);Serial.println("slow");} else if(count==2){analogWrite(fan,255);Serial.println("full speed"); } else if(count>=3){analogWrite(fan,0);count=0;Serial.println("off");}  Serial.print("c :"); Serial.println(count); 
delay(100); 
} 
 // Callback called by timer void action() 
{ sec++;}
