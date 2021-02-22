// 지금 만나러 갑니다

#include <iostream>
#include <queue>

using namespace std;

int n, A, B;
int visited[500001];

int bfs() {
	queue<int> q1, q2;
	q1.push(A);	q2.push(B);
	int x, nx, len, t = 0;
	while (!q1.empty() && !q2.empty()) {
		t++;
		len = q1.size();
		while (len--) {
			x = q1.front();	q1.pop();
			for (int i = -1; i <= 1; i += 2) {
				nx = x + ((1 << (t - 1)) * i);
				if (nx <= 0 || nx > n) continue;
				q1.push(nx);
				visited[nx] = t;
			}
		}
		len = q2.size();
		while (len--) {
			x = q2.front();	q2.pop();
			for (int i = -1; i <= 1; i += 2) {
				nx = x + ((1 << (t - 1)) * i);
				if (nx <= 0 || nx > n) continue;
				if (visited[nx] == t) return t;
				q2.push(nx);
			}
		}
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> A >> B;
	cout << bfs() << '\n';
	return 0;
}