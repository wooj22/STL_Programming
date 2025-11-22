// 여러가지 출력 코드

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print_fnc(int n)
{
    cout << n << " ";
}

int main() {
    int arr[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10 };

    cout << "배열 호출 : ";
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "함수 호출 : ";
    for (int i = 0; i < 10; i++) print_fnc(arr[i]);

    vector<int> v = { 5,2,3,4,5 };
    vector<int>::iterator itr = v.begin();

    cout << "[]  : ";
    for (int i = 0; i < 5; i++) cout << v[i] << " ";
    cout << endl;

    cout << "at  : ";
    for (int i = 0; i < 5; i++) cout << v.at(i) << " ";
    cout << endl;

    cout << "iterator : ";
    for (itr; itr != v.end(); itr++) cout << *itr << " ";
    cout << endl;

    cout << "for_each ";
    for_each(v.begin(), v.end(), print_fnc);
    cout << endl;

    cout << "copy ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
}
