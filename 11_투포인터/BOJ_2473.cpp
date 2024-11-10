#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
    �ð� ���⵵ �м�:
    - �迭�� �����ϴ� �� O(n log n)
    - ����, �� ���Ҹ� �ϳ��� �����Ͽ� ������ �� ���� �� �����ͷ� Ž���ϴ� �ݺ����� ����
    - ù ��° ������ n-2 �� ����ǰ�, �� �������� �� �����ʹ� �־��� ��� �迭�� ������ Ž���ϹǷ� O(n)
    => ���� ��ü �ð� ���⵵�� O(n log n + n^2), O(n^2)

*/

// �� ����� ���� 0�� ���� ����� ������ ã�� �Լ�
vector<int> findClosestSum(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    long long closest = LLONG_MAX; 
    vector<int> result(3); // ����� ��ȯ�� �� ���� ��� �� ����

    // ù ��° ���� �����ϰ� ������ �� ���� �� �����ͷ� Ž��
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1; 
        int right = n - 1; 

        while (left < right) {
            // �� ���� �� ���
            long long sum = static_cast<long long>(arr[i] + arr[left] + arr[right]);

            // ���� ���� 0�� �� ������ ����� ���� ����� �� ������Ʈ
            if (abs(sum) < abs(closest)) {
                closest = sum;
                result = { arr[i], arr[left], arr[right] };
            }

            // ���� 0���� �۴ٸ�, ���� ������Ű�� ���� ���� �����͸� ���������� �̵�
            if (sum < 0) {
                left++;
            }

            // ���� 0���� ũ�ٸ�, ���� ���ҽ�Ű�� ���� ������ �����͸� �������� �̵�
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

    vector<int> arr(n); // ����� ������ ������ ����
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = findClosestSum(arr); // ���� 0�� ����� ���� ���� �� ��� ã��

    // ��� ���
    for (int num : result) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
