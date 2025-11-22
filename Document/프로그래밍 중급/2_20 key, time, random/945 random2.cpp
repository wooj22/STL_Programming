https://docs.microsoft.com/ko-kr/cpp/standard-library/random?view=msvc-170

//비결정적 난수 생성기(Non-deterministic Random Generator)
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=drvoss&logNo=220340760979

//연속확류분포 uniform_int_distribution,  uniform_real_distribution

//베르누이 분포 bernoulli_distribution 

#include <iostream>
#include <random>
using namespace std;

inline bool RandomMtPick(float percent)
{
    random_device rd;
    mt19937_64 mt(rd());

    bernoulli_distribution d(percent);  //

    return d(mt);
}

void main()
{
    int t = 0, f = 0;
    for (int i = 0; i < 10000; i++)
    {
        bool b = RandomMtPick(0.4);
        if (b) {
            t++;
        }
        else {
            f++;
        }
    }
    cout << t << " " << f << endl;
}

//출처: https://jeunjeun.tistory.com/28 
