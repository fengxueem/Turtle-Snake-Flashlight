#include <stdlib.h> 
#include <stdio.h>
#define P_L 4//the pin number of left button
#define P_R 3//the pin number of right button
#define P_sleep 5//the pin number of on/off switch
#define P_flaswch 8//the pin number of flash switch 
#define P_1 2//the pin number of 1 charlie pin
#define P_2 6//the pin number of 2 charlie pin
#define P_3 7//the pin number of 3 charlie pin
#define P_4 9//the pin number of 4 charlie pin
#define P_5 10//the pin number of 5 charlie pin
#define P_6 14//the pin number of 6 charlie pin
#define P_7 13//the pin number of 7 charlie pin
#define P_8 12//the pin number of 8 charlie pin
#define P_9 11//the pin number of 9 charlie pin
#define P_flash 19 //the pin number of flash light
#define time_one 10//time duration of one LED being lightened
#define left (-1)// turn left	
#define right (1)// turn right
#define time_warmup 80
const int debounce_delay = 250;// 1/4 sec debouncing delay after sleep switch is closed or opened 
unsigned int v=20;//speed of the snake
const int f_flag=0;
unsigned int d,ld;
unsigned int x_1,x_2,x_3,randx,y_1,y_2,y_3,randy;
void setup()
{
  Initialize_Pins();
}

void loop()
{
  for(int i=1;i<=5;i++)
  {
      for(int j=1;j<=4+i;j++)
      {
        lightone(i,j,time_warmup);
      }
  }
  for(int i=6;i<=9;i++)
  {
      for(int j=i-4;j<=9;j++)
      {
        lightone(i,j,time_warmup);
      }
  }
}

void turn(int dir)
{
  d=(6+d+dir)%6;
}

void lightone(int x, int y,int time) //light up one LED in very little duration to deceive th eyes
{
  int pinx,piny;
  if(x!=y)
  {
    pinx=codtopin(x);piny=codtopin(y);
    pinMode(pinx,OUTPUT);
    pinMode(piny,OUTPUT);
    digitalWrite(pinx,HIGH);
    digitalWrite(piny,LOW);
    delay(time);
    pinMode(pinx,INPUT);
    pinMode(piny,INPUT);
  }
  else
  {
    if(x<=4)
    {
      pinx=codtopin(x);
      pinMode(pinx,OUTPUT);
      pinMode(P_9,OUTPUT);
      digitalWrite(pinx,HIGH);
      digitalWrite(P_9,LOW);
      delay(time);
      pinMode(pinx,INPUT);
      pinMode(P_9,INPUT);
    }
    else if(x==5)
    {
      pinMode(P_7,OUTPUT);
      pinMode(P_2,OUTPUT);
      digitalWrite(P_7,HIGH);
      digitalWrite(P_2,LOW);
      delay(time);
      pinMode(P_7,INPUT);
      pinMode(P_2,INPUT);
    }
    else
    {
      pinx=codtopin(x);
      pinMode(pinx,OUTPUT);
      pinMode(P_1,OUTPUT);
      digitalWrite(pinx,HIGH);
      digitalWrite(P_1,LOW);
      delay(time);
      pinMode(pinx,INPUT);
      pinMode(P_1,INPUT);      
    }
  }     
}

void dir_coor(void)
{ 
   ld=d;
   switch(ld)
   {
     case 0:x_3=x_2;y_3=y_2;x_2=x_1;y_2=y_1;x_1=x_1-1;break;//y_1 stays the same
     case 1:x_3=x_2;y_3=y_2;x_2=x_1;y_2=y_1;y_1=y_1+1;break;//x_1 stays the same
     case 2:x_3=x_2;y_3=y_2;x_2=x_1;y_2=y_1;x_1=x_1+1;y_1=y_1+1;break;
     case 3:x_3=x_2;y_3=y_2;x_2=x_1;y_2=y_1;x_1=x_1+1;break;//y_1 stays the same
     case 4:x_3=x_2;y_3=y_2;x_2=x_1;y_2=y_1;y_1=y_1-1;break;//x_1 stays the same
     case 5:x_3=x_2;y_3=y_2;x_2=x_1;y_2=y_1;x_1=x_1-1;y_1=y_1-1;break;
   }
}

int codtopin(int x)
{
int X;
switch(x)
{
    case 1:X=P_1;break;
    case 2:X=P_2;break;
    case 3:X=P_3;break;
    case 4:X=P_4;break;
    case 5:X=P_5;break;
    case 6:X=P_6;break;
    case 7:X=P_7;break;
    case 8:X=P_8;break;
    case 9:X=P_9;break;
  }
  return X;
}
void Initialize_Pins(void) 
{
  pinMode(P_1,INPUT);//charlieplexing output pins,from 1 to 9
  pinMode(P_2,INPUT);
  pinMode(P_3,INPUT);
  pinMode(P_4,INPUT);
  pinMode(P_5,INPUT);
  pinMode(P_6,INPUT);
  pinMode(P_7,INPUT);
  pinMode(P_8,INPUT);
  pinMode(P_9,INPUT);
  pinMode(P_flash,OUTPUT);//flashlight transistor pin
  digitalWrite(P_flash,LOW);
  pinMode(P_sleep,INPUT_PULLUP);//P1.3
  pinMode(P_flaswch,INPUT_PULLUP);//P2.0
  pinMode(P_L,INPUT_PULLUP);//P1.2
  pinMode(P_R,INPUT_PULLUP);//P1.1
} 
