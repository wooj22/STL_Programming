//vector 내의 중복된 원소 제거  erase(unique)

// unique 함수 
//      순차적으로 중복된 원소가 있으면 제거하며 앞에서부터 원소들을 채워나간다

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {

    vector<int> v = { 1, 1, 2, 1, 3, 5, 4, 2 };

    unique(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    cout << endl;

    // unique 는 순차적으로 중복된 것이 있으면 제거한 후 위치 리턴


    //중복된 것을 제거 하려면 ???

    // sort 후 unique 사용 //erase 로 뒷 부분에 필요없는 값들을 삭제

    sort(v.begin(), v.end());
    auto itr = unique(v.begin(), v.end());
    v.erase(itr, v.end());

    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
}

/*
template <class ForwardIterator>
ForwardIterator unique(ForwardIterator first, ForwardIterator last)
{
    if (first == last) return last;
    ForwardIterator result = first;
    while (++first != last) {
        if (!(*result == *first)) *(++result) = *first;
    }
    return ++result;
}
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {

    vector<int> v = { 1, 1, 2, 1, 3, 5, 4, 2 };

    sort(v.begin(), v.end());
    
    v.resize(unique(v.begin(), v.end()) - v.begin());   // resize 함수를 이용

    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
}
