#include <stdio.h>

long long int arr[41];
int cache[41]={0};

/*euclids algorithm*/
long long int gcd(long long int a,long long int b){
  if(a<b){
    a = a + b;
    b = a - b;
    a = a - b;
  }

  if(a%b>0){
    return gcd(b,a%b);
  }

  return b;
}

long long int lcm(long long int a,long long int b){
  return a*b/gcd(a,b);
}

int main(/* arguments */) {
  long long int n,t,i;
  long long int ans;
  scanf("%lld",&t);
  while (t-->0) {
    scanf("%lld",&n);
    ans=1;
    
    for ( i = 2; i <= n; i++) {
      if(cache[i]!=0){
        ans=arr[i];
        continue;
      }
      arr[i]=lcm(ans,i);
      cache[i]=1;
      ans=arr[i];
    }
    printf("%lld\n",ans);
  }
  return 0;
}
