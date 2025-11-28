/*
	다형성을 이용한 sort 함수객체 전달
*/

#include <iostream>
using namespace std;

// 추상 클래스
class SortRule
{
public:
	virtual bool operator()(int n1, int n2) const = 0;
};

// 오름차순 함수객체
class AscendingSort : public SortRule
{
public:
	bool operator()(int n1, int n2) const override
	{
		return n1 > n2;		// 앞의 원소가 더 크다면 swap -> 큰값이 뒤로감
	}
};

// 내림차순 함수객체
class DescendingSort : public SortRule
{
public:
	bool operator()(int n1, int n2) const override
	{
		return n1 < n2;		// 앞의 원소가 더 작다면 swap -> 작은 값이 뒤로 감
	}
};

class DataStorage
{
private:
	int* array;
	int index;
	const int MAX_LEN;

public:
	DataStorage(int arrlen) :index(0), MAX_LEN(arrlen)
	{
		array = new int[MAX_LEN];
	}

	void AddData(int num)
	{
		if (index >= MAX_LEN) {
			cout << "더 이상 저장이 불가능합니다." << endl;
			return;
		}
		array[index++] = num;
	}

	void Show()
	{
		for (int i = 0; i < index; i++)
			cout << array[i] << ' ';
		cout << endl;
	}

	// buble sort
	// 다형성을 활용하여 부모타입으로 받고 객체 타입으로 처리
	void Sort(const SortRule& functor)
	{
		for (int i = 0; i < (index - 1); i++){
			for (int j = 0; j < (index - 1); j++){
				if (functor(array[j], array[j + 1]))
				{
					// swap
					int temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}
	}
};

int main(void)
{
	DataStorage storage(5); 
	storage.AddData(40);
	storage.AddData(30);
	storage.AddData(50);
	storage.AddData(20);
	storage.AddData(10);

	storage.Sort(AscendingSort());
	storage.Show();
	storage.Sort(DescendingSort());
	storage.Show();

	return 0;
}
