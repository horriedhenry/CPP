#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    char string[] = "Hello, Iam Underwater";
    char* strPtr = string;
    for(int i = 0; i < strlen(string); i++) {
        printf("%c", *(strPtr + i));
    }
}
