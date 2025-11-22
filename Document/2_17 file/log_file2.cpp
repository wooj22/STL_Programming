#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

void log_msg(char* msg)
{
	FILE* fp = nullptr;
	fp = fopen("logfile.log", "a");
	fprintf(fp, "%s\n", msg);
	fclose(fp);
}

void main() 
{
	char buff[200];
	memset(buff, 0, sizeof(buff));
	sprintf(buff, "Sock Error = %d\n", 1000);

	log_msg(buff);
}


