/*
	[ class ]

	struct랑 똑같은데 private, protected, public 지정 가능


	[ 객체 지향 프로그래밍의 특징 ]
	1. 캡슐화(Encapsulation) : 데이터와 함수를 하나로 묶고, 접근 제한(private/protected/public)으로 내부 구현 숨김
	2. 상속(Inheritance)	    : 기존 클래스 기능을 재사용하고 확장 가능
	3. 다형성(Polymorphism)  : 동일 인터페이스로 다양한 동작 가능 (overloading, virtual overriding)
	4. 추상화(Abstraction)   : 불필요한 구현은 숨기고, 필요한 핵심 기능만 제공


	[ SOLID 클래스 설계 원칙 ]
	1. 단일 책임 원직(SRP, Single Responsibillty Principle)
		클래스는 한가지 책임만 진다. 여러개가 섞이면 유지보수가 어렵다.

	2. 개방-폐쇄 원칙 (OCP, Open/ Closed Principle)
		클래스는 확장에는 열려있고, 수정에는 닫혀있어야 한다.
		기존 코드를 바꾸지 않고 기능을 추가할 수 있어야 안정적인 유지보수가 가능하다.
	
	3. 리스코프 치환 원칙 (LSP, Liskov Substitution Principle)
		자식 클래스는 부모 클래스를 대체 가능해야한다.
		즉, 자식 객체를 부모 타입으로 써도 프로그램 동작이 깨지면 안 된다.

	4. 인터페이스 분리 원칙 (ISP, Interface Segergation Principle)
		불필요한 메소드를 강요하지 말고, 작은 인터페이스로 나눠야한다.

	5. 의존 역전 원칙 (DIP, Dependency Inversion Principle)
		부모 클래스가 자식 클래스에 의존하지 않고, 추상화에 의존해야한다.
*/


#include <iostream>
#include <vector>
#include <memory>

// 인터페이스 분리 (ISP)
// 작은 인터페이스로 분리하여 클래스의 메소드로 불필요한 기능 강제 X
class IPrintable
{
public:
	virtual void Print() const = 0;
	virtual ~IPrintable() = default;
};

class ISavale
{
public:
	virtual void Save() const = 0;
	virtual ~ISavale() = default;
};

// 단일 책임 (SRP)
// 하나의 책임: 문서 관리, 페이지 추가, 출력/저장
class Document : public IPrintable, public ISavale
{
private: 
	std::vector<std::string> pages;
public:
	void AddPage(const std::string& text) { pages.push_back(text); }

	// 기존 코드 수정 없이 기능 확장 (OCP)
	// 기능 확장 가능: Report 상속해 Summary 추가 가능, 기존 Document 수정 없음
	void Print() const override
	{
		for (const auto& page : pages) std::cout << page << std::endl;
	}

	void Save() const override {
		std::cout << "Document saved with " << pages.size() << " pages.\n";
	}
};

// 의존 역전 (DIP)
// Document에 직접 의존하지 않고 인터페이스 IPrintable에 의존
class Printer
{
private:
	const IPrintable& printable;  

public:
	Printer(const IPrintable& p) : printable(p) {}
	void DoPrint() { printable.Print(); }
};

// 상속구조 치환 (LSP)
// Document 대신 Report를 사용할 수 있음
class Report : public Document
{
public :
	void AddSummary(const std::string& text) { AddPage(text); }
};

int main()
{
	Report report;
	Printer printer(report);	// LSP 만족 (자식이 부모를 대신함)
	printer.DoPrint();
}