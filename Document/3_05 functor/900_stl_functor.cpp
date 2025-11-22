//함수 객체(Function Object)(Functor) 
//      함수처럼 사용하는 클래스
//      operator() - 함수연산자의 오버로드
 
//함수와 다른 함수 객체의 장점
//      속성을 지닐 수 있는 것이 가능하고, 
//      함수 객체가 일반적인 함수보다 빠르기도 하며,
//      각각의 함수객체는 서로 다른 타입을 지닌다. 

#include <iostream>
using namespace std;

int main(void)
{
    // 함수객체 만들기  -------------------------
    // 
    //  - () 연산자 오버로드
    //  - 더하기 함수를 함수객체로 만들고, 실행해 보세요.
    

    // 이미 정의된 함수객체 사용하기--------------

    plus<int> add;
    cout << add(7, 3) << endl;

    cout << plus<int>()(7, 3) << endl;

    greater_equal<int> ge;
    //cout << ge(7, 3);

    equal_to<int> comp;
    //cout << comp(7, 3) << endl;

    //equal_to 를 구현하여 보세요 class Equal

    return 0;
}

/*
//equal_to 를 구현해 보자 -----------------------------

    #include <iostream>
    using namespace std;

    class Equal
    {
    public:
        int operator()(int a, int b)
        {
            return a == b;
        }
    };

    int main()
    {
        Equal cmp;
        cout << cmp(5, 5) << endl;                  //암묵적 호출
        cout << cmp.operator()(10, 20) << endl;     //명시적 호출
        cout << Equal()(10, 10) << endl;            //임시 객체를 통한 암묵적 호출  //디폴트 생성자 호출
        return 0;
    }

*/