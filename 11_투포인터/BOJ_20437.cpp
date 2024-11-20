#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 특정 문자 조건에 맞는 최소 및 최대 길이 계산 함수
pair<int, int> findMinMaxLen(string& str, int k) {
    vector<vector<int>> pos(26); // 알파벳별 위치 저장
    int minLen = 10001, maxLen = -1;

    // 문자 위치 저장
    for (int i = 0; i < str.size(); i++) {
        pos[str[i] - 'a'].push_back(i);
    }

    // 각 문자에 대해 k개 이상 출현하는 부분 문자열 길이 확인
    for (int i = 0; i < 26; i++) {
        if (pos[i].size() < k) {
            continue;
        }

        for (int j = 0; j <= pos[i].size() - k; j++) {
            int len = pos[i][j + k - 1] - pos[i][j] + 1;
            minLen = min(minLen, len);
            maxLen = max(maxLen, len);
        }
    }

    // 조건 만족하지 않는 경우
    if (maxLen == -1) {
        return { -1, -1 }; 
    }

    return { minLen, maxLen };
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string str;
        int k;
        cin >> str >> k;

        pair<int, int> result = findMinMaxLen(str, k);
        if (result.first == -1) {
            cout << "-1\n";
        }
        else {
            cout << result.first << " " << result.second << "\n";
        }
    }

    return 0;
}
