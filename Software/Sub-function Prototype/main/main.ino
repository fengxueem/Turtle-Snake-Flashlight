#include <stdlib.h> 
#include <time.h>
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
const int debounce_delay = 250;// 1/4 sec debouncing delay after sleep switch is closed or opened 
unsigned int v=20;//speed of the snake
unsigned int L,R,d,ld;//L and R record the number of how many times the left and right buttons are pressed. 
                      //d is the next direction of snake,ld is the last direction snake went from.
int x1,x2,x3,randx,y1,y2,y3,randy;
int v;
const int f_flag=0;

void setup()
{
 Initialize_Pins();
 warmup();
 after_warm_up():
}
void loop()
{
  if((L>R)&&(abs(L-R)>=3))
  {
    d=(6+ld-2)%6;
  }
  if((L<R)&&(abs(L-R)>=3))
  {
    d=(6+ld+2)%6;
  }
  dir_coor(d);
  GameOver(x1,y1);
  judgement(x1,x2,x3,randx,t1,y2,y3,radny);
  ld=d;
  for(int t=0;t<=v;t++)
  {
    lightone(x1,y1,time_one);
    lightone(x2,y2,time_one);
    lightone(x3,y3,time_one);
    lightone(randx,randy,time_one);
  }
  if (digitalRead(sleep_switch) == LOW)
  {
     Fall_Asleep();
  }
}

