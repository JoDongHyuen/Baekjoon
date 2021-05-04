#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int Alphabet[26] = { 0 };

void QuickSort(int start, int end)
{
	int pivot = (start + end) / 2;
	int low = start, high = end;
	int temp;

	while (low <= high)
	{
		while (Alphabet[low] > Alphabet[pivot]) low++;
		while(Alphabet[high] < Alphabet[pivot]) high--;

		if (low <= high)
		{
			temp = Alphabet[low];
			Alphabet[low] = Alphabet[high];
			Alphabet[high] = temp;
			low++;
			high--;
		}
	}

	if (start < low - 1)
		QuickSort(start, low - 1);
	if (low < end)
		QuickSort(low, end);
}

int Problem1339()
{
	int input;
	int i, j, len, pos;
	int result = 0;

	char input_string[11];
	double exp;

	scanf("%d", &input);

	for (i = 0; i < input; i++)
	{
		scanf("%s", input_string);
		len = strlen(input_string) - 1;
		for (j = 0; j <= len; j++)
		{
			pos = input_string[j] - 'A';
			Alphabet[pos] += (int)pow(10.0, (double)(len - j));
		}
	}

	QuickSort(0, 25);

	for (i = 0; i < 10; i++) {
		result += Alphabet[i] * (9-i);
	}

	printf("%d\n", result);
}