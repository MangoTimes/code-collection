#include <stdio.h>


int main(int argc, char const *argv[]) {
  int t,d=0;
  long int n,sum=0,fib[2],h=1;
  fib[0]=1;
  fib[1]=2;
  scanf("%d",&t);
  while(t-- >0){
    scanf("%ld",&n);
    while (fib[0]<=n && fib[1]<=n) {
      if(fib[1]%2==0){
        sum+=fib[1];
      }

      h=fib[0];
      fib[0]=fib[1];
      fib[1]+=h;


    }
    printf("%ld\n",sum);
    sum=0;
    d=0;
fib[0]=1;
fib[1]=2;
  }
  return 0;
}
