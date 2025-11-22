//지역변수 a 는 함수의 리턴과 함께 소멸되기 때문에, 
//	계속 참조할 수가 없다. (Dangling reference)

#include <iostream>

int function1() {
	int a = 1;
	return a;
}

int& function2() {
	int a = 2;
	return a;
}

int& function3() {
	int a = 3;
	return a;
}

int main()
{
	//int& c = function1();			//컴파일 에러

	const int& c1 = function1();	//상수 참조자로 받으면 가능
	std::cout << c1 << std::endl;

	int& c2 = function2();			//지역변수를 참조로 받으면 오류 ***
	std::cout << c2 << std::endl;	//여기서 이미 댕글링


	int& c3 = function3();
	std::cout << c2 << std::endl;	//오류 //알기 어려운 버그 발생. 
	std::cout << c3 << std::endl;

	return 0;
}