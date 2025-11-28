/*
	[ 변수 템플릿 (variable template) ]

	C++14부터는 템플릿 기반으로 변수의 선언이 가능하다.
	타입별 상수 생성, 타입 traits 단순화(이건 아직 잘 모름)에 유용하다.
*/


// 타입별로 상수를 만들고싶을떄 원래 이렇게 했다.
const double pi_d = 3.141592;
const float  pi_f = 3.141592f;


// 하지만 변수 템플릿을 사용하면?
// T가 들어오면 전역 변수 pi<T>를 하나 생성하여 반환하는 변수 템플릿
template <typename T>
constexpr T pi = (T)3.141592f;

int main()
{
	// 원하는 타입으로 변수를 찍어내는게 간단해진다.
	int pi1 = pi<int>;
	double pi1 = pi<double>;
}