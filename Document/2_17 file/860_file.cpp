/*
 C++ 표준은 3개의 클래스 제공
	파일 읽기를 위해			ifstream, 
	쓰기를 위해				ofstream, 
	읽기와 쓰기를 동시에		fstream 

	이들은 각각 istream, ostream, iostream을 상속받기 때문에 
	이들이 가진 입출력 함수들을 모두 사용할 수 있다

 - 파일 입출력 스트림 클래스는 파일을 프로그램과 연결한다
 - 텍스트 I/O는 '문자' 단위로 읽고 쓰는 모드이며, 바이너리 I/O는 '바이트' 단위로 읽고 쓴다
 - << 와 >> 연산자는 모두 텍스트 I/O로 텍스트 파일만 입출력한다

 - 파일 입출력을 위해서는 
   1. 스트림 객체를 생성하고,								//fstream a;
   2. 읽거나 쓰고자 하는 파일을 열어 스트림과 연결하고,		//a.open("file.txt")

   3. 파일 읽기나 파일 쓰기를 진행하며,					//a.read(), a.write() ...

   4. 마지막에 스트림 즉 파일을 닫아야 한다				//a.close();	
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream file("input.txt");

	if (file.is_open())
		cout << "파일이 열렸습니다." << endl;
	else
		cout << "파일을 열 수 없습니다." << endl;


	file.close(); //읽고 난 후에는 꼭 닫아줘야 합니다. 
	return 0;
}

/*
- 경로 지정 방법 : 절대 경로 지정 방법과 상대 경로 지정 방법이 있다.
  절대 경로는 파일이 위치한 디스크 드라이브의 최상의(root) 폴더(디렉토리)부터 파일이 위치한 폴더까지의 경로를 말한다. 
  상대 경로는 현재 화면에 보이는 소스 파일이 위치한 폴더 부터 헤더 파일이 위치한 폴더까지 경로를 말한다.

- 경로와 경로 또는 경로와 파일 구분하는 역슬리쉬(\)는 원칙적으로 2개를 연속해서 써야 하지만 
  비쥬얼 스튜디오는 문자열 내부에 역슬래시를 1개만 써도 2개를 쓴 것으로 인식한다.

 #include "D:\\kookgi_oje\\C\\workspace\\0103\\0103\\include\\config.h"  => 원래 표현
 #include "D:\kookgi_oje\C\workspace\0103\0103\include\config.h"   // 비주얼 스튜디오는 1개만 써도 된다.
 #include "D:/kookgi_oje/C/workspace/0103/0103/include/config.h"  => 역슬래시 대신 슬래시를 사용해도 된다.

-  "."  => 현재 화면에 보이는 파일이 위치한 폴더
-  ".." => 현재 화면에 보이는 파일이 위치한 폴더의 한 단계 상위 폴더
*/