//2주차

#pragma region  실행시간 측정 p.27
//#include <stdio.h>
////#include <stdlib.h>
//#include <time.h>
//
//int main(void)
//{
//	//실행 시간을 측정하는 코드를 넣는 부분
//	int sum = 0; 
//	time_t start = time(NULL); //time()함수로 현재 시간 반환, time_t 타입의 'start' 변수 선언
//
//	for (int i = 0; i< 80000; i++)
//		for (int j = 0; j < 10000; j++)
//			sum += i + j;
//
//	time_t end = time(NULL); //time()함수로 현재 시간 반환
//	printf("소요시간: %lf\n", (double)(end - start));
	
	//이 밑에 있는 코드는 가이드인가봄
	/*clock_t start, finish;
	double duration;
	start = clock();*/

	//finish = clock();
	//duration = (double)(finish - start) / CLOCKS_PER_SEC; //초단위로 나옴
	//printf("%f 초 입니다.\n", duration);

}
#pragma endregion 

#pragma region 순차탐색의 최선, 평균, 최악 p.41
#include <stdio.h>

int sequentialSearch(int list[], int n, int key) {
	for (int i = 0; i < n; i++) {
		if (list[i] == key) return i;

	}
	return -1;
}

int main(void)
{
	int n, key;
	int list[10] = { 1, 2, 3, 4,5,6,7,8,9,10 };
	n = 10;
	key = 9;

	int t;
	t = sequentialSearch(list, n, key);
	printf("%d", t);
	return 0;
}
#pragma endregion