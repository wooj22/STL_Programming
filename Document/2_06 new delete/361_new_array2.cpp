//  배열을 힙에 할당하면 런타임시 크기를 정할 수 있는 장점 (동적할당)

#include <iostream>
using namespace std;

int main(void)
{
	int size = 10;
	int* pnum = new int[size];			//일반 배열과 달리 변수 값으로 설정 가능
	delete[] pnum;						//배열의 경우에는 대괄호를 표시해 전체를 해제.				

	//------------------------------------------------------------
	int num = 3;
	float* pfloat = nullptr;			//초기화 nullptr
	pfloat = new float[num];	

	for (int i = 0; i < num; i++) {
		pfloat[i] = i + 1.1;
		//cout << pfloat[i] << " ";
	}
	cout << endl;
	delete[] pfloat;

	//------------------------------------------------------------
	double* pdouble{ new double[5] };	//C++11 // 초기화
	delete[] pdouble;

	return 0;
}


// 2차원 배열을 동적으로 할당하기 -----------------------------------------

	#include <iostream>
	using namespace std;

	int main()
	{
		int rows = 3;
		int** table = nullptr;		   		//가변배열 //2차원 배열과 같은 메모리 형태는 아님

		table = new int* [rows];	   		//int*
		table[0] = new int[4]{1,2,3,4};		//int
		table[1] = new int[3]{10,20,30};
		table[2] = new int[1]{};

		for (int row = 0; row < rows; row++)
			delete[] table[row];
		delete[] table;

		return 0;
	}


// 두가지를 비교해 보세요.

	//----------------------------------------------------------------
	int height = 6, width = 8;

	int** arr = new int* [height];
	for (int i = 0; i < height; i++)	arr[i] = new int[width];

	for (int i = 0; i < height; i++)	delete arr[i];
	delete arr;

	//----------------------------------------------------------------
	int height = 8, width = 6;
	int** arr = new int* [height];
	arr[0] = new int[width * height];

	for (int i = 1; i < height; i++) {
		arr[i] = arr[i - 1] + width;
	}

	delete arr[0];
	delete arr;
}