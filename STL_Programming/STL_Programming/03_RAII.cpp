/*
	[ RAII (Resource Acquisition Is Initialization) ]

	자원 획득을 객체의 초기화와 함께 수행하고,
	자원 해제를 객체의 소멸과 함께 처리하는 패턴

	-> 프로그래머가 직접 new/ delete 호출 x
	-> 소멸자에서 알아서 메모리를 해제하기 때문에 메모리 누수 방지
	-> STL 라이브러리는 모두 RAII 패턴으로 구현되어있다.

	RAII 패턴은 기본이다!!!
*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

// file을 자동으로 닫아주는 RAII 클래스
class FileGuard
{
private:
	FILE* file;

public:
	// 생성자에서 자원 획득
	FileGuard(const char* path, const char* mode)
	{
		file = fopen(path, mode);
		if (!file) throw runtime_error("file open failed");
	}

	// 소멸자에서 자원 해제
	~FileGuard()
	{
		if (file) fclose(file);
	}

	FILE* Get() const { return file; }
};

int main()
{
	try {
		FileGuard file("../test.txt", "w");
		fprintf(file.Get(), "Hello RAII!\n");
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	// 소멸자에서 알아서 자원을 해제한다.
}