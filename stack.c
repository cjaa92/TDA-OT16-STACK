#include <stdio.h>
#include <stdlib.h>


void push (int * stack, int pos, int val){
  stack[pos] = val;
}

int pop (int * stack, int pos){
  int val = stack[pos];
  stack[pos] = -2147483648;
  return val;
}

int peek (int * stack, int pos){
  int val = stack[pos];
  return val;
}

void print (int * stack, int max){
  int i;
  for(i=(max-1); i>=0; i--){
    if(stack[i] == -2147483648)
      printf("\n[\t \t]");
    else
      printf("\n[\t%d\t]",stack[i]);
  }
  printf("\n");
}
