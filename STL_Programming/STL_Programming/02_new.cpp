/*
	C의 동적 메모리 할당
	 -> malloc, free

	C++의 동적 메모리 할당
	 -> new, delete
*/
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

int main()
{
	// [ C ]
	{
		int* ptr1 = (int*)malloc(sizeof(int));
		int* ptr2 = (int*)malloc(sizeof(int) * 10);

		*ptr1 = 1;
		cout << "ptr1 = " << *ptr1 << endl;

		for (int i = 0; i < 10; i++)
		{
			ptr2[i] = i;
			cout << "ptr2[" << i << "] = " << ptr2[i] << endl;
		}

		free(ptr1);
		free(ptr2);
	}

	// [ C++ ]
	{
		int* ptr1 = new int;
		int* ptr2 = new int[10];

		*ptr1 = 1;
		for (int i = 0; i < 10; i++)
		{
			ptr2[i] = i;
			cout << "ptr2[" << i << "] = " << ptr2[i] << endl;
		}

		delete ptr1;
		delete[] ptr2;
	}
}
