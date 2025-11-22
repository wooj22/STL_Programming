//binary_search  //value 가 있는지 이진 탐색을 통해서 확인
//
//  일반적인 선형 탐색과는 다르게 이진 탐색을 사용하기 때문에 
//  함수가 제대로 작동하기 위해서는 [first, last] 범위의 원소들이 
//  최소한 value 를 기준으로 부분 정렬 되어 있어야만 한다.

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    vector<int>  v(8);

    for (int i = 0; i < v.size(); i++)
        v[i] = i + 1;

    if (binary_search(v.begin(), v.end(), 2))       //binary_search
        cout << "2 찾음!" << endl;
    else
        cout << "2 못 찾음!" << endl;

    if (binary_search(v.begin(), v.end(), 10))
        cout << "10 찾음!" << endl;
    else
        cout << "10 못 찾음!" << endl;


    //----------------------------------------------------------------
    {
        int arr[] = { 3, 16, 7, 1, 20, 8, 3, 10, 25, 18 };
        sort(arr, arr + 6);     //이진탐색 전에 반드시 정렬을 해줘야 한다.
        cout << "arr에 8이 있나요? " << boolalpha << binary_search(arr, arr + 6, 8) << endl;
        cout << "arr에 2가 있나요? " << boolalpha << binary_search(arr, arr + 6, 2) << endl;
    }

    //----------------------------------------------------------------
    {
        vector<int> v = { 3, 16, 7, 1, 20, 8, 3, 10, 25, 18 };
        sort(v.begin(), v.end()); //이진탐색 전에 반드시 정렬을 해줘야 한다.
        cout << "arr에 8이 있나요? " << boolalpha << binary_search(v.begin(), v.end(), 8) << endl;
        cout << "arr에 2가 있나요? " << boolalpha << binary_search(v.begin(), v.end(), 2) << endl;
    }

    //어느 인덱스에 있는지는 binary_search 함수로는 알 수 없다. 
    //그래서 사용하는 것이 upper_bound, lower_bound 함수이다.

    {
        int arr[] = { 1, 3, 4, 4, 7, 10, 10, 10, 13, 17 };
        sort(arr, arr + 10);
        cout << "lower_bound: " << lower_bound(arr, arr + 10, 10) << endl;
        cout << "upper_bound: " << upper_bound(arr, arr + 10, 10) << endl;
    }
    //주소 말고 인덱스로 보고 싶다면, 이렇게 시작주소를 빼주면 된다. 
    {
        int arr[] = { 1, 3, 4, 4, 7, 10, 10, 10, 13, 17 };
        sort(arr, arr + 10);
        cout << "lower_bound: " << lower_bound(arr, arr + 10, 10) - arr << endl;

        vector<int> v = { 1, 3, 4, 4, 7, 10, 10, 10, 13, 17 };
        sort(v.begin(), v.end());
        cout << "lower_bound: " << lower_bound(v.begin(), v.end(), 10) - v.begin() << endl;
        cout << "upper_bound: " << upper_bound(v.begin(), v.end(), 10) - v.begin() << endl;
    }

    //10이 arr에 몇 개가 있는지 알고 싶다면, upper_bound에서 lower_bound를 빼보면 된다.
    {
        int arr[] = { 1, 3, 4, 4, 7, 10, 10, 10, 13, 17 };
        sort(arr, arr + 10);
        cout << "arr에 10은 " << upper_bound(arr, arr + 10, 10) - lower_bound(arr, arr + 10, 10) << "개가 있다" << endl;
    }


    return 0;
}

