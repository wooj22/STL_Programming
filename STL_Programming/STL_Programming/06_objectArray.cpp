// 다양한 객체의 메모리 관리 


#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	int age;
	string name;

	Person() : age(0), name("") {}
	Person(int a, string n) : age(a), name(n) {}
};

int main()
{
	/*------------- 정적 (stack) -----------------*/
	// 단일 객체
	Person p1(24, "우정");

	// 객체 배열
	Person arr1[3] = {
		{24, "양우정"},
		{24, "양우정"},
		{24, "양우정"}
	};


	/*------------- 동적 (heap) -----------------*/
	// 포인터
	Person* p2 = new Person(24, "양우정");
	delete p2;

	// 포인터 배열 
	// arr2는 단순한 배열임. 안에 들어있는 원소가 동적 객체일 뿐
	Person* arr2[3];
	for (int i = 0; i < 3; i++)
	{
		arr2[i] = new Person(24, "양우정");
	}
	for (int i = 0; i < 3; i++)
	{
		delete arr2[i];
	}

	// 동적 배열 (Person*)
	// arr3은 Person[3]만큼의 메모리를 할당받은 포인터
	// 한번에 가리키는 객체 단위는 Person이다.
	Person* arr3 = new Person[3]
	{
		{24, "양우정"},
		{24, "양우정"},
		{24, "양우정"}
	};

	Person** arr4 = new Person* [2];
	for (int i = 0; i < 2; i++) {
		arr4[i] = new Person[3]
		{
			{24, "양우정"},
			{24, "양우정"},
			{24, "양우정"}
		};
	}
	for (int i = 0; i < 2; i++) {
		delete[] arr4[i];
	}
	delete[] arr4;


	// 배열 포인터 (Person (*)[3])
	// 2차원 배열로 작동하여
	// 한번에 가리키는 객체 단위 Person[3]
	Person(*arr5)[3] = new Person[1][3]
	{
		{ Person{24, "양우정"}, Person{24, "양우정"}, Person{24, "양우정"} }
	};
	arr5[0][0].age = 25;
	delete[] arr5;
}