#include <iostream>
#include <queue>

using namespace std;

// 1���� n������ ���� queue ä���ֱ�
void makeQueueFull(queue<int>& q, const int n) {	
	for (int i = 0; i < n; i++)
		q.push(i + 1);
}

queue<int> popKth(queue<int>& q, const int n, const int k) {
	queue<int> yq;
	int cnt;

	for (int i = 0; i < n; i++) {
		// k-1����ŭ ���� ���� �ٽ� �־��ְ�
		for (int j = 0; j < k - 1; j++) {
			cnt = q.front();
			q.pop();
			q.push(cnt);
		}
		// k��°�� ���� �ٸ� ť�� ����ֱ�
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
	queue<int> yq = popKth(q, n, k);


	cout << "<" << yq.front();
	yq.pop();

	while (!yq.empty()) {
		cout << ", " << yq.front();
		yq.pop();
	}

	cout << ">";

	return 0;
}