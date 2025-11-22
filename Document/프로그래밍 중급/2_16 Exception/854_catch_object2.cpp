//사용자 정의 예외클래스 만들기 //예시

#include <iostream>
using namespace std;

const char* account = "1234-5678";  //계좌번호
int sid = 1122;						//비밀번호
int balance = 1000;					//잔액

int main(void)
{
	char acc[10];
	int id;
	int money;

	cout << "계좌번호 입력: "; cin >> acc;
	cout << "비밀번호 4자리 입력: "; cin >> id;
	if (strcmp(account, acc) || sid != id)
		cout << "다음 입력을 다시 한번 확인 하세요" << endl;

	cout << "출금액 입력: "; cin >> money;
	if (balance < money)
		cout << "부족 금액: " << money - balance << endl;

	balance -= money;
	cout << "잔액: " << balance << endl;

	return 0;
}


/*

class AccountExpt			//사용자 정의 예외클래스
{
	char acc[10];
	int sid;
public:
	AccountExpt(char* str, int id) {
		strcpy_s(acc, str);
		sid = id;
	}
	void What() {
		cout << "계좌번호: " << acc << endl;
		cout << "비밀번호: " << sid << endl;
	}
};

int main(void)
{
	char acc[10];
	int id;
	int money;

	try {
		cout << "계좌번호 입력: ";		cin >> acc;
		cout << "비밀번호 4자리 입력: ";	cin >> id;

		if (strcmp(account, acc) || sid != id)
			throw AccountExpt(acc, id);
	}
	catch (AccountExpt& expt) {
		cout << "다음 입력을 다시 한번 확인 하세요" << endl;
		expt.What();
	}

	try {
		cout << "출금액 입력: ";
		cin >> money;
		if (balance < money) throw money;

		balance -= money;
		cout << "잔액: " << balance << endl;
	}
	catch (int money) {
		cout << "부족 금액: " << money - balance << endl;
	}
	return 0;
}
*/

//예외처리할 때 주의해야 할 사항
// 
//트랜잭션(Transaction)  *** 
// 
//	하나의 논리적 기능을 수행하기 위한 작업의 단위 또는 한꺼번에 모두 수행되어야 할 일련의 연산들을 의미
//	트랜잭션 처리가 정상적으로 완료된 경우 커밋(commit)을 하고, 
//	오류가 발생할 경우 원래 상태대로 롤백(rollback)을 한다.
//
//관련 함수 중 하나가 예외가 발생하면 모두 취소 처리해야 함  


//데이터베이스 트랜잭션의 4가지 특성
//
//원자성(Automicity)
//트랜잭션에서 정의된 연산들은 모두 성공적으로 실행되던지 아니면 전혀 실행되지 않은 상태로 남아 있어야 한다. (All or Nothing)
//
//일관성(Consistency)
//트랜잭션이 실행 되기 전의 데이터베이스 내용이 잘못 되어 있지 않다면
//트랜잭션이 실행된 이후에도 데이터베이스의 내용에 잘못이 있으면 안된다.
//
//고립성(Isolation)
//트랜잭션이 실행되는 도중에 다른 트랜잭션의 영향을 받아 잘못된 결과를 만들어서는 안된다.
//
//지속성(Durability)
//트랜잭션이 성공적으로 수행되면 그 트랜잭션이 갱신한 데이터베이스의 내용은 영구적으로 저장된다.