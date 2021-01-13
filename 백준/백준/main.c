#include <stdio.h>

int main(){

	//memcpy_test();
	//plus_speed_test();
	//test_atoi();
	//star1();

	//basic1(); //각 변수들의 바이트 길이 체크
	//basic2();
	//basic3(); //자료형 변환
	//IFproblem1();
	//IFproblem2();
	//IFproblem3();
	//IFproblem4();
	//IFproblem5();
	//IFtest(); //?연산자 이중 삼중사용 테스트

	//FORproblem1();
	//FORproblem3(); // 1부터 n까지의 합 구하는 함수
	//FORproblem3ver2(); //1부터 n까지 합 구하는 함수 가우스 덧셈 활용 (항상 간편하게 생각하자)
	//assertTEST(); //assert 명령어 시험 앞으로 자주 사용할 것 !
	//FORproblem4();
	//FORproblem5();
	//FORproblem6();
	//FORproblem7();
	//FORproblem8();
	//FORproblem9();
	//FORproblem10();
	//FORproblem11();

	//WHILEproblem1();
	//WHILEproblem2(); //입력 데이터에서 끝이 명시되어 있지 않을 땐 EOF를 조건으로 사용할것 *EOF는 End of File 의 약자
	//WHILEproblem3();  //주어진 값이 26일 때 2 + 6 = 8에서 68, 6 + 8 = 14에서 84, 8 + 4 = 12에서 42, 4 + 2 = 6에서 26 주이진 값으로 돌아오는데
						//여기서 8 과 14 와 12 와 6이라는 값을 담기 위한 변수를 따로 만들어 낼 필요는 없었다. 수식 짤 때 가독성은 높아지겠지만
						//차라리 그 옆에 주석을 붙이는 방식이 나을 듯 하다*/
	//WHILEproblem3ver2(); // 문제를 푸는데 지장이 없는 값을 저장하는 변수를 일부러 저장하지 말자!
	//WHILEproblem3ver3(); //while문 3번의 최종 압축.. 가독성은 2가 나을지도 모르겠다.
	//practice1();
	//practice2();
	//practice3();
	//practice4();
	//practice5();
	//practice6();

	//ArrPractice1();
	//ArrPractice2();
	//ArrPractice3();
	//ArrPractice4();
	//ArrPractice5();
	//ArrPractice6(); //배열에 string 넣는법에 관한 문제
	//ArrPractice7(); //동적할당 사용해서 풀어본 문제

	//functionTest();
	//SelfNumberProblem();
	//HansuProblem();

	//stringProblem1();  //about ASCII Code
	//stringProblem2();  // 정수를 문자열로 입력받는 문제
	//stringProblem3();  // 한 단어에서 알파벳의 처음 등장위치를 찾으시오
	//stringProblem4();  // 각 문자를 반복출력하는 문제
	//stringProblem5();  // 주어진 단어에서 가장 많이 사용된 알파벳을 출력하는 문제
	//stringProblem6();  // 단어의 개수를 구하는 문제
	//stringProblem7();  // 주어진 정수를 거꾸로 읽어 대수비교하는 문제
	//stringProblem8();  // 전화다이얼 문제
	//stringProblem9(); // 단어 한묶음을 한 개의 단어로 판단하는 문제
	//stringProblem10();

	//math1Problem1();
	//math1Problem2();
	//math1Problem3();
	//math1Problem4();
	//math1PRoblem5(); // 달팽이 올라가는 문제, 한 줄로 풀기 실패해서 결국 다른 사람 풀이 참고함(자존심 상함)
	//math1Problem6();
	//math1Problem7(); //파스칼 삼각형 문제
	//math1Problem8(); // 큰 수 A + B
	//math1Problem9(); // 알파 센타우리 문제

	//math2Problem1(); //1은 소수가 아니다 2는 소수이다 해당수의 루트까지만 구하면 빅오를 루트N까지 절약 가능하다!
	//math2Problem2();
	//math2Problem3(); //소인수 분해
	//math2Problem4();
	//math2Problem5(); //베르트랑 공준 문제 (n과 2n 사이엔 적어도 하나의 소수가 존재한다는 이론)
	//math2Problem6(); //골드바흐 가설 문제 (2보다 큰 모든 짝수는 소수의 합으로 표현 가능하다)
	//math2Problem7();
	//math2Problem8(); // 직사각형 네번째 점 찍기 (축이랑 평행으로 주어져서 쉬움)
	//math2Problem8ver2(); // 만약 대각으로 주어지면 어떻게 풀래?
	//math2Problem9();
	//math2Problem10(); //원 넓이 구하는 문제, float 쓰면 안되는 듯 함
	//math2Problem11(); // 두 원의 위치 관계, r1 - r2 < d < r1 + r2

	//recursiveProblem1(); //팩토리얼 재귀함수 풀이
	//recursiveProblem2(); //피보나치 재귀함수 풀이
	//recursiveProblem3(); // 재귀를 이용한 별찍기(프랙탈 구조), matrix 활용 해야함, 비슷한 문제 보면 헤메지 말 것!
	   					   // + 스택 공간 늘리는 법 : 프로젝트 우클릭해서 설정 들어간 다음에 링커 -> 시스템 -> 스택 예약 크기 변경하면됨
						   // + 바이트 단위라 10MB로 설정하고 싶으면, 10^7 입력해야함, 디폴트는 1MB로 되어 있음
	//recursiveProblem4(); //하노이 탑 재귀 문제, 힌트를 너무 많이 받음 다시 생각해 볼 필요가 있음

	//bruteforceProblem1(); //블랙잭 문제
	//bruteforceProblem2(); //분해합 문제
	//bruteforceProblem3(); //덩치 문제
	//bruteforceProblem4(); //체스판 다시 칠하기 문제, 문제에 대해 다양한 반례를 떠올리는 역량을 길러야 할 듯
	//bruteforceProblem5(); //영화감독 숌 문제

	//sortProblem1verSelection(); //선택 정렬
	//sortProblem1verBubble(); //버블 정렬
	//sortProblem1verInsertion(); //삽입 정렬
	//sortProblem2verQuick(); //퀵정렬
	sortProblem3(); // 계수 정렬 (counting sort)

}

