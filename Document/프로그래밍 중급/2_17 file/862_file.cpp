#include <fstream>
#include <iostream>
#include <string>
//using namespace std;

int main()
{
    // 파일 읽기 준비
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        
        in.seekg(0, std::ios::end);     // 위치 지정자를 파일 끝으로 옮긴다.        
        int size = in.tellg();          // 그리고 그 위치를 읽는다. (파일의 크기)        
        s.resize(size);                 // 그 크기의 문자열을 할당한다.
        
        in.seekg(0, std::ios::beg);     // 위치 지정자를 다시 파일 맨 앞으로 옮긴다.        
        in.read(&s[0], size);           // 파일 전체 내용을 읽어서 문자열에 저장한다.
        std::cout << s << std::endl;    // 출력
    }
    else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }

    return 0;
}

/*
//이어쓰기 모드를 사용하는 방법

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream output("test.txt", ios::app);
    output << "이어 쓰기 완료" << endl;
    output.close();
    return 0;
}
*/

/*
// put

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream output("output.txt");
    output.put('H');
    output.put('e');
    output.put('\n');
    output.setf(ios::fixed);        // 소숫점     // unsetf
    output.setf(ios::showpoint);    // 소숫점 보여준다
    output.precision(2);            // 두자리
    output << "파이: " << 3.14159 << endl;
    output.close();
    return 0;
}

*/