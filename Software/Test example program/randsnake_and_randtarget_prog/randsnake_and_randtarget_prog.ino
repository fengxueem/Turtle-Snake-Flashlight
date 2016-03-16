// continue showing different snake and target pairs
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
#define time_one 3//time duration of one LED being lightened
#define time_warmup 100
#define left (-1)// turn left	
#define right (1)// turn right
const int debounce_delay = 100;// 1/4 sec debouncing delay after sleep switch is closed or opened 
unsigned int v=20;//speed of the snake
unsigned int L=0,R=0,ld;//L and R record the number of how many times the left and right buttons are pressed
unsigned int x_1,x_2,x_3,randx,y_1,y_2,y_3,randy;
unsigned int f_flag=0;
volatile unsigned int d;//d is the current direction of snake,ld is the last direction snake went from.
void setup()
{
  // put your setup code here, to run once:
  Initialize_Pins();
  randsnake();
  randtarget();
}

void loop()
{
  // put your main code here, to run repeatedly:
    for(int i=0;i<=60;i++)
    {
        lightone(x_1,y_1,time_one);
        lightone(x_2,y_2,time_one);
        lightone(x_3,y_3,time_one);
        lightone(randx,randy,time_one);
    }
     randsnake(); randtarget();
}


void warmup(void)
{
  x_1=1;
  y_1=5;
  d=2;
  for(int i=1;i<=25;i++)
  {
    lightone(x_1,y_1,time_warmup);
    dir_coor();
    if(i%4==0) turn(right);
  }
}


void randtarget(void)
{
  do
  {
	  randx=(abs(rand())%9)+1;
	  randy=(abs(rand())%9)+1;
  }while((abs(randx-randy)>=5)||((randx==x_1)&&(randy==y_1))||((randx==x_2)&&(randy==y_2))||((randx==x_3)&&(randy==y_3)));
}

void randsnake(void)
{
  do
  {
	x_1=(abs(rand())%5)+3;
        y_1=(abs(rand())%5)+3;
  }while(abs(x_1-y_1)>=3);//control the area where the snake's head  first shows up into central haxegon with side length equal to 3 leds
  d=abs(rand())%6;
  ld=d;
  switch(ld)
  {
    case 0:x_2=x_1+1;y_2=y_1;x_3=x_2+1;y_3=y_2;break;
    case 1:x_2=x_1;y_2=y_1-1;x_3=x_2;y_3=y_2-1;break;
    case 2:x_2=x_1-1;y_2=y_1-1;x_3=x_2-1;y_3=y_2-1;break;
    case 3:x_2=x_1-1;y_2=y_1;x_3=x_2-1;y_3=y_2;break;
    case 4:x_2=x_1;y_2=y_1+1;x_3=x_2;y_3=y_2+1;break;
    case 5:x_2=x_1+1;y_2=y_1+1;x_3=x_2+1;y_3=y_2+1;break;
  }
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
  pinMode(P_sleep,INPUT_PULLUP);//P1.3
  pinMode(P_flaswch,INPUT_PULLUP);//P2.0
  pinMode(P_L,INPUT_PULLUP);//P1.2
  pinMode(P_R,INPUT_PULLUP);//P1.1
  L=0;R=0;v=20;f_flag=0;
  srand((unsigned)millis());//update new time seed
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

void turn(int dir)
{
  d=(6+d+dir)%6;
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
