#include <8051.h>


char read(){
int str = -1; 
int stl = -1;
P0 = 0;
P2 = 0b11111111;

if(P20 == 0)
stl = 1;
if(P21 == 0)
stl = 2;
if(P22 == 0)
stl = 3;
if(P23 == 0)
stl = 4;

P2 = 0;
P0 = 0b11111111;

if(P00 == 0)
str = 1;
if(P01 == 0)
str = 2;
if(P02 == 0)
str = 3;
if(P03 == 0)
str = 4;

if(stl == 1){
	if(str == 1) return '1';
	if(str == 2) return '4';
	if(str == 3) return '7';
	if(str == 4) return '*';
	}
if(stl == 2){
	if(str == 1) return '2';
	if(str == 2) return '5';
	if(str == 3) return '8';
	if(str == 4) return '0';
	}
if(stl == 3){
	if(str == 1) return '3';
	if(str == 2) return '6';
	if(str == 3) return '9';
	if(str == 4) return '#';
}
if(stl == 4){
	if(str == 1) return 'A';
	if(str == 2) return 'B';
	if(str == 3) return 'C';
	if(str == 4) return 'D';
}
return ' ';
}
void  write (char w){
P32 = 0; // RW
P31 = 1; //RS
P1 = w; //Data

P30 = 1; //E
P30 = 0; //E
}
void  display (char w){
P32 = 0; // RW
P31 = 0; //RS
P1 = w; //Data

P30 = 1; //E
P30 = 0; //E
}
void main()
{int i;
char b;
while(1){
b = read ();
	if(b != ' '){
	write (b);
	for(i = 0; i<200; i++);
	}

}
}

