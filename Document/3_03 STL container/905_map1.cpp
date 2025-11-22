//map 예제 <key,value>

#include <map>
#include <string>
#include <iostream>
using namespace std;

void main()
{
    //이름과 전화번호를 저장하는 map 을 선언하세요. 

    map<string, string> PhoneBooks;         
    map<string, string>::iterator iter;

    PhoneBooks.insert(make_pair("Kim", "010-1111-1111"));  //insert //key, value 추가

    // map<string, string>::value_type("Kim", "010-1111-1111")
    // pair<string, string>("Kim", "010-1111-1111")
    // 
    // std::make_pair( )  //pair<,> 객체 생성    

    PhoneBooks["Song"] = "010-3333-3333";       // []연산자로 key에 접근, 추가 및 수정가능.
    PhoneBooks["Kang"] = "010-5555-5555";
    
    cout << PhoneBooks["Kim"] << endl;

    //find 사용
    iter = PhoneBooks.find("Kim");              // iterator를 리턴
    if (iter != PhoneBooks.end())               // end() 가 아니라는 건 찾았다는 의미 ***
        cout << iter->first << " " << iter->second << endl;


    //이름을 입력받아 전화번호를 출력하세요 -------------------------

    string Name;

    for (;;) {
        cout << "이름을 입력하시오(exit로 종료) : ";
        cin >> Name;
        if (Name == "exit")
            break;

        iter = PhoneBooks.find(Name);
        if (iter == PhoneBooks.end()) {
            cout << "그런 사람은 없다.\n";
        }
        else {
            cout << Name << "의 전화번호는" << iter->second << "이다.\n";
        }
    }
}