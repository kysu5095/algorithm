// 회전하는 큐
// 12:15

#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int n, m, res = 0;
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int input, t, left, right;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);
	for (int i = 0; i < m; i++) {
		t = 0;
		cin >> input;
		deque<int>::iterator iter = dq.begin();
		for (iter; iter != dq.end(); iter++) {
			if (*iter == input) break;
			t++;
		}
		left = t;
		right = dq.size() - t;
		if (left < right) {
			for (int i = 0; i < left; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			dq.pop_front();
			res += left;
		}
		else {
			for (int i = 0; i < right; i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			dq.pop_front();
			res += right;
		}
	}
	cout << res << '\n';
	return 0;
}