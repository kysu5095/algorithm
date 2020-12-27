// 토너먼트
// 1:10

#include <iostream>
#include <queue>

using namespace std;

int n, a, b, res;
queue<int> q;

int game() {
	int len, p1, p2, round = 0;
	while (true) {
		queue<int> tmp;
		round++;
		if (q.size() == 1) return -1;
		while (!q.empty()) {
			p1 = q.front();
			q.pop();
			if (!q.empty()) {
				p2 = q.front();
				q.pop();
			}
			else {
				tmp.push(p1);
				continue;
			}

			if ((p1 == a && p2 == b) || (p1 == b && p2 == a))
				return round;
			if (p1 == a || p2 == a || p1 == b || p2 == b) {
				if (p1 == a) tmp.push(p1);
				else if (p2 == a) tmp.push(p2);
				else if (p1 == b) tmp.push(p1);
				else if (p2 == b) tmp.push(p2);
			}
			else
				tmp.push(p1);
		}
		q = tmp;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
		q.push(i);
	cout << game() << '\n';
	return 0;
}