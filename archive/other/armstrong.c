// sum of cube of individual numbers = number -> armstrong

#include <math.h>
#include <stdio.h>

int cube(int num) { return (num * num * num); }

int main(void) {
  int n;
  scanf_s("%d", &n);
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
