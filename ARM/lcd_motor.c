#include<lpc214x.h>
void data(char a)
{
int k;
IO0SET=1<<1;
IO0CLR=0xff<<3;
IO0SET=a<<3;
IO0SET=1<<2;
for(k=0;k<=1000;k++);
IO0CLR=1<<2;	
}
void cmd(char a)
{
int k;
IO0CLR=1<<1;
IO0CLR=0xff<<3;
IO0SET=a<<3;
IO0SET=1<<2;
for(k=0;k<=1000;k++);
IO0CLR=1<<2;	
}
void display(const char *p)
{
while(*p)
{
data(*p++);
}
}

void main()
{
int i=0;
int k;
PINSEL0=0;
PINSEL1=0;
IO0DIR=~(1);
cmd(0x01);
cmd(0x06);
cmd(0x0c);
cmd(0x38);
while(1)
{
if(IO0PIN&(1)==1)
  {
  for(k=0;k<=10000;k++);
  while(IO0PIN&(1)==1);
  i++;
  if(i%3==0)
  {
  IO0SET=1<<11;
  IO0CLR=1<<12;
  cmd(0xc0);
  display("Clockwise            ");
  }
  else if(i%3==1)
  {
  IO0CLR=1<<11;
  IO0SET=1<<12;
  display("Motor");
  cmd(0xc0);
  display("AntiClockwise                  ");
  }
  else
  {
  IO0CLR=3<<11;
  cmd(0xc0);
  display("Stop                     ");
  }
  }
  }
  }
  