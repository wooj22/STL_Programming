//map
//1. 크기가 가변적이다.
//2. 데이터를 넣으면, key를 기준으로 정렬을 한다. (단, key는 유일하다 // 중복사용하고 싶다면 multi_map 사용)
//3. 많은 자료를 저장하면서 동시에 빠른 검색을 지원한다. ***
//4. 빈번하게 삽입, 삭제하지 않는다.

#include <iostream>
#include <string>
#include <map>
using namespace std;

template <typename K, typename V>
void print_map(std::map<K, V>& m)  // 맵의 모든 원소들을 출력하기
{
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		std::cout << itr->first << " " << itr->second << std::endl;
	}
}

int main()
{
	// 초기화
	map<string, int> mp;

	mp.insert(map<string, int>::value_type("민수", 10000));	//value_type
	mp.insert(map<string, int>::value_type("수연", 5200));
	mp.insert(map<string, int>::value_type("지수", 9800));

	mp.insert(make_pair("민수", 10000));		// pair<,> 활용
	mp.insert(make_pair("수연", 5200));
	mp.insert(make_pair("지수", 9800));
	//mp.insert(make_pair("수연", 6000));

	for (auto e : mp) cout << e.first << " " << e.second << endl;

	// [ key ] 사용 가능  ***

	mp["민수"] = 10000;						// map[key] = value
	mp["수연"] = 5200;
	mp["지수"] = 9800;
	//mp["수연"]= 6000; 으로 입력하면, 즉 키가 중복되면 insert 와 달리 변경됨 ***

	for (auto e : mp) cout << e.first << " " << e.second << endl;

 	
	//--------------------------------------------------------

	map<int, int> mp1;

	// insert case 1:
	mp1.insert(map<int, int>::value_type(1, 1));
	mp1.insert(map<int, int>::value_type(2, 4));
	mp1.insert(map<int, int>::value_type(3, 2));
	mp1.insert(map<int, int>::value_type(4, 8));
	mp1.insert(map<int, int>::value_type(5, 9));

	// insert case 2:
	mp1[6] = 11;		// 추가
	mp1[7] = 22;
	mp1[1] = 100;		// operator[] 형식은 삽입뿐만 아니라 수정도 가능 ***

	// insert case 3:
	map<int, int> mp2;
	mp2[8] = 3;
	mp2[9] = 10;
	mp1.insert(mp2.begin(), mp2.end()); // 범위추가

	// const가 반복자에 있으면, 수정 불가능!
	map<int, int>::const_iterator iter;
	for (iter = mp1.begin(); iter != mp1.end(); iter++)
		cout << "[" << iter->first << "," << iter->second << "]" << ' ';
	cout << endl << endl;


	// search case 1 -------------------------------------
	map<int, int>::iterator FindIter = mp1.find(9);		//find( key ) 검색
	if (FindIter != mp1.end()) {
		FindIter->second = 999;		// 결과가 <key, value > 
	}

	cout << "map1 : ";
	for (auto e : mp1) cout << "[" << e.first << "," << e.second << "]" << ' ';	cout << endl << endl;

	// search case 2
	if (mp1.count(8))				// count() 로도 검색 가능 //없으면 0
	{
		cout << "map에서 key 8의 형태를 가지고 있습니다." << endl;
	}

	// search case 3				// contains()
	if (mp1.contains(8))	cout << "Key Exists!" << endl;
	else					cout << "Key does not exist!" << endl;

	cout << endl;

	// erase case 1 -------------------------------------

	mp1.erase(mp1.begin());					//erase(iter)

	//for (auto e : mp1) cout << "[" << e.first << "," << e.second << "]" << ' ';	cout << endl << endl;

	// erase case 2:
	iter = mp1.begin();						
	iter++;
	iter++;
	mp1.erase(iter, mp1.end());				//erase(begin,end)

	//for (auto e : mp1) cout << "[" << e.first << "," << e.second << "]" << ' ';	cout << endl << endl;

	// erase case 3:
	int remove_key2_cnt = mp1.erase(2);		//erase(key_value)
	int remove_key3_cnt = mp1.erase(3);

	cout << "삭제한 개수" << endl;
	cout << "key가 2인 데이터 삭제의 개수 : " << remove_key2_cnt << endl;
	cout << "key가 3인 데이터 삭제의 개수 : " << remove_key3_cnt << endl;

	cout << "map1 : ";
	for (auto e : mp1) cout << "[" << e.first << "," << e.second << "]" << ' ';	cout << endl << endl;

	cout << endl;


	// <int, string> 의 경우 ----------------------------------------------------

	map<int, string> mp3;
	mp3[1] = "Apple";
	mp3[2] = "Banana";
	mp3[3] = "Cheeze";
	mp3[4] = "Coconut";

	cout << "mp3 : ";
	for (auto e : mp3) cout << "[" << e.first << "," << e.second << "]" << ' ';	cout << endl << endl;

	return 0;
}

//- Sort by key
// 
//	일반적으로 map 사용 시 key를 이용하여 정렬하게 되는데, 특별한 내용 없이 생성 단계에서 지정이 가능하다. ***
//	1) 오름 차순의 경우 : std::map< int, int > data
//	2) 내림 차순의 경우 : std::map< int, int, std::greater<int> > data
//	std::greater는 functional 에 정의된 template struct 로 기본 제공된다.
/*
	int main()
	{
		std::map< int, int > data;
		data.insert({ 1,1000 });
		data.insert({ 2,2000 });
		data.insert({ 3,3000 });
		data.insert({ 4,4000 });
		for (auto e : data) cout << "[" << e.first << "," << e.second << "]" << ' ';	cout << endl << endl;

		std::map< int, int, std::greater<int> > data2;
		data2.insert({ 1,1000 });
		data2.insert({ 2,2000 });
		data2.insert({ 3,3000 });
		data2.insert({ 4,4000 });
		for (auto e : data2) cout << "[" << e.first << "," << e.second << "]" << ' ';	cout << endl << endl;
	}
*/

// Sort by value
// 
//		경우에 따라 value를 통한 sorting이 필요한데, 이 경우는 순수하게 map으로 구현하기 까다롭다.
//		그래서 익숙한 vector로 치환 후 sorting 

	#include <iostream>
	#include <map>
	#include <vector>
	#include <algorithm>
	using namespace std;

	template<template <typename> class P = std::less >
	struct compare_pair_second {
		template<class T1, class T2> 
		bool operator()(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right) {
			return P<T2>()(left.second, right.second);
		}
	};

	int main()
	{
		std::map< int, int > mapData;
		std::vector< std::pair< int, int > > vec;

		for (auto iter = mapData.begin(); iter != mapData.end(); ++iter)
			vec.emplace_back(std::make_pair(iter->first, iter->second));

		std::sort(vec.begin(), vec.end(), compare_pair_second<std::greater>());		//compare_pair_second
	}

/*
	// lower_bound, upper_bound, equal_range ------------------------
	//
	//	lower_bound() : 범위 내에서 찾으려는 값 이상의 원소들 중 처음 나오는 Iterator
	//	upper_bound() : 범위 내에서 찾으려는 값 초과의 원소들 중 처음 나오는 Iterator
	//	equal_range()는 lower_bound(), upper_bound() 결과를 쌍으로 반환

	map<int, int> mp4;
	mp4.insert(map<int, int>::value_type(1, 10));
	mp4.insert(map<int, int>::value_type(2, 20));
	mp4.insert(map<int, int>::value_type(3, 30));
	mp4.insert(map<int, int>::value_type(4, 40));
	cout << "mp4 : ";
	for (auto e : mp4) cout << "[" << e.first << "," << e.second << "]" << ' ';	cout << endl << endl;

	pair<map<int, int>::const_iterator, map<int, int>::const_iterator> p1, p2, p3;

	p1 = mp4.equal_range(2);

	cout << "key 2의 lower_bound : ";
	cout << "[" << p1.first->first << "," << p1.first->second << "]" << endl;
	cout << "key 2의 upper_bound : ";
	cout << "[" << p1.second->first << "," << p1.second->second << "]" << endl << endl;

	p2 = mp4.equal_range(3);

	cout << "key 3의 lower_bound : ";
	cout << "[" << p2.first->first << "," << p2.first->second << "]" << endl;
	cout << "key 3의 upper_bound : ";
	cout << "[" << p2.second->first << "," << p2.second->second << "]" << endl << endl;

	p3 = mp4.equal_range(4);

	if ((p3.first == mp4.end()) || (p3.second == mp4.end()))
	{
		cout << "key 4의 lower_bound는 있지만, key 4의 upper_bound는 없습니다. " << endl;
	}
	else
	{
		cout << "key 4의 lower_bound : ";
		cout << "[" << p3.first->first << "," << p3.first->second << "]" << endl;
		cout << "key 4의 upper_bound : ";
		cout << "[" << p3.second->first << "," << p3.second->second << "]" << endl << endl;
	}

*/