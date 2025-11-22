//우선순위 큐

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

//구조체 활용 및 구조체 내부 연산자 오버로딩

#include <iostream>
#include <queue>
#include <functional>    // greater
using namespace std;

struct Student {
    int id;
    int math, eng;
    Student(int num, int m, int e) : id(num), math(m), eng(e) {}    // 생성자 정의

    // 그냥 점수에 상관 없이 학번기준 학번이 작은것이 Top 을 유지 한다
    bool operator<(const Student s) const {
        return this->id > s.id;
    }
};

int main() {
    priority_queue<Student> pq;

    pq.push(Student(3, 100, 50));
    pq.push(Student(1, 60, 50));
    pq.push(Student(2, 80, 50));
    pq.push(Student(4, 90, 50));
    pq.push(Student(5, 70, 40));

    // 학번을 기준으로 작은 것이 먼저 출력이 된다 그 이유는 구조체 내부의 연산자 오버로딩에 있다
    while (!pq.empty()) {
        Student ts = pq.top(); pq.pop();
        cout << "(학번, 수학 , 영어 ) : " << ts.id << ' ' << ts.math << ' ' << ts.eng << '\n';
    }

    return 0;
}

// 함수 객체 활용 ----------------------------------------------------------
//
//      priority_queue<int, vector<int>, less<int>> pq;

#include <iostream>
#include <queue>
#include <functional>    // greater
using namespace std;

struct Student {
    int id;
    int math, eng;
    Student(int num, int m, int e) : id(num), math(m), eng(e) {}    // 생성자 정의
};

// 학번을 기준으로 학번(id) 값이 큰 것이 Top 을 유지 하도록 한다.
struct cmp {
    bool operator()(Student a, Student b) {
        return a.id < b.id;
    }
};

int main() {
    // 위에서 만든 cmp 구조체를 넣어 준다.
    priority_queue<Student, vector<Student>, cmp> pq;

    pq.push(Student(3, 100, 50));
    pq.push(Student(1, 60, 50));
    pq.push(Student(2, 80, 50));
    pq.push(Student(4, 90, 50));
    pq.push(Student(5, 70, 40));

    while (!pq.empty()) {
        Student ts = pq.top(); pq.pop();
        cout << "(학번, 수학 , 영어 ) : " << ts.id << ' ' << ts.math << ' ' << ts.eng << '\n';
    }

    return 0;
}

