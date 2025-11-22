// 객체 동적할당  // new delete

#include <iostream>
using namespace std;

class CTest {
private:
    int num;
public:
    void setNum(int n) { num = n; }
    int getNum() { return num; }
};

int main()
{
    //정적할당 --------------------------------
    CTest t1;
    t1.setNum(22);
    cout << t1.getNum() << endl;
    //cout << t1;                   //error
    //cout << &t1 << endl; 

    //동적할당 --------------------------------
    CTest* t2;
    t2 = new CTest();
    t2->setNum(22);
    cout << t2->getNum() << endl;    // 22
    cout << t2;                      // 주소값이 나옴.
    delete t2;

    // CTest 객체를 3개 배열 선언하세요. (객체 배열)

    CTest  arr[3];

    // CTest 객체를 3개 배열로 동적 할당하세요. (객체 배열의 동적할당)

    CTest* t3 = new CTest[3];
    delete[] t3;
    
    // CTest 객체의 포인터를 3개 담는 배열을 선언하세요. (객체 포인터의 배열)

    CTest* t4[] = { new CTest(), new CTest(), new CTest() };
    delete t4[0];
    delete t4[1];
    delete t4[2];

    return 0;
}


//new
//  new 는 1.메모리 할당, 2.생성자 호출, 3.타입 변환 까지 총 세 가지의 일을 한다.
//  new 키워드 뒤에는 임의의 타입이 들어간다.
//  동적 할당 시에는 ->로 포인터가 가르키는 공간에 접근한다.

//delete
//  delete는 1.소멸자를 자동으로 호출하고 2.메모리를 해제하는 두 가지 일을 한다.
//  힙 메모리의 데이터는 프로그래머에 의해 생성 및 해제되기 때문에 delete 키워드가 필요하다.
//  delete로 해제할 수 있는 메모리 공간은 new를 통해 할당한 공간만 해당된다.
//  new = > delete, new[] = > delete[]로 쌍을 맞춰 사용한다.

