// 문제 // 아래코드에서 에러가 발생하는 이유는?

#include <iostream>
using namespace std;

class Foo
{
	int bar;
public:
	int& Get() const { return bar; }	//error 이유는?
};

int main(void)
{
	return 0;
}

//레퍼런스를 리턴하면 
//   클래스의 내부 상태(bar 멤버 변수)를 바꾸지 않는다는 것(const)을 보장할 수 없기 때문이다. 
//	 따라서 const를 빼던가, 리턴 타입에 const를 추가해야 한다