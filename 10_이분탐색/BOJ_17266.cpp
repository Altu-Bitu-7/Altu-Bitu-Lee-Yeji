#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �ʿ��� ���ε� ������ ����ϴ� �Լ�
int getRequiredLamps(int n, int h, vector<int>& points) {
	// ù ��° ���ε��� ���� ������(0��)�� Ŀ������ ���ϴ� ���
	if (points[0] - h > 0) {
		return -1;
	}

	// ù ��° ���ε� ��ġ
	int cnt = 1;
	int cur = points[0];

	
	for (int i = 1; i < points.size(); i++) {
		// ���� ���������� ��ġ�� ��ġ�� ���ε� ���� ���� �ʴ´ٸ�, �� �簢���� �߻���
		if (points[i] - cur > h * 2) {
			return -1;
		}

		/* 
		* ���� place���� ���� �簢���� ���峪 Ȯ���ҰŶ� �ߺ� ������ �ʤ�
		&& �ε��� ���� ���� �߻� ���� -> ����

		// ������ ��ġ�� ���ε����� �̹��� ��ġ�� �ʿ䰡 ���� ���
		else if (points[i + 1] - cur <= h * 2) {
			continue;
		}
		*/

		// ���ε� ��ġ
		cnt++;
		cur = points[i];
	}

	// ������ ���ε��� ������ ���� �ʴ´ٸ� �簢���� �߻�
	if (cur + h < n) {
		return -1;
	}

	// ��ġ�� �� ���ε��� ���� ����
	return cnt;
}


// binarySearch�� �ʿ��� ���� �ּ� ���̸� ���ϴ� �Լ�
int findMinLampHeight(int lowerb, int upperb, int n, int m, vector<int>& points) {
	while (lowerb <= upperb) {
		int mid = (lowerb + upperb) / 2;

		// mid ������ ���ε��� ��ġ�ϴ� ��� �ʿ��� ���ε��� �� ���
		int installed = getRequiredLamps(n, mid, points);

		// �簢���밡 �߻��ϰų� ���ε��� ������ ��� ���� ����
		if ((installed == -1) || (installed > m)) {
			lowerb = mid + 1;
		}

		// ���� ���̷� ����� ��� �� ���� ���� �õ�
		else if (installed <= m) {
			upperb = mid - 1;
		}
	}

	return lowerb;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n; cin >> m;

	vector<int> points(m);
	for (int i = 0; i < m; i++) {
		cin >> points[i];
	}

	cout << findMinLampHeight(0, n, n, m, points) << "\n";

	return 0;
}