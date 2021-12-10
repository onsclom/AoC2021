#include <stdio.h>
#include <string.h>

int main()
{
    FILE *inputFile = fopen("day2-input.txt", "r");

    char curDirection[10];
    int distance;
    int curX = 0;
    int curDepth = 0;
    while (fscanf(inputFile, "%s %i", curDirection, &distance) != EOF)
    {
        if (strcmp("forward", curDirection) == 0)
        {
            curX += distance;
        }
        else if (strcmp("down", curDirection) == 0)
        {
            curDepth += distance;
        }
        else
        {
            // up
            curDepth -= distance;
        }
    }

    int answer = curX * curDepth;
    printf("part 1: %i\n", answer);

    fclose(inputFile);
    // PART 2
    inputFile = fopen("day2-input.txt", "r");

    curDirection[10];
    curX = 0;
    curDepth = 0;
    int curAim = 0;
    while (fscanf(inputFile, "%s %i", curDirection, &distance) != EOF)
    {
        if (strcmp("forward", curDirection) == 0)
        {
            curX += distance;
            curDepth += curAim * distance;
        }
        else if (strcmp("down", curDirection) == 0)
        {
            curAim += distance;
        }
        else
        {
            // up
            curAim -= distance;
        }
        //printf("currently curX:%i, curDepth:%i, curAim:%i\n", curX, curDepth, curAim);
    }

    answer = curX * curDepth;
    printf("part 2: %i\n", answer);
}