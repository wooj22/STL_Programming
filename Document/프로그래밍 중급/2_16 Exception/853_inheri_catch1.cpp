// 상속관계시 주의 사항 
// 
//		업캐스팅에 의해 부모클래스로 받아지는 경우 주의 

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

class ExceptA
{
public:
	void What() { cout << "ExceptA 예외" << endl; }
};

class ExceptB : public ExceptA
{
public:
	void What() { cout << "ExceptB 예외" << endl; }
};

class ExceptC : public ExceptB
{
public:
	void What() { cout << "ExceptC 예외" << endl; }
};

void ExcepFunction(int ex)
{
	if (ex == 1)		throw ExceptA();
	else if (ex == 2)	throw ExceptB();
	else				throw ExceptC();
}

int main(void)
{

	int exID;
	cout << "발생시킬 예외의 숫자: ";
	cin >> exID;

	try {
		ExcepFunction(exID);
	}
	catch (ExceptA& ex) {
		ex.What();
	}
	catch (ExceptB& ex) {
		ex.What();
	}
	catch (ExceptC& ex) {
		ex.What();
	}

	return 0;
}

/*
// 올바르게 수정하세요.

int main(void)
{
	int exID;
	cout<<"발생시킬 예외의 숫자: ";
	cin>>exID;

	try{
		ExcepFunction(exID);
	}
	catch(ExceptC& ex){
		ex.What();
	}
	catch(ExceptB& ex){
		ex.What();
	}
	catch(ExceptA& ex){
		ex.What();
	}
	return 0;
}
*/