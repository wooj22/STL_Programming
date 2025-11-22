// C++ 표준 라이브러리에는 이미 여러가지 종류의 예외들이 정의
//      exception
//      out_of_range, overflow_error, length_error, runtime_error 등등 

//https://cplusplus.com/reference/stdexcept/
//https://learn.microsoft.com/ko-kr/cpp/standard-library/stdexcept?view=msvc-170


// runtime_error.cpp
// compile with: /EHsc
#include <exception>
#include <iostream>
#include <locale>
#include <typeinfo>
using namespace std;

int main()
{
    try
    {
        locale loc("test");             //runtime_error 발생
    }
    catch (const exception& e)
    {
        cerr << "Caught: " << e.what() << endl;
        cerr << "Type: " << typeid(e).name() << endl;
    }
}



//-------------------------------------------------------------------

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
public:
    Vector(size_t size) : size_(size) {
        data_ = new T[size_];
        for (int i = 0; i < size_; i++) {
            data_[i] = 3;
        }
    }
    const T& at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("vector 의 index 가 범위를 초과하였습니다.");
        }
        return data_[index];
    }
    ~Vector() { delete[] data_; }

private:
    T* data_;
    size_t size_;
};
int main() 
{
    Vector<int> vec(3);

    int index, data = 0;
    std::cin >> index;

    try {
        data = vec.at(index);
    }
    catch (std::out_of_range& e) {
        std::cout << "예외 발생 ! " << e.what() << std::endl;
    }
    // 예외가 발생하지 않았다면 3을 이 출력되고, 예외가 발생하였다면 
    // 원래 data 에 들어가 있던 0 이 출력된다.
    std::cout << "읽은 데이터 : " << data << std::endl;
}