#include <iostream>
using namespace std;

struct Person {
	char name[30];
	int age;
	char gender;
};

int main()
{
	// struct new
	{
		Person* p = new Person{ "양우정", 24, 'F' };

		cout << "name  : " << (*p).name << endl;
		cout << "age   : " << p->age << endl;
		cout << "gender: " << (*p).gender << endl;

		delete p;
	}

	// struct array new
	{
		Person* parray = new Person[3]
		{
			{ "양우정", 24, 'F' },
			{ "양우징", 25, 'M' },
			{ "양우장", 26, 'M' }
		};

		for (size_t i = 0; i < 3; i++)
		{
			cout << "name  : " << (parray + i)->name << endl;
			cout << "age   : " << (parray + i)->age << endl;
			cout << "gender: " << (parray + i)->gender << endl;
		}

		delete[] parray;
	}
}