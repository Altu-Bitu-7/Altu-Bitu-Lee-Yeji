#include <iostream>
#include <queue>

using namespace std;

// 1부터 n까지의 수로 queue 채워주기
void makeQueueFull(queue<int>& q, const int n) {
    for (int i = 0; i < n; i++)
        q.push(i + 1);
}

// k번째 수를 제거하며 요세푸스 순열을 생성하는 함수
queue<int> popKth(queue<int>& q, const int k) {
    queue<int> yq;

    /*
    반복문 for 이중 반복문에서 while 문으로 간결하게 코드 수정
    
    for (int i = 0; i < n; i++) {
		// k-1번만큼 숫자 빼서 다시 넣어주고
		for (int j = 0; j < k - 1; j++) {
    */

    while (!q.empty()) {
        // k-1번만큼 숫자 빼서 다시 넣어주기
        for (int j = 0; j < k - 1; j++) {
            q.push(q.front());
            q.pop();
        }
        // k번째의 값은 다른 큐에 담아주기
        yq.push(q.front());
        q.pop();
    }

    return yq;
}

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q;

    makeQueueFull(q, n);
    queue<int> yq = popKth(q, k);

    cout << "<" << yq.front();
    yq.pop();

    while (!yq.empty()) {
        cout << ", " << yq.front();
        yq.pop();
    }

    cout << ">";

    return 0;
}
