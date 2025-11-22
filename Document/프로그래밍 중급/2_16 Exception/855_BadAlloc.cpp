//메모리 할당 에러 처리하기

#include <iostream>
#include <new>

using namespace std;

int main(void)
{
	int num = 0;

	try
	{
		while (1)
		{
			num++;
			cout << num << "번째 할당" << endl;
			new int[10000][10000];
		}
	}
	catch (bad_alloc& bad)			//bad_alloc
	{
		cout << bad.what() << endl;
		cout << "더 이상 할당 불가!" << endl;
	}

	return 0;
}

// bad_alloc 
//		new는 malloc과는 다르게 new는 메모리 할당 실패시 익셉션 bad_alloc을 리턴한다

// nothrow
//		리턴 값을 malloc처럼 널포인터로 하고 싶을 때
//		nothrow를 사용하면 익셉션(bad_alloc)대신 nullptr를 리턴해줍니다.

#include <iostream>
using namespace std;

int main()
{
	int* pnum = new(nothrow) int;
	if (pnum == nullptr)
		cout << "메모리 할당 실패!\n";
}
