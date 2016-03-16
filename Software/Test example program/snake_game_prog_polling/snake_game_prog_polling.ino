#define P_L 8//the pin number of left button
#define P_R 3//the pin number of right button
#define P_1 2//the pin number of 1 charlie pin
#define P_2 6//the pin number of 2 charlie pin
#define P_3 7//the pin number of 3 charlie pin
#define P_4 9//the pin number of 4 charlie pin
#define P_5 10//the pin number of 5 charlie pin
#define P_6 14//the pin number of 6 charlie pin
#define P_7 13//the pin number of 7 charlie pin
#define P_8 12//the pin number of 8 charlie pin
#define P_9 11//the pin number of 9 charlie pin
#define time_one 3//time duration of one LED being lightened
#define time_warmup 150
#define begin_level 90
#define left (-1)// turn left	
#define right (1)// turn right

#define NOT_PUSHED true
#define WATCH_BUTTON true
#define IGNORE_BUTTON false
const long buttonWaitInterval = 200000;
unsigned long previousMicros = 0;
boolean bounceState = false;

unsigned int v;//speed of the snake
unsigned int ld;//L and R record the number of how many times the left and right buttons are pressed. 
                      //d is the next direction of snake,ld is the last direction snake went from.
unsigned int x_1,x_2,x_3,randx,y_1,y_2,y_3,randy;
unsigned int f_flag=0;
volatile unsigned int d,L=0,R=0;
boolean lf,rf;
void setup()
{
 Initialize_Pins();
 warmup();
 randsnake();
 randtarget();
 ld=d;
 lf=leftbutton();
 rf=rightbutton();
 while((lf==0)&&(rf==0))//display the snake and target
  {
      lightone(x_1,y_1,time_one);
      lightone(x_2,y_2,time_one);
      lightone(x_3,y_3,time_one);
      lightone(randx,randy,time_one);
      lf=leftbutton();
      rf=rightbutton();
  }
}
void loop()
{
  if(abs(L-R)>=3)//update new direction
  {
    if(L>R)   d=(6+ld-2)%6;
    else        d=(6+ld+2)%6;
  }
  L=0;R=0;ld=d;
  dir_coor();//update coordinates according the new direction
  GameOver();//determine whether it hits a wall or not
  for(int t=0;t<=v;t++)//display the snake
  {
    lf=leftbutton();
    rf=rightbutton();
    lightone(x_1,y_1,time_one);
    lightone(x_2,y_2,time_one);
    lightone(x_3,y_3,time_one);
    lightone(randx,randy,time_one);
  }
  judgement();//determine whether it gets the target or not
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
  pinMode(P_L,INPUT_PULLUP);//P1.2
  pinMode(P_R,INPUT_PULLUP);//P1.1
  L=0;R=0;v=begin_level;
  srand((unsigned)millis());//update new time seed
}

void turn(int dir)
{
  d=(6+d+dir)%6;
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

void randtarget(void)
{
  do
  {
	  randx=(abs(rand())%9)+1;
	  randy=(abs(rand())%9)+1;
  }while((abs(randx-randy)>=5)||((randx==x_1)&&(randy==y_1))||((randx==x_2)&&(randy==y_2))||((randx==x_3)&&(randy==y_3)));
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

void judgement(void)
{
  if((x_1==randx)&&(y_1==randy))  {randtarget();v=v-(int)sqrt(v);}
}


void GameOver(void)
{
  if((x_1<1)||(x_1>9)||(y_1<1)||(y_1>9)||((x_1==1)&&(y_1==6))||((x_1==2)&&(y_1==7))||((x_1==3)&&(y_1==8))||((x_1==4)&&(y_1==9))||((x_1==9)&&(y_1==4))||((x_1==8)&&(y_1==3))||((x_1==7)&&(y_1==2))||((x_1==6)&&(y_1==1)))
  { //game over
     unsigned  int x_4=0,y_4=0;//recover the last location of tail
     switch(ld)
	  {
	  case 0:x_4=x_3+1;y_4=y_3;break;
	  case 1:x_4=x_3;y_4=y_3-1;break;
	  case 2:x_4=x_3-1;y_4=y_3-1;break;
	  case 3:x_4=x_3-1;y_4=y_3;break;
	  case 4:x_4=x_3;y_4=y_3+1;break;
	  case 5:x_4=x_3+1;y_4=y_3+1;break;
	  }
     for(int j=0;j<=2;j++)
       {
         for(int i=0;i<=17;i++)
         {
           lightone(x_2,y_2,time_one);//head
           lightone(x_3,y_3,time_one);//body
           lightone(x_4,y_4,time_one);//tail
         }
         delay(500);
       }
    detachInterrupt(P_L);
    detachInterrupt(P_R);
    Initialize_Pins();
    warmup();
    randsnake();
    randtarget();
    ld=d;
    lf=leftbutton();
    rf=rightbutton();
    while((lf==0)&&(rf==0))//display the snake and target
    {
        lightone(x_1,y_1,time_one);
        lightone(x_2,y_2,time_one);
        lightone(x_3,y_3,time_one);
        lightone(randx,randy,time_one);
        lf=leftbutton();
        rf=rightbutton();
    }
  }
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
 

bool leftbutton()
{
  if (bounceState == WATCH_BUTTON) 
  {
    if (digitalRead(P_L)==LOW) 
    {
      bounceState = IGNORE_BUTTON;previousMicros = micros();turn(left);L++;return(1);
    }
    else return(0);
  }
  if (bounceState == IGNORE_BUTTON) 
  {
    unsigned long currentMicros = micros();
    if ((unsigned long)(currentMicros - previousMicros) >= buttonWaitInterval) 
    {
      bounceState = WATCH_BUTTON;
    } 
  }
}

bool rightbutton()
{
  if (bounceState == WATCH_BUTTON) 
  {
    if (digitalRead(P_R)==LOW) 
    {
      bounceState = IGNORE_BUTTON;previousMicros = micros();turn(right);R++;return(1);
    }
    else return(0);
  }
  if (bounceState == IGNORE_BUTTON) 
  {
    unsigned long currentMicros = micros();
    if ((unsigned long)(currentMicros - previousMicros) >= buttonWaitInterval) 
    {
      bounceState = WATCH_BUTTON;
    } 
  }
}
