//메모리 관리와 메모리의 동적 할당  // malloc free ***

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

int main(void)
{
	// C: malloc free -----------------------------------------
	{
		int* ptr1 = (int*)malloc(sizeof(int));
		int* ptr2 = (int*)malloc(sizeof(int) * 7);
		int i;

		*ptr1 = 20;
		for (i = 0; i < 7; i++)	ptr2[i] = i + 1;

		printf("%d \n", *ptr1);
		for (i = 0; i < 7; i++)	printf("%d ", ptr2[i]);

		free(ptr1);
		free(ptr2);
	}
	// C++ : new delete ---------------------------------------
	{
		int* ptr1 = new int;
		*ptr1 = 20;
		printf("%d \n", *ptr1);

		int* ptr2 = new int[7];
		for (int i = 0; i < 7; i++)	ptr2[i] = i + 1;		
		for (int i = 0; i < 7; i++)	printf("%d ", ptr2[i]);

		delete ptr1;
		delete[] ptr2;
	}

	return 0;
}

/*
//전역변수나 지역변수로 문자열을 담아둘수 없는 경우. 동적 할당 필요.

	char name[30];

	void ReadUserName(void)
	{
		printf("What's your name? ");
		cin >> name;
	}

	int main(void)
	{
		ReadUserName();	printf("name1: %s \n", name);
		ReadUserName();	printf("name2: %s \n", name);
		printf("again name1: %s \n", name);
		printf("again name2: %s \n", name);
		return 0;
	}

	//-----------------------------------------------
	char* ReadUserName(void)
	{
		char* name = (char*)malloc(sizeof(char) * 30);
		printf("What's your name? ");
		//gets(name);
		cin >> name;
		return name;
	}

	int main(void)
	{
		char* name1;
		char* name2;
		name1 = ReadUserName();	printf("name1: %s \n", name1);
		name2 = ReadUserName();	printf("name2: %s \n", name2);
		printf("again name1: %s \n", name1);
		printf("again name2: %s \n", name2);
		free(name1);
		free(name2);
		return 0;
	}
*/

/*
// malloc, realloc ----------------------------------------------------------------

malloc()
	함수선언: void* malloc(size_t size);
	malloc은 size만큼의 메모리를 할당하고(초기화 없이) 해당 힙 영역을 반환합니다.

	int* ptr = malloc(10 * sizeof(int));

calloc()
	함수선언: void* calloc(size_t nelements, size_t bytes);
	calloc는 num* size만큼의 메모리를 할당하고 해당 힙 영역을 0으로 초기화하여 반환합니다.

	int* ptr = calloc(10, sizeof(int));

realloc()
	함수선언: void *realloc(void *block, size_t size);
	realloc은 malloc이나 calloc으로 할당받은 메모리의 사이즈를 변경할 때 사용한다.
	

	//-------------------------------------------------------------
	#include <stdio.h>
	#include <stdlib.h>

	int main() {
		int *pi1;
		int *pi2;

		pi1 = (int *)malloc(sizeof(int) * 3); //할당
		printf("malloc : %d %d %d\n", pi1[0], pi1[1], pi1[2]);

		pi2 = (int *)calloc(3, sizeof(int)); //할당
		printf("calloc : %d %d %d\n", pi2[0], pi2[1], pi2[2]);

		free(pi1);		//메모리 해제
		free(pi2);		//메모리 해제
	}

	//-------------------------------------------------------------
	#include <stdio.h>
	#include <stdlib.h>

	int main()
	{
		int i;
		int *pi = (int *)malloc(sizeof(int) * 3);	//4x3 메모리 할당
		for (i = 0; i < 3; i++)	pi[i] = i * 4;
		for (i = 0; i < 3; i++)
			printf("pi[%d] : memory %d %d\n", i, &pi[i], pi[i]);
		printf("-----------------------------\n");

		pi = (int *)realloc(pi,sizeof(int) * 5);	//4x5 메모리 재할당
		for (i = 3; i < 5; i++)	pi[i] = i * 4;
		for (i = 0; i < 5; i++)
			printf("pi[%d] : memory %d %d\n", i, &pi[i], pi[i]);
		printf("-----------------------------\n");

		free(pi);	//메모리 해제
	}

*/

//연습) int 데이타 10개의 공간을 동적으로 확보하고
//		1부터 10 의 숫자를 저장한 후
//		각 내용을 출력하는 프로그램을 작성하라.


//연습) 아래 코드에서 잘못된 부분을 지작하세요. 
/*

#include<iostream>
using namespace std;

int main(void)
{
	int n = 2;
	int arr[n];					//1
	int* p = new int[n];		//2
	cout << p[1];				//3
	p[2] = 2;					//4
	p = new int[3];				//5
	delete p;					//6
}

//1 배열갯수 상수 사용해야 함
//2 정상
//3 초기화 없이 사용
//4 범위 벗어남
//5 주소 상실(메모리 누수)
//6 []로 해제 해야 함

*/


//연습) 20자이내의 문자열을 5개 저장 및 출력하려고 합니다.
//		동적할당을 사용하여 공간확보 후 문자열을 키보드로 입력받아 저장 후 출력하세요.
/*
#include <iostream>
#include <cstring> // strlen, strcpy 함수 사용

int main() {
	const int STRING_COUNT = 5;
	const int MAX_LENGTH = 20; // 20자 + 널문자('\0')를 위해 21로 할당
	char** arr = new char*[STRING_COUNT]; // 문자열 포인터 배열 동적 할당

	// 각 문자열 공간 동적 할당 및 입력
	for (int i = 0; i < STRING_COUNT; ++i) {
		arr[i] = new char[MAX_LENGTH + 1]; // 20자 + '\0'
		std::cout << i + 1 << "번째 문자열 입력: ";
		std::cin.getline(arr[i], MAX_LENGTH + 1);
	}

	// 입력된 문자열 출력
	std::cout << "\n입력한 문자열 목록:\n";
	for (int i = 0; i < STRING_COUNT; ++i) {
		std::cout << arr[i] << std::endl;
	}

	// 동적 할당 해제
	for (int i = 0; i < STRING_COUNT; ++i) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}
*/

/*
//함수 이중포인터의 동적 배열 할당

	typedef void (*FPTR)();					//typedef 활용

	void (**p)() = new FPTR[4];				//함수포인터 동적할당

	void (*(*p)[3])() = new FPTR[4][3];		//함수포인터 배열 동적할당

*/

//동적할당이란
//new delete
// 
//동적할당이 필요한 이유
//배열의 동적할당 - new[] delete[]
//구조체의 동적할당
//
//클래스의 동적할당
//포인터 사용의 주의 사항
//스마트 포인터 (unique_ptr, shared_ptr) 사용
