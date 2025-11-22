
#include <iostream>
//#include <string>	//c++ 표준 string
using namespace std;

class String		//String 클래스와 다양한 연산자 오버로딩
{
private:
	int len;
	char* str;
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();

	//String& operator= (const String& s);						//대입
	//String& operator+= (const String& s);						//복합 대입
	//bool operator== (const String& s);							//비교
	//bool operator!= (const String& s);							//비교
	//String operator+ (const String& s);							//더하기
	//friend ostream& operator<< (ostream& os, const String& s);	//출력
	//friend istream& operator>> (istream& is, String& s);		//입력
};

String::String()
{
	len = 0;
	str = NULL;
}

String::String(const char* s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy_s(str, len, s);
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len];
	strcpy_s(str, len, s.str);
}

String::~String()
{
	if (str != NULL) delete[]str;
}


int main(void)
{
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)	cout << "동일 문자열" << endl;
	else				cout << "동일하지 않은 문자열" << endl;

	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}
