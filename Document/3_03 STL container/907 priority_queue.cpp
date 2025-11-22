//우선순위 큐 //priority_queue
//      우선순위 큐 내부에 새로운 자료가 들어가면, 
//      자신의 부모 노드와 크기를 비교하면서 조건에 따라 swap

#include <iostream>
#include <queue>
#include <functional>    // greater, less
using namespace std;
int main() {
    priority_queue<int> pq;  // - >  priority_queue<int, vector<int>, less<int>> pq;

    // 우선순위 큐에 원소를 삽입 (push) 한다 
    pq.push(4);
    pq.push(7);
    pq.push(3);
    pq.push(1);
    pq.push(10);

    cout << "우선순위 큐 사이즈 : " << pq.size() << "\n";
    // 우선순위 큐가 비어 있지 않다면 while 문을 계속 실행
    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
    return 0;
}

// pair의 second를 기준으로 오름차순 정렬---------------------------------------------- -

#include <queue>
using namespace std;

struct compare {
    bool operator()(int a, int b) { return a > b; }
};

int main() 
{    
	priority_queue<int, vector<int>, compare> pq; 

    // < 자료형 int, 컨테이너 vector, 사용자 정의 비교연산자 compare >
}

//pair의 second를 기준으로 오름차순 정렬 -----------------------------------------------

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};
int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
}