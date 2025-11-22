//소멸자	- 객체 소멸할 때 호출되는 함수
//		소멸자에서 해제 처리

//클래스에 맴버로 포인터변수가 있는 경우
//객체내부 - 동적할당과 해제 예시 ***

/*
	//이름,나이 를 저장 출력하자
	int main(void)
	{
		char name[100]  = "Lee dong su";
		int age			= 29;
	}

	//이름,나이를 저장 출력하는 객체 만들기
	int main(void)
	{
		CPerson man1("Lee dong su", 29);
		CPerson man2("Kim min woo", 41);
		man1.ShowInfo();
		man2.ShowInfo();
		return 0;
	}
*/

//맴버에 포인터변수를 선언하고 동적할당을 하는 경우 ----------------------

#include <iostream>
using namespace std;

class CPerson
{
private:
	char* name;			//맴버가 포인터로 선언됨 
	int		age;
public:
	CPerson(const char* _name, int _age)
	{
		int len = strlen(_name) + 1;
		name = new char[len]; strcpy_s(name, len, _name);	//new
		age = _age;
	}
	~CPerson()
	{
		delete[] name;										//delete
	}

	void Show() const
	{
		cout << "이름: " << name << " 나이: " << age << endl;
	}
};

int main(void)
{
	char name1[] = "Lee dong su";
	char name2[] = "Kim min woo";
	CPerson man1(name1, 29);
	CPerson man2(name2, 41);
	man1.Show();
	man2.Show();

	return 0;
}

//맴버에 포인터변수가 있는 경우 - 해제 여부를 주의하라 ***


//RAII 패턴 --------------------------------------------------------------------
//	리소스 획득은 초기화다. 
//  (Resource Acquisition Is Initialization)  ***
//	자원의 안전한 사용을 위해 객체가 쓰이는 스코프를 벗어나면 자원을 해제해주는 기법
// 
//	stack에 할당된 자원은 
//	자신의 scope가 끝나면, 메모리가 해제되며 destructor가 불린다는 원리를 이용 ***



//연습)
// 아래처럼 간단하게 할 수 있지만, 
// 예외 발생하면 fclose를 호출하지 않고 종료되는 위험 존재
// RAII 패턴으로 수정하세요.

#include <iostream>
#include <cstdio>
using namespace std;

void UseFile() {
	FILE* file = nullptr;
	errno_t err = fopen_s(&file, "./test.txt", "w+");
	// Do something  //여기서 예외 발생하면 ????
	if (file != nullptr) fclose(file);
}

int main()
{
	UseFile();
}

/*
//예시) 객체로 구현 (RAII 패턴) ---------------------------

class CFile final
{
public:
	CFile(const std::string& path)
	{
		errno_t err = fopen_s(&file_, path.c_str(), "w+");	//
	}
	~CFile()
	{
		fclose(file_);	//
	}

private:
	FILE* file_ = nullptr;
};

void UseFile() {
	string path = "./test.txt";
	CFile fileobj(path);
}

int main()
{
	UseFile();
}

*/
