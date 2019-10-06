#include <stdio.h>

void main(){
  int high=0,high2=0;
  int i,num,n;

  printf("How many numbers do you want to enter?\n");
  scanf("%d",&num);
  for (i = 0; i < num; i++) {
    scanf("%d",&n);
    if(n>high){
      high2=high;
      high=n;
    }
  }
  printf("%d and %d are the highest numbers.\n",high,high2);
  scanf("%d",&i);
}
