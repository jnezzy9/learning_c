#include <stdio.h>
#include <stdlib.h>

int main() {

  float a;
  float b;
  float d;
  char c;

  printf("Enter your two numbers here:\n");
  scanf("%f %f", &a, &b);
  printf("%.2f, %.2f\n", a, b);
  printf("Enter your operation here:\n");
  scanf(" %c", &c);

  switch (c) {
  case '+':
    d = a + b;
    break;
  case '-':
    d = a - b;
    break;
  case '*':
    d = a * b;
    break;
  case '/':
    d = a / b;
    break;
    default:
    abort();
  }
  printf("%.2f %c %.2f = %.2f\n", a, c, b, d);

  return 0;
}