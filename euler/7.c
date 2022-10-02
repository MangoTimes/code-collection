#include <stdio.h>
#include <stdlib.h>
void main() {
  int n,i,k,j,t;
  int *arr;
  arr=(int*)malloc(10000*sizeof(int));

  for (i = 0; i < n; i++) {
    arr[i]=2+i;
  }

  for (i = 0; i < n; i++) {
    if(arr[i]==-1)continue;
    k=arr[i];
    for (j = i+k; j < n; j+=k) {
      arr[j]=-1;
    }
  }

  for (i = 0; i < n; i++) {
    if(arr[i]==-1)continue;
    printf("%d ",arr[i]);
  }

  scanf("%d",&t);
  while (n) {
    /* code */
  }

  free(arr);
}
