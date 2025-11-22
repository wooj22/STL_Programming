
//고정된 벡터 배열 ------------------------------------------------------------
//      기본적으로 고정 된 수의 행과 가변적 인수의 열로 2 차원 배열을 정의

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using std::array;
using std::vector;

int main()
{
    vector<int> arr_vectors[3];             // 3개의 vector<int>

    int n = 0;
    for (auto& vec : arr_vectors) {
        for (int i = 0; i < 5; ++i) {
            vec.push_back(++n);
        }
    }

    arr_vectors[2][0] = 99;

    for (auto& item : arr_vectors) {
        for (auto& i : item) {
            cout << setw(3) << i << "; ";
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}

//벡터의 가변 배열 ------------------------------------------------------------

#include <iostream>
#include <vector>
#include <iomanip>

using std::cout; 
using std::endl; 
using std::setw;
//using namespace std;

constexpr int LENGTH = 3;
constexpr int WIDTH = 4;

int main()
{
    vector<vector<int>> vector_2d(LENGTH, vector<int>(WIDTH, 0));   //백터가 여러개.

    vector_2d[2][2] = 12;
    cout << vector_2d[2][2] << endl;

    vector_2d.at(2).at(3) = 99;
    cout << vector_2d[2][3] << endl;

    cout << endl;

    //출력해 보세요.

    for (auto& item : vector_2d) {
        for (auto& i : item) {
            cout << setw(3) << i << "; ";
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}