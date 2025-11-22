//random_shuffle    //C++14บฮลอ deprecated

#include <iostream>
#include <iterator> // ostream_iterator
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    vector<int> v(8);
    for (int i = 0; i < v.size(); i++)
        v[i] = i + 1;

    ostream_iterator<int>  out_iter(cout, "  :  ");
    copy(v.begin(), v.end(), out_iter);
    cout << endl;

    random_shuffle(v.begin(), v.end());         

    copy(v.begin(), v.end(), out_iter);
    cout << endl;
}