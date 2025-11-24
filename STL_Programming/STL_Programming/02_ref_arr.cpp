// 배열 참조
// 식별자의 타입은 식별자와 가장 가까운 *, &, [], ()를 따라간다.
// 참조 변수 선언을 위해 &가 가장 가깝도록 괄호로 묶어주면 된다.

int main(void)
{
	// 정적 1차원 배열
	int arr[3] = { 1,2,3 };
	int(&arr_ref)[3] = arr;
	int& arr1_ref = arr[0];

	// 정적 2차원 배열
	int arr2[2][3];
	int(&arr2_ref)[2][3] = arr2;

	// 동적 1차원 배열
	int* ptr = new int[5];
	int* &ptr_ref = ptr;

	// 동적 2차원 배열 (배열포인터)
	int(*ptr2)[3] = new int[2][3];
	int(*&ptr2_ref)[3] = ptr2;

	// 동적 2차원 배열 (2중 포인터)
	int** ptr3 = new int* [2];
	for (int i = 0; i < 2; i++)
		ptr3[i] = new int[3];
	int** ptr3_ref = ptr3;
}