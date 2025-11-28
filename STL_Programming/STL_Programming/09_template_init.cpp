/*
*	템플릿의 T에는 다양한 자료형이 올 수 있다.
	 - 기본형(int, float)
	 - 클래스(std::string, vector<int>)
	 - POD 타입(struct)
	 - 포인터
	 - 사용자 정의 클래스
	
	이때 어떤 T가 와도 “안전한 기본값”을 만드는 표준적인 초기화 방식이 필요하다.
	=> T(), T{}
	   : T의 기본값을 만들라는 뜻
*/

// 함수 템플릿 안에서 T의 기본형 초기화
template<typename T>
void foo()
{
	T x1 = T();
	T x2 = T{};
}


// 클래스 템플릿의 T 멤버 기본형 초기화
template <typename T>
class MyClass
{
private:
	T x1;
	T x2;
public:
	MyClass() : x1(), x2{}
	{}
};