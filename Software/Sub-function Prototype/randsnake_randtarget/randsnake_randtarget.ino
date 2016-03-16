void after_warm_up(void)
{srand((unsigned)time(NULL));
 x1=rand()%6+2;
 y1=rand()%6+2:
 d=rand()%6;
 switch(d)
 {case 0:x2=x1+1;y2=y1;x3=x2+1;y3=y2;break;
  case 1:x2=x1;y2=y1-1;x3=x2;y3=y2-1;break;
  case 2:x2=x1-1;y2=y1-1;x3=x2;y3=y2-1;break;
  case 3:x2=x1-1;y2=y1;x3=x1-1;y3=y2+1;break;
  case 4:x2=x1;y2=y1+1;x3=x2;y3=y2+1;break;
  case 5:x2=x1+1;y2=y1+1;x3=x2+1;y3=y2+1;break;
  default:break;
 }
 srand((unsigned)time(NULL));
 randx=rand()%8+1;
 randy=tand()%8+1;
 while(((randx==x1)&&(randy==y1))||((randx==x2)&&(randy==y2))||((randx==x3)&&(randy==y3)))
 {srand((unsigned)time(NULL));
  randx=rand()%8+1;
  randy=rand()%8+1;
 }
 lightfour(x1,x2,x3,randx,y1,y2,y3,randy);
}

