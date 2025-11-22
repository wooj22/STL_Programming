//함수를 호출과 포인터의 형  //선언형식과 실형식

#include <iostream>
using namespace std;

class Person
{
public:
	void Sleep() { cout << "Sleep" << endl; }
};

class Student : public Person
{
public:
	void Study() { cout << "Study" << endl; }
};

class WorkStudent : public Student
{
public:
	void Work() { cout << "Work" << endl; }
};

//함수를 호출할때 사용된 포인터의 형에 따라서 호출되는 함수가 결정된다 

int main(void)
{
	Person* ptr1 = new Student();		//선언형식 Person //실형식 Student
	Person* ptr2 = new WorkStudent();
	Student* ptr3 = new WorkStudent();

	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();						//선언형식을 따른다. ***  //정적바인딩

	delete ptr1; delete ptr2; delete ptr3;

	return 0;
}

//정적바인딩 vs 동적바인딩