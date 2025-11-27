/*
	[ const를 포인터 변수 참조에 사용할 경우 ]

   포인터 참조 시 참조 타입의 "가리키는 타입"은 반드시 원본 포인터 타입과 동일해야 한다.
   따라서 int* → const int*& 와 같은 타입 승격은 불가능하다.

    - const T*    : 데이터 읽기 전용  (이 경우를 주의)
    - T* const    : 포인터 주소 변경 불가
    - const T* const : 데이터와 포인터 모두 읽기 전용

    즉, 포인터 변수의 const는 무조건 참조변수에서 똑같이 선언해야하며 
    기존에 const가 없을경우 가리키는 타입의 승격은 불가하지만 포인터주소 const는 추가 가능하다.

	>> 포인터 참조는 헷갈리기 쉬우므로, 굳이 사용하지 말고 그냥 const 포인터를 사용하자!
*/

int main()
{
    int data = 10;

    // 일반 포인터
    int* ptr1 = &data;
    int*& ref1 = ptr1;             // 가능 - 주소와 값 모두 변경 가능
    int* const& ref2 = ptr1;       // 가능 - 값 변경 가능, 주소 변경 불가
    // const int*& ref_err = ptr1; // 불가능 - 가리키는 타입 불일치


    // 데이터가 const인 포인터
    const int* ptr2 = &data;
    const int*& ref3 = ptr2;         // 가능 - 가리키는 타입이 둘다 cosnt이므로 일치
    const int*& const ref4 = ptr2;   // 가능


    // 포인터 자체가 const
    int* const ptr3 = &data;
    const int*& ref5 = ptr3;        // 불가능 - 가리키는 타입 불일치
    int* const& ref6 = ptr3;        // 가능


    // 데이터와 포인터 모두 const
    const int* const ptr4 = &data;
    const int* const& ref7 = ptr4;  // 가능

    
    // 그냥 포인터로 참조해...
    {
        int* p = new int(10);
        const int* cp = p;
        // 얼마나 편함!!
    }
}