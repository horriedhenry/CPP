#include <stdio.h>

void rectangle(int rows, int cols)
{
  printf("\nRectangle\n");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("* ");
    }
    printf("\n");
  }
  printf("\n");
}

void HollowRectangle(int rows, int cols)
{
  // hollow rectangle
  // * * * *
  // *     *
  // *     *
  // *     *
  // * * * *
  printf("HollowRectangle\n");
  for (int i = 1; i <= rows; i++)
  {
    for (int j = 1; j <= cols; j++)
    {
      if (i == 1 || i == rows)
      {
        printf("* ");
      }
      else if (j == 1 || j == cols)
      {
        printf("* ");
      }
      else
      {
        printf("  ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

void invertedPyramid(int count)
{
  // * * * * *
  // * * * *
  // * * *
  // * *
  // *
  // // recursive
  // if (count == 0)
  // {
  //     return;
  // }

  // for (int i = 0; i < count; i++)
  // {
  //     printf("* ");
  // }
  // printf("\n");
  // invertedPyramid(count - 1);
  // end recursive

  printf("invertedPyramid\n");
  for (int i = count; i >= 1; i--)
  {
    for (int j = 0; j < i; j++)
    {
      printf("* ");
    }
    printf("\n");
  }
  printf("\n");
}

void invertedPyramid180(int n)
{
  printf("invertedPyramid180\n");
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (j <= n - i)
      {
        printf("  ");
      }
      else
      {
        printf("* ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

void halfPyramidUsingNUmbers(int n)
{
  // for (int i = 1; i <= n; i++)
  // {
  //     for (int j = 1; j <= n; j++)
  //     {
  //         if (j <= i)
  //         {
  //             printf("%d ", i);
  //         }
  //         else
  //         {
  //             printf("  ");
  //         }
  //     }
  //     printf("\n");
  // }
  printf("halfPyramidUsingNUmbers\n");
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      printf("%d ", i);
    }
    printf("\n");
  }
  printf("\n");
}

void halfpyr180(int n)
{
  printf("halfpyr180\n");
  for (int i = n; i >= 1; i--)
  {
    // TODO
  }
}

void floyds_triangle(int n)
{
  printf("floyds_triangle\n");
  int counter = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      printf("%d ", counter);
      counter++;
    }
    printf("\n");
  }
  printf("\n");
}

void butterfly_pattern(int n)
{
  printf("ButterFly!\n");
  int space = 8;
  for (int i = 1; i <= n; i++)
  {
    // int space = (2 * n) - (2 * i);
    space -= 2;
    for (int j = 1; j <= i; j++)
    {
      printf(" * ");
    }
    for (int i = 1; i <= space; i++)
    {
      printf("   ");
      // printf(" %d ", space);
    }
    for (int j = 1; j <= i; j++)
    {
      printf(" * ");
    }

    printf("\n");
  }

  space = 0;
  for (int i = n; i >= 1; i--)
  {
    // int space = (2 * n) - (2 * i);
    for (int j = 1; j <= i; j++)
    {
      printf(" * ");
    }
    for (int i = 1; i <= space; i++)
    {
      printf("   ");
      // printf(" %d ", space);
    }
    for (int j = 1; j <= i; j++)
    {
      printf(" * ");
    }
    printf("\n");
    space += 2;
  }
  printf("\n");
}

int main(void)
{
  rectangle(5, 5);
  HollowRectangle(5, 5);
  invertedPyramid(5);
  invertedPyramid180(5);
  halfPyramidUsingNUmbers(5);
  halfpyr180(5);
  floyds_triangle(5);
  butterfly_pattern(4);
  return 0;
}
