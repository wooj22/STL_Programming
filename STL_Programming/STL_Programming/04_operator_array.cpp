/*
	[ 배열 연산자 [] 재정의 ]
*/

#include <iostream>
using namespace std;

class MyArray
{
public:
	int* arr;
	int size = 0;

	MyArray(int n) : size(n) { arr = new int(n); }
	~MyArray() { delete[] arr; }
	
	// []
	int& operator[](int index)
	{
		return arr[index];
	}

	// [] 상수 객체 전용
	int operator[](int index) const 
	{ 
		return arr[index]; 
	}
};

int main()
{
	MyArray arr(5);
	arr[0] = 1;
	cout << arr[0] << endl;

	// 상수 객체 전용
	const MyArray arr2(5);
	cout << arr2[0] << endl;
}