// 이름과 나이를 관리하는 CPerson 클래스를 완성하세요.
// 맴버 포인터를 RAII 원칙에 맞도록 구현하세요.

#include <iostream>
using namespace std;

class CPerson
{
private:
	char*	name;			//포인터 맴버 선언 
	int		age;
public:
	//생성자
	//생성자()
	//소멸자
	//SetName()
	void Show() const
	{
		cout << "이름: " << name << " 나이: " << age << endl;
	}
};

int main(void)
{

	CPerson man1("Lee", 29); man1.Show();
	CPerson man2("Kim", 41); 
	man2.SetName("Kang"); man2.Show();

	return 0;
}