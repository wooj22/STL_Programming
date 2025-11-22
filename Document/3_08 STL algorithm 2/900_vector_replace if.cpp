//벡터의 값을 조건부로 바꾸기 (람다)

//1. std::replace_if 사용

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec{ 6, 3, 8, 9, 1, 2, 8 };
    //5보다 큰 것을 10으로 변경하기
    std::replace_if(vec.begin(), vec.end(), [](int& i) { return i > 5; }, 10);

    for (int& i : vec) {
        std::cout << i << ' ';
    }

    return 0;
}

//2. std::transform 사용

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec{ 6, 3, 8, -9, 1, -2, 8 };
    // 부호 바꾸기
    std::transform(vec.begin(), vec.end(), vec.begin(), [](int& i) {  return -1 * i; });

    for (int& i : vec) {
        std::cout << i << ' ';
    }

    return 0;
}

//3. 루프 사용

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec{ 6, 3, 8, -9, 1, -2, 8 };
    // 부호 바꾸기
    for (int i = 0; i < vec.size(); i++) {
        vec[i] *= -1;
    }

    for (int& i : vec) {
        std::cout << i << ' ';
    }

    return 0;
}

//4. std::replace 사용

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec{ 6, 3, 8, 9, 1, 2, 8 };
    
    // 8을 7로 바꾸기
    std::replace(vec.begin(), vec.end(), 8, 7);

    for (int& i : vec) {
        std::cout << i << ' ';
    }

    return 0;
}

//5. std::find_if 사용

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec{ 6, 3, 8, -9, 1, -2, 8 };

    // 첫 번째 음수 값을 찾아 0으로 바꿉니다.
    auto it = std::find_if(vec.begin(), vec.end(), [](int& i) { return i < 0; });
    if (it != vec.end()) {
        *it = 0;
    }

    for (int& i : vec) {
        std::cout << i << ' ';
    }

    return 0;
}
