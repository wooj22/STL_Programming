#include <iostream>
using namespace std;
#define SIZE  4
#define ROWS    2
#define COLS    3


int main()
{
	// 1차원 배열 동적 할당
	{
		int* arr = new int[SIZE] { 10, 20, 30, 40 };

		for (int i = 0; i < SIZE; ++i)
			cout << "arr[" << i << "] = " << arr[i] << endl;

		delete[] arr;
		cout << endl;
	}

	// 2차원 배열 동적 할당 (2중 포인터)
    {
        int** arr2 = new int* [ROWS];
        for (int i = 0; i < ROWS; ++i)
        {
            arr2[i] = new int[COLS] {};
        }

        int value = 1;
        for (int i = 0; i < ROWS; ++i)
        {
            for (int j = 0; j < COLS; ++j)
            {
                arr2[i][j] = value++;
            }
        }

        for (int i = 0; i < ROWS; ++i)
        {
            for (int j = 0; j < COLS; ++j)
            {
                cout << "arr2[" << i << "][" << j << "] = " << arr2[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < ROWS; ++i)
        {
            delete[] arr2[i];
        }
        delete[] arr2;
    }
}