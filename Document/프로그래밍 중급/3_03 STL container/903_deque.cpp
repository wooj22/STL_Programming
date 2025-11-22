// deque 데크
//1. 크기가 가변적이다.
//2. 앞과 뒤에서 삽입, 삭제가 좋다.***
//3. 구현이 쉽지 않습니다. Stack과 Queue의 합친 자료구조.
//4. vector와 마찬가지로 랜덤 접근이 가능합니다
//5. 중간에 데이터 삽입과 삭제가 용이하지 않다. 그 위치에서의 앞뒤로의 모두 이동해야되기 때문에 성능 저하.
//이 경우에는 deque보다는 vector가 성능이 더 좋습니다.


#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	deque<int> dq;

	for (int i = 0; i < 5; i++)
		dq.push_back(i + 1);

	// 앞에 추가해보기
	dq.push_front(100);
	dq.push_front(200);

	// 뒤에 추가해보기
	dq.push_back(50);
	dq.push_back(60);


	// 전체적으로 출력해보기
	deque<int>::iterator iter;
	for (iter = dq.begin(); iter != dq.end(); ++iter)
		cout << *iter << ' ';
	cout << endl << endl;

	// 반복문 다음 형태도 가능하다. [n]
	for (deque<int>::size_type i = 0; i < dq.size(); i++) 
		cout << dq[i] << ' ';
	cout << endl << endl;

	// 역순으로 출력해보기
	deque<int>::reverse_iterator rIter;
	for (rIter = dq.rbegin(); rIter != dq.rend(); ++rIter) 
		cout << *rIter << ' ';
	cout << endl;

	// insert case 1 --------------------------
	iter = dq.begin();
	dq.insert(iter, 1000);

	// insert case 2 --------------------------
	iter = dq.begin() + 3;
	dq.insert(iter, 2000);

	//for (deque<int>::size_type i = 0; i < dq.size(); i++) cout << dq.at(i) << ' ';
	//cout << endl << endl;

	// insert case 3 --------------------------
	deque<int> dq2;
	dq2.push_back(11);
	dq2.push_back(22);
	dq2.push_back(33);

	iter = dq.begin();	
	dq.insert(iter, dq2.begin(), dq2.end());

	//for (deque<int>::size_type i = 0; i < dq.size(); i++) cout << dq.at(i) << ' ';
	//cout << endl << endl;


	// erase case 1 --------------------------
	iter = dq.begin();
	dq.erase(iter);

	// erase case 2 --------------------------
	iter = dq.begin() + 3;
	dq.erase(iter, dq.end());

	//for (deque<int>::size_type i = 0; i < dq.size(); i++) cout << dq.at(i) << ' ';
	//cout << endl << endl;


	// sort ------------------------------------
	for (int i = 10; i > 0; i--) dq.push_back(i); //정렬하기 전에 데이터 넣고

	// sort (오름차순)
	sort(dq.begin(), dq.end());

	for (deque<int>::size_type i = 0; i < dq.size(); i++) cout << dq.at(i) << ' ';
	cout << endl << endl;


	return 0;
}