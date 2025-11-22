//set 연습

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	set<int> set1;

	set1.insert(1);
	set1.insert(10);
	set1.insert(5);
	set1.insert(8);
	set1.insert(3);
	set1.insert(6);
	set1.insert(7);
	set1.insert(2);		//값 추가

	set<int>::const_iterator iter;
	cout << "set1: ";
	for (iter = set1.begin(); iter != set1.end(); iter++) cout << *iter << ' ';
	cout << endl << endl;

	// insert case 2 --------------------------
	set<int> set2;
	set2.insert(42);
	set2.insert(23);
	set2.insert(17);
	set2.insert(13);
	set1.insert(set2.begin(), set2.end());  // 범위지정 추가 

	// insert case 3 --------------------------
	iter = set1.begin();
	iter++;
	set1.insert(iter, 20); //특정위치 추가


	// search case 1 --------------------------
	set<int>::iterator FindIter = set1.find(20);	//find
	if (FindIter != set1.end())
	{
		cout << "set1에 20이라는 key가 존재합니다." << endl;
	}
	cout << endl;;

	// search case 2 --------------------------
	set<int>::size_type i = set1.count(10);			//count
	if (i != 0)	{
		cout << "set1에 10이라는 key가 존재합니다." << endl;
	}
	cout << endl;


	// erase case 1 --------------------------
	set1.erase(set1.begin());					

	// erase case 2 --------------------------
	set1.erase(set1.begin(), set1.end());


	// 복사 가능 ***
	set<int> set3 = set1;						// =


	// lower_bound, upper_bound, equal_range 
	//		lower_bound : key값보다 같거나 큰 가장 작은 정수 값
	//		upper_bound : key값을 초과하는 가장 첫 번째 원소의 위치

	pair<set<int>::const_iterator, set<int>::const_iterator> p1, p2;

	p1 = set3.equal_range(3);
	cout << "key 3의 lower_bound : " << *(p1.first) << endl;
	cout << "key 3의 upper_bound : " << *(p1.second) << endl;
	p2 = set3.equal_range(15);
	cout << "key 15의 lower_bound : " << *(p2.first) << endl;
	cout << "key 15의 upper_bound : " << *(p2.second) << endl;
	cout << endl;

	// string 기반 ---------------------------------------------------

	set<string> set4;
	set<string> set5;

	set4.insert("AAA");
	set4.insert("BBB");
	set4.insert("CCC");
	set4.insert("DDD");

	set5.insert("AAA");
	set5.insert("BBB");
	set5.insert("CCC");
	set5.insert("FFF");

	set<string>::const_iterator iter4;
	cout << "set4 : ";
	for (iter4 = set4.begin(); iter4 != set4.end(); iter4++) cout << *iter4 << ' ';
	cout << endl << endl;

	cout << "set5 : ";
	for (iter4 = set5.begin(); iter4 != set5.end(); iter4++) cout << *iter4 << ' ';
	cout << endl << endl;

	// 비교 ***

	if (set4 == set5)	cout << "두 set은 같습니다." << endl;
	else				cout << "두 set은 다릅니다." << endl;
	cout << endl;

	if (set4 > set5)	cout << "set5가 사전적으로 앞입니다." << endl;
	else				cout << "set5가 사전적으로 뒤입니다." << endl;
	cout << endl;
	

	set<string>::iterator iter5 = set4.find("DDD");	// set4에서는 "DDD" 문자열을 삭제
	set4.erase(iter5);		

	iter5 = set5.find("FFF");	// set5에서는 "FFF" 문자열을 삭제
	set5.erase(iter5);
	
	if (set4 == set5)	cout << "두 set은 같습니다." << endl;
	else				cout << "두 set은 다릅니다." << endl;
	cout << endl;

	return 0;
}
