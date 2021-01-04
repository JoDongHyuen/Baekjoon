#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int hanoiTower(int block_num, int pos, int via, int target) {
	if (block_num == 1)
		printf("%d %d\n", pos, target);
	else {
		hanoiTower(block_num - 1, pos, target, via);
		printf("%d %d\n", pos, target);
		hanoiTower(block_num - 1, via, pos, target);
	}
}

int recursiveProblem4() {
	int block_num, move_num = 1;
	int i;

	scanf("%d", &block_num);

	for (i = 0; i < block_num; i++)
		move_num = move_num * 2;
	move_num = move_num - 1;

	printf("%d\n", move_num);

	hanoiTower(block_num, 1, 2, 3);
}

void recursiveStar(int x, int y, int size, char matrix[][2187]) {
	int i, j;
	int frag;
	if (size == 3) {
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (i != 1 || j != 1)
					matrix[x + i][y + j] = '*';
	}
	else{
		
		frag = size / 3;
		/*
		recursiveStar(0, 0, frag, matrix);
		recursiveStar(0, 0 + frag, frag, matrix);
		recursiveStar(0, 0 + frag * 2, frag, matrix);

		recursiveStar(0 + frag, 0, frag, matrix);
		recursiveStar(0 + frag, 0 + frag * 2, frag, matrix);

		recursiveStar(0 + frag * 2, 0, frag, matrix);
		recursiveStar(0 + frag * 2, 0 + frag, frag, matrix);
		recursiveStar(0 + frag * 2, 0 + frag * 2, frag, matrix);
		*/
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (i != 1 || j != 1)
					recursiveStar(x + ( frag * i), y + ( frag * j), frag, matrix);
	}
}

int recursiveProblem3() {
	int num;
	int i, j;
	char matrix[2187][2187];

	scanf("%d", &num);
	
	for (i = 0; i < 2187; i++)
		for (j = 0; j < 2187; j++)
			matrix[i][j] = ' ';
	
	recursiveStar(0, 0, num, matrix);

	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++)
			printf("%c", matrix[i][j]);
		printf("\n");
	}
}

int Fibonacci(int order) {
	if (order == 1)
		return 1;
	if (order < 1)
		return 0;
	else
		return Fibonacci(order - 1) + Fibonacci(order - 2);
}

int recursiveProblem2() {
	int order, result;

	scanf("%d", &order);

	result = Fibonacci(order);
	printf("%d\n", result);
}

int Factorial(int num) {
	if (num <= 1)
		return 1;
	else
		return num * Factorial(num - 1);
}

int recursiveProblem1() {
	int num, result;
	scanf("%d", &num);

	result = Factorial(num);
	printf("%d\n", result);
}