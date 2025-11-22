//unordered_map
//  1. 많은 자료를 저장해야합니다.그 때의 검색 속도는 빨라야 할때. ***
//  2. 너무 빈번하게 자료를 삽입, 삭제하지 않을 때
//  문자열의 길이가 길고 데이터의 크기가 크지 않은 경우는 map이 unordered_map보다 탐색에 유리

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

template < typename T, typename U >
void print(unordered_map<T, U>& hash)
{
	typename unordered_map<T, U>::iterator iter2;
	for (iter2 = hash.begin(); iter2 != hash.end(); iter2++)
		cout << "[" << iter2->first << "," << iter2->second << "]" << ' ';
	cout << endl << endl;
}

int main()
{
	unordered_map<int, float> hash1;

	// insert case 1:
	hash1.insert(unordered_map<int, float>::value_type(10, 10.5f));

	// insert case 2:
	hash1.insert(hash1.begin(), unordered_map<int, float>::value_type(20, 20.8f));

	// insert case 3:
	unordered_map<int, float> hash2;
	hash2.insert(hash1.begin(), hash1.end());


	// for문 활용 // iterator 사용
	cout << "hash1: ";
	unordered_map<int, float>::iterator iter;
	for (iter = hash1.begin(); iter != hash1.end(); ++iter)
		cout << "[" << iter->first << "," << iter->second << "]" << ' ';
	cout << endl << endl;;

	cout << "hash2: ";
	for (iter = hash2.begin(); iter != hash2.end(); ++iter)
		cout << "[" << iter->first << "," << iter->second << "]" << ' ';
	cout << endl << endl;


	// erase case 1:
	hash1.erase(hash1.begin());
	print(hash1);

	// erase case 2:
	hash1.erase(hash1.begin(), hash1.end());
	print(hash1);

	// erase case 3:
	hash2.erase(10); // key가 10인 요소를 삭제한다.
	print(hash2);


	// search case 1:
	unordered_map<int, float>::iterator findIter;

	// 찾으면 그 요소의 반복자를 리턴, 아니면 end()를 리턴
	findIter = hash2.find(20);
	if (findIter != hash2.end()) { cout << "key가 20인 요소가 있어요." << endl << endl; }
	else						 { cout << "그런 요소는 없네요." << endl << endl;	}


	//----------------------------------------------------------------------
	unordered_map<int, int> hash3;
	for (int i = 0; i < 5; i++)
		hash3.insert(unordered_map<int, int>::value_type(i, i + 10));
	cout << "hash3: ";  print(hash3);

	// 다른 형태로도 insert할 수 있습니다.
	hash3[1000] = 200;
	hash3[2000] = 300;
	cout << "hash3: "; print(hash3);

	// 이런 형태도 생성되어서 넣어집니다. default로 넣어집니다. int면 0  ***
	hash3[3000];
	cout << "hash3: "; print(hash3);
	cout << "hash3 size : " << hash3.size() << endl;

	// string  -----------------------------------------------------------

	unordered_map<int, string> hash4;
	hash4[1] = "Apple";
	hash4[2] = "Banana";
	hash4[3] = "Cheeze";
	cout << "hash4: "; print(hash4);

	// hash[key]를 이용하면 변경이 가능합니다. ***
	hash4[3] = "Tomato";
	cout << "hash4: "; print(hash4);

	// insert는 이미 key가 저장되어 있으면 변경이 불가능 합니다. 
	// 구문 오류는 뜨지 않으나 변경이 되지 않습니다.

	hash4.insert(unordered_map<int, string>::value_type(3, "Grape"));
	hash4.insert(unordered_map<int, string>::value_type(4, "Grape"));
	cout << "hash4: "; print(hash4);

	// search 방법에 또 다른 방법이 있습니다 --------------------------------------
	
	// count 입니다.
	if (hash4.count(4))
	{
		cout << hash4[4] << endl << endl;
	}
	else
	{
		cout << "찾고 싶은 요소는 버킷에 없네요." << endl << endl;
	}

	// find  // 이렇게 뽑아서 사용할 수 도 있습니다.
	auto item = hash4.find(3);
	if (item != hash4.end()) {
		cout << "[" << item->first << "," << item->second << "]" << endl << endl;
	}
	else {
		cout << "찾고 싶은 요소는 버킷에 없네요." << endl << endl;
	}

	// 아까 hash[key]에 아무것도 안넣으면 default가 넣어진다. ***
	// string도 확인해봅시다.

	hash4[5];

	// 이것은 key로 인정될까요? // key로 인정이 되네요. value는 "".

	auto item2 = hash4.find(5);
	if (item2 != hash4.end()) {
		cout << "[" << item2->first << "," << item2->second << "]" << endl << endl;
		//if (item2->second == "") cout << "ssd";
	}
	else {
		cout << "찾고 싶은 요소는 버킷에 없네요." << endl << endl;
	}
	return 0;
}

//Hash Map(unordered_map)
 
//https://woo-dev.tistory.com/106
//std::map은 요소가 자동으로 오름 차순으로 정렬되는 이진 탐색 트리(BST) 기반의 map이였다.
// 정확히 말하면 Red-black-tree 라는 스스로 균형을 맞추는 이진 탐색 트리의 일종이다.
//C++ 11에서 std::unordered_map이라는 컨테이너가 등장했고, 기존의 std::map과 달리 이진 탐색트리가 아닌 해시 테이블로 구현되어 있다. 
// 때문에 요소를 자동으로 정렬하지 않으며 요소의 검색, 삽입, 삭제 연산이 평균적으로 상수 시간에 가능하다.

//해시 테이블
https://velog.io/@mooh2jj/Hash%EC%9D%98-%EA%B0%9C%EB%85%90-%EB%B0%8F-%EC%84%A4%EB%AA%85


