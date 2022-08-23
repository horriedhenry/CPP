// sum of cube of individual numbers = number -> armstrong

#include <stdio.h>
#include <math.h>

int cube(int num) {
    return (num * num * num);
}

int main(void) {
  int n;
  scanf("%d", &n);
  int num = n;
  int result = 0;
  while (n > 0) {
    int lastdig = n % 10;
    result += cube(lastdig);
    n = n / 10;
  }

  if (result == num) {
    printf("Armstrong");
  } else {
    printf("Naa!!!");
  }
  return 0;
}
