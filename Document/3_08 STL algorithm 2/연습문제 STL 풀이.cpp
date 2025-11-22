#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

void main()
{
	//---------------------------------------------------------------
	// 다음의 문자열을 vector 에 담아 출력하는 코드를 작성하세요.
	// "apple","melon","banana"

	vector<string>  v = { "apple","melon","banana" };
	for (auto e : v) cout << e << " "; cout << endl;

	//copy 출력-------------------
	//copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

	//---------------------------------------------------------------
	//백터 vec 를 내림차순으로 출력하세요.		//함수객체 사용
	vector<int>  vec = { 1,3,2,7,5,9 };

		//sort(vec.begin(), vec.end(), greater<int>());
		//for (auto it = vec.begin(); it != vec.end(); it++)
		//	cout << "   " << *it;
		//cout << endl;

	//---------------------------------------------------------------
	//백터 v 의 내용 중 10보다 큰 숫자를 제거하는 코드를 작성하세요.	 ***	//erase(), remove_if() 사용
	vector<int>  v = { 11, 3, 25, 71, 5, 9, 12, 7, 89 };

		//bool badValue(int x) {
		//	if (x > 10) return true;
		//	return false;
		//}
		// 
		//v.erase(remove_if(v.begin(), v.end(), badValue), v.end());
		//for (auto e : v) cout << e << " "; cout << endl;

	//---------------------------------------------------------------
	//백터 v 에서 홀수의 개수를 출력하세요 
	vector<int>  v(8) = { 3,2,7,9,4,1,3 }

		//bool is_odd(int num)
		//{
		//	return num % 2 == 1;
		//}
		//total = count_if(v.begin(), v.end(), is_odd);       // count_if
		//cout << " 홀수의 개수는 " << total << endl;

	//---------------------------------------------------------------
	//백터 내용 중 중복을 제거하세요.  //unique 사용  ***
	vector <int> v = { 1,1,2,3,4,5,3,3,5,6 };

		//#include <algorithm>
		//#include <iostream>
		//#include <vector>
		//using namespace std;

		//int main()
		//{
		//	vector <int> v = { 1,1,2,3,4,5,3,3,5,6 };
		//	sort(v.begin(), v.end());
		//	v.erase(unique(v.begin(), v.end()), v.end());
		//	for (const auto& n : v) cout << n << ' ';
		//	cout << endl;
		//	return 0;
		//}

	//---------------------------------------------------------------
	//리스트의 내용 중 10보다 작은 숫자를 제거하는 코드를 작성하세요.	//remove_if() 사용
	list<int> ls = { 11, 3, 25, 71, 5, 9, 12, 7, 89 };

		//bool Predicate(int n){
		//	return n < 10;
		//}
		// 	   
		//ls.remove_if(Predicate);
		//for (auto e : ls) cout << e << " "; cout << endl;


	//---------------------------------------------------------------
	//아래 list 에서 2를 삭제하세요.(람다)
	std::list<int> ls = { 1,2,2,3,2,4,2 };

		//ls.remove_if([](int n) {return n == 2; });

		//---------------------------------------------------------------
	//아래 리스트의 값에 2씩 더한 값을 출력하세요.		// for_each() 사용
	list<int> list3 = { 1,2,3,4,5 };

	//void printAdd2(int a)
	//{
	//	printf("%d\n", a + 2);
	//}

	//for_each(list3.begin(), list3.end(), printAdd2);



	//---------------------------------------------------------------
	// 아래 두 리스트를 합치는 코드를 작성하세요	//합친 결과는 { 1,2,10,20,30,3,4,5 }; //splice() 사용
	list<int> list1 = { 1,2,3,4,5 };
	list<int> list2 = { 10,20,30 };

		//list<int>::iterator iter = list1.begin();
		//++iter;
		//++iter;
		//list1.splice(iter, list2);	//다른 리스트의 원소를 잘라 붙이기

		//for (auto e : list1) cout << e << " "; cout << endl;
		//for (auto e : list2) cout << e << " "; cout << endl;

	//---------------------------------------------------------------
	//아래 리스트의 값에 2씩 더한 값을 출력하세요.		// for_each() 사용
	list<int> list3 = { 1,2,3,4,5 };

		//void printAdd2(int a)
		//{
		//	printf("%d\n", a + 2);
		//}

		//for_each(list3.begin(), list3.end(), printAdd2);


	//---------------------------------------------------------------
	// 합을 구하라. 	 accumulate
	std::vector<int> v2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		//int sum = std::accumulate(v2.begin(), v2.end(), 0);
		//cout << sum <<endl;

	//---------------------------------------------------------------
	// 다음과 같은 이름과 점수가 주어졌을때 데이타를 STL map 을 활용하여, 랭킹을 출력하세요  ***
	// 민수 10000 
	// 수연 5200 
	// 지수 2500
	// 민호 5200

		//multimap<int, string, greater<int> > m;
		//m.insert(make_pair(10000,"민수"));			//m[10000] = "민수";
		//m.insert(make_pair(5200,"수연"));
		//m.insert(make_pair(9800,"지수"));
		//m.insert(make_pair(5200,"민호"));

		//int rank = 1;
		//int count = 0;
		//int old = 9999999;
		//for (auto e : m) {
		//	count++; if (e.first < old) rank = count;
		//	cout << rank << " ";
		//	cout << e.first << " " << e.second << endl;
		//	old = e.first;		
		//}

	//---------------------------------------------------------------
	//(예) 7 이상 10 이하의 숫자가 몇 개인지 출력하세요.
	vector<int> arr = { 1,3,5,5,7,8,8,10,10,11,13 };

		//int main()
		//{
		//	vector<int> arr = { 1,3,5,5,7,8,8,10,10,11,13 };
		//	cout << upper_bound(arr.begin(), arr.end(), 10) - lower_bound(arr.begin(), arr.end(), 7);
		//	return 0;
		//}
}
