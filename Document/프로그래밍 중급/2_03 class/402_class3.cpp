//예제 )
//	소비자가 과일장수에게 10000원짜리 사과2개를 구매한다.
//	구매전과 후의 구매자와 판매자의 사과 갯수를 출력하라
// 
//	클래스 구성 Buyer, Seller, 함수 구성 Trade();


#include <iostream>
using namespace std;

class CBuyer  //객체로 데이타와 기능을 캡슐화
{
	int money = 10000;
	int apple = 0;
public:
	void Buy(int _money, int _apple) {
		money -= _money; apple += _apple;
	}
	void Show() {
		cout << money << ", " << apple << endl;
	}
};

class CSeller
{
	int money = 0;
	int apple = 10;
public:
	void Sell(int _money, int _apple) {
		money += _money; apple -= _apple;
	}
	void Show() {
		cout << money << ", " << apple << endl;
	}
};

void Trade(CBuyer& buyer, CSeller& seller, int price, int applenum)
{
	buyer.Buy(price, applenum);
	seller.Sell(price, applenum);
}

int main()
{
	CBuyer buyer;
	CSeller seller;

	cout << "거래전" << endl;
	buyer.Show();
	seller.Show();

	Trade(buyer, seller, 2000, 2); //거래 

	cout << "거래후" << endl;
	buyer.Show();
	seller.Show();

	return 0;
}

//변수를 private 으로 숨겨보세요.
//클래스의 정보출력은 맴버함수를 활용하세요.


//클래스를 어떻게 정의할 것인가? 
//			- 관련된 것끼리 묶음 (추상화), 캡슐화와 정보은닉
// 
//정의하고자 하는 문제의 분석 
//			- 대상 - 객체(클래스)
//			- 속성 - 데이타(변수), 기능(함수), 

//클래스 관계를 구성하기 
//	- 1.인자전달(연관), 2.관련클래스 선언(구성), 3.콘트롤러(집합.메니저)
//	- 클래스 다이어그램, UML

//프로그램 설계 요령
// 
//  내용(정보), 입출력, 프로세서 진행 을 분리하라 ***
//  MVC - model, view, controll - 어떤 대상을 어떻게 처리하고 어떻게 보여줄 것인가?
//  UI, Contents, Manager, Display, Resource, Rule, Flow

//추가 예제
// 
//  두 정수 4칙연산을 하는 Calculator 클래스 만들기
// 
//  게임 플레이어가 몬스터를 사냥한다. 
//  사냥전과 후의 플레이어와 몬스터의 HP를 출력하라
