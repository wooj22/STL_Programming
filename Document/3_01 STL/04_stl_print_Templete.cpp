// STL Templete 연습 

#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// array 출력하는 함수
void printArrInt(int* begin, int* end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

// array 출력하는 함수를 Templete 으로 만들어 보자.
template <typename T>
void printArray(T begin, T end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

// vector 출력하는 템플릿을 만들어 보자.
template <typename T>
void printVector(T begin, T end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

// vector 안에 s 가 있는지 없는지를 리턴한다.
template <typename T, typename U>
bool isValue(T begin, T end, const U n) {
    while (begin != end) {
        if (*begin == n) return true;
        begin++;
    }
    return false;
}

// vector 안에 작은 순서대로 추가하라. ***
template <typename T>
void insertVector(vector<T>& v, const T n)
{
    auto it = v.begin();
    for (; it != v.end(); it++) {
        if (n <= *it) {
            v.insert(it, n);
            return;
        }
    }
    v.insert(it, n);
}

int main()
{
    // 배열 출력하는 템플릿을 만들어 보자.
    int arr1[] = { 1,2,3,4,5,6 };
    printArrInt(arr1, arr1 + 6);

    double arr2[] = { 1,2,3,4,5,6 };
    printArray(arr2, arr2 + 6);

    // vector 출력하는 템플릿을 만들어 보자.
    vector<int> v = { 1,2,3,4,5,6 };
    printVector(v.begin(), v.end());

    // vector 안에 s 가 있는지 없는지를 리턴한다.
    cout << isValue(v.begin(), v.end(), 13) << endl;

    // vector 안에 작은 순서대로 추가하라.
    vector<int> v2;
    //v2.insert(v2.begin(), 2);
    //v2.insert(v2.begin(), 3);

    insertVector(v2, 3);
    insertVector(v2, 1);
    insertVector(v2, 4);
    insertVector(v2, 2);
    printVector(v2.begin(), v2.end());
}

