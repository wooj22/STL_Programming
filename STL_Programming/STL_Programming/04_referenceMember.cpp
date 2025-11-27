// 클래스 멤버에 참조 변수를 사용하는 경우
// 참조는 재할당이 불가능하기 떄문에 my.ref = a;와 같은 표현이 안된다.
// 때문에 참조 멤버 변수는 선언과 동시에 꼭 "초기화 리스트로" 초기화 해야한다
// (안그럼 에러)


#include <iostream>
using namespace std;

class Num
{
public:
	int& ref;			// rvalue가 오면 댕글링
	const int& ref_c;	// rvalue도 가능

public:
	Num() = default;
	Num(int r, int cr) : ref(r), ref_c(cr) {}	// 반드시 초기화 리스트로 참조 변수 초기화
	void Show() { cout << ref << " " << ref_c << endl; }
};

int main()
{
	int a = 10;
	Num my(a, 20);	// 20을 cosnt&로 받아서 수명 연장. ok
	my.Show();
}