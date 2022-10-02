#include <stdio.h>

unsigned long long int pow1(unsigned long long int a,int n){
  if(n==1)
    return a;
  return a*pow1(a,--n);
}
int main() {
  int t;
  int n;
  unsigned long long int a1;
  unsigned long long int a2;
  scanf("%d",&t);
  while (t-->0) {
    scanf("%d",&n);
    a1=(unsigned long long int)((unsigned long long int)n*(n+1)*(2*n+1)/6);
    a2=(unsigned long long int)pow1((unsigned long long int)(n*(n+1)/2),2);
    printf("%lld\n",a2-a1);
  }
  return 0;
}
