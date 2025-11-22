//https://andjjip.tistory.com/293

//예외 클래스 계층 --------------------------------------------------------------------------------------
//
//	예외를 클래스로 정의하면 객체 지향의 여러가지 기법을 활용할 수 있다.
//	비슷한 종류의 예외라면 상속 계층을 구성하여 
//	반복된 코드를 줄이고 에러 처리 함수를 가상으로 선언하면 다형성의 이점도 누릴 수 있다.

//다음 예제는 100 이하의 양의 짝수만 입력받으며 그 외의 숫자는 예외 처리한다.
#include <stdio.h>

class ExNegative
{
protected:
	int number;
public:
	ExNegative(int n) : number(n) {}
	virtual void PrintError() { printf("%d는 음수이므로 잘못된 값입니다.\n", number); }
};

class ExTooBig : public ExNegative
{
public:
	ExTooBig(int n) : ExNegative(n) {}
	virtual void PrintError() { printf("%d는 너무 큽니다. 100보다 작아야합니다.\n", number); }
};

class ExOdd : public ExTooBig
{
public:
	ExOdd(int n) : ExTooBig(n) {}
	virtual void PrintError() { printf("%d는 홀수입니다. 짝수여야 합니다.\n", number); }
};

int main()
{
	int n;
	for (;;) {
		try
		{
			printf("숫자를 입력하세요(0:종료) : ");
			scanf_s("%d", &n);
			if (n == 0) break;
			if (n < 0) throw ExNegative(n);
			if (n > 100) throw ExTooBig(n);
			if (n % 2 != 0) throw ExOdd(n);

			printf("%d 숫자는 규칙에 맞는 숫자입니다.\n", n);
		}

		catch (ExNegative& e)
		{
			e.PrintError();
		}
	}
}

//ExNegative를 최상위 클래스로 정의하고 에러 메세지를 출력하는 PrintError 함수를 가상으로 선언
//catch 블록을 일일이 작성할 필요 없이 루트 타입인 ExNegative 객체만 받아 처리하면 된다.


//예외의 캡슐화 ---------------------------------------------------------------------------------------
// 
//	클래스 동작 중에 특정한 예외가 발생할 수 있다면 
//	이 예외에 대한 모든 처리도 클래스 안에 완벽하게 통합해 넣는 것이 좋다.
//	예외 클래스를 지역적으로 선언해 두면 
//	어떤 상황에서라도 클래스 스스로 예외를 처리할 수 있어 안전성과 재활용성이 향상된다.

// 파일이름 : ExceptionClass.cpp
#include <stdio.h>

class MyClass
{
public:
	class Exception
	{
	private:
		int ErrorCode;

	public:
		Exception(int ae) : ErrorCode(ae) {}
		int GetErrorCode() { return ErrorCode; }
		void ReportError()
		{
			switch (ErrorCode)
			{
			case 1:
				puts("메모리가 부족합니다.");
				break;
			case 2:
				puts("연산 범위를 초과했습니다.");
				break;
			case 3:
				puts("하드 디스크가 가득 찼습니다.");
				break;
			}
		}
	};

	void calc()
	{
		try
		{
			if (true /*에러발생*/) throw Exception(1);
		}
		catch (Exception& e)
		{
			printf("에러 코드 = %d => ", e.GetErrorCode());
			e.ReportError();
		}
	}
	void calc2() throw(Exception)
	{
		if (true /*에러발생*/) throw Exception(2);
	}
};

int main()
{
	MyClass m;
	m.calc();
	try
	{
		m.calc2();
	}
	catch (MyClass::Exception& e)
	{
		printf("에러 코드 = %d => ", e.GetErrorCode());
		e.ReportError();
	}
}


//생성자와 연산자의 예외 ---------------------------------------------------------------------------
//		생성자에서 예외가 던져져도 아무 문제 없을까?

#include <iostream>

struct S
{
	struct Error { };
	S(int i = 0) { if (i < 0) throw Error(); }
};

int main()
{
	try
	{
		S* p = new S(-1);
	}
	catch (const S::Error& e)
	{
		std::cerr << "oops\n";
	}
}

//-----------------------------------------------------------
#include <stdio.h>

class IntOver
{
private:
	int num;

public:
	IntOver(int a)
	{
		if (a <= 100)	{ num = a; }
		else			{ throw a; }				// 생성자 종료 처리
	}

	IntOver& operator += (int b)
	{
		if (num + b <= 100) { num += b; }
		else				{ throw num + b; }		//
		return *this;
	}

	void OutValue() { printf("%d\n", num); }
};

int main()
{
	try
	{
		IntOver i(85);
		i += 12;
		i.OutValue();
	}
	catch (int n)
	{
		printf("%d는 100보다 큰 정수이므로 다룰 수 없습니다.\n", n);
	}
}

//try 블록 함수
//	함수 실행 중에 항상 예외가 발생할 수 있다면 함수 본체 자체를 try 블록으로 완전히 묶는다.
//	함수 실질적인 코드는 모두 try 블록에 작성되어있으므로 본체를 따로 만들 필요없이 try 블록 자체를 함수의 본체로 만들면 된다.
//	함수의 시작과 끝을 표시하는{ } 괄호를 없애고 try와 catch 블록을 함수의 본체인 것처럼 작성하는 것이다.
//	괴상해보이는 코드지만 이런 이상한 문법은 생성자의 경우, 
//	본체 이전에 실행되는 초기화 리스트까지 예외 처리 블록에 포함시키려면 이런 구문이 필요하다.

// 파일이름 : tryCtor.cpp
#include <stdio.h>

class IntOver
{
private:
	int num;

public:
	IntOver(int a)
	try : num(a) {
		if (a > 100) { throw a; }
	}
	catch (int a)
	{
		printf("%d은 100보다 더 큽니다.\n", a);
	}

	void OutValue() { printf("%d\n", num); }
};

int main()
{
	try
	{
		IntOver i(101);
		i.OutValue();
	}
	catch (int n)
	{
		printf("무효한 객체임.\n", n);
	}
}

//예외를 생성자에서 던질 때 주의해야 할 점이 하나 있습니다. 
//바로 생성자에서 예외가 발생 시에 소멸자가 호출되지 않는다 라는 점입니다. ***
//따라서, 만일 예외를 던지기 이전에 획득한 자원이 있다면 catch 에서 잘 해제시켜 줘야만 합니다.


//noexcept
// 
//	프로그래머가 컴파일러에게 주는 힌트. 
//	컴파일러가 어떤 함수가 절대로 예외를 발생시키지 않는다는 사실을 안다면, 
//	여러가지 추가적인 최적화를 수행할 수 있습니다.
/*
	#include <iostream>

	int foo() noexcept {}

	int bar(int x) noexcept { throw 1; }

	int main() { foo(); }
*/