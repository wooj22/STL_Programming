// 함수객체를 이용한 함수 전달하기.

// int 를 비교하는 함수.		 함수 전달해서 사용. (함수 포인터로 전달 받음 - 포인터로 호출 )
// int 를 비교하는 함수객체.  함수객체 전달해서 사용. (객체로 전달 받음 - 객체를 함수처럼 호출 )

#include <iostream>
using namespace std;

bool Compare(int num1, int num2) { return num1 > num2; }

class Sort
{
public:
	bool operator()(int num1, int num2) const {	return num1 > num2;	}
};

class DataStorage		// Storage for int data
{
private:
	int*	arr;		// pointer for array
	int		index;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) :index(0), MAX_LEN(arrlen)
	{
		arr = new int[MAX_LEN];
	}
	void AddData(int num)
	{
		if (index >= MAX_LEN) {	cout << "저장 불가" << endl; return;	}
		arr[index++] = num;
	}
	void Show()
	{
		for (int i = 0; i < index; i++)	cout << arr[i] << ' ';
		cout << endl;
	}

	void Sort(const Sort& functor)		//bubble sort 구현
	{
		for (int i = 0; i < (index - 1); i++) {
			for (int j = 0; j < (index - 1) - i; j++) {
				if (functor(arr[j], arr[j + 1]))
				{
					std::swap(arr[j], arr[j + 1]);
				}
			}
		}
	}

	/*
		void AscendingSort(const AscendingSort& functor) {
		}
		void DescendingSort(const DescendingSort& functor) {
		}
	*/
};

int main(void)
{
	DataStorage storage(5);  //배열을 다양한 방식으로 정렬. 
	storage.AddData(40);
	storage.AddData(20);
	storage.AddData(30);
	storage.AddData(10);

	storage.Sort(Compare);  //
	storage.Sort(Sort());

	storage.Show();

	/*
	//다양한 방식의 정렬방식을 알려주기.
	
	storage.Sort( Compare );

	storage.Sort( Sort() );

	storage.AscendingSort(AscendingSort());

	storage.DescendingSort(DescendingSort());

	*/
	return 0;
}


/*
class AscendingSort  // 오름차순
{
public:
	bool operator()(int num1, int num2) const {
		return num1 > num2;
	}
};

class DescendingSort  // 내림차순
{
public:
	bool operator()(int num1, int num2) const {
		return num1 < num2;
	}
};
*/