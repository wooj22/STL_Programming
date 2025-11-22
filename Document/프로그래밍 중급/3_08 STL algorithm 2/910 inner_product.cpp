#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

void main()
{
    vector<int> v1;
    vector<int> v2;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(2);

    cout << inner_product(v1.begin(), v1.end(), v2.begin(), 0) << endl;     //두 입력 시퀀스의 내적

    //1*2 + 2*2 +  3*2
}