void Initialize_Pins(void) 
{
  pinMode(P_1,OUTPUT);//charlieplexing output pins,from 1 to 9
  pinMode(P_2,OUTPUT);
  pinMode(P_3,OUTPUT);
  pinMode(P_4,OUTPUT);
  pinMode(P_5,OUTPUT);
  pinMode(P_6,OUTPUT);
  pinMode(P_7,OUTPUT);
  pinMode(P_8,OUTPUT);
  pinMode(P_9,OUTPUT);
  pinMode(P_flash,OUTPUT);//flashlight transistor pin
  pinMode(P_sleep,INPUT_PULLUP);//P1.3
  pinMode(P_flaswch,INPUT_PULLUP);//P2.0
  pinMode(P_L,INPUT_PULLUP);//P1.2
  pinMode(P_R,INPUT_PULLUP);//P1.1
  P1IE |= BIT1;//enable interrupt by change in voltage at pin P1.1, P1.2 and P2.0
  P1IE |= BIT2;  
  P2IE |= BIT0;
  P1IES |= BIT1;//trigger interrupt at HIGH to LOW transition in P1.1, P1.2 and P2.0
  P1IES |= BIT2; 
  P2IES |= BIT0;            
  P1IFG &= ~BIT1;//clear interrupt flage IFG corresponding to pin P1.1, P1.2 and P2.0
  P1IFG &= ~BIT2;
  P2IFG &= ~BIT0;
} 

