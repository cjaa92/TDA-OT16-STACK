#include <stdio.h>
#include <stdlib.h>
#include "operaciones.c"
#include "stack.c"

extern void push(int *stack, int pos, int val);
extern int pop(int *stack, int pos);
extern int peek(int *stack, int pos);
extern void print(int *stack, int max);

extern int suma(int a, int b);
extern int resta(int a, int b);
extern int multiplicacion(int a, int b);
extern int division(int a, int b);
extern int residuo(int a, int b);

#define NARR   10

int main(void){
  int stack[NARR], pos = -1, opt = -1, in = 0, a = 0, b = 0, c = 0, val = -2147483648;
  char sym, line;
  for (int i = 0; i < NARR; i++){
    stack[i] = -2147483648;
  }
  printf("***BIENVENIDO A LA CALCULADORA DE STACK***\n");
  while (in == 0){
    if(pos == -1){
      printf(">>>>>>¿Que desea hacer?<<<<<<\n1) Insertar al Stack\n4) Imprimir el Stack\n5) Salir\n$ ");
    } else if(pos == (NARR-1)){
      printf(">>>>>>¿Que desea hacer?<<<<<<\n2) Realizar una operacion\n3) Ver el ultimo valor\n4) Imprimir el Stack\n5) Salir\n$ ");
    }else if(pos < 1 && pos > -1){
      printf(">>>>>>¿Que desea hacer?<<<<<<\n1) Insertar al Stack\n3) Ver el ultimo valor\n4) Imprimir el Stack\n5) Salir\n$ ");
    } else {
      printf(">>>>>>¿Que desea hacer?<<<<<<\n1) Insertar al Stack\n2) Realizar una operacion\n3) Ver el ultimo valor\n4) Imprimir el Stack\n5) Salir\n$ ");
    }
    scanf("%d%c",&opt,&line);
    switch(opt){
      case 1:
        if(pos >= (NARR-1)){
          pos = NARR - 1;
          printf("\nERROR... el stack esta lleno, vuelva a intentar\n");
        }else{
          printf("Que valor desea ingresar?\n$ ");
          scanf("%d%c",&val,&line);
          pos++;
          push(stack, pos, val);
        }
        break;
      case 2:
        if(pos <= -1){
          pos = -1;
          printf("\nERROR... el stack esta vacio, vuelva a intentar\n");
        }else if(pos == 0){
          printf("\nERROR... el stack tiene solo un valor, agrege un valor mas y vuelva a intentar\n");
        }else{
          printf(">>>>>>¿Que operacion desea hacer?<<<<<<\n+ Sumar\n- Restar\n* Multiplicar\n/ Dividir\n%% Residuo\n$ ");
          scanf("%c%c",&sym,&line);
          switch(sym){
            case '+':
              a = pop(stack, pos);
              pos--;
              b = pop(stack, pos);
              pos--;
              c = suma(a,b);
              break;
            case '-':
              a = pop(stack, pos);
              pos--;
              b = pop(stack, pos);
              pos--;
              c =  resta(a,b);
              break;
            case '*':
              a = pop(stack, pos);
              pos--;
              b = pop(stack, pos);
              pos--;
              c = multiplicacion(a,b);
              break;
            case '/':
              a = pop(stack, pos);
              pos--;
              b = pop(stack, pos);
              pos--;
              c = division(a,b);
              break;
            case '%':
              a = pop(stack, pos);
              pos--;
              b = pop(stack, pos);
              pos--;
              c = residuo(a,b);
              break;
            default:
              printf("\nERROR... opcion invalida, vuelva a intentar...\n");
              c = -2147483648;
              break;
          }
          if(c != -2147483648){
            pos++;
            push(stack, pos, c);
            printf("\nEl resultado de la operacion %d %c %d = %d\n",a,sym,b,c);
          }

        }
        break;
      case 3:
        a=peek(stack, pos);
        printf("\nEl ultimo valor en el stack es -> %d\n", a);
        break;
      case 4:
        print(stack,NARR);
        break;
      case 5:
        in=1;
        break;
      default:
        printf("\nERROR... opcion invalida, vuelva a intentar...\n");
        break;
    }
  }
        return 0;
      }
