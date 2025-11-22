// vector - 가변 배열, 동적 배열
//		1. 저장할 데이터의 개수가 가변적이라면 vector를 사용하는 편이 훨씬 편하고 빠릅니다.
//		2. 중간에 데이터 삽입이나 삭제가 없을 때
//		3. 랜덤 접근이 가능합니다.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// vector의 선언  
	vector<int> v;					// 아무것도 없는 vector
	vector<int> a(2);				// int 2개, 값이 0 로 초기화
	vector<int> b(2, 1);			// int 2개, 값이 1 로 초기화
	vector<int> c = { 1, 2, 3 };    // int형 백터 생성 후 1, 2, 3 으로 초기화

	v.push_back(1);					// vector의 추가 
	v.push_back(2);
	//cout << v.front() << endl;
	//cout << v.back() << endl;
	v.pop_back();					// vector의 삭제 
	
	// Vector의 초기화, 2차원 백터
		
	vector<int> v[] = { { 1, 2}, {3, 4} };  //int형 백터 배열 생성(행은 가변이지만 열은 고정)
	vector<vector<int>> v;					//2차원 백터 생성(행과 열 모두 가변)

	vector<int> v = { 1, 2, 3, 4, 5 };      //백터 범위를 5로 지정하고 정수 10으로 초기화
	v.assign(5, 10);						//output : 10 10 10 10 10


	// vector에 1~10을 넣고 출력해보기 -----------------------------------------
	for (int i = 0; i < 10; i++)	v.push_back(i + 1);

	for (int i = 0; i < 10; i++)	cout << v[i] << ' ';	cout << endl;
	for (int i = 0; i < 10; i++)	cout << v.at(i) << ' ';	cout << endl;
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) cout << *iter << ' ';	cout << endl;
	for (auto iter = v.begin(); iter != v.end(); ++iter) cout << *iter << ' ';	cout << endl;

	// Vector의 Iterators 
	{
		vector<int> v = { 1, 2, 3, 4 };

		vector<int>::iterator itor = v.begin();
		for (; itor != v.end(); itor++)
			cout << *itor << endl;			//output : 1 2 3 4

		vector<int>::reverse_iterator itor2 = v.rbegin();	//역방향 출력
		for (; itor2 != v.rend(); itor2++)
			cout << *itor2 << endl;			//output : 4 3 2 1

		for_each(v.begin(), v.end(), [&](int& n) {
			cout << n << endl;				//output : 1 2 3 4
			});

		for_each(v.rbegin(), v.rend(), [&](int& n) {
			cout << n << endl;				//output : 4 3 2 1
			});
	}

	//Vector Element access(백터의 요소 접근)
	{
		vector<int> v = { 1, 2, 3, 4 };

		cout << v.front() << endl;        //output : 1
		cout << v.back() << endl;         //output : 4
		cout << v.at(1) << endl;          //output : 2
		cout << v[2] << endl;             //output : 3​

		//※ vector의 at과[]에 대한 차이점
		//	at은 범위를 검사하여 범위 밖의 요소에 접근 시 예외처리를 발생시킴 (디버깅)
		//	백터는 효율을 중점으로 둔 라이브러리 함수여서 보통 []를 권장
	}
	//Vector에 요소 삽입
	{
		vector<int> v;

		v.push_back(10);
		v.push_back(20);				//v = { 10, 20 }

		v.insert(v.begin() + 1, 100);   //v = { 10, 100, 20 }

		v.pop_back();					//v = { 10, 100 }

		v.emplace_back(1);				//v = { 10, 100, 1 }
		v.emplace_back(2);				//v = { 10, 100, 1, 2 }
		v.emplace(v.begin() + 2, -50);  //v = { 1, 100, -50, 1, 2 }

		//empace 와 emplace_back 은 백터 내부에서 값들을 생성

		v.erase(v.begin() + 1);			// v = { 1, -50, 1, 2 }
		v.resize(6);					// v = { 1, -50, 1, 2, 0, 0 }
		v.clear();						// v = empty()  
	}
	//삭제 
	{
		vector<int>v = { 1, 2, 3 };

		v.erase(v.begin());		
		//1. v.erase(삭제하려는 값의 위치);
		//2. v.erase(first, last);	// 범위		

		// 모두 삭제 
		v.clear();

		// empty 확인해 보기 
		if (v.empty())	cout << "vector가 비어있어요." << endl;
		else			cout << "vector에 들어있네요." << endl;
	}

	// vector의 크기 
	//		size()는 백터가 생성된 크기이며 
	//		capacity()는 백터의 최대 할당 크기
	{
		vector<int>v = { 1, 2, 3 };

		// size 알아보기 
		cout << "vector의 현재 size : " << v.size() << endl;

		// capacity 알아보기 
		cout << "vector의 capacity : " << v.capacity() << endl;


		//size()는 백터가 생성된 크기이며 capacity()는 백터의 최대 할당 크기 ***

		// capacity 늘려보기 
		for (int i = 0; i < 20; i++) v.push_back(i + 1);
		//for (auto iter = v.begin(); iter != v.end(); ++iter) cout << *iter << ' '; cout << endl;	
		cout << "vector의 capacity : " << v.capacity() << endl;

		//백터의 크기가 capacity()의 크기를 초과해 버린다면 reallocate(재할당)이 발생.
		//reallocate이 자주 일어나는 현상을 막기 위해서 reserve()라는 함수를 사용

		// reserve() 알아보기

		vector<int> v2;
		v2.reserve(20);				// 프로그래머가 직접 메모리 크기를 할당
		cout << "vector2의 capacity : " << v2.capacity() << endl;

		// shrink_to_fit()			//남은 공간을 잡아주는 함수
		v2.shrink_to_fit();
		cout << "vector2의 capacity : " << v2.capacity() << endl;
	}
	// vector의 크기 Test
	{
		vector<int>v = { 1, 2, 3, 4 };

		cout << v.size() << endl;		//output : 4
		cout << v.capacity() << endl;	//output : 10 (컴파일 환경에 따라 달라질 수 있음)

		v.reserve(6);
		cout << v.capacity() << endl;	//output : 6
		cout << v.max_size() << endl;	//output : 1073741823(시스템 성능에 따라 달라질 수 있음)

		v.shrink_to_fit();
		cout << v.capacity() << endl;	//output : 4

		cout << v.empty() << endl;		//output : false
		v.clear();
		cout << v.empty() << endl;		//output : true​
	}


	// insert 사용하기 -----------------------------------------

	vector<int> v3;
	v3.push_back(10);
	v3.push_back(20);

	v3.insert(v3.begin(), 5);					// 1. 특정 위치에 추가

	for (int i = 0; i < v3.size(); i++)	cout << v3[i] << ' '; cout << endl;


	// insert 사용하기 ( vector 범위로 넣는 방법 ) 

	vector<int> v4(5, 1);	//1,1,1,1,1
	vector<int>::iterator iter2 = v3.begin(); 
	iter2++; iter2++;
	
	v3.insert(iter2, v4.begin(), v4.end());		// 2. vector 범위로 넣는 방법  

	for (int i = 0; i < v3.size(); i++)	cout << v3[i] << ' '; cout << endl;


	// insert 사용하기 ( 횟수만큼 넣는 방법 ) 

	iter2 = v3.begin();	
	v3.insert(iter2, 2, 100);					// 3. iter2 위치에 100을 2번 넣는다.
	
	for (int i = 0; i < v3.size(); i++)	cout << v3[i] << ' '; cout << endl;


	// erase 사용하기 -----------------------------------------

	iter2 = v3.begin();
	v3.erase(iter2);							// 첫번째 위치 요소 삭제

	for (int i = 0; i < v3.size(); i++)	cout << v3[i] << ' '; cout << endl;

	v3.erase(v3.begin(), v3.end());				// 전 구간 삭제

	for (int i = 0; i < v3.size(); i++)	cout << v3[i] << ' '; cout << endl;

	//size만 줄어들고 capacity(할당된 메모리)는 그대로 남습니다.
	// 
	//erase 함수는 범위와 상관없이 마지막으로 지워진 값의 위치에서 
	//바로 뒤에 있던 값의 새로운 위치의 iterator를 반환해준다.  ***


	// assign 알아보기 -----------------------------------------

	vector<int> v5;
	v5.assign(7, 4);							//특정 원소로 채웁니다.

	for (int i = 0; i < v5.size(); i++)	cout << v5[i] << ' '; cout << endl;

	cout << v5.size() << ' ' << v5.capacity() << endl;

	return 0;
}

/*
vector의 멤버 함수 ----------------------------------------------------------

== vector<int> v; 라고 가정.
== 참조 한다는 것은 해당 데이터를 리턴 한다는 뜻입니다.

v.assign(5, 2);	- 2의 값으로 5개의 원소 할당.

v.at(idx);		- idx번째 원소를 참조합니다. - v[idx] 보다 속도는 느리지만, 범위를 점검하므로 안전합니다.

v[idx];			- idx 번째 원소를 참조합니다. - 범위를 점검하지 않으므로 속도가 v.at(idx)보다 빠릅니다.

v.front();		- 첫번째 원소를 참조합니다.

v.back();		- 마지막 원소를 참조합니다.

v.clear();		- 모든 원소를 제거합니다. - 원소만 제거하고 메모리는 남아있습니다. - size만 줄어들고 capacity는 그대로 남아있습니다.

v.push_back(7);	- 마지막 원소 뒤에 원소 7을 삽입합니다.

v.pop_back();	- 마지막 원소를 제거합니다.

v.begin();		- 첫번째 원소를 가리킵니다. (iterator와 사용)

v.end();		- 마지막의 "다음"을 가리킵니다 (iterator와 사용)

v.rbegin();		- reverse begin을 가리킨다 (거꾸로 해서 첫번째 원소를 가리킵니다) - iterator와 사용.

v.rend();		- reverse end 을 가리킨다 (거꾸로 해서 마지막의 다음을 가리킵니다) - iterator와 사용.

v.reserve(n);	- n개의 원소를 저장할 위치를 예약합니다(미리 동적할당 해놓습니다)

v.resize(n);	- 크기를 n으로 변경한다. - 더 커졌을 경우 default값인 0으로 초기화 한다.

v.resize(n,3);	- 크기를 n으로 변경한다. - 더 커졌을 경우 인자의 값을 3으로 초기화한다.

v.size();		- 원소의 갯수를 리턴한다.

v.capacity();	- 할당된 공간의 크기를 리턴한다. 공간 할당의 기준은 점점 커지면서 capacity를 할당하게 됩니다.

v.insert(2, 3, 4);
- 2번째 위치에 3개의 4값을 삽입합니다. (뒤쪽 요소는 뒤로 밀림)

v.insert(2, 3);
- 2번째 위치에 3의 값을 삽입합니다. 삽입한 곳의 iterator를 반환합니다.

v.erase(iter);
- iter 가 가리키는 원소를 제거합니다.
- size만 줄어들고 capacity(할당된 메모리)는 그대로 남습니다.
- erase는 파라미터 하나를 받을때와 두개를 받을 때 다릅니다.

v.empty()
- vector가 비었으면 리턴 true
- 비어있다의 기준은 size가 0이라는 것이지, capacity와는 상관이없습니다.

v2.swap(v1);
- v1과 v2의 원소와 capacity 바꿔줍니다. (모든 걸 스왑해 줌)
- v1의 capacity를 없앨때 (할당한 메모리를 프로그램이 끝나기 전에 없애고 싶을때) 사용하기도 합니다.
- v2를 capacity가 0인 임시 객체로 만들어서 스왑을 해줍니다.
- vector<int>().swap(v1);

v.max_size()
- v가 담을 수 있는 최대 원소의 개수(메모리 크기) 반환

v.shrink_to_fit()
- capacity의 크기를 vector의 실제 크기에 맞춤



// vecotr의 size와 capacity와의 관계 (중요!) -------------------------------------

v.size();
- 원소의 갯수를 리턴한다.

v.capacity();
- 할당된 공간의 크기를 리턴한다.
- 공간 할당의 기준은 점점 커지면서로 capacity를 할당하게 됩니다.

  //기존 메모리의 * 2 로 증가하게 됩니다.
  //이런식으로 메모리 할당을 하는 이유는 push_back이 일어날때 마다 동적할당을 하면,
  //비효율적이므로 미리 정해둔 만큼 동적할당을 한번에 하는 것

*/

/*
//clear()로 백터의 값들을 지우게 되면 백터의 요소들은 없어지지만 capacity()는 남아있습니다.
//swap()으로 정리
{
	vector<int> v = { 1, 2, 3, 4 };
	v.clear();
	cout << v.capacity() << endl;    //output : 10

	vector<int>().swap(v);
	cout << v.capacity() << endl;    //output : 0​
}
*/

/*
//emplace_back ------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>

class A {
private:
	int num;
	std::string name;
public:
	A(int i, std::string s) : num(i), name(s) {}
};

int main(void) {
	std::vector<A> v;
	A a(1, "hwan");

	v.push_back(1, "hi");			//error -> v.push_back(a);
	v.emplace_back(1, "hi");		//ok!! //생성과 동시에 추가

	return 0;
}
*/


/*
	//정수 배열 numbers가 매개변수로 주어집니다.
	//numbers 의 원소의 평균값을 return 하도록 solution 함수를 완성해주세요.

	#include <string>
	#include <vector>
	using namespace std;

	double solution(vector<int> numbers) {
		double answer = 0;		
		
		//code

		return answer;
	}
*/