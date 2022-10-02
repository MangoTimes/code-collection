#include <stdio.h>
#include <math.h>

int prime(int n){
  int i;
  if(n%2==0)return 0;
  for (i = 3; i <= sqrt(n); i+=2) {
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}


int main(int argc, char const *argv[]) {
  int t;
  long int n,i,root,factor;

  scanf("%d",&t);

  while (t-->0) {
    scanf("%ld",&n);
    root=sqrt(n);
    factor=n;

    if(n==0 || n==1){printf("%ld\n",n);continue;}

    while (n%2==0) {
      n/=2;
      factor=n;
    }
    if(n==1){printf("2\n");continue;}

    if(!prime(n))
    for (i = 3; i <= sqrt(n); i+=2){
      if(n%i==0){
          factor=i;
          n/=i;
      }
    }

    printf("%ld\n",factor);

  }



  return 0;
}
