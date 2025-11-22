#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    // { 3, 5 } 값이 각각 v 벡터에 존재하는지 확인하기             // find
    const auto v = { 1, 2, 3, 4 };

    for (const int n : {3, 5})
        (std::find(v.begin(), v.end(), n) == std::end(v))
        ? std::cout << "v does not contain " << n << '\n'
        : std::cout << "v contains " << n << '\n';


    // 각 array 안에 짝수가 있는지 검사 후 출력               // find_if
    //  { 3, 1, 4 }, { 1, 3, 5}

    auto is_even = [](int i) { return i % 2 == 0; };
    auto arlist = { std::array { 3, 1, 4 } , std::array { 1, 3, 5} };

    for (auto const& w : arlist)
        if (auto it = std::find_if(std::begin(w), std::end(w), is_even); it != std::end(w))
            std::cout << "w contains an even number " << *it << '\n';
        else
            std::cout << "w does not contain even numbers\n";
}