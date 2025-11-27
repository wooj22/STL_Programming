/*
	[ friend ]

	friend는 외부에서 private/ protected 멤버에 접근하는것을 허용하는 키워드로
	접근할 함수나 클래스를 클래스의 친구(friend)로 등록시키면 된다.
	프렌드에 등록시키는 방법은 'friend + 등록시킬 대상의 원형'을 클래스의 멤버에 선언하면 된다.

	프렌드 등록 가능 종류
	 1. 일반 함수, operator 함수
	 2. 클래스
	 2. 클래스 멤버함수 (구현부를 cpp로 분리해야함)
*/

#include <iostream> 
using namespace std;


class Num {
private:
	int value = 10;

public:
	friend class FriendClass;										// 클래스
	friend void FriendMemberFunc::ShowValue(const Num& obj);	// 멤버함수
	friend void ShowValue(const Num& obj);					    // 일반함수
	friend ostream& operator<<(ostream& os, const Num& obj);    // operator 함수
};

// 클래스 frined
class FriendClass
{
public:
	void ShowValue(const Num& obj)
	{
		cout << obj.value << endl;
	}
};

// 멤버함수 friend
class FriendMemberFunc
{
public:
	void ShowValue(const Num& obj);	// cpp를 분리해야한다.
};

// 일반 함수 frined
void ShowValue(const Num& obj)
{
	cout << obj.value << endl;
}

// operator 함수 friend
ostream& operator<<(ostream& os, const Num& obj)
{
	os << obj.value;
	return os;
}