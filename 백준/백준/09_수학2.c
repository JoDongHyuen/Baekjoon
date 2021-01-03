#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int math2Problem11() {
	int test_case;
	double x1, y1, r1, x2, y2, r2;
	int i;
	double distance;

	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++) {
		scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2);
		
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				printf("%d\n", -1);
				continue;
			}
			else {
				printf("%d\n", 0);
				continue;
			}
		}

		distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		
		/*두 원이 외접하는 경우*/
		if (distance == r1 + r2)
			printf("%d\n", 1);

		/*두 원의 거리가 반지름의 합보다 먼 경우*/
		else if (distance > r1 + r2)
			printf("%d\n", 0);

		/*두 원의 거리가 반지름의 합보다 가까운 경우*/
		else {
			/*두 원이 내접하는 경우*/
			if (distance == abs(r1 - r2))
				printf("%d\n", 1);

			/*하나의 원 안에 다른 하나의 원이 속한 경우*/
			else if (distance < abs(r1 - r2))
				printf("%d\n", 0);

			/*두 원의 교점이 두 개인 경우*/
			else
				printf("%d\n", 2);
		}
	}
}

int math2Problem10() {
	double r;
	double pi = 3.14159265359;

	scanf("%lf", &r);

	printf("%lf\n", r * r * pi);
	printf("%lf\n", r * r * 2);
}


int math2Problem9() {
	int x[3], max;
	int i, pow_length;

	while (1) {
		scanf("%d%d%d", &x[0], &x[1], &x[2]);
		if (x[0] == 0 && x[1] == 0 && x[2] == 0)
			break;

		pow_length = 0;
		max = 0;
		for (i = 1; i <= 2; i++) {
			if (x[max] < x[i])
				max = i;
		}

		for (i = 0; i <= 2; i++) {
			if (i == max)
				continue;
			else
				pow_length = pow_length + x[i] * x[i];
		}

		if ( pow_length == (x[max] * x[max]) )
			printf("right\n");
		else
			printf("wrong\n");
	}
}

/*축과 평행이 아닌 경우 네번째 점 구하는 방법*/
int math2Problem8ver2() {
	/* 접근 방법 : 주어진 세점 중 빗변의 대각에 해당하는 점(이하 A라 칭함)을 구해야함
	 * i) 각 점의 차이를 구한후 내적이 0이 나오는 점을 선택 or 두 점을 선택해서 길이가 가장 길 때 나머지 점이 A임
	 * ii) A를 구했다면, 다른 점 (B, C라고 칭함)들을 통해 B + C - A 하면 답이 나옴*/

	int pos_x[3], pos_y[3];
	int fourth_x, fourth_y;
	int vector1_x, vector1_y, vector2_x, vector2_y, result;
	int A_pos;
	int inner_product;
	int i;

	for (i = 0; i < 3; i++)
		scanf("%d%d", &pos_x[i], &pos_y[i]);

	/* i 과정 */
	while (1) {
		vector1_x = pos_x[0] - pos_x[1];
		vector1_y = pos_y[0] - pos_y[1];
		vector2_x = pos_x[0] - pos_x[2];
		vector2_y = pos_y[0] - pos_y[2];
		inner_product = (vector1_x * vector2_x) + (vector1_y * vector2_y);
		if (inner_product == 0) {
			A_pos = 0;
			break;
		}

		vector1_x = pos_x[1] - pos_x[0];
		vector1_y = pos_y[1] - pos_y[0];
		vector2_x = pos_x[1] - pos_x[2];
		vector2_y = pos_y[1] - pos_y[2];
		inner_product = (vector1_x * vector2_x) + (vector1_y * vector2_y);
		if (inner_product == 0) {
			A_pos = 1;
			break;
		}

		vector1_x = pos_x[2] - pos_x[0];
		vector1_y = pos_y[2] - pos_y[0];
		vector2_x = pos_x[2] - pos_x[1];
		vector2_y = pos_y[2] - pos_y[1];
		inner_product = (vector1_x * vector2_x) + (vector1_y * vector2_y);
		if (inner_product == 0) {
			A_pos = 2;
			break;
		}

		printf("직사각형을 만들 수 없습니다!\n");
		break;
	}

	/* ii 과정 */
	fourth_x = pos_x[0] + pos_x[1] + pos_x[2] - 2 * pos_x[A_pos];
	fourth_y = pos_y[0] + pos_y[1] + pos_y[2] - 2 * pos_y[A_pos];

	printf("%d %d\n", fourth_x, fourth_y);
}

int math2Problem8() {
	int pos_x[3], pos_y[3];
	int fourth_x, fourth_y;
	int i;
	
	for (i = 0; i < 3; i++)
		scanf("%d%d", &pos_x[i], &pos_y[i]);

	fourth_x = (pos_x[0] == pos_x[1]) ? pos_x[2] : (pos_x[0] == pos_x[2]) ? pos_x[1] : pos_x[0];
	fourth_y = (pos_y[0] == pos_y[1]) ? pos_y[2] : (pos_y[0] == pos_y[2]) ? pos_y[1] : pos_y[0];

	printf("%d %d\n",fourth_x, fourth_y);
}

int math2Problem7() {
	int pos_x, pos_y, horizon, vertical;
	int horizon_min, vertical_min, result;
	scanf("%d%d%d%d", &pos_x, &pos_y, &horizon, &vertical);

	/*가로(너비) 최소 거리 구하기*/
	horizon_min = pos_x < (horizon - pos_x) ? pos_x : (horizon - pos_x);
	/*세로(높이) 최소 거리 구하기*/
	vertical_min = pos_y < (vertical - pos_y) ? pos_y : (vertical - pos_y);
	/*구한 최소 거리중 더 작은 값 구하기*/
	result = horizon_min < vertical_min ? horizon_min : vertical_min;

	printf("%d\n", result);
}

bool check_prime(int num) {

	int i;
	float sqrt_num;
	
	sqrt_num = sqrt((double)num);

	if (num == 2)
		return true;

	else if (num % 2 == 0 || num == 1)
		return false;

	for (i = 3; i <= sqrt_num; i++) {
		if (num % i == 0)
			return false;
	}

	return true;
}

int math2Problem6() {
	int test_case;
	int input_num, little_prime, big_prime;
	int i, j;
	bool LP_isPrime, BP_isPrime;

	scanf(" %d", &test_case);

	for (i = 0; i < test_case; i++) {
		scanf(" %d", &input_num);

		/* 문제 조건상 두 수 차이가 가장 작은 파티션을 구해야하므로
		 *  2로 나눈 후에 거기서 점점 숫자를 작게하며 소수를 찾아낸다*/
		for (j = input_num / 2; j >= 2; j--) {
			LP_isPrime = check_prime(j);
			if (LP_isPrime == false)
				continue;
			else
				little_prime = j;

			BP_isPrime = check_prime(input_num - j);
			if (BP_isPrime == false)
				continue;
			else
				big_prime = input_num - j;

			printf("%d %d\n", little_prime, big_prime);
			break;
		}
	}
}

int math2Problem5() {
	int input_num, result;
	int i, j, flag;
	float sqrt_i;

	while (1) {
		scanf("%d", &input_num);
		result = 0;

		/*0이 입력이면 프로그램 종료*/
		if (input_num == 0)
			break;

		/* 2n보다 작아야하는데 부등호를 <= 로한 이유?
		 * =를 빼게되면 1을 넣었을 때 정상적으로 되지않음
		 * 추가적으로 2를 곱한 값은 소수가 될 일이 없기때문에 =를 넣어 포함해주어도
		 * 결과에 아무 영향 없음 */
		for (i = input_num + 1; i <= 2 * input_num; i++) {
			sqrt_i = sqrt((double)i);
			flag = 0;

			/*2는 소수처리*/
			if (i == 2) {
				result++;
				continue;
			}

			/*2로 나눠지는 수와 1은 소수로 처리하지 않음*/
			else if (i % 2 == 0 || i == 1)
				continue;

			/*i 를 3부터 루트(i)까지 modulus 연산을 통해 소수 판별*/
			for (j = 3; j <= sqrt_i; j++) {
				if (i % j == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				continue;
			result++;
		}

		/*n과 2n사이의 소수의 숫자 출력*/
		printf("%d\n", result);
	}
}

int math2Problem4() {
	int start, end;
	int result;
	int i, j, flag;
	float sqrt_i;

	scanf("%d%d", &start, &end);

	for (i = start; i <= end; i++) {
		flag = 0;
		if (i == 2) {
			printf("%d\n", i);
			continue;
		}

		if ( (i % 2) == 0 || i == 1 )
			continue;

		sqrt_i = sqrt( (double)i );
		for (j = 3; j <= sqrt_i; j++)
			if ((i % j) == 0) {
				flag = 1;
				break;
			}

		if (flag == 1)
			continue;
		printf("%d\n", i);
	}
}

int math2Problem3() {
	int input;
	float sqrt_input;
	int i, flag;

	scanf("%d", &input);
	while (input != 1) {
		sqrt_input = sqrt((double)input);
		flag = 0;

		for (i = 2; i <= sqrt_input; i++) {
			if (input % i == 0) {
				input = input / i;
				printf("%d\n", i);
				flag = 1;
				break;
			}
		}

		if (flag == 1)
			continue;

		printf("%d\n", input);
		input = 1;
	}
}

int math2Problem2() {
	int min, max, flag;
	int i, j, sum = 0;
	int result_min = 0;
	int min_check = 0;
	float sqrt_i;
	scanf("%d%d", &min, &max);

	for (i = min; i <= max; i++) {
		flag = 0;

		if (i == 2) {
			result_min = i;
			min_check = 1;
			sum = sum + i;
			continue;
		}

		if ( (i % 2) == 0 || i == 1 )
			continue;

		sqrt_i = sqrt( (double)i );
		for (j = 3; j <= sqrt_i; j++) {
			if ((i % j) == 0) {
				flag = 1;
				break;
			}
		}

		if (flag == 1)
			continue;

		if (min_check == 0) {
			min_check = 1;
			result_min = i;
		}
		sum = sum + i;
	}
	if (result_min == 0)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, result_min);
}

int math2Problem1() {
	int test_case;
	int num;
	int i, j, count, flag;
	float sqrt_num;

	count = 0;

	scanf(" %d", &test_case);
	for (i = 0; i < test_case; i++) {
		flag = 0;
		scanf(" %d", &num);

		/*2는 소수*/
		if (num == 2)
			count++;

		/*2로 나눠지는 수와 1은 소수가 아님*/
		if ( (num % 2) == 0  || num == 1)
			continue;

		/*해당 숫자의 루트까지 판별하면 
		 *빅오를 루트n으로 낮출수 있음 */
		sqrt_num = sqrt((double)num);
		for (j = 3; j <= sqrt_num; j++)
			if ((num % j) == 0) {
				flag = 1;
				break;
			}
		if (flag == 1)
			continue;

		/*모든 조건들이 못거른 경우, 소수*/
		count++;
	}
	printf("%d\n", count);
}