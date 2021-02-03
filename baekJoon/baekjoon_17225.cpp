// 세훈이의 선물가게

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int A, B, n;
priority_queue<pair<int, char>> pq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int t, cnt, t_a = 0, t_b = 0;
	char ch;
	cin >> A >> B >> n;
	for (int i = 0; i < n; i++) {
		cin >> t >> ch >> cnt;
		if (ch == 'B') {
			t = max(t, t_a);
			for (int i = t, j = 0; j < cnt; i += A, j++)
				pq.push(make_pair(-i, 'B'));
			t_a = t + A * cnt;
		}
		else {
			t = max(t, t_b);
			for (int i = t, j = 0; j < cnt; i += B, j++)
				pq.push(make_pair(-i, 'A'));
			t_b = t + B * cnt;
		}
	}
	cnt = 1;
	vector<int> va, vb;
	while (!pq.empty()) {
		ch = pq.top().second;
		pq.pop();
		if (ch == 'B') va.push_back(cnt++);
		else vb.push_back(cnt++);
	}
	cout << va.size() << '\n';
	for (int idx : va) cout << idx << " ";
	cout << '\n';
	cout << vb.size() << '\n';
	for (int idx : vb) cout << idx << " ";
	cout << '\n';
	return 0;
}