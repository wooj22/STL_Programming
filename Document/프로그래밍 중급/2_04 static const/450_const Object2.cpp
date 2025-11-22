// 문제 // const 객체 

#include <iostream>
using namespace std;

class Coffee
{
public:
	Coffee() { SugarCount = 0;	bTakeout = false; }

	const int& GetSugarCount() { return SugarCount; }
	void AddSugar() { SugarCount++; }
	bool IsTakeout() const { return bTakeout; }

private:
	int SugarCount;
	bool bTakeout;

};

int main(void)
{
	const Coffee* A = new Coffee();		// const * 로 동적할당
	//Coffee const * A = new Coffee();	// same expression

	Coffee* const B = new Coffee();

	//아래코드 중 에러가 발생하는 곳은?

	A->AddSugar();						// error
	B->AddSugar();						// success

	A->IsTakeout();						// success
	B->IsTakeout();						// success
	B = new Coffee();					// error

	A->GetSugarCount();					// error  // const function 아님
	B->GetSugarCount();

	return 0;
}