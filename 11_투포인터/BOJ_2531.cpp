#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 초기 윈도우 설정 함수
int initWindow(int k, int coupon, vector<int>& sushi, vector<int>& count, int& kind) {
    int maxKind = 0;

    for (int i = 0; i < k; i++) {
        if (count[sushi[i]] == 0) {
            kind++; // 새로운 종류의 초밥이 추가되면 종류 수 증가
        }
        count[sushi[i]]++;
    }

    // 쿠폰 초밥을 포함한 최대 초밥 종류 수 계산
    maxKind = kind + (count[coupon] == 0 ? 1 : 0);

    return maxKind;
}

// 슬라이딩 윈도우로 최대 초밥 종류 계산 함수
int findMaxKind(int maxKind, int n, int k, int coupon, vector<int>& sushi, vector<int>& count, int kind) {
    for (int i = 1; i < n; i++) {
        int remove = sushi[i - 1];
        int add = sushi[(i + k - 1) % n];

        // 윈도우에서 빠지는 초밥 처리
        if (--count[remove] == 0) {
            kind--; // 종류가 0이 되면 종류 수 감소
        }

        // 윈도우에 추가되는 초밥 처리
        if (count[add]++ == 0) {
            kind++; // 새로운 종류의 초밥이 추가되면 종류 수 증가
        }

        // 쿠폰 초밥을 포함한 최대 초밥 종류 수 갱신
        maxKind = max(maxKind, kind + (count[coupon] == 0 ? 1 : 0));
    }

    return maxKind;
}

int main() {
    int n, d, k, coupon;
    cin >> n >> d >> k >> coupon;

    vector<int> sushi(n);
    for (int i = 0; i < n; i++) {
        cin >> sushi[i];
    }

    vector<int> count(d + 1, 0); // 초밥 종류별 개수 카운트 배열
    int kind = 0; // 현재 윈도우 내의 고유 초밥 종류 수

    int maxKind = initWindow(k, coupon, sushi, count, kind);
    maxKind = findMaxKind(maxKind, n, k, coupon, sushi, count, kind);

    cout << maxKind << "\n";

    return 0;
}
