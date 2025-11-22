// Is a 관계 - 상속관계

// 상속을 하기 적합한 경우는? ------------------------------------------------------

// is a 관계일 때 상속하기 적합 ( 관계형성, 추상화 관련 )
//		EX) 동물,고양이 (is a 관계) 
//		EX) 총,경찰관 (is a 관계가 아니다 -> has a 관계)


//Computer - Notebook - Tabletbook

#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
private:
	char owner[50];
public:
	Computer(const char* name) { strcpy_s(owner, name);	}

	void Calculate() {
		cout << "계산합니다." << endl;
	}
};

class Notebook : public Computer
{
private:
	int battary;
public:
	Notebook(const char* name, int charg) : Computer(name), battary(charg) { }

	void UseBattary() { battary -= 1; }
	void Charging() { battary += 5; }
	void MovingCalculate()
	{
		cout << "이동하면서 ";
		Calculate();
		UseBattary();
	}
};

class Tabletbook : public Notebook
{
public:
	Tabletbook(const char* name, int charg) : Notebook(name, charg) { }

	void Write() {
		cout << "필기 내용을 처리합니다." << endl;
	}
};

int main(void)
{
	Notebook nc("이정우", 5);
	Tabletbook tn("김수영", 5);
	nc.MovingCalculate();
	tn.Write();
	return 0;
}