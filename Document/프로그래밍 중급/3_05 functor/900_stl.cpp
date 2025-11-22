#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// vector의 선언	// 숫자 0 ~ 4 를 vector 로 저장 ---------------
	vector<int> v = { 0,1,2,3,4 };
	vector<int> a(2);			// int 2개 값이 0인 vector
	vector<int> b(2, 1);		// int 2개 값이 1인 vector


	// vector 출력해보기 -----------------------------------------
	for (int i = 0; i < v.size(); i++)  //v.size()
		cout << v[i] << ' ';
	cout << endl;

	// 포인터 이용 출력 // vector<int>::iterator 
	for (auto it = v.begin(); it != v.end(); it++)
		cout << *it << ' ';
	cout << endl;

	// 범위기반 for문
	for (auto e : v) 
		std::cout << e << ' '; 
	cout << endl;

	// // vector의 추가, 삭제 ----------------------------------
	v.push_back(5);		// vector의 추가
	cout << v.size() << endl;

	v.pop_back();		// vector의 삭제
	cout << v.size() << endl;


	// 두번째 값을 7 로 바꿔보자. ------------------------------
	//auto it = v.begin(); it++; *it = 7;
	//for (auto e : v) std::cout << e << ' '; cout << endl;


	return 0;
}


