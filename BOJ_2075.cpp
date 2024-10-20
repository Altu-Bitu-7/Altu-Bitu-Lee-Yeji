#include <iostream>
#include <queue>

using namespace std;

// min_heap을 n 사이즈로 유지하며 n^2개의 입력을 받는 메서드
void getInput(const int n, priority_queue<int, vector<int>, greater<int>>& pq) {
	int num;

	// n ^ 2까지로 조건을 변경해서 불필요한 2중 반복문 삭제
	for (int i = 0; i < n * n; i++) {
			cin >> num;
			pq.push(num);

			// 크기가 n을 넘으면 가장 작은 값 제거
			if (pq.size() > n)
				pq.pop();
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> min_heap;
	getInput(n, min_heap);

	cout << min_heap.top() << "\n";

	return 0;
}