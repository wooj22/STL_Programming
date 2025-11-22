//연습) 객체배열, 동적할당, 포인터 배열 
//  객체 생성, 소멸 예제  -------------------------------------------------------------

#include <cstdlib>
#include <iostream>
using namespace std;

class Circle 
{
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle();
    void setRadius(int r) { radius = r; }
    double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle() { radius = 1; }
Circle::Circle(int r) { radius = r; }
Circle::~Circle() {}


int main()
{
    // 객체 배열	// 각각 반지름 2,3,5로 설정후 넓이를 출력하세요. ----------------
    Circle arr1[3] = { Circle(2), Circle(3), Circle(5) };

    for (int i = 0; i < 3; ++i) {
        cout << arr1[i].getArea() << endl;
    }


    // 객체를 동적으로 할당하여, 각각 반지름 2,3,5로 설정후 출력하세요.------------
    Circle* arr2 = new Circle[3]{ Circle(2), Circle(3), Circle(5) };

    for (int i = 0; i < 3; ++i) {
        cout << arr2[i].getArea() << endl;
    }

    //Circle* n = new Circle[10]; //copy
    //delete[] arr2; arr2 = n;

    delete[] arr2;


    // 포인터 배열  -----------------------------------------------------------

    Circle* arr3[3] = { new Circle(2), new Circle(3), new Circle(5) };

    //포인터만 관리하면, 추가 삭제 복사 이동이 좀더 효율적임
    
    //지우고 재할당 하기
    //delete arr3[0]; arr3[0] = nullptr;
    //if (arr3[0] == nullptr) arr3[0] = new Circle(10);

    delete arr3[0];
    delete arr3[1];
    delete arr3[2];


    //system("PAUSE");
    return EXIT_SUCCESS;
}
