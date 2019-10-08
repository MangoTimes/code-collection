#include<graphics.h>
#include<math.h>


int main(){
    initwindow(600,600);
    float x0 = 200;
    float y0 = 50;
    float x1 = 20;
    float y1 = 20;

    float dy = abs(y1-y0);
    float dx = abs(x1-x0);
    float slope = abs(dy/dx);

    //for m<=1
    if(x0<=x1){ // Left to right scanning
        if(slope<=1){ // m <= 1
            float p0 = 2*dy - dx;
            putpixel(x0,y0,WHITE);

            for(int i=0;i<=dx;i++){
                if(p0<0){
                    putpixel(++x0,y0,WHITE);
                    p0 += 2*dy;
                }
                else{
                    putpixel(++x0,++y0,WHITE);
                    p0 += 2*dy-2*dx;
                }
            }
        }else { //m > 1
            float p0 = 2*dx - dy;
            putpixel(x0,y0,WHITE);
            for(int i=0;i<=dy;i++){
                if(p0<0){
                    putpixel(x0,++y0,WHITE);
                    p0 += 2*dx;
                }
                else {
                    putpixel(++x0,++y0,WHITE);
                    p0 += 2*dx - 2*dy;
                }
            }
        }
    }
    else { // right to left scanning
        if(slope<=1){ // m <= 1
            float p0 = 2*dy - dx;
            putpixel(x0,y0,WHITE);

            for(int i=0;i<=dx;i++){
                if(p0<0){
                    putpixel(--x0,y0,WHITE);
                    p0 += 2*dy;
                }
                else{
                    putpixel(--x0,--y0,WHITE);
                    p0 += 2*dy-2*dx;
                }
            }
        }else { //m > 1
            float p0 = 2*dx - dy;
            putpixel(x0,y0,WHITE);
            for(int i=0;i<=dy;i++){
                if(p0<0){
                    putpixel(x0,--y0,WHITE);
                    p0 += 2*dx;
                }
                else {
                    putpixel(--x0,--y0,WHITE);
                    p0 += 2*dx - 2*dy;
                }
            }
        }
    }

    getch();
	return 0;
}
