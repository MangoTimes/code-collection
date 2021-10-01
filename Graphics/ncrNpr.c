#include <stdio.h>

int fact(int n){
  if(n<=1)return 1;

  return n*fact(n-1);
}

int combination(int n,int r){
  return fact(n)/(fact(r)*fact(n-r));
}

int permutation(int n,int r){
  return fact(n)/fact(n-r);
}

void main(){
  int t,n,r;
  printf("Enter N and R\n");
  scanf("%d%d",&n,&r);
  printf("NpR = %d\n",permutation(n,r));
  printf("NcR = %d\n",combination(n,r));
  scanf("%d",&t);
}
