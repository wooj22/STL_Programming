//min_element() / max_element() 


//절대값으로 최대 최소를 구하세요.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//bool test(int i, int j) { return(std::abs(i) < std::abs(j)); }

int main() {

    int buf[] = { 1, 5, 3, 4, 1, 2, -14 };

    //std::cout << "min test: " << *std::min_element(buf, buf + 7, test) << std::endl;

    //std::cout << "max test: " << *std::max_element(buf, buf + 7, test) << std::endl;

    return 0;
}

//----------------------------------------------------------
// std::min 예시

int main() {
{   
    //initializer list 
    //  - T min(initializer_list<T> il, Compare comp);

    int min_value = std::min({ 7, 2, 5, 1 });      // min value of 
    cout << min_value << endl;
}
