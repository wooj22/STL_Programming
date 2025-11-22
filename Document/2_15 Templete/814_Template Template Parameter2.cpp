//템플릿 클래스 전달과 템플릿 의 전달 구별하기

#include <iostream>
#include <string>
#include <deque>

//템플릿 인수로 템플릿 전달 -----------------------------------------------

template <typename T, typename Container>
class Stack1
{
private:
    Container m_Container;      //std::deque<int> 
public:
    // You can use forwarding reference for the better performance
    void Push(T const& value) {}
    // Some member functions
};

//템플릿 템플릿 파라미터 -----------------------------------------------

template <typename T, template <typename> class Container = std::deque >    //
class Stack2
{
private:
    Container<T> m_Container;   //std::deque<int> 
public:
    // You can use forwarding reference for the better performance
    void Push(T const& value) {}
    // Some member functions
};

int main()
{    
    Stack1<int, std::deque<int>> stack;                 //1. std::deque<int>
    // the element type 'int' is specified twice

    Stack2<int, std::deque> stack;                      //2. std::deque
}