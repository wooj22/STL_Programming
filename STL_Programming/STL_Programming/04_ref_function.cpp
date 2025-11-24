// 함수와 함수 포인터 참조

int Add(int a, int b) { return a + b; }

int main(void)
{
	// 함수 참조
	int(&ref_func1)(int, int) = Add;

	// 함수 포인터 참조
	int (*ref_func2)(int, int) = Add;

	// 함수 포인터 참조 참조
	int (*&ref_func3)(int, int) = ref_func2;
}