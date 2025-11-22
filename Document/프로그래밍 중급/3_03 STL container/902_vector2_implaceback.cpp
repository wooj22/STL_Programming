// vector  //emplace_back

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int size = 3;
	std::vector<int> va(size);

	va.reserve(10);			//statck 에 ptr, size, capacity  //heap 에 데이타 할당  //미리 확보하면 조각을 방지

	for (auto e : va)  cout << e << ' '; cout << endl;

	va.push_back(1);		//O(1)		//copy(Lvalue) 혹은 move(Lvalue)  // (const &T v) or (T&& v)

	va.emplace_back(1);		//O(1)		//바로 생성가능 //reference 리턴(C++17)	//이거 쓰면 됨 *** 

	return 0;
}



//emplace_back은 push_back과 같이 vector의 요소 끝에 원소를 추가하는 함수이다.
// 
//두 함수의 가장 큰 차이점은,
// 
//		push_back은 
//		임시 객체를 '생성' 후 push_back 함수 내부에서 객체 추가를 위해 '복사'를 한 뒤 객체 추가를 한다
// 
//		emplace_back은 객체를 추가할 때 std::vector 내에서 '직접' 객체를 추가하고,
//		임시 객체의 생성과 파괴, 복사(혹은 move)를 하지 않아도 되어 성능상 유리하다는 것이다.

#include <iostream>
#include <vector>
using namespace std;

class SomeClass {
public:
	SomeClass(int a, int b, string s) {}
};

int main()
{
	std::vector<SomeClass> vec;
	vec.push_back(SomeClass(1, 2, "3"));
	vec.emplace_back(1, 2, "3");		//생성자로 넘길 인자를 그냥 emplace_back에 넘겨주면 된다

	return 0;
}

//emplace_back
// 
//   가변인자 템플릿을 사용하여 객체 생성에 필요한 인자만 받은 후, 함수 내에서 객체를 생성해 삽입하는 방식
//   임시 객체를 만들 필요가 없기 때문에, emplace_back 내부에서 삽입에 필요한 생성자 한번만 호출


	#include <iostream>
	#include <vector>
	using namespace std;

	class Item {
	public:
		Item(const int _n) : m_nx(_n) { cout << "일반 생성자 호출" << endl; }
		Item(const Item& rhs) : m_nx(rhs.m_nx) { cout << "복사 생성자 호출" << endl; }
		Item(Item&& rhs) : m_nx(std::move(rhs.m_nx)) { cout << "이동 생성자 호출" << endl; }
		~Item() { cout << "소멸자 호출" << endl; }
	private:
		int m_nx;
	};

	int main() {
		std::vector<Item> v;

		cout << "push_back 호출" << endl;
		v.push_back(Item(3));

		//cout << "emplace_back 호출" << endl;
		//v.emplace_back(3);
	}

//각각 따로 실행 태스트 할 것, 기존 맴버있으면 사이즈 변경으로 복사 발생함
//C++ std::vector push_back 보단 emplace_back 을 사용하자 ***



