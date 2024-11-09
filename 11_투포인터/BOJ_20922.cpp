#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 조건을 만족하는 최대 부분 수열 길이를 찾는 함수
int findMaxLen(int n, int k, vector<int>& nums) {
    vector<int> count(100001, 0); // 수의 빈도 저장 배열
    int left = 0, right = 0;
    int maxLen = 0;

    while (right < n) {
        int num = nums[right];
        count[num]++;

        // 현재 숫자가 K를 초과하는 경우 윈도우 왼쪽을 조정
        while (count[num] > k) {
            count[nums[left]]--;
            left++;
        }

        // 최대 길이 갱신
        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    return maxLen;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << findMaxLen(n, k, nums) << "\n";

    return 0;
}
