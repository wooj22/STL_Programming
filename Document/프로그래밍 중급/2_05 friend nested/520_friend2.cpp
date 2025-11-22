//프렌드 클래스 선언하기

//한 클래스가 다른 클래스의 private 및 protected 멤버에 직접 접근할 수 있도록 허용하는 특별한 관계

#include <iostream>
#include <cstring>
using namespace std;

class Girl;

class Boy
{
private:
	int height;
	friend class Girl;				//friend 선언한 클래스는 private 멤버의 접근을 허용
public:
	Boy(int len) : height(len) { }
	void ShowYourFriendInfo(Girl& frn);
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(char* num) { strcpy_s(phNum, num); }
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;					//각자 허용여부를 선언
};

void Boy::ShowYourFriendInfo(Girl& frn)
{
	cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy& frn)
{
	cout << "His height: " << frn.height << endl;
}

int main(void)
{
	char number[] = "010-1234-5678";
	Boy boy(170);
	Girl girl(number);

	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}
