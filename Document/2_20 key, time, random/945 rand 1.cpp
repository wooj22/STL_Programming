// rand() // srand()

//첫번째로, time을 seed로 가지고 있는 srand 함수를 부르고
//두번째로, rand() 함수를 이용해서 랜덤한 값을 가지고 오고
//세번째로, 그 랜덤한 값을 % n 으로 나머지를 구해서 0 ~ n-1 까지의 범위의 랜덤값을 얻는 것

//rand() : 0부터 약 6만의 숫자까지 숫자를 리턴합니다. // 0~32767
//rand()를 쓰기 전 srand((unsigned)time(NULL)) 를 한번만 써주면 됩니다. 써주지 않으면, 
//rand()는 프로그램 실행시마다 같은 랜덤값을 리턴하게 됩니다.

//rand % b					: 0 ~ (b-1)
//rand % b + 1				: 1 ~ b  // b로 나눈 나머지에 1을 더함.그러면 1 ~b의 범위가 설정됨
//rand % (b - a + 1) + a	: a ~ b  // a ~ b의 범위가 설정됨


//C언어만 사용하시는 분들은 해당 헤더만 포함하세요.
//#include<stdio.h> 
//#include<stdlib.h>
//#include<time.h>

//C++용 헤더
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 5; i++)
		printf("Random Number : %d\n", rand() % 50);

	return 0;
}

/* 
//rand 함수는 내부적으로 어떤 srand의 매개변수로 들어온 seed 값과 매칭되는 숫자가 정해진다.

//시간 출력
int main(void)
{
	printf("%lld\n", time(NULL));
	system("pause");
	return 0;
}
*/


//소수점 확률은? ---------------------------------------

//cout << fixed;   
//cout.precision(2);
// 
//printf("%.2f%%\n", 10.0 / 100.0 * 100.0);


/*
//https://boycoding.tistory.com/192?category=1009239

int getRandomNumber(int min, int max) 
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0); 
	// static used for efficiency, so we only calculate this value once 
	// evenly distribute the random number across our range 
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction)); 
}

*/