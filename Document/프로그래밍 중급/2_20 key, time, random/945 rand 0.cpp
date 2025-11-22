#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//rand() : 0부터 약 6만의 숫자까지 숫자를 리턴합니다. // 0~32767

int main(void)
{
    // rand()
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << endl;

    // rand % b					: 0~(b-1)
    cout << rand() % 10 << endl;
    cout << rand() % 10 << endl;
    cout << rand() % 10 << endl;

    // rand % b + 1				: 1~b  //b로 나눈 나머지에 1을 더함.그러면 1 ~b의 범위가 설정됨    
    cout << rand() % 10 + 1 << endl;
    cout << rand() % 10 + 1 << endl;
    cout << rand() % 10 + 1 << endl;

    //srans() ---------------------------------------

    srand(1234); cout << rand() << endl;
    srand(1234); cout << rand() << endl;
    srand(1234); cout << rand() << endl;

    cout << endl;

    for (int i = 0; i < 5; ++i)
    {
        srand(i);
        printf("rand : %d\n", rand());
    }
    cout << endl;

    srand(rand()); cout << rand() << endl;
}

//----------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>

void main()
{
    srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여 

    printf("난수 : %d\n", rand());
    printf("난수 : %d\n", rand());
    printf("난수 : %d\n", rand());
    printf("난수 : %d\n", rand());
    printf("난수 : %d\n", rand());


    // 난수 %10 = 난수의 범위 0~9까지 한정
    printf("난수 : %d\n", rand() % 10);

    // 1 ~ 6  주사위 던지기 값을 출력해 보세요.
}

/*

//1에서 10사이의 난수를 출력하는 예

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {

  srand((unsigned)time(0));

  int random_integer;
  int lowest = 1, highest = 10;
  int range = (highest - lowest) + 1;

  for (int index = 0; index < 20; index++) {
    random_integer = lowest + int(range*rand() / (RAND_MAX + 1.0));
    cout << random_integer << endl;
  }
}
*/


/*
// 1 부터 45까지의 숫자를 중복없이 6개 출력하는 로또 번호추첨 예제

#define MAX 45          //1부터 45 숫자
#define NUMBER 6        //6개 숫자출력

void main()
{
    int i, tmp;
    int save[NUMBER];
    int count = 0;
    int isSame = 0;
    srand(time(0));

    //숫자 추출
    while (count < NUMBER) {
        isSame = 0;
        tmp = rand() % MAX + 1;//1부터 45 출력
        for (int i = 0; i < count; i++) { //중복검사
            if (tmp == save[i]) { //중복이 있을때
                isSame = 1;
                break;
            }
        }
        if (isSame == 0) { //중복없음
            save[count] = tmp;
            count++;
        }
    }

    //결과 출력
    printf("추첨 숫자 : ");
    for(i =0; i < NUMBER; i++)
        printf("%d ", save[i]);
    printf("\n");
}

*/

/*

//비결정적 난수 생성기(Non-deterministic Random Generator)

    #include <iostream>
    #include <random>

    int main() {

        std::random_device rd;

        std::mt19937 mt(rd());

        std::uniform_int_distribution<innt> dist(0, 99);

        std::cout << dist(mt) << std::endl;

    }
*/