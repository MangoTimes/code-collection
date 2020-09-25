#include<graphics.h>

main(){
	initwindow(800,800);

for(int i=1;i<1200;i=i+10){
	cleardevice();
		setcolor(RED);
	line(120+i,200,180+i,90);
	line(180+i,90,340+i,90);
	line(340+i,90,400+i,200);
	setcolor(BLUE);
	rectangle(90+i,200,430+i,300);
	setcolor(GREEN);
	circle(150+i,280,60);
	circle(350+i,280,60);
delay(100);}
	
	
	
	getch();
}
