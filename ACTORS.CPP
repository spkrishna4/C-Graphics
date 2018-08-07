#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#define round(a) ((int)(a+0.5))
int gd=DETECT,gm;
void circleMidpoint (int, int, int);
void circlePlotPoints (int, int, int, int);
void main()
{
int i=0,steps=0;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setcolor(10);
while(i<500){
cleardevice();
line(0,220,1000,220);
//circleMidpoint(100+i,100,20);
circle(100+i,100,20);
line(100+i,150,100+i,200);
line(100+i,150,80+i,150);
line(100+i,150,120+i,150);
line(100+i,150,100+i,120);
if(steps%2==0){
line(100+i,200,80+i,220);//lleg
line(100+i,200,120+i,220);  //rleg
}
else{
line(100+i,200,80+i,200);
line(100+i,200,120+i,200);
}i=i+10;
steps++;
delay(500);
}
getch();
closegraph();
}
void circleMidpoint(int xCenter, int yCenter, int radius)
{
int x = 0, y = radius, p = 1 - radius;
circlePlotPoints (xCenter, yCenter, x, y);
while (x < y)
{
x++;
if(p < 0)
p += 2 * x + 1;
else
{
y--;
p += 2 * (x - y) + 1;
}
circlePlotPoints (xCenter, yCenter, x, y);
}
getch();
}
void circlePlotPoints (int xCenter, int yCenter, int x, int y)
{
putpixel (xCenter + x, yCenter + y, 10);
putpixel (xCenter - x, yCenter + y, 10);
putpixel (xCenter + x, yCenter - y, 10);
putpixel (xCenter - x, yCenter - y, 10);
putpixel (xCenter + y, yCenter + x, 10);
putpixel (xCenter - y, yCenter + x, 10);
putpixel (xCenter + y, yCenter - x, 10);
putpixel (xCenter - y, yCenter - x, 10);
}