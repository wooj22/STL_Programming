//prev_permutation() / next_permutation() : 이전 / 다음 순열 구하기 -------------------------

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // 1부터 4까지 저장할 벡터 선언
    // 배열도 가능!
    vector<int> v(4);

    // 1부터 4까지 벡터에 저장
    for (int i = 0; i < 4; i++) { v[i] = i + 1; }

    // next_permutation을 통해서 다음 순열 구하기
    do {
        for (int i = 0; i < 4; i++) { cout << v[i] << " "; }
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));

    return 0;

}

/*
    vector<int> v;
    v.sort(v.begin(), v.end());

    do {

    } while (next_permutation(v.begin(), v.end()));

    //next_permutation을 사용한다면 less로
    //prev_permutation을 사용한다면 greater로 정렬 후 사용해야 모든 경우의 수를 접근 할 수 있다.
*/


