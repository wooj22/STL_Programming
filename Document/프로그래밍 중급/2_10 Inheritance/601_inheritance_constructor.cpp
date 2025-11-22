//상속 클래스의 객체 생성은 어떻게 이루어지는가?

//상속 클래스의 생성자 호출 순서
//		파생 호출 -> 기반 호출 -> 기반 실행 -> 파생 실행
 
//생성자는 호출과 실행이 분리된다. 
//		각 생성자에선 객체 자신의 초기화만 해야한다. 즉 기반, 파생은 각각 자신의 생성자로 생성된다.
//		기반 클래스의 멤버 대상의 동적 할당은 기초 클래스의 생성자를 통해서, 
//		소멸 역시 기초 클래스의 소멸자를 통해서

//파생 클래스로 객체를 생성하면
//		파생클래스의 생성자에서 기반 클래스의 생성자를 호출하는 코드를 컴파일러가 생성해 주는 것


#include <iostream>
using namespace std;

class CBase
{
private:
	int baseNum;
public:
	CBase() : baseNum(20) { cout << "CBase()" << endl; }
	CBase(int n) : baseNum(n) { cout << "CBase(int n)" << endl; }

	void ShowBaseData()
	{
		cout << baseNum << endl;
	}
};

class CDerived : public CBase
{
private:
	int derivNum;
public:
	CDerived() : derivNum(30) { 
		cout << "CDerived()" << endl; 
	}
	CDerived(int n) : derivNum(n) { 
		cout << "CDerived(int n)" << endl; 
	}
	CDerived(int n1, int n2) : CBase(n1), derivNum(n2) {	//CBase(n1) - 부모 생성자 호출, 호출안하면 기본 생성자 호출
		cout << "CDerived(int n1, int n2)" << endl;
	}

	void ShowDerivData()
	{
		ShowBaseData();
		cout << derivNum << endl;
	}
};

int main(void)
{
	cout << "case1..... " << endl;
	CDerived dr1;
	dr1.ShowDerivData();

	cout << "case2..... " << endl;
	CDerived dr2(12);
	dr2.ShowDerivData();

	//cout << "case3..... " << endl;
	//CDerived dr3(23, 24);
	//dr3.ShowDerivData();
	return 0;
};


//다음 멤버들은 고유한 처리를 담당하기 때문에 상속의 대상에서 제외된다. 
//
//	- 생성자와 소멸자
//	- 대입 연산자
//	- 정적 멤버
//	- 프렌드 관계지정
 
 
//상속 받은 클래스의 경우 처리 순서 ---------------------------------------

//		Derived( int param) : Base(param), member(param) {  } 

//생성자의 인수를 받는 부분
//생성자 초기화 리스트 부분
//		메모리를 할당 받는다. 부모 생성자를 호출한다. 부모로부터 상속받은 멤버들을 초기화
//자신의 생성자 {} 중괄호 부분 처리
//		자신만의 멤버들을 초기화한다.

//1 메모리 할당(생성자 초기화 리스트에 있는 자기 자신 멤버들은 쓰레기값만 들어있는 상태)
//2 부모 생성자 호출(물려 받은 멤버는 할당 + 초기화까지 완료)
//3 초기화(생성자 초기화 리스트에 있는 자기 자신 멤버들 초기화)
//4 자신의 생성자 내부 { } 중괄호 부분 처리




/*

// Monster 를 상속하는 Boss 만들고, 각각 생성해 보세요. 
//		Monster - int level
//		Boss - int level, int skill
//		주의사항)  : public Monster, protected, 부모 생성자 호출


#include <iostream>
using namespace std;

class Monster
{
protected:		//
	int level;
public:
	Monster(int a) : level(a)				//생성자
	{
		cout << "Monster()" << endl; level = 0;
	}
	void ShowData() { cout << level << endl; }
};

class Boss : public Monster
{
	int skill = 0;
public:
	Boss(int lv, int sk);
	void ShowData();
};
Boss::Boss(int lv, int sk) : Monster(lv), skill(sk)		//생성자
{
	cout << "Boss()" << endl;
}
void Boss::ShowData() {
	cout << level << " " << skill << endl;
}

int main(void)
{
	Boss boss(1, 10);
	boss.ShowData();		//출력은?

	//Monster* m1 = new Boss(1, 10);
	//m1->ShowData();			//출력은?

	return 0;
};

*/
