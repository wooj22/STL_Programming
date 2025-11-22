//가변인자 템플릿(Variadic template)를 활용하여 tuple 전체 요소를 출력

#include <iostream>
#include <tuple>
using namespace std;

//튜플과 index_sequence를 받아서 튜플 전체 요소를 출력
template<typename TP, size_t ... I>
void print_tuple_imp(const TP& tp, const index_sequence<I...>&)
{
    int x[] = { get<I>(tp)... };

    for (auto& n : x)
        cout << n << " ";
}

template<typename TP>
void print_tuple(const TP& tp)
{
    // 튜플 사이즈를 구해서 index_sequence를 생성하여 print_tuple_imp에 전달
    print_tuple_imp(tp, make_index_sequence<tuple_size<TP>::value>());
}

int main()
{
    index_sequence is = make_index_sequence<3>();  // index_sequence<0,1,2>  인덱스를 타입으로 변환

    tuple<int, int, int> tp(1, 2, 3);
    print_tuple(tp);
}
