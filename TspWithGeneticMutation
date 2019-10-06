#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int CITIES=5;
const short DEBUG=1;
const short GENERATIONS=100;
const short PARENTS_PER_GENERATION=10;
const short AUTO_FILL_WITH_ONES=0;
const short ENTER_WITHOUT_DUPLICATE=1;

void printArray(int arr[CITIES]){
  int i;
  for (i = 0; i < CITIES; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void main() {

  int adj[CITIES][CITIES];//Dist table
  int parents[GENERATIONS][PARENTS_PER_GENERATION][CITIES];//parents array
  int selectedParents[PARENTS_PER_GENERATION],sum[GENERATIONS],min[GENERATIONS][PARENTS_PER_GENERATION],minI[GENERATIONS];
  short flag=0,rev;
  int loop=-1;
  int rn=0,index=0,startIndex,endIndex,distinct,mutation;
  int stop,i,j,k;


  //scans the adjcency matrix and auto replicates it
  if(!ENTER_WITHOUT_DUPLICATE){
  for (i = 0; i < CITIES; i++) {
    for (j = i; j < CITIES; j++) {
      if(i==j)adj[i][j]=0;
      else{
        if(!AUTO_FILL_WITH_ONES){
        printf("Enter dist b/w %d and %d\n",i,j);
        scanf("%d",&adj[i][j]);
        adj[j][i]=adj[i][j];
        }
        else{
          adj[i][j]=1;
          adj[j][i]=1;
        }
      }
    }
  }
  }else{
      printf("scanning without replicates\n");
      for (i = 0; i < CITIES; i++) {
        for (j = 0; j < CITIES; j++) {
          scanf("%d",&adj[i][j]);
        }
      }
  }
  printf("MATRIX ->\n" );
  for (i = 0; i < CITIES; i++) {
    for (j = 0; j < CITIES; j++) {
      printf("%d ", adj[i][j]);
    }
    printf("\n");
  }

  while (++loop < PARENTS_PER_GENERATION) {

    for (i = 0; i <CITIES; i++) {
      parents[0][loop][i]=-1;
    }
    if(DEBUG)
    printf("Generating random sets for the %d iteration\n",loop);

    while (index<CITIES) {
      rn= (rand() % CITIES);
      //checks for duplicates in the set
      for (i = 0; i < CITIES; i++) {
        if(parents[0][loop][i]==rn){
          flag=1;
          break;
        }
      }

      if(flag==0){
        parents[0][loop][index]=rn;
        index++;
      }

      flag=0;
    }

    if(DEBUG){
    printf("Generating random set is done. This is what the random set looks like ->\n");
    printArray(parents[0][loop]);
    }

    index=0;

    if(DEBUG)
    printf("going to the next iteration...........\n");

  }

  loop=-1;
  startIndex=rn=endIndex=flag=index=0;

  while(++loop < GENERATIONS-1){



    if(DEBUG){
      printf("least sum for this gen is at index %d with value of %d and looks like\n",minI[loop],min[loop][minI[loop]]);
      printArray(parents[loop][minI[loop]]);
    }

    for (i = 0; i < PARENTS_PER_GENERATION; i++) {

      do{

        rn=rand()%PARENTS_PER_GENERATION;
        for (j = 0; j < PARENTS_PER_GENERATION; j++) {
            if(selectedParents[j]==rn || rn==i){
            flag=1;
            break;
          }else{
            flag=0;
          }
        }
        if(flag==0){selectedParents[i]=rn;}

      }while(flag==1);
      if(DEBUG){printf("Selected parent for %d parent is %d\n",i,selectedParents[i]);
      printArray(parents[loop][i]);
      printArray(parents[loop][selectedParents[i]]);
      }
      do{
        startIndex=rand()%CITIES;
        endIndex=rand()%CITIES;
      }while (startIndex>=endIndex);

      if(DEBUG)printf("start index is %d and end index is %d\n",startIndex,endIndex);

      for (j = 0; j < CITIES; j++) {
        parents[loop+1][i][j]=parents[loop][i][j];
      }

      for (j = startIndex; j <= endIndex; j++) {
        parents[loop+1][i][j]=parents[loop][selectedParents[i]][j];
      }

      if(DEBUG){
        printf("after crossover the new child looks like this\n");
        printArray(parents[loop+1][i]);
      }

      for (j = 0; j < PARENTS_PER_GENERATION; j++) {
        selectedParents[j]=-1;
      }
      flag=0;
      distinct=mutation=0;
      rev=0;
      do{
          for (k = 0; k < CITIES; k++) {
            for (j = 0; j < CITIES; j++) {
              if(k==j)continue;
              if(parents[loop+1][i][k]==parents[loop+1][i][j]){
                distinct=1;
                flag=1;
                break;
              }else{
                distinct=0;
              }
            }
              if(flag==1){
                mutation=k;
                break;
              }
            }
            if(flag==1){
            parents[loop+1][i][k]=rand()%CITIES;
            flag=0;
          }

      }while (distinct==1);
      rev=0;
      if(DEBUG){
        printf("after mutation the new child looks like \n");
        printArray(parents[loop+1][i]);
        printf("and the sum is ");
      }

      min[loop][i]=0;
      for (j = 0; j < CITIES; j++) {
        if(j!=CITIES-1)
        min[loop][i]+=adj[parents[loop+1][i][j]][parents[loop+1][i][j+1]];
        else
        min[loop][i]+=adj[parents[loop+1][i][j]][parents[loop+1][i][0]];
      }
      if(DEBUG){
        printf("%d\n",min[loop][i]);
      }

    }

    for (j = 0; j < PARENTS_PER_GENERATION-1; j++) {
      if(min[loop][j]<min[loop][j+1]){
        minI[loop]=j;
      }
    }

    if(DEBUG){printf("after gen %d this is the result\n",(loop)+1);
      for (i = 0; i < PARENTS_PER_GENERATION; i++) {
        printArray(parents[loop+1][i]);
      }
      printf("with the least sum being %d at index %d and looks like\n",min[loop][minI[loop]],minI[loop]);
      printArray(parents[loop+1][minI[loop]]);
    }
    if(DEBUG)scanf("%d",&stop);
  }
  rn=99999999;
  for (j = 0; j < GENERATIONS-1; j++) {
    if(rn>min[j][minI[j]]){
      rn=min[j][minI[j]];
    }
  }
  printf("%d LEAST SUM\n",rn);
}
