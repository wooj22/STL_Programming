//std::initializer_list
//		컨테이너의 초기화를 편리하게 할 수 있도록 도와주는 템플릿

//	std::initializer_list 객체를 인수로 받는 '생성자'를 구현해 놓으면, 
//	대입 연산자 = 와 함께 { } 중괄호를 사용해서 생성자를 호출할 수 있다.
//	이때의 중괄호가 바로 std::initializer_list 객체가 되기 때문.

#include <iostream>
#include <initializer_list>
#include <vector>
using namespace std;

class IntArray
{
private:
	unsigned m_length = 0;
	int* m_data = nullptr;

public:
	IntArray(unsigned length) : m_length(length)
	{
		m_data = new int[length];
	}

	IntArray(const std::initializer_list<int>& list) : IntArray(list.size()) //initializer_list // 위임생성자
	{
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	~IntArray()
	{
		delete[] this->m_data;
	}

	friend ostream& operator << (ostream& out, IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << " ";
		out << endl;
		return out;
	}
};

int main()
{
	auto intarr = { 1,2,3,4,5 };			//

	IntArray int_array = { 1,2,3,4,5 };		// 중괄호로 생성자 호출이 가능해짐!

	//IntArray int_array { 1,2,3,4,5 };		// = 대입 연산자는 빼도 상관없다.

	cout << int_array << endl;

	return 0;
}

//initializer_list 템플릿은 대괄호를 지원하지 않는다.
//   std::initializer_list 객체에 첨자 []를 쓸 수 없다

//initializer_list 템플릿은 얕은 복사를 한다. ***
//	std::initializer_list 객체끼리 복사해야 하는 경우가 있다면 
//	깊은 복사를 위해 따로 대입 연산자 오버로딩을 구현해주자.  

//std::initializer_list 타입의 참조 객체를 인수로 받는 생성자는 
//	생성자 초기화에 사용되는 {}보다 우선된다. ***
//	()말고 {}로 생성자를 호출하는게 자동 형변환을 막아주는 더 엄격한 호출

