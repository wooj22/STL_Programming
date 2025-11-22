//연습) 클래스 포인터 맴버를 활용해서 목록관리하기

#include <iostream>    
using namespace std;

class MyClass {
	int* ptr = nullptr;
	int size = 0;

public:
	MyClass(int size) { ptr = new int[size]; this->size = size; }
	~MyClass() { delete[] ptr; }

	void Set(int index, int v) { ptr[index] = v; }
	void Print() {
		for (size_t i = 0; i < size; i++) std::cout << ptr[i] << " ";
		std::cout << std::endl;
	}

	void Add(int n) {
		//내용을 추가하세요.
	}
	void Remove(int n) {
		//내용을 추가하세요.
	}
};

int main()
{
	MyClass myclass(3);  // 3
	myclass.Set(0, 1);
	myclass.Set(1, 2);
	myclass.Set(2, 3);
	myclass.Print();

	myclass.Add(4);		 // ptr 사이즈 변화 필요 
	myclass.Print();
}