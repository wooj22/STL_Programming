##include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	stack<int> st;		//stack
	st.push(1);
	st.push(2);
	st.push(3);

	cout << st.top() << endl;		//3

	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}

	stack<int> st2;
	st2.push(10);
	st2.push(20);
	st2.push(30);

	swap(st, st2); //


	// 결과 // st, st2 내용을 확인해 보려면?

	//stack은 컨테이너에 대한 접근을 제한하는 어댑터. 임의접근 안됨.
	//제일 상단이 아닌 나머지 원소들의 확인 / 변경이 불가능

	stack<int> copy1 = st;
	stack<int> copy2 = st2;
	cout << "copy1" << endl;
	while (!copy1.empty()) { cout << copy1.top() << endl; copy1.pop(); }
	cout << "copy2" << endl;
	while (!copy2.empty()) { cout << copy2.top() << endl; copy2.pop(); }

	return 0;
}

//--------------------------------------------------------------------
#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
	queue<int> q;		//queue
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	cout  << "size  : " << q.size() << endl;
	cout  << "empty : " << q.empty() << endl;
	cout  << "front : " << q.front() << endl;
	cout  << "back  : " << q.back() << endl  << endl;

	while (!q.empty())
	{
		cout  << q.front() << endl;
		q.pop();
	}
	return 0;
}
