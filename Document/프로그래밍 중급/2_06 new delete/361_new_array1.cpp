//메모리 관리와 메모리의 동적 할당

#include <iostream>
using namespace std;

int main(void)
{
	//정적 배열 -------------------------------------------------------------

	int Array[5] = { 9, 7, 5, 3, 1 };					//고정 배열
	//int Array[5] { 9, 7, 5, 3, 1 };					//고정 배열 //C++11	
	for (size_t i = 0; i < 5; i++) { cout << Array[i]; } 
	cout << endl;

	char Array2[14] = { "Hello, world!" };
	//char Array2[14] { "Hello, world!" };				//C++11
	for (size_t i = 0; i < 14; i++) { cout << Array2[i]; }	cout << endl;
	cout << Array2 << endl;

	// 동적으로 할당된 배열 -------------------------------------------------

	int* array1 = new int[5]{ 9, 7, 5, 3, 1 };			//배열 //유니폼 초기	
	delete[] array1;

	char* array2 = new char[14]{ "Hello, world!" };		//배열 //유니폼 초기화 //C++11	 
	cout << array2 << endl;
	delete[] array2;

	return 0;
}

//주의) 동적으로 할당된 배열은 동적 배열과 구분하자. (배열이 할당될 때 크기가 고정) 
//동적 배열(dynamic array) 은 보통 동적 가변 배열을 뜻한다. (크기를 변경할 수 있는 배열) ***

//동적 할당 - 메모리 할당이 실행 시간에 정해짐. 
//정적 할당 - 메모리 할당이 컴파일시간에 정해짐. 


//연습) 동적으로 배열을 선언하고, 정수 0 ~ 9 값으로 초기화 하세요

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int* arr = new int[10]();							//int 배열 //0 초기화	
	for (size_t i = 0; i < 10; i++) { arr[i] = i; }
	//for (size_t i = 0; i < 10; i++) { cout << arr[i]; } cout << endl;
	delete[] arr;
	return 0;
}
