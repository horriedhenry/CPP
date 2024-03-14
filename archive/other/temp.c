#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  float name;
  struct Node *link;
} Node;

Node *head = NULL;

int main(void)
{
  head = (Node *)malloc(sizeof(Node));
  printf("%d", sizeof(Node));
  return 0;
}
