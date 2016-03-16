void lightone(int x, int y,int time) //light up one LED in very little duration to deceive th eyes
{
  int pinx,piny;
  if(x!=y)
  {
    pinx=codtopin(x);piny=codtopin(y);
    digitalWrite(pinx,HIGH);
    digitalWrite(piny,LOW);
    delay(time);
    digitalWrite(pinx,LOW);
  }
  else
  {
    if(x<=4)
    {
      pinx=codtopin(x);
      digitalWrite(pinx,HIGH);
      digitalWrite(P_9,LOW);
      delay(time);
      digitalWrite(pinx,LOW);
    }
    else if(x==5)
    {
      digitalWrite(P_7,HIGH);
      digitalWrite(P_2,LOW);
      delay(time);
      digitalWrite(P_7,LOW);
    }
    else
    {
      pinx=codtopin(x);
      digitalWrite(pinx,HIGH);
      digitalWrite(P_1,LOW);
      delay(time);
      digitalWrite(pinx,LOW);        
    }
  }     
}
