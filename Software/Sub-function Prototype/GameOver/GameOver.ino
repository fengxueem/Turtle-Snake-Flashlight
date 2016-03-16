void GameOver(x1,y1)
{
  if(x1<1||x1>9||y1<1||y1>9)
  {
    for(int j=0;j<=2;j++)
       {
         for(int i=0;i<=17;i++)
         {
           lightone(x1,y1,time_one);
           lightone(x2,y2,time_one);
           lightone(x3,y3,time_one);
         }
         delay(500);
       }
  }
  if(((x1==0)&&(y1==4))||((x1==0)&&(y1==5))||((x1==1)&&(y1==6))||((x1==2)&&(y1==7))||((x1==3)&&(y1==8))||((x1==4)&&(y1==9))||((x1==5)&&(y1==10))||((x1==6)&&(y1==9))||((x1==10)&&(y1==6))||((x1==10)&&(y1==5))||((x1==9)&&(y1==4))||((x1==8)&&(y1==3))||((x1==7)&&(y1==2))||((x1==6)&&(y1==1))||((x1==5)&&(y1==0))||((x1==4)&&(y1==0)))
  {
    for(int j=0;j<=2;j++)
       {
         for(int i=0;i<=17;i++)
         {
           lightone(x1,y1,time_one);
           lightone(x2,y2,time_one);
           lightone(x3,y3,time_one);
         }
         delay(500);
       }
  }
}
