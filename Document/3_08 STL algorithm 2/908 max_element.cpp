//min_element() / max_element() : 최소/최대 값 찾기 -------------------------------

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{

    int test_arr[] = { 2, 4, 3, 6, 1, 7 };
    std::vector<int> test_vec = { 2, 4, 3, 6, 1, 7 };
    std::list<int> test_list = { 2, 4, 3, 6, 1, 7 };

    std::cout << "min array: " << *std::min_element(test_arr, test_arr + 6) << std::endl;
    std::cout << "max array: " << *std::max_element(test_arr, test_arr + 6) << std::endl;

    std::cout << "min vector: " << *std::min_element(test_vec.begin(), test_vec.end()) << std::endl;
    std::cout << "max vector: " << *std::max_element(test_vec.begin(), test_vec.end()) << std::endl;

    std::cout << "min list: " << *std::min_element(test_list.begin(), test_list.end()) << std::endl;
    std::cout << "max list: " << *std::max_element(test_list.begin(), test_list.end()) << std::endl;


    //범위 지정해서 min max 찾기

    int a[10] = { 42,32,9,72,92,3,41,2,18,64 };

    cout << "max : " << *max_element(a, a + 10) << endl;    // max : 92
    cout << "min : " << *min_element(a, a + 10) << endl;    // min : 2
    cout << "min : " << *min_element(a + 1, a + 7) << endl; // min : 3

    vector<int> v = { 10,4,23,72,9,14,1,42 };

    cout << "max : " << *max_element(v.begin(), v.end()) << endl;           // max : 72
    cout << "min : " << *min_element(v.begin(), v.end()) << endl;           // min : 1
    cout << "min : " << *min_element(v.begin() + 2, v.end() - 2) << endl;   // min : 9


    return 0;
}


