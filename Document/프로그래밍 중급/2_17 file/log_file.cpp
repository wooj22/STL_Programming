#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdarg>
#include <ctime>
#include <sstream>
#include <cstring>
#include <cstdio>

using namespace std;

void ClearFileLog(const char* pszFileName)
{
	//unlink(pszFileName);
}

void FileLog(const char* pszFileName, const char* pszLog, ...)
{
	fstream _streamOut;
	_streamOut.open(pszFileName, ios::out | ios::app);

	va_list argList;		//가변 인자
	char cbuffer[1024];
	va_start(argList, pszLog);
	vsnprintf(cbuffer, 1024, pszLog, argList);
	va_end(argList);

	_streamOut << cbuffer << endl;
	_streamOut.close();
}

void main() {

	FileLog("test.log","logggggg");
}