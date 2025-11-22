//객체를 배열처럼 사용하기  // 배열 연산자 [] 정의하기

#include <iostream>
using namespace std;

class MyArray {
public:
	int* arr;
	int size = 0;
	MyArray(int n) : size(n) { arr = new int[3]; }
	~MyArray() { delete[] arr; }

	//int& operator[](int index) { return arr[index]; }
	//int  operator[](int index) const { return arr[index]; }
};

int main()
{
	int arr[3];
	arr[0] = 1;

	MyArray myarr(3);
	myarr.arr[0] = 1;

	myarr[0] = 1;  //객체를 배열처럼 사용 ??
}
