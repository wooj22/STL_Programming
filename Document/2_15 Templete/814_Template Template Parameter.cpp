
//템플릿 템플릿 파라미터 -----------------------------------------------
//		템플릿 파라미터로 템플릿을 사용하는 것
//		template<..., template<TemplateTypeParams> class ParameterName, ...>

//템플릿 파라미터 
//          type 템플릿 파라미터
//      non-type 템플릿 파라미터
//      template 템플릿 파라미터

#include <iostream>
using namespace std;

template <typename T>
class ClassA
{
public:
    void Show() { cout << "ClassA::Show" << endl; }
};

template <typename T, template <typename T> class Class >   //
class ClassB
{
private:
    Class<T> m_obj;
public:
    void Show() { cout << "ClassB::Show" << endl; m_obj.Show(); }
};

int main()
{
    ClassB<int, ClassA> obj; obj.Show();

    //ClassA        //클래스 템플릿을 인수로 전달
    //ClassA<int>   //템플릿 클래스를 인수로 전달

}

//----------------------------------------------------------------------

#include <iostream>
#include <vector>   //
using namespace std;

template < template <class> class Vector >      //
class VectorInt
{
private:
    Vector<int> arr = { 1,2,3 };
public:
    void Show() {
        for (auto e : arr)
            cout << e << endl;
    }
};

int main()
{
    VectorInt< std::vector > v;
    v.Show();
}
