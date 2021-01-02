#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int math2Problem6() {

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

int math2Problem5() {
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

int math2Problem4() {
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

int math2Problem3() {
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