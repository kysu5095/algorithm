// 문자열 합치기

#include <iostream>
#include <queue>

using namespace std;

int C, n;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int val, a, b, sum;
	cin >> C;
	while (C--) {
		sum = 0;
		priority_queue<int> pq;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> val;
			pq.push(-val);
		}
		while (pq.size() > 1) {
			a = -pq.top(); pq.pop();
			b = -pq.top(); pq.pop();
			a += b;
			sum += a;
			pq.push(-a);
		}
		if (n == 1) cout << val << '\n';
		else cout << sum << '\n';
	}
	return 0;
}