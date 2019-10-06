#include <stdio.h>


void caseA(int height,int width){
    int n=width/2,i,j;
    for(i=0;i<height;i++){
        for(j=0;j<=width;j++){
            if(j==n || j==(width-n) || (i==height/2 && j>n && j<(width-n)) )
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
        n--;
    }
}

void caseB(int height,int width){
    int i,j,half=(height/2);
    for(i=0;i<height;i++){
       printf("*");
        for(j=0;j<width;j++){
            if((i==0 || i==height-1 || i==half)&& j<(width-2))printf("*");
            else if(j==(width-2) && !(i==0 || i==height-1 || i==half))printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}

void caseC(int height,int width) {
    int i,j;
    for (i = 0; i < height; i++) {
      printf("*");
      for (j = 0; j < (height-1); j++) {
        if(i==0 || i==height-1)printf("*");
        else continue;
      }
      printf("\n");
    }
}


void caseD(int height,int width){
  int i,j;
  for (i = 0; i < height; i++) {
    printf("*");
    for (j = 0; j < height; j++) {
      if((i==0||i==height-1)&& j<height-1)printf("*");
      else if(j==height-1 && i!=0 && i!=height-1)printf("*");
      else printf(" ");
    }
    printf("\n");
  }
}


void caseE(int height){
  int i,j;
  for (i = 0; i < height; i++) {
    printf("*");
    for (j = 0; j < height; j++) {
      if((i==0||i==height-1) || (i==height/2 && j<=height/2 ))printf("*");
      else continue;
    }
    printf("\n");
  }
}


void caseF(int height){
  int i,j;
  for (i = 0; i < height; i++) {
    printf("*");
    for (j = 0; j < height; j++) {
      if((i==0) || (i==height/2 && j<=height/2 ))printf("*");
      else continue;
    }
    printf("\n");
  }
}


void caseG(int height,int width){
  int i,j;
  width--;
  for (i = 0; i < height; i++) {
    for ( j = 0; j < width; j++) {
      if((i==0||i==height-1)&&(j==0||j==width-1))printf(" ");
      else if(j==0)printf("*");
      else if(i==0&&j<=height)printf("*");
      else if(i==height/2&& j>height/2)printf("*");
      else if(i>height/2&&j==width-1)printf("*");
      else if(i==height-1&&j<width)printf("*");
      else printf(" ");
    }
    printf("\n");
  }
}


void caseH(int height){
  int i,j;
  for (i = 0; i < height; i++) {
    printf("*");
    for (j = 0; j < height; j++) {
      if((j==height-1)|| (i==height/2))printf("*");
      else printf(" ");
    }
    printf("\n");
  }
}


void caseI(int height){
  int i,j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < height; j++) {
      if(i==0||i==height-1)printf("*");
      else if(j==height/2)printf("*");
      else printf(" ");
    }
    printf("\n");
  }
}

void caseJ(int height){
  int i,j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < height; j++) {
      if(i==height-1&&(j>0&&j<height-1))printf("*");
      else if((j==height-1&&i!=height-1) || (i>(height/2)-1&&j==0&&i!=height-1))printf("*");
      else printf(" ");
    }
    printf("\n");
  }
}


int abs(int d){
  return d<0?-1*d:d;
}

void caseK(int height){
  int i,j,half=height/2,dummy=half;
  for (i = 0; i < height; i++) {
    printf("*");
    for (j = 0; j <= half; j++) {
      if(j==abs(dummy))printf("*");
      else printf(" ");
    }
    printf("\n");
    dummy--;
  }
}

void caseL(int height){
  int i,j;
  for (i = 0; i < height; i++) {
    printf("*");
    for (j = 0; j <= height; j++) {
      if(i==height-1)printf("*");
      else printf(" ");
    }
    printf("\n");
  }
}


void caseM(int height){
  int i,j,counter=0;
  for (i = 0; i < height; i++) {
    printf("*");
    for (j = 0; j <= height; j++) {
      if(j==height)printf("*");
      else if(j==counter||j==height-counter-1)printf("*");
      else printf(" ");
    }
    if(counter==height/2){
      counter=-99999;
    }
    else counter++;
    printf("\n");
  }
}


void caseN(int height){
  int i,j,counter=0;
  for (i = 0; i < height; i++) {
    printf("*");
    for (j = 0; j <= height; j++) {
      if(j==height)printf("*");
      else if(j==counter)printf("*");
      else printf(" ");
    }
    counter++;
    printf("\n");
  }
}


void caseO(int height){
  int i,j,space=(height/3);
  int width=height/2+height/5 +space +space;
  for (i = 0; i < height; i++) {
    for (j = 0; j <= width; j++) {
      if(j==width-abs(space) || j==abs(space))printf("*");
      else if((i==0||i==height-1) &&j>abs(space)&&j<width-abs(space) )printf("*");
      else printf(" ");
    }
    if(space!=0&&i<height/2){space--;}
    else if(i>=(height/2+height/5))space--;
    printf("\n");
  }
}


void caseP(int height){
  int i,j;
  for (i = 0; i < height; i++) {
    printf("*");
    for (j = 0; j < height; j++) {
      if((i==0||i==height/2) && j<height-1)printf("*");
      else if(i<height/2&&j==height-1 && i!=0)printf("*");
      else printf(" ");
    }
    printf("\n");
  }
}


void caseQ(int height){
  caseO(height);
  int i,j,d=height;
  for (i = 0; i < height/2; i++) {
    for ( j = 0; j <= d; j++) {
      if(j==d)printf("*");
      else printf(" ");
    }
    printf("\n");
    d++;
  }
}


void caseR(int height,int width){
  int i,j,half=(height/2);
  for(i=0;i<height;i++){
     printf("*");
      for(j=0;j<width;j++){
          if((i==0 || i==half)&& j<(width-2))printf("*");
          else if(j==(width-2) && !(i==0 || i==half))printf("*");
          else printf(" ");
      }
      printf("\n");
  }
}


void caseS(int height){
  int i,j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < height; j++) {
      if((i==0||i==height/2||i==height-1))printf("*");
      else if(i<height/2&&j==0)printf("*");
      else if(i>height/2&&j==height-1)printf("*");
      else printf(" ");
    }
    printf("\n");
  }
}


void caseT(int height){
  int i,j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < height; j++) {
      if(i==0)printf("*");
      else if(j==height/2)printf("*");
      else printf(" ");
    }
    printf("\n");
  }
}


void caseU(int height){
  int i,j;
  for (i = 0; i < height; i++) {
    if(i!=0&&i!=height-1)printf("*");
    else printf(" ");
    for (j = 0; j < height; j++) {
      if(((i==height-1)&&j>=0&&j<height-1))printf("*");
      else if(j==height-1 && i!=0 && i!=height-1)printf("*");
      else printf(" ");
    }
    printf("\n");
  }
}


void caseV(int height,int width){
  int i,j,counter=0;
  for (i = 0; i < height; i++) {
    for (j = 0; j <= width; j++) {
      if(j==counter || j== width-counter-1)printf("*");
      else printf(" ");
    }
    counter++;
    printf("\n");
  }
}

void caseW(int height){
  int i,j,counter=height/2;
  for (i = 0; i < height; i++) {
    printf("*");
    for (j = 0; j <= height; j++) {
      if(j==height)printf("*");
      else if((i>=height/2)&&(j==counter||j==height-counter-1))printf("*");
      else printf(" ");
    }
    if(i>=height/2){
      counter++;
    }
    printf("\n");
  }
}


void caseX(int height){
  int i,j,counter=0;
  for (i = 0; i <= height; i++) {
    for (j = 0; j <= height; j++) {
      if(j==counter||j==height-counter)printf("*");
      else printf(" ");
    }
    counter++;
    printf("\n");
  }
}


void caseY(int height){
  int i,j,counter=0;
  for (i = 0; i < height; i++) {
    for (j = 0; j <= height; j++) {
      if(j==counter||j==height-counter && i<=height/2)printf("*");
      else printf(" ");
    }
    printf("\n");
    if(i<height/2)
      counter++;
  }
}

void caseZ(int height){
  int i,j,counter=height-1;
  for (i = 0; i < height; i++) {
    for (j = 0; j < height; j++) {
      if(i==0||i==height-1||j==counter)printf("*");
      else printf(" ");
    }
    counter--;
    printf("\n");
  }
}


void main()
{
    char character;
    int height,width,stopper;
    printf("Enter a character to be printed\n");
    scanf(" %c",&character);
    printf("Enter the height of the grid\n");
    scanf("%d",&height);
    //  I/O ends.
    width=(2*height)-1;
    switch(character){
        case 'A':caseA(height,width);break;
        case 'B':caseB(height,width);break;
        case 'C':caseC(height,width);break;
        case 'D':caseD(height,width);break;
        case 'E':caseE(height);break;
        case 'F':caseF(height);break;
        case 'G':caseG(height,width);break;
        case 'H':caseH(height);break;
        case 'I':caseI(height);break;
        case 'J':caseJ(height);break;
        case 'K':caseK(height);break;
        case 'L':caseL(height);break;
        case 'M':caseM(height);break;
        case 'N':caseN(height);break;
        case 'O':caseO(height);break;
        case 'P':caseP(height);break;
        case 'Q':caseQ(height);break;
        case 'R':caseR(height,width);break;
        case 'S':caseS(height);break;
        case 'T':caseT(height);break;
        case 'U':caseU(height);break;
        case 'V':caseV(height,width);break;
        case 'W':caseW(height);break;
        case 'X':caseX(height);break;
        case 'Y':caseY(height);break;
        case 'Z':caseZ(height);break;
    }

}
