void judgement(void)
{while((x1==randx)&&(y1==randy))
 {
   srand((unsigned)time(NULL));
   randx=rand()%8+1;
   randy=tand()%8+1;
  while(((randx==x1)&&(randy==y1))||((randx==x2)&&(randy==y2))||((randx==x3)&&(randy==y3)))
  {
    srand((unsigned)time(NULL));
    randx=rand()%8+1;
    randy=rand()%8+1;
  }
 }
 v=v-1;

}
