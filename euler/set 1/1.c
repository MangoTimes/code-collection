#include <stdio.h>



long sumC(int a,int b,long c){
  long res1= (2*a + (c-1)*b);
  long res2  = c;
  if(res1%2==0){
         res1=res1/2;
     }else{
         res2 = res2/2;
     }

     return res1*res2;
}

int main(){
  long t,num,sum,multOfThree,multOfFive,multOfFifteen;
  t = num = sum = multOfThree = multOfFive = multOfFifteen = 0;
  scanf("%ld",&t);

  while (t-- >0) {
    scanf("%ld",&num);

    num--;
    multOfThree=num/3;
    multOfFifteen=num/15;
    multOfFive=num/5;

    sum=sumC(3,3,multOfThree);
    sum+=sumC(5,5,multOfFive);
    sum-=sumC(15,15,multOfFifteen);

    printf("%ld\n",sum);

    sum=0;
  }
  return 0;
}
