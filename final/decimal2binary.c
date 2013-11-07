#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef int Bit;

Bit contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(Bit i);
Bit pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void) {
  int decimal;
  Bit bit;

  printf("Enter a decimal integer: ");
  scanf("%d", &decimal);

  while (decimal > 0) {
    bit = decimal % 2;
    __________;
    decimal /= 2;
  }

  printf("This number can be expressed in binary as: ");

  while (!is_empty()) {
    printf("%d", _______);
  }

  printf("\n");

  return 0;
}

void make_empty(void) {
  top = 0;
}

bool is_empty(void) {
  return top == 0;
}

bool is_full(void) {
  return top == STACK_SIZE;
}

void push(Bit i) {
  if (is_full())
    stack_overflow();
  else
    contents[top++] = i;
}

Bit pop(void) {
  if (is_empty())
    stack_underflow();
  else
    return contents[_________];
}

void stack_overflow(void) {
  printf("Error: stack overflow!\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Error: stack underflow!\n");
  exit(EXIT_FAILURE);
}
