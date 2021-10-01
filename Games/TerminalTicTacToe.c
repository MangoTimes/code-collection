#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int getEmptySlotFromRow(int board[3][3],int n){
  int i;
  for ( i = 0; i < 3; i++) {
    if(board[n][i]<10)return board[n][i];
  }
  return -2;
}

int getEmptySlotFromColumn(int board[3][3],int n){
  int i;
  for ( i = 0; i < 3; i++) {
    if(board[i][n]<10)return board[i][n];
  }
  return -2;
}

int getEmptySlotFromDiagonal(int board[3][3],int n){
  int i,j=3;
  if(n==0){
    for (int i = 0; i < 3; i++) {
      if(board[i][i]<10)return board[i][i];
    }
  }else{
    for (int i = 0; i < 3; i++) {
      if(board[i][--j]<10)return board[i][j];
    }
  }
  return -2;
}


int checkRowAndColumn(int board[3][3],int sumT){
  int i,j,sum=0,sumC=0;
  for (i = 0; i <3; i++) {
    for (j = 0; j < 3; j++) {
      sum+=board[i][j]>10?board[i][j]:0;
      sumC+=board[j][i]>10?board[j][i]:0;

    }
    if(sum==sumT)return getEmptySlotFromRow(board,i);
    if(sumC==sumT)return getEmptySlotFromColumn(board,i);
    sumC=0;
    sum=0;
  }
  return -1;
}

int checkDiagonals(int board[3][3],int sumT){
  int sumC=0,sumD=0;
  int j=3,i;
  for (i = 0; i < 3; i++) {
    sumD+=board[i][i]>10?board[i][i]:0;
    if(sumD==sumT)return getEmptySlotFromDiagonal(board,0);
    sumC+=board[i][--j]>10?board[i][j]:0;
    if(sumC==sumT)return getEmptySlotFromDiagonal(board,1);
  }
  return -1;
}

int generateTurnFromSum(int board[3][3]){
  int i,c;
  int arr[3]={158,176,167};
  for (i = 0; i < 3; i++) {
    c=checkRowAndColumn(board,arr[i]);
    if(c!=-1&&c!=-2)return c;
    c=checkDiagonals(board,arr[i]);
    if(c!=-1&&c!=-2)return c;
  }
  return -1;
}


void printBoard(int arr[3][3]){
  int i,j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if(j==2){
        if(arr[i][j]==88)printf("X");
        else if(arr[i][j]==79)printf("O");
        else printf("%d",arr[i][j]);
      }
      else{
         if(arr[i][j]==88)printf("X|");
         else if(arr[i][j]==79)printf("O|");
         else printf("%d|",arr[i][j]);
      }
    }
    printf("\n");
    if(i!=2){
      for (j = 0; j < 5; j++) {
        printf("-");
      }
      printf("\n");
    }
  }
}

int* getPointerToBoardValue(int board[3][3],int j){
  if(j>0&&j<4)return &board[0][j-1];
  else if(j>3&&j<7)return &board[1][j-4];
  else if(j>6&&j<10)return &board[2][j-7];
  return &j;
}

short isFilled(int board[3][3],int j){
  return *getPointerToBoardValue(board,j)==88||*getPointerToBoardValue(board,j)==79?1:0;
}


int getRow(int number){
  if(number>0&&number<4)return 0;
  else if(number>3&&number<7)return 1;
  else return 2;
}

int getColumn(int number){
  int i,j;
  for(j=1;j<4;j++){
    for (i = j; i < 9; i+=3) {
      if(i==number)return j-1;
    }
  }
}

int* getExisitingSurroundingPointers(int board[3][3],int lastTurn){
  int i;
  int arr[9];
  int *p=arr;
  for (i = 0; i < 9; i++) {
    arr[i]=-1;
  }
  int s=0;
  if(lastTurn==9){arr[0]=board[2][1];
    arr[1]=board[1][2];
    arr[2]=board[1][1];
  }
  else for (int i = -1; i <= 1; ++i)
  {
      for (int j = -1; j <= 1; ++j)
      {
          if( (i==0&&j==0) || (getRow(lastTurn)+i>2 || getRow(lastTurn)+i<0)
          || getColumn(lastTurn)+j>2 || getColumn(lastTurn)+j<0 )continue;
          else {arr[s++]=board[getRow(lastTurn)+i][getColumn(lastTurn)+j];}
      }
  }
  return p;
}


int generateTurn(int board[3][3],int lastTurn){
  int a=generateTurnFromSum(board);
  if(a!=-1&& a!=-2)return a;
  int *point=getExisitingSurroundingPointers(board,lastTurn);
  int suc=0,index,i;

  while (suc==0) {
    index=rand()%9+1;
    for (i = 0; i < 9; i++) {
      if(*(point+i)==index){
        suc=1;
        break;
      }
    }
  }

  return index;
}





void changeBoard(int board[3][3],int j,char *playerSign,short sentBy){
  while (j>10 || j<1 || *getPointerToBoardValue(board,j)>10) {
    printf("that number doesnt fit in the board or is already taken. please re-enter the number.\n");
    scanf("%d",&j);
  }
  *getPointerToBoardValue(board,j)=(int)*playerSign;
}


void assignCharacters(char *playerSign,char *opponentSign){
  int rn=rand()%2;
  if(rn){
    *playerSign='X';
    *opponentSign='O';
  }else{
    *playerSign='O';
    *opponentSign='X';
  }
}

void clearBoard(int board[3][3]){
  int i,j,n=0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      board[i][j]=++n;
    }
  }
}

int checkBoard(int board[3][3]){
  int arr[2]={237,264};
  int i;
  for (i = 0; i < 2; i++) {
    if(checkRowAndColumn(board,arr[i])!=-1) return i;
    else if(checkDiagonals(board,arr[i])!=-1) return i;
  }
  return -1;
}

void renderPlay(int board[3][3],int multiplayer,char playerSign,char opponentSign){
  //system("clr");
  //system("clear");
  clrscr();
  if(!multiplayer){
    printf("[START]:Creating a new tic tac toe board.\n%c's represent player's slot\n%c's represent computer's slot\n",playerSign,opponentSign);
  }else{
    printf("[START]:Creating a new tic tac toe board.\n %c's represent player one's slot\n %c's represent player two's slot\n",playerSign,opponentSign);
  }

  printf("[HINT]:To place your marker, you just have to enter the respective board number when asked\n");
  printBoard(board);
}

void main(){
  int board[3][3],i,j,rn,nextMove,totalMoves=9;
  short turn=0;//0 means player's trun and 1 means computer's turn
  short multiplayer=0;//0 means its a single player match
  char playerSign;// symbol used to represent player's slot
  char opponentSign;// symbol used to represent enemy's slot
  short win=0;// 1 means the match has been finished with victory
  assignCharacters(&playerSign,&opponentSign);// gives player and enemy a sign from X or O randomly
  clearBoard(board);// initializes the board matrix with numbers

  renderPlay(board,multiplayer,playerSign,opponentSign);


  rn=rand()%2;

  if(rn){
    turn=1;
    if(!multiplayer){
      printf("Computer plays first\n");
     nextMove=generateTurn(board,rand()%9+1);
    }
    else{
      printf("Player two play's first : ");
      scanf("%d",&nextMove);
    }
  }
  else{
    if(!multiplayer)
      printf("You play first : ");
    else
      printf("Player one play's first : ");

    scanf("%d", &nextMove);
  }

  changeBoard(board,nextMove,turn?&opponentSign:&playerSign,turn);

  //Should be 8 here after the decrement oprator.
  totalMoves--;

  // Turn == 1 means enemy's turn just finished so we can make the player select
  // the next move.
  while (totalMoves-->0) {
    renderPlay(board,multiplayer,playerSign,opponentSign);


      if(turn){ //Player's turn
        turn=0;
        if(!multiplayer)
          printf("Player's turn : ");
        else
          printf("Player one's turn : ");
        scanf("%d",&nextMove);
      }else{  //Computer's turn
        turn=1;
        if(!multiplayer){
          printf("Computer's turn");
          nextMove=generateTurn(board,nextMove);
          printf(" : %d\n",nextMove);
        }
        else{
          printf("Player two's turn : ");
          scanf("%d",&nextMove);
        }
      }

      changeBoard(board,nextMove,turn?&opponentSign:&playerSign,turn);
      if(checkBoard(board)==0){
        win=1;
        printf("Game finished and %c is the winner.\n",opponentSign);
        break;
      }else if(checkBoard(board)==1){
        win=1;
        printf("Game finished and %c is the winner.\n",playerSign);
        break;
      }
  }
  renderPlay(board,multiplayer,playerSign,opponentSign);

  if(!win){
    printf("Game finished with no winners");
  }
}
