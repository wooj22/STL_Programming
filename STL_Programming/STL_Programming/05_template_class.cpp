/*
	- 클래스 템플릿
		클래스를 템플릿으로 만들 수 있다.
		이 경우 클래스의 타입은 Class<T>이며,
		선언부와 구현부를 분리할 경우 형식을 제대로 선언해주어야한다.

	- 멤버함수 템플릿
		일반 템플릿 함수처럼 클래스의 멤버함수를 템플릿으로 만들 수 있다.
		선언부와 구현부를 분리할 경우 클래스 타입과 함수 템플릿 형식을 모두 선언해주어야한다.

*/

#include <iostream>
#include <typeinfo>
using namespace std;

// 클래스 템플릿 Point<T>
template <typename T>
class Point											
{
private:
	T xpos, ypos;

public:
	// 클래스 템플릿의 멤버 함수
	Point(T x = 0, T y = 0);
	void ShowPosition() const;

	// 클래스 템플릿의 멤버 함수 템플릿
	template <typename U>
	void PrintType(U value) const;
};


// template <typename T>
// Point<T>::
template <typename T>									
Point<T>::Point(T x, T y) : xpos(x), ypos(y) {  }		


// template <typename T>
// Point<T>::
template<typename T>
void Point<T>::ShowPosition() const
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}

// template <typename T>		// 클래스 템플릿 지정
// template <typename U>		// 멤버 함수 템플릿 지정
// Point<T>::
template <typename T>
template <typename U>
void Point<T>::PrintType(U value) const
{
	cout << typeid(value).name() << endl;
}

int main(void)
{
	// Point<int>
	Point<int> pos1(3, 4);
	pos1.ShowPosition();

	// Point<double>
	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	// Point<char>
	Point<char> pos3('P', 'F');
	pos3.ShowPosition();

	// 멤버함수 템플릿
	pos1.PrintType(1);
	pos1.PrintType(1.0);

	return 0;
}
