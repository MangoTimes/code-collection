#include <stdio.h>
#include <stdlib.h>

const int SIZE=100000;


void populateArray(int arr[SIZE]){
  int i;
  for (i = 0; i < SIZE; i++) {
    arr[i]=rand()%SIZE;
  }
}

void searchRegular(int arr[SIZE],int n){
  int i;
  for (i = 0; i < SIZE; i++) {
    if(arr[i]==n){
      printf("With regular search it took %d checks and the answer is %d\n",i,arr[i]);
      break;
    }
  }
}

void searchRandom(int arr[SIZE],int n){
  int i,index=0,rn=rand()%SIZE,flag=0;
  for (i = rn; i < SIZE; i++) {
    index++;
    if(arr[i]==n){
      flag=1;
      printf("With random INCREASING search it took %d checks and the answer is %d\n",index,arr[i]);
      break;
    }
  }
  if(!flag){
    for (i = 0; i <= rn; i++) {
      if(arr[i]==n){
        printf("With random DECREASING search it took %d checks and the answer is %d\n",i+(SIZE-rn),arr[i]);
      }
    }
  }
}


void searchEvenOdd(int arr[SIZE],int n){
  int i,flag=0;
  for (i = 0; i < SIZE; i+=2) {
    if(arr[i]==n){
      printf("with even search it took %d checks and the answer is %d\n",i/2,arr[i]);
      flag=1;
      break;
    }
  }
  if(flag==0){
    for (i = 1; i < SIZE; i+=2) {
      if(arr[i]==n){
        printf("with odd search it took %d checks and the answer is %d\n",(SIZE+i)/2,arr[i]);
      }
    }
  }
}

void firstLastSearch(int arr[SIZE],int n){
  int i;

  for (i = 0; i < SIZE/2; i++) {
    if(arr[i]==n||arr[SIZE-i]==n){
      printf("with first last search it took %d checks and the answer is %d\n",i*2,n);
      break;
    }
  }
}

void SelectionSort(int arr[SIZE]){
  int i,j,temp,min=999999,index;
  for (i = 0; i < SIZE; i++) {
    for (j = i; j < SIZE; j++) {
      if(arr[j]<min){
        min=arr[j];
        index=j;
      }
    }
    temp=arr[i];
    arr[i]=arr[index];
    arr[index]=temp;
    index=0;
    min=999999;
  }

}

void binarySearch(int arr[SIZE],int n){
  int i,s=0,e=SIZE,checks=0;
  int half;
  for (i = 0; i < SIZE/2; i++) {
    half=(e+s)/2;
    checks++;
    if(arr[half]==n){
      printf("With binarySearch it took %d checks and the answer is %d",checks,n);
      break;
    }
    if(arr[half]<n)s=half;
    else e=half;
  }
}

void main(){
  int arr[SIZE],n;
  populateArray(arr);
  printf("Enter the element to search\n");
  scanf("%d",&n);

  searchRegular(arr,n);
  searchRandom(arr,n);
  searchEvenOdd(arr,n);
  firstLastSearch(arr,n);


  SelectionSort(arr);
  binarySearch(arr,n);

}
