#include <stdio.h>
#include <stdlib.h>

int suma(int a, int b){
  return a + b;
}

int resta(int a, int b){
  return a - b;
}

int multiplicacion(int a, int b){
  return a * b;
}

int division(int a, int b){
  int t;
  if(b == 0 && a!=0){
    printf("\nError en la division, se invertiran los valores...\n");
    t = a;
    a = b;
    b = t;
  } else if(b == 0 && a==0){
    return 0;
  }
  return a / b;
}

int residuo(int a, int b){
  int t;
  if(b == 0 && a!=0){
    printf("\nError en el residuo, se invertiran los valores...\n");
    t = a;
    a = b;
    b = t;
  } else if(b == 0 && a==0){
    return 0;
  }
  return a % b;
}
