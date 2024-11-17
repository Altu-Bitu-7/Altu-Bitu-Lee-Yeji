#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 해당 수의 카드가 몇 개인지 세는 함수
int countCards(vector<int>& nums, int target) {
	int count = 0;

	int le = 0, ri = nums.size() - 1;

	while (le <= ri) {
		int mid = (le + ri) / 2;

		// target 값을 찾은 경우
		if (nums[mid] == target) {
			return 1;
		}

		if (nums[mid] > target) {
			ri = mid - 1;
		}

		else if (nums[mid] < target) {
			le = mid + 1;
		}
	}

	// target이 존재하지 않는 경우, 0 반환
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	int target;

	cin >> n;
	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	// 이분 탐색을 위한 정렬
	sort(nums.begin(), nums.end());

	cin >> m;


	for (int i = 0; i < m; i++) {
		cin >> target;
		cout << countCards(nums, target) << ' ';
	}

	return 0;
}