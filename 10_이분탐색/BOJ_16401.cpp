#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 과자를 합칠 수는 없다고 했으므로 !과자를 재조합 할 수는 없음!
// 이 포인트를 놓쳐서 함수 구현에서 많이 헤맸음
bool canDistribute(int mid, int m, const vector<int>& lengths) {
	int num = 0;

	for (int length : lengths) {
		num += length / mid;  // 각 막대 과자를 mid 길이로 나눌 수 있는 조각의 수
	}

	return num >= m;  // m명의 조카에게 나눠줄 수 있는지 확인
}

// 이분탐색하며 m명의 조카에게 나눠줄 수 있는 과자 조각의 최대 길이를 찾는 함수
int findMaxSnackLength(int m, vector<int>& lengths) {
	int low = 1;
	int up = lengths.back();

	// 입력값이 정렬되지 않은 경우 일반적으로 사용하는 max 값을 구하는 코드
	//int up = *max_element(lengths.begin(), lengths.end());	

	while(low <= up) {
		int mid = (low + up) / 2;

		if (canDistribute(mid, m, lengths)) {
			low = mid + 1;
		} else {
			up = mid - 1;
		}
	}

	return low - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m, n;
	cin >> m >> n;
	
	vector<int> lengths(n);
	
	int sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> lengths[i];
	}
	
	/*
	가지고 있는 과자의 길이 자체로는 탐색하지 않으며,
	순서에 상관 없이 주어진 길이로 과자 몇 개를 나눠줄 수 있는지 계산할 때만 사용
	 => 정렬 필요 없음
	
	sort(lengths.begin(), lengths.end());
	*/

	cout << findMaxSnackLength(m, lengths) << "\n";
		
	return 0;
}