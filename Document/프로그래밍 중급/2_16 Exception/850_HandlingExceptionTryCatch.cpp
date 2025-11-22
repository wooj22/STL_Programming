// 예외처리 
//	throw 에 의해 던져진 '예외' 데이터는, 
//	예외 데이터를 감싸는 try 블록에 의해서 감지가 되어 
//	이어서 등장하는 catch 블록에 의해 처리된다.

// C++ 예외처리에서 예외를 던지는 throw는 
//	try구문 안에 있어야 하며, 
//	throw 발생 시 예외를 받아주는 catch구문으로 점프한다.


#include <iostream>
using namespace std;

/*
// 예외처리 하기

int main(void)
{
	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;

	cout << "나눗셈의 몫: " << num1 / num2 << endl;
	cout << "나눗셈의 나머지: " << num1 % num2 << endl;
}

//C 처리 -----------------------------------------------------
int main(void)
{
	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;

	if (num2 == 0)			//if 문 으로 처리
	{
		cout << "제수는 0이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}
	else
	{
		cout << "나눗셈의 몫: " << num1 / num2 << endl;
		cout << "나눗셈의 나머지: " << num1 % num2 << endl;
	}
	return 0;
}
*/

int main(void)
{
	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;

	try						//try catch 문 으로 처리
	{
		if (num2 == 0)
			throw num2;

		cout << "나눗셈의 몫: " << num1 / num2 << endl;
		cout << "나눗셈의 나머지: " << num1 % num2 << endl;
	}
	catch (int expn)
	{
		cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}

	cout << "end of main" << endl;
	return 0;
}
