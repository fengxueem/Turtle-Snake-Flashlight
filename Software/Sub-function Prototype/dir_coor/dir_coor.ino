void dir_coor(void)
{switch(d)
 {case 0:x3=x2;y3=y2;x2=x1;y2=y1;x1=x1-1;y1=y1;break;
  case 1:x3=x2;y3=y2;x2=x1;y2=y1;x1=x1;y1=y1+1;break;
  case 2:x3=x2;y3=y2;x2=x1;y2=y1;x1=x1+1;y1=y1+1;break;
  case 3:x3=x2;y3=y2;x2=x1;y2=y1;x1=x1+1;y1=y1;break;
  case 4:x3=x2;y3=y2;x2=x1;y2=y1;x1=x1;y1=y1-1;break;
  case 5:x3=x2;y3=y2;x2=x1;y2=y1;x1=x1-1;y1=y1-1;break;
  default:break;
 }
}
