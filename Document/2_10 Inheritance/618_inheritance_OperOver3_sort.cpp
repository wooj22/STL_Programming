// 상속 활용 // 함수객체를 이용한 함수 전달하기 

/*
	//아래 클래스로 관리되는 정수배열을 내림차순과 오름차순으로 정렬시키기
	class DataStorage		// Storage for int data
	{
	private:
		int* arr;			// pointer for array
		int idx;
		const int MAX_LEN;
	public:
		DataStorage(int arrlen) :idx(0), MAX_LEN(arrlen)
		{
			arr = new int[MAX_LEN];
		}
		void AddData(int num)
		{
			if (idx >= MAX_LEN) return;
			arr[idx++] = num;
		}
		void Show()
		{
			for (int i = 0; i < idx; i++)
				cout << arr[i] << ' ';
			cout << endl;
		}
	}
*/


#include <iostream>
using namespace std;

class SortRule		//상속을 이용해서 공통요소를 묶음
{
public:
	virtual bool operator()(int num1, int num2) const = 0;  //virtual //순수가상(상속 강제)
};

class AscendingSort : public SortRule		// 오름차순
{
public:
	bool operator()(int num1, int num2) const { return num1 > num2; }
};

class DescendingSort : public SortRule		// 내림차순
{
public:
	bool operator()(int num1, int num2) const { return num1 < num2; }
};

class DataStorage		// Storage for int data
{
private:
	int* arr;			// pointer for array
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) :idx(0), MAX_LEN(arrlen)
	{
		arr = new int[MAX_LEN];
	}
	void AddData(int num)
	{
		if (idx >= MAX_LEN) {
			cout << "더 이상 저장이 불가능합니다." << endl;
			return;
		}
		arr[idx++] = num;
	}
	void Show()
	{
		for (int i = 0; i < idx; i++)
			cout << arr[i] << ' ';
		cout << endl;
	}
	void SortData(const SortRule& functor)		//bubble sort //부모형식으로 받음
	{
		for (int i = 0; i < (idx - 1); i++) {
			for (int j = 0; j < (idx - 1) - i; j++) {
				if (functor(arr[j], arr[j + 1]))
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
};

int main(void)
{
	DataStorage storage(5);  //배열을 다양한 방식으로 정렬. 
	storage.AddData(40);
	storage.AddData(30);
	storage.AddData(50);
	storage.AddData(20);
	storage.AddData(10);

	storage.SortData(AscendingSort()); //정렬방식을 알려주기.
	storage.Show();

	storage.SortData(DescendingSort());
	storage.Show();

	return 0;
}



//여러 함수객체를 받는 다른 방법은?
//		function<T> 