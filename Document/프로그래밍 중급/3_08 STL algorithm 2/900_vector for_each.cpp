//for_each //Lambda 호출

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print_fnc(int n) {
    cout << n << " ";
}

int main(void) {

    vector<int> v = { 1,2,3,4,5 };
    vector<int>::iterator itr = v.begin();

    cout << "for_each문 함수 호출 : ";
    for_each(v.begin(), v.end(), print_fnc);        //함수 호출
    cout << endl;


    cout << "for_each문 Lambda 호출 : ";
    for_each(itr, itr + v.size(), [](auto& n) {     //Lambda 호출
        cout << n << " ";
        });

    return 0;
}

/*
for_each문의 사용 이유

    1. 코드의 간결화
    2. 함수 객체를 이용한 inline 화
    3. 사용자가 for_each문의 기능을 정의해 유연성을 부여.
*/

// 반환 값 :
//      for_each 는 값을 반환할 수 있습니다. 
//      반환되는 것은 사용자로부터 전달 받은 함수 또는 함수 객체의 형식으로 반환 됩니다.

// 시작 주소와 끝 주소 값 : 
//      for_each는 인자를 주소 값으로 전달 받습니다.
//      2번째 인자를 전달 받을 때 전달 받은 주소 값 까지 출력하는 것이 아니라 
//      전달 받은 주소 값 '전' 까지의 값만을 출력

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print_fnc(int n) {
    cout << n << " ";
}

int main(void)
{
    int arr[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10 };

    cout << "arr [9]의 값 : " << arr[9] << endl;
    for_each(arr, &arr[9], print_fnc);
    cout << endl;

    cout << "arr [10]의 값 : " << arr[10] << endl;
    for_each(arr, &arr[10], print_fnc);
}
