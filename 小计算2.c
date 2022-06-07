#include<stdio.h>
void main( )
{
  int a=0,b=0,c=0;
  if(++a>0||++b>0)  
  ++c;
  printf(“\na=%d,b=%d,c=%d”,a,b,c);
}
