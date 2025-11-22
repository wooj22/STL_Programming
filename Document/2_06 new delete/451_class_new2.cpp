// new로 객체 초기화하기
//		new는 메모리를 할당할 뿐만 아니라 객체를 생성한다.

	#include <iostream>
	using std::cout;
	using std::endl;

	class Test
	{
	public:
		Test() { std::cout << "Test 생성자 호출됨!\n"; }
	};

	int main()
	{
		Test* ptest = new Test;			//new로 객체 생성, 초기화
		delete ptest;
		return 0;
	}

// 맴버 int num; 추가, 생성자(), 생성자(int) 만들고, new 로 동적생성해 보세요.

	class Test
	{
		int num;
	public:
		Test() : num(0)	{
			cout << "Test 생성자 호출됨 num:\t" << num << endl;
		}
		Test(int num) : num(num) {
			cout << "Test 생성자 호출됨 num:\t" << num << endl;;
		}
	};
	int main()
	{
		Test* ptest1 = new Test;		//new는 객체를 생성한다 ***
		Test* ptest2 = new Test(10);	//생성, 초기화

		delete ptest1;
		delete ptest2;

		return 0;
	}

// Circle 클래스를 선언하고, 
// int radius, setRadius(int), getArea() 만들어 보세요.
// Circle(), Circle(int r) 만들어 보세요.
// 
// 객체 3개를 담을 배열선언 후 , 각각 반지름 2,3,5로 설정, 출력하세요.
// 
//		Circle array[3];
// 
// 객체 3개를 담을 배열을 동적으로 할당한 후, 각각 반지름 2,3,5로 설정 후 넓이를 출력하세요.
// 
//		Circle* pArray = new Circle[3];										
// 
// 객체포인터 배열로 선언하여, 각각 반지름 2,3,5로 객체 생성 후 넓이를 출력하세요.
// 
//		Circle* pArray[3];

/*
	//--------------------------------------------------------------------------

	#include <iostream>
	using std::cout;
	using std::endl;

	class Circle	// int radius, setRadius(int), getArea() 만들어 보세요.
	{
		int radius = 0;
	public:
		Circle() {}
		Circle(int r):radius(r) {}
		void setRadius(int r) { radius = r; }
		float getArea() { return radius * radius *3.14f; }
	};

	int main(int argc, char* argv[])
	{
		//정적할당 --------------------------------------------------------------

		Circle array[3] { Circle(2), Circle(3), Circle(5) };
		for (int i = 0; i < 3; i++) {
			cout << array[i].getArea() << endl;
		}

		//동적할당 : 객체배열생성  -----------------------------------------------

		Circle* pArray = new Circle[3]; //heap 영역에 3개짜리 객체 배열 생성
		pArray[0].setRadius(2);
		pArray[1].setRadius(3);
		pArray[2].setRadius(5);
		for (int i = 0; i < 3; i++) {
			cout << pArray[i].getArea() << endl;
		}
		delete[] pArray;                    //객체배열 반환


		//객체포인터 배열 -------------------------------------------------------

		Circle* pArray2[3] { new Circle(2),  new Circle(3),  new Circle(5) };
		for (int i = 0; i < 3; i++) {
			cout << pArray2[i]->getArea() << endl;
		}			

		delete pArray2[0];					//객체 각각 반환
		delete pArray2[1];
		delete pArray2[2];

		
		//추가,삭제가 일어난다면 ??	
		// Circle(2) 삭제, Circle(6), Circle(7) 추가하는 코드를 작성해보세요.


		//system("PAUSE");
		return EXIT_SUCCESS;
	}


*/


-----------------------------------------------------------------------------------------------------------
// bad_alloc 
//		new는 malloc과는 다르게 new는 메모리 할당 실패시 익셉션 bad_alloc을 리턴한다

#include <iostream>
int main() {
	try
	{
		int* pary = new int[3];
	}
	catch (std::bad_alloc & ba)
	{
		std::cerr << "bad_alloc이 발생했습니다: " << ba.what() << '\n';
	}
	return 0;
}

-----------------------------------------------------------------------------------------------------------
// nothrow
//		리턴 값을 malloc처럼 널포인터로 하고 싶을 때

#include <iostream>
using namespace std;
int main()
{
	int* pnum = new(nothrow) int;
	if (pnum == nullptr)
		cout << "메모리 할당 실패!\n";
}
//nothrow를 사용하면 익셉션(bad_alloc)대신 nullptr를 리턴해줍니다.
