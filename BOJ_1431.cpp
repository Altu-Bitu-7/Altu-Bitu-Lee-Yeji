#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int sum(string s) {
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
		if (isdigit(s[i]))
			ans += s[i] - '0';
	return ans;
}

bool cmp(const string& s1, const string& s2) {
	if (s1.length() != s2.length())
		return s1.length() < s2.length();
	if (sum(s1) != sum(s2))
		return sum(s1) < sum(s2);
	return s1 < s2;
}

int main()
{
	int n;

	cin >> n;
	
	vector<string> serials(n);

	for (int i = 0; i < n; i++)
		cin >> serials[i];

	sort(serials.begin(), serials.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << serials[i] << "\n";

	return 0;
}