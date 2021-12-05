#include <stdio.h>

int main()
{
	// PART 1
	FILE *inputFile = fopen("day1-input.txt", "r");
	int prevNum = -1;
	int num = 0;
	int increaseCount = 0;
	while (fscanf(inputFile, "%i", &num) != EOF)
	{
		if (prevNum != -1 && num > prevNum)
			increaseCount += 1;
		prevNum = num;
	}
	fclose(inputFile);
	printf("%i\n", increaseCount);

	// PART 2
	inputFile = fopen("day1-input.txt", "r");
	int data[4] = {-1, -1, -1, -1};
	increaseCount = 0;
	while (fscanf(inputFile, "%i", &data[0]) != EOF)
	{
		if (data[3] != -1)
		{
			int sum1 = data[0] + data[1] + data[2];
			int sum2 = data[1] + data[2] + data[3];

			if (sum1 > sum2)
				increaseCount += 1;
		}
		prevNum = num;

		data[3] = data[2];
		data[2] = data[1];
		data[1] = data[0];
	}
	printf("%i\n", increaseCount);
}
