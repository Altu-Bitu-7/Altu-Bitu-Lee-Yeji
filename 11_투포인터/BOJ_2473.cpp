#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
    시간 복잡도 분석:
    - 배열을 정렬하는 데 O(n log n)
    - 이후, 각 원소를 하나씩 고정하여 나머지 두 수를 투 포인터로 탐색하는 반복문이 실행
    - 첫 번째 루프가 n-2 번 실행되고, 각 루프에서 투 포인터는 최악의 경우 배열을 끝까지 탐색하므로 O(n)
    => 따라서 전체 시간 복잡도는 O(n log n + n^2), O(n^2)

*/

// 세 용액의 합이 0에 가장 가까운 조합을 찾는 함수
vector<int> findClosestSum(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    long long closest = LLONG_MAX; 
    vector<int> result(3); // 결과로 반환할 세 개의 용액 값 저장

    // 첫 번째 수를 고정하고 나머지 두 수는 투 포인터로 탐색
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1; 
        int right = n - 1; 

        while (left < right) {
            // 세 수의 합 계산
            long long sum = static_cast<long long>(arr[i] + arr[left] + arr[right]);

            // 현재 합이 0에 더 가까우면 결과와 가장 가까운 합 업데이트
            if (abs(sum) < abs(closest)) {
                closest = sum;
                result = { arr[i], arr[left], arr[right] };
            }

            // 합이 0보다 작다면, 합을 증가시키기 위해 왼쪽 포인터를 오른쪽으로 이동
            if (sum < 0) {
                left++;
            }

            // 합이 0보다 크다면, 합을 감소시키기 위해 오른쪽 포인터를 왼쪽으로 이동
            else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n); // 용액의 값들을 저장할 벡터
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = findClosestSum(arr); // 가장 0에 가까운 합을 갖는 세 용액 찾기

    // 결과 출력
    for (int num : result) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
