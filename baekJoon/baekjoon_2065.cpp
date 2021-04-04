// 나룻배

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int m, t, n;
int arr[10001];
queue<pair<int, int>> l, r;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> t >> n;
	for (int i = 0; i < n; i++) {
		int num;
		string str;
		cin >> num >> str;
		if (str == "left") l.push(make_pair(i, num));
		else r.push(make_pair(i, num));
	}
	bool is_left = true;
	int cur = 0;
	while (!l.empty() || !r.empty()) {
		if (is_left) {
			bool take = false;
			int cnt = 0;
			while (!l.empty() && l.front().second <= cur && cnt < m) {
				arr[l.front().first] = cur + t;
				l.pop();
				cnt++;
				take = true;
			}
			if (take) {
				is_left ^= true;
				cur += t;
			}
			else {
				if (l.empty()) {
					is_left ^= true;
					if (cur > r.front().second) cur += t;
					else cur = r.front().second + t;
				}
				else if (r.empty()) cur = l.front().second;
				else if (!r.empty() && l.front().second <= r.front().second) cur = l.front().second;
				else {
					is_left ^= true;
					if (cur > r.front().second) cur += t;
					else cur = r.front().second + t;
				}
			}
		}
		if (!is_left) {
			bool take = false;
			int cnt = 0;
			while (!r.empty() && r.front().second <= cur && cnt < m) {
				arr[r.front().first] = cur + t;
				r.pop();
				cnt++;
				take = true;
			}
			if (take) {
				is_left ^= true;
				cur += t;
			}
			else {
				if (r.empty()) {
					is_left ^= true;
					if (cur > l.front().second) cur += t;
					else cur = l.front().second + t;
				}
				else if (l.empty()) cur = r.front().second;
				else if (!l.empty() && r.front().second <= l.front().second) cur = r.front().second;
				else {
					is_left ^= true;
					if (cur > l.front().second) cur += t;
					else cur = l.front().second + t;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
	return 0;
}