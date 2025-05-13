#include <8051.h>
void msec (int x) 
{ 
int i;
for(i=0; i<20*x; i++){
	TH0 = 0;
	TL0 = 0;
	TR0 = 1;
	while (TH0<195);
	TR0 = 0;
	TF0 = 0;	
}
}
void main() 
{
int i;
const unsigned char array[6];
const unsigned char queue[5];
TMOD=0x1; 
array[0]=0b00000010; 
array[1] = 0b00000100; 
array[2]= 0b00100000;
array[3] = 0b01000000;
array[4] = 0b10000001;
array[5] = 0b00011000;

queue[0]= 1.5; 
queue[1] = 1.5; 
queue[2]= 2.5;
queue[3] = 2.5;
queue[4]= 5;

for(i=0;i<6;i++) 
{
P1=array[i];
msec(queue[i]); 
}
P1 = 0;
while(1);
}