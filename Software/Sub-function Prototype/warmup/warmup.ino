void warm up(void)
{
  x1=1;
  y1=5;
  for(int i=1;i<=4;i++)
  {
    x1=x1+1;
    y1=y1+1;
    lightone(x1,y1,time_one);
  }
  for(int i=1;i<=4;i++)
  {
    x1=x1+1;
    lightone(x1,y1,time_one);
  }
  for(int i=1;i<=4;i++)
  {
    y1=y1-1;
    lightone(x1,y1,time_one);
  }
  for(int i=1;i<=4;i++)
  {
    x1=x1-1;
    y1=y1-1;
    lightone(x1,y1,time_one);
  }
  for(int i=1;i<=4;i++)
  {
    y1=y1+1;
    lightone(x1,y1,time_one);
  }
}
