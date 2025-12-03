/*
* [파일 입출력(File I/O)]
	- 텍스트 I/O
		문자(char)단위로 읽고 쓰는 모드로 
		<< 와 >> 연산자는 모두 텍스트 I/O로 텍스트 파일만 입출력한다
	- 바이너리 I/O
		바이트(byte)단위로 읽고 쓰는 모드로
		텍스트 파일이 아닌 모든 종류의 파일(이미지, 동영상, 실행파일 등)을 입출력할 수 있다.


	C++ 표준은 3개의 클래스를 제공한다.
		1. ifstream  -> read
		2. ofstream	 -> write
		3. fstream   -> read & write
		
		이들은 각각 istream, ostream, iostream을 상속받기 때문에
		이들이 가진 입출력 함수들을 모두 사용할 수 있다.

	파일 입출력을 위한 기본적인 단계는 아래와 같다.
	1. 스트림 객체 생성				// fstream fs;
	2. 파일 open(스트림 연결)			// fs.open("file.txt");
	3. read & write					// fs.read(), fs.write()...
	4. close						// fs.close()
*/

#include <iostream>
#include <fstream>
using namespace std;

struct USERINFO
{
	char name[20];
	int age;
};

void ReadWrite_Text()
{
	// write (ofstream)
	{
		USERINFO man = { "Woojeong", 20 };

		// 1. 스트림 객체 생성
		ofstream fout;

		// 2. 파일 open(스트림 연결)
		fout.open("../test.txt");

		// 3. write
		fout << man.name << " " << man.age << endl;

		// 4. close
		fout.close();
	}

	// read (ifstream)
	{
		USERINFO man2;

		// 1. 스트림 객체 생성
		ifstream fin;

		// 2. 파일 open(스트림 연결)
		fin.open("../test.txt");
		if (fin.fail()) { cout << "fail. file open x." << endl; return; };

		// 3. read
		fin >> man2.name >> man2.age;

		// 4. close
		fin.close();

		cout << man2.name << " " << man2.age << endl;
	}
}

void ReadWrite_Binary()
{
	// write (ofstream)
	USERINFO man = { "홍길동", 20 };
	{
		ofstream fout;
		fout.open("../test.txt");

		fout.write((char*)&man, sizeof(man));	// 바이너리로 쓰기

		fout.close();
	}

	// read (ifstream)
	USERINFO man2;	// = { "", 10 };
	{
		ifstream fin;
		fin.open("../test.txt");
		if (fin.fail()) { cout << "fail. file open x." << endl; return; }

		fin.read((char*)&man2, sizeof(man));	// 바이너리로 읽기
		cout << man2.name << " " << man2.age << endl;

		fin.close();
	}
}

void main()
{
	ReadWrite_Text();
	ReadWrite_Binary();
}