#include <stdio.h>
#include <string.h>


typedef struct _Pok {
	char name[21];
	int index;
}Poket;

char EncTemp[100000][21];
Poket Enc[100000];
Poket temp[100000];
char check[21];

void Binary_Search(int start, int end, char* name)
{
	int mid = (start + end) / 2;

	if (start <= end) {
		if (strcmp(name, Enc[mid].name) == 0)
			printf("%d\n", Enc[mid].index);
		else if (strcmp(name, Enc[mid].name) < 0)
			Binary_Search(start, mid - 1, name);
		else
			Binary_Search(mid + 1, end, name);
	}
}

void Merge_Sort(int start, int mid, int end)
{
	int i;
	int Main_Idx = start, Idx1 = start, Idx2 = mid;

	for (i = start; i <= end; i++) {
		strcpy(temp[i].name, Enc[i].name);
		temp[i].index = Enc[i].index;
	}

	while (Idx1 <= (mid - 1) && Idx2 <= end)
	{
		if (strcmp(temp[Idx1].name, temp[Idx2].name) <= 0) {
			Enc[Main_Idx].index = temp[Idx1].index;
			strcpy(Enc[Main_Idx++].name, temp[Idx1++].name);
		}
		else {
			Enc[Main_Idx].index = temp[Idx2].index;
			strcpy(Enc[Main_Idx++].name, temp[Idx2++].name);
		}
	}

	if (Idx1 < mid)
		for (i = 0; i < mid - Idx1; i++) {
			Enc[Main_Idx + i].index = temp[Idx1 + i].index;
			strcpy(Enc[Main_Idx + i].name, temp[Idx1 + i].name);
		}
}

void Merge(int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		Merge(start, mid);
		Merge(mid + 1, end);
		Merge_Sort(start, mid + 1, end);
	}
}

int Problem1620()
{
	int Pok_Num, Problem_Num;
	int i, j, num;

	scanf("%d%d", &Pok_Num, &Problem_Num);
	for (i = 0; i < Pok_Num; i++) {
		scanf("%s", Enc[i].name);
		strcpy(EncTemp[i], Enc[i].name);
		Enc[i].index = i;
	}

	/* Á¤·Ä */
	Merge(0, Pok_Num - 1);

	for (i = 0; i < Problem_Num; i++) {
		scanf("%s", check);
		if (check[0] >= 'A') {
			Binary_Search(0, Pok_Num, check);
		}
		else
		{
			num = atoi(check);
			printf("%s\n", EncTemp[num - 1]);
		}
				
	}
}