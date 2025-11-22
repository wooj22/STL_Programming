//벡터 출력하기 //iterator 연습

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print_vector(std::vector<T>& vec)  // 전체 벡터를 출력하기 
{
    typename std::vector<T>::iterator itr;
    for (itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << std::endl;
    }
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec)  // 전체 벡터를 출력하기
{
    for (const auto& elem : vec) {
        std::cout << elem << std::endl;
    }
}

int main()
{
    std::vector<int> vec;
    vec.push_back(10);  // 맨 뒤에 10 추가
    vec.push_back(20);  // 맨 뒤에 20 추가
    vec.push_back(30);  // 맨 뒤에 30 추가
    vec.push_back(40);  // 맨 뒤에 40 추가

    // vec[i]
    for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
        std::cout << "vec 의 " << i + 1 << " 번째 원소 :: " << vec[i] << std::endl;
    }

    // int arr[4] = {10, 20, 30, 40}
    // *(arr + 2) == arr[2] == 30;
    // *(itr + 2) == vec[2] == 30;

    // *itr사용   // 3 번째 원소 출력하라
    std::vector<int>::iterator itr = vec.begin() + 2;  //배열을 가리키는 포인터와 똑같이 동작
    std::cout << "3 번째 원소 :: " << *itr << std::endl;


    // 전체 벡터를 출력하기. ***
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << std::endl;
    }

    // print_vector 를 템플릿으로 구현하세요.***
    print_vector(vec);


    // vec[2] 앞에 15 추가하고 출력해보세요.
    vec.insert(vec.begin() + 2, 15);
    print_vector(vec);


    // vec[3] 제거하고 출력해보세요.
    vec.erase(vec.begin() + 3);
    print_vector(vec);


    // 역방향 반복자  reverse_iterator ----------------------------
    vector<int> vc = { 1, 2, 3, 4, 5 };

    std::vector<int>::reverse_iterator riter = vc.rbegin();  // riter 은 끝을 가리킨다.  
    for (; riter != vc.rend(); riter++) {
        std::cout << *riter << std::endl;
    }

    //스트림 반복자(stream iterator) ---------------------------- 
    vector<int> vc = { 1, 2, 3, 4, 5 };

    copy(vc.begin(), vc.end(), ostream_iterator<int>(cout));            //copy 함수
    cout << endl;

    copy(vc.begin(), vc.end(), ostream_iterator<int>(cout, " "));       //공백 출력 ***
    cout << endl;

}
