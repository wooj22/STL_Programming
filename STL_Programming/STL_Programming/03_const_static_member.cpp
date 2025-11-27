/*
	cosnt static member는 읽기 전용 정적 변수로
	객체마다 같은 값을 가지는 상수가 필요할 때
	메모리 낭비 없이 클래스 단위로 상수를 공유한다.

    C++11 부터는 정수형 정적 상수 멤버는 클래스 내에서 초기화 가능하다.
    (정수형 외는 클래스 외부 초기화 필수)
*/

#include <iostream>
using namespace std;


class Color {
public:
    // RGB const static member
    static const int RED = 0xFF0000;
    static const int GREEN = 0x00FF00;
    static const int BLUE = 0x0000FF;

    static void ShowColor(int color) {
        cout << hex << color << endl;
    }
};

int main() {
    Color::ShowColor(Color::RED);    // FF0000
    Color::ShowColor(Color::GREEN);  // FF00
    Color::ShowColor(Color::BLUE);   // FF

    // 객체를 생성해도 같은 값을 공유
    Color c1, c2;
    cout << (c1.RED == c2.RED) << endl; // 1 (같은 값)
}