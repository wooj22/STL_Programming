//rand() 코드의 문제점
// 
//      시드값이 너무 천천히 변한다.
//      0부터 99까지 균등하게 난수를 생성하지 않는다.
//      rand() 자체도 별로 뛰어나지 않다.

#include <iostream>
#include <random>

int main()
{
    // 시드값을 얻기 위한 random_device 생성.
    std::random_device rd;

    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    std::mt19937 gen(rd());

    // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    std::uniform_int_distribution<int> dis(0, 99);

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Ramdom Num : " << dis(gen) << std::endl;
    }
}

/*

#include <iomanip>
#include <iostream>
#include <map>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> dist( 0, 1);   // 평균, 표준 편차

    std::map<int, int> hist{};
    for (int n = 0; n < 10000; ++n) {
        ++hist[std::round(dist(gen))];
    }
    for (auto p : hist) {
        std::cout << std::setw(2) << p.first << ' '
            << std::string(p.second / 100, '*') << " " << p.second << '\n';
    }
}

*/