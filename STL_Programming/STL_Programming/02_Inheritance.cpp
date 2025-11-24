/*
	[ 부모 클래스 선정 원칙 ]

	1. is-a (~은 ~이다) 관계가 성립한다면? >> 상속
	 - 자식클래스가 부모클래스와 is-a관계가 성립한다면 올바른 상속이다.
	 - 다형성 가능
	 - LSP 준수 필요(자식이 부모 대체 가능)
	 ex) 고양이는 동물이다.
	 ex) 사과은 과일이다.

	2. has-a (~은 ~을 가진다) 관계가 성립한다면? >> 포함/집합
	 - 클래스가 다른 객체를 포함(조합)할 때 has-a 관계가 성립한다.
	 - 상속이 필요 없고, 다형성보다 재사용/ 조합이 목적이다.
	 ex) 플레이어는 인벤토리를 가진다.
	 ex) 차는 엔진을 가진다.
*/


/*  Cat is a Animals  */
class Animals
{
public:
	virtual void Move() {}
};

class Cat : public Animals	// 상속
{
public:
	void Move() override {}
};


/*  Car has-a Engine  */
class Engine {
public:
	void Start() {}
};

class Car {  
private:
	Engine engine;  // 포함
public:
	void StartCar() { engine.Start(); }
};