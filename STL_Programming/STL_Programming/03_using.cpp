/*
	[using]

	using문을 활용해 어떠한 namespace를 사용한다고 미리 알리고,
	식별자 사용시 namespace 선언을 생략할 수 있다.

	namespace를 사용하는 방식
	- namespace까지 써서 식별자 사용하기
	- using namespace -> namespace 전체 사용
	- using		      -> namespace 일부 사용
	- namespace 별칭   -> namespace에 별명을 붙여 간략하게 사용
*/

namespace A {
	int dataA;
	void FucnA() {}
}

namespace B
{
	int dataB;
	void FucnB() {}

	namespace BB
	{
		void FucnBB() {}
	}
}

int main()
{
	// namespace 전체 사용
	using namespace A;
	dataA = 1;
	FucnA();

	// namespace 일부 사용
	using B::dataB;
	dataB = 2;
	//FucnB();		// error
	B::FucnB();

	// 별칭
	namespace BF = B::BB;
	BF::FucnBB();
}