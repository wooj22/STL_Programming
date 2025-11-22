//우선순위 큐 //priority_queue

#include <queue>
using namespace std;

//우선순위 큐 내부에 새로운 자료가 들어가면, 자신의 부모 노드와 크기를 비교하면서 조건에 따라 swap
struct compare {
    bool operator()(int a, int b) { return a > b; }
};

int main()
{
    // 자료형 int, 컨테이너 vector, 사용자 정의 비교연산자 compare
    priority_queue<int, vector<int>, compare> pq;
}

/*

//pair의 second를 기준으로 오름차순 정렬 -------------------------------------------------

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};
int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
}

*/