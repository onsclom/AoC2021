#include <stdio.h>

#define MAX_SIZE 20

int main()
{
    FILE *input = fopen("day3-input.txt", "r");

    int counts[MAX_SIZE]={0};
    char curChar;
    int curCount = 0;
    while ( (curChar = fgetc(input)) != EOF) {
        printf("%i %i\n", curChar, curCount);
        if (curChar == '0')
            counts[curCount] -= 1;
        if (curChar == '1')
            counts[curCount] += 1;

        curCount += 1;
        if  (curChar == '\n')
            curCount = 0;
    }

    char binaryStr[MAX_SIZE];
    int size=0;
    for (int i=0; i<MAX_SIZE; i++) {
        if (counts[i] == 0) {
            size = i;
            binaryStr[i] = '\0';
            break;
        }
        if (counts[i] > 0)
            binaryStr[i] = '1';
        else if ( counts[i] < 0)
            binaryStr[i] = '0'; 
    }

    int gammaRate=0;
    int epsilonRate=0;
    for (int i=0; i<size; i++) {
        gammaRate *= 2;
        epsilonRate *= 2;
        if (binaryStr[i] == '1')
            gammaRate += 1;
        else 
            epsilonRate += 1;
    }


    printf("%s %i %i\n", binaryStr, gammaRate, epsilonRate);
    printf("gammaRate*epsilonRate: %i\n", gammaRate*epsilonRate);
}