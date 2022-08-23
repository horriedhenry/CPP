#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int value;
    struct tree *left;
    struct tree *right;

} tree;

void inverted_pattern(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void O_1Pattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((j + i) % 2 == 0)
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void rhombus(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf("  ");
        }
        for (int j = 1; j <= n; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void numberPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void palindromePattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf("  ");
        }
        for (int j = i; j >= 1; j--)
        {
            printf("%d ", j);
        }
        for (int j = 2; j <= i; j++)
        {
            printf("%d ", j);
        }

        printf("\n");
    }
    // TODO : Try Another Logic
}

void StarPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf("  ");
        }

        for (int j = 1; j <= ((i * 2) - 1); j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf("  ");
        }

        for (int j = 1; j <= ((i * 2) - 1); j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void ZigZagPattern(int n)
{
    // row fixed - 3
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (((i + j) % 4 == 0) || (i == 2 && j % 4 == 0))
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
}


int main(void)
{
    ZigZagPattern(9);
    return 0;
}
