#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)  
{
  if(P1IFG==0x02)//right button is pressed,P1.1,controlling LED
  {
    turn(right);R++;
  }
  else if(P1IFG==0x04)//left button is pressed,P1.2,controlling fLED
  {
    turn(left);L++;
  }
  else if(P1IFG==0x08)//sleep button is pressed,P1.3
  {
    __bic_SR_register_on_exit(LPM4_bits+GIE); // Resume execution in Active Mode
  }
  P1IFG &= 0x00;
}
#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)  
{
  if(f_flag==0) {digitalWrite(P_flash,HIGH);f_flag=1;}
  else {digitalWrite(P_flash,LOW);f_flag=0;}
  P2IFG &= ~BIT0; 
}
