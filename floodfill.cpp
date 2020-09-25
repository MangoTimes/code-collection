#include<graphics.h>
#include<math.h>

void fourFlood(int x,int y,int replaceColor,int newColor){
    if(getpixel(x,y)!=replaceColor) return;
    putpixel(x,y,newColor);

    fourFlood(x,y+1,replaceColor,newColor);
    fourFlood(x,y-1,replaceColor,newColor);
    fourFlood(x+1,y,replaceColor,newColor);
    fourFlood(x-1,y,replaceColor,newColor);
}


int main(){
    initwindow(800,800);
    const float R = 120;
    const float Xc = 300;
    const float Yc = 300;
    const int d = abs(Xc-Yc);
    const int WHITE=BLUE;
    putpixel(Xc,Yc-R,WHITE);
    putpixel(Xc,Yc+R,WHITE);
    putpixel(Yc-R+d,Xc-d,WHITE);
    putpixel(Yc+R+d,Xc-d,WHITE);
    int xk = 0;
    int yk = R;
    float p0 = 5/4.0 - R;
    while(yk>=xk){
        if(p0 < 0){
            int finalPointX = Xc+(++xk);
            int finalPointY = Yc+yk;
            putpixel(finalPointX,finalPointY,WHITE);
            putpixel(Xc-xk,Yc-yk,WHITE);
            putpixel(Xc-xk,Yc+yk,WHITE);
            putpixel(Xc+xk,Yc-yk,WHITE);
            //reverse symmetry
            if(Yc<Xc){
            putpixel(Yc-yk+d,Xc+xk-d,WHITE);
            putpixel(Yc+yk+d,Xc+xk-d,WHITE);
            putpixel(Yc-yk+d,Xc-xk-d,WHITE);
            putpixel(Yc+yk+d,Xc-xk-d,WHITE);
            }
            else if(Yc>Xc){
            putpixel(Yc-yk-d,Xc+xk+d,WHITE);
            putpixel(Yc+yk-d,Xc+xk+d,WHITE);
            putpixel(Yc-yk-d,Xc-xk+d,WHITE);
            putpixel(Yc+yk-d,Xc-xk+d,WHITE);
            }
            else {
            putpixel(Yc-yk,Xc+xk,WHITE);
            putpixel(Yc+yk,Xc+xk,WHITE);
            putpixel(Yc-yk,Xc-xk,WHITE);
            putpixel(Yc+yk,Xc-xk,WHITE);
            }
            p0 += 2*xk + 1;
        }
        else {
            int finalPointX = Xc+(++xk);
            int finalPointY = Yc+(--yk);
            putpixel(finalPointX,finalPointY,WHITE);
            putpixel(Xc-xk,Yc-yk,WHITE);
            putpixel(Xc-xk,Yc+yk,WHITE);
            putpixel(Xc+xk,Yc-yk,WHITE);
            //reverse
            if(Yc<Xc){

            putpixel(Yc-yk+d,Xc+xk-d,WHITE);
            putpixel(Yc+yk+d,Xc+xk-d,WHITE);
            putpixel(Yc-yk+d,Xc-xk-d,WHITE);
            putpixel(Yc+yk+d,Xc-xk-d,WHITE);
            }
            else if(Yc>Xc){
            putpixel(Yc-yk-d,Xc+xk+d,WHITE);
            putpixel(Yc+yk-d,Xc+xk+d,WHITE);
            putpixel(Yc-yk-d,Xc-xk+d,WHITE);
            putpixel(Yc+yk-d,Xc-xk,WHITE);
            }
            else {
            putpixel(Yc-yk,Xc+xk,WHITE);
            putpixel(Yc+yk,Xc+xk,WHITE);
            putpixel(Yc-yk,Xc-xk,WHITE);
            putpixel(Yc+yk,Xc-xk,WHITE);
            }
            p0 += 2*xk+1-2*yk;
        }
    }

    fourFlood(350,300,getpixel(350,300),GREEN);

    getch();
    return 0;
}
