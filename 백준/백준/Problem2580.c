/* ������ ���� */
#include <stdio.h>

/* ��Ʈ��ŷ ��� �κ� ������ ����� �� �� �־��� ���� ��ȸ���� */

typedef struct _Value_Check {
	int value[10];
}Value_Check;

Value_Check Section_Check[3][3] = { 0 };
Value_Check Row_Check[9] = { 0 };
Value_Check Col_Check[9] = { 0 };
int Sudoku[9][9] = { 0 };
int Zero_Check = 0;

void Problem2580_SetNumber(int row, int col, int num)
{
	Section_Check[row / 3][col / 3].value[num] = 1;
	Row_Check[row].value[num] = 1;
	Col_Check[col].value[num] = 1;
}

void Problem2580_UnsetNumber(int row, int col, int num)
{
	Section_Check[row / 3][col / 3].value[num] = 0;
	Row_Check[row].value[num] = 0;
	Col_Check[col].value[num] = 0;
}

void Problem2580_Backtracking(int row, int col, int pos)
{
	int i, j;
	if (pos == Zero_Check) {
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++)
				printf("%d ", Sudoku[i][j]);
			printf("\n");
		}
		exit(0);
	}
	else
	{
		if (Sudoku[row][col] == 0)
		{
			for (i = 1; i <= 9; i++)
				if (Section_Check[row / 3][col / 3].value[i] == 0 && Row_Check[row].value[i] == 0 && Col_Check[col].value[i] == 0)
				{
					Sudoku[row][col] = i;
					Problem2580_SetNumber(row, col, i);

					if (col == 8)
						Problem2580_Backtracking(row + 1, 0, pos + 1);
					else
						Problem2580_Backtracking(row, col + 1, pos + 1);
					Problem2580_UnsetNumber(row, col, i);
					Sudoku[row][col] = 0;
				}
		}
		else
		{
			if (col == 8)
				Problem2580_Backtracking(row + 1, 0, pos);
			else
				Problem2580_Backtracking(row, col + 1, pos);
		}

		// �̷� ������ �ϸ� ���ѷ��� ���� ��찡 ���� (��� input�� 0 �� ��)
		/*
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
				if (Sudoku[i][j] == 0)
					for (k = 1; k <= 9; k++)
						if (Section_Check[i / 3][j / 3].value[k] == 0 && Row_Check[i].value[k] == 0 && Col_Check[j].value[k] == 0)
						{
							Sudoku[i][j] = k;
							Problem2580_SetNumber(i, j, k);
							Problem2580_Backtracking(pos + 1);
							Problem2580_UnsetNumber(i, j, k);
							Sudoku[i][j] = 0;
						}
						*/
	}
}

int Problem2580()
{
	int i, j;
	int input;

	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
		{
			/* �Է� ��Ʈ */
			scanf("%d", &input);
			
			/* ������ �迭�� �Է�*/
			Sudoku[i][j] = input;

			/* Depth ���� */
			if (input == 0)
				Zero_Check++;

			/* ����ġ�⸦ ���� ����ü �迭 */
			Section_Check[i / 3][j / 3].value[input] = 1;
			Row_Check[i].value[input] = 1;
			Col_Check[j].value[input] = 1;
		}

	Problem2580_Backtracking(0, 0, 0);

}