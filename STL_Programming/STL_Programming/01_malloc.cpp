/*
   [ C의 동적 메모리 할당 ]

	1. malloc() 
	함수선언: void* malloc(size_t size);
	malloc은 size만큼의 메모리를 할당하고(초기화 없이) 해당 힙 영역을 반환

	int* ptr = malloc(10 * sizeof(int));

	2. calloc()
	함수선언: void* calloc(size_t nelements, size_t bytes);
	calloc는 num* size만큼의 메모리를 할당하고 해당 힙 영역을 0으로 초기화하여 반환
	
	int* ptr = calloc(10, sizeof(int));
	
	3. realloc()
	함수선언: void *realloc(void *block, size_t size);
	realloc은 malloc이나 calloc으로 할당받은 메모리의 사이즈를 변경하여 메모리를 재할당
	재할당된 사이즈가 기존 사이즈보다 작은 경우, size만큼의 데이터만 살아남음
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int* ptr1;
	int* ptr2;

	// malloc
	// 값 초기화 x
	ptr1 = (int*)malloc(sizeof(int) * 3);
	printf("malloc : %d %d %d\n", ptr1[0], ptr1[1], ptr1[2]);

	// calloc
	// 값을 0으로 초기화
	ptr2 = (int*)calloc(3, sizeof(int) * 3);
	printf("calloc : %d %d %d\n", ptr2[0], ptr2[1], ptr2[2]);

	// realloc
	ptr1 = (int*)realloc(ptr1, sizeof(int) * 5);
	ptr2 = (int*)realloc(ptr2, sizeof(int) * 5);
	printf("realloc : %d %d %d %d %d\n", ptr1[0], ptr1[1], ptr1[2], ptr1[3], ptr1[4]);
	printf("realloc : %d %d %d %d %d\n", ptr2[0], ptr2[1], ptr2[2], ptr1[3], ptr1[4]);

	// free
	free(ptr1);
	free(ptr2);
}