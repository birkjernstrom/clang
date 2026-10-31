#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);

int main(void) {
  int a = add(10, 20);
  int b = sub(a, 20);

  printf("a: %d\n", a);
  printf("b: %d\n", b);
}
