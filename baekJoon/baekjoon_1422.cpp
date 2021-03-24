// 숫자의 신

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int n, k;
deque<string> dq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n;
	dq.resize(k);
	for (int i = 0; i < k; i++) cin >> dq[i];
	sort(dq.begin(), dq.end(), [](string& str1, string& str2) {
		if (stoi(str1) > stoi(str2)) return true;
		else return false;
		});
	for (int i = 0; i < n - k; i++) dq.push_back(dq[0]);
	sort(dq.begin(), dq.end(), [](string& str1, string& str2) {
		if (str1 + str2 > str2 + str1) return true;
		else return false;
		});
	for (auto& str : dq) cout << str;
	cout << '\n';
	return 0;
}