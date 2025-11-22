#include <vector>
#include <iostream>
using namespace std;


//배열에서 가장 작은 수 제거한 백터를 만들어서 출력하세요. ------------------------------
vector<int> solution(vector<int> arr);

int main()
{
    int arr[5] = { 42,9,7,2,64 };  //case 1
    //int arr[5] = { 2,9,7,2,64 };    //case 2

    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    vector<int> v2 = solution(v);
    for (auto a : v2)
        cout << a << " ";
}

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;

    //case 1
    answer.erase(min_element(answer.begin(), answer.end()));

/*
    //case 2
    int minn = *min_element(answer.begin(), answer.end());  // 가장 작은 수
    auto s = remove_if(answer.begin(), answer.end(), [minn](int n) {return n == minn; });
    answer.erase(s, answer.end());

    //case 3
    std::erase(v1, minn);   //c++20   
*/

    //if (answer.size() == 0) answer.push_back(-1);
    return answer;
}
