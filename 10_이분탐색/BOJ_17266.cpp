#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 필요한 가로등 개수를 계산하는 함수
int getRequiredLamps(int n, int h, vector<int>& points) {
	// 첫 번째 가로등이 길의 시작점(0번)을 커버하지 못하는 경우
	if (points[0] - h > 0) {
		return -1;
	}

	// 첫 번째 가로등 설치
	int cnt = 1;
	int cur = points[0];

	
	for (int i = 1; i < points.size(); i++) {
		// 현재 마지막으로 설치한 위치의 가로등 빛이 닿지 않는다면, 즉 사각지대 발생시
		if (points[i] - cur > h * 2) {
			return -1;
		}

		/* 
		* 다음 place에서 전에 사각지대 생겼나 확인할거라 중복 로직이 됨ㄴ
		&& 인덱스 범위 오류 발생 가능 -> 삭제

		// 다음에 설치될 가로등으로 이번에 설치할 필요가 없는 경우
		else if (points[i + 1] - cur <= h * 2) {
			continue;
		}
		*/

		// 가로등 설치
		cnt++;
		cur = points[i];
	}

	// 마지막 가로등이 끝까지 닿지 않는다면 사각지대 발생
	if (cur + h < n) {
		return -1;
	}

	// 설치된 총 가로등의 개수 리턴
	return cnt;
}


// binarySearch로 필요한 높이 최소 높이를 구하는 함수
int findMinLampHeight(int lowerb, int upperb, int n, int m, vector<int>& points) {
	while (lowerb <= upperb) {
		int mid = (lowerb + upperb) / 2;

		// mid 높이의 가로등을 설치하는 경우 필요한 가로등의 수 계산
		int installed = getRequiredLamps(n, mid, points);

		// 사각지대가 발생하거나 가로등이 부족한 경우 높이 상향
		if ((installed == -1) || (installed > m)) {
			lowerb = mid + 1;
		}

		// 현재 높이로 충분한 경우 더 낮은 높이 시도
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