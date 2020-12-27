// 암벽 등반

#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

int n, T;
bool visited[50001] = { false, };
class Point {
public:
	int y, x;
	bool operator <(const Point &p) const {
		if (y == p.y) return x < p.x;
		else return y < p.y;
	}
};
Point p[50001];

int bfs() {
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(0, 0)));
	int y, x, ny, nx, idx, len, t = 0;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			idx = q.front().first;
			y = q.front().second.first;
			x = q.front().second.second;
			q.pop();
			if (y == T) return t;

			for (int i = idx; i < n; i++) {
				if (visited[i]) continue;
				ny = p[i].y;
				nx = p[i].x;
				if (abs(ny - y) <= 2 && abs(nx - x) <= 2) {
					visited[i] = true;
					q.push(make_pair(i, make_pair(ny, nx)));
				}
			}
			for (int i = idx; i >= 0; i--) {
				if (visited[i]) continue;
				ny = p[i].y;
				nx = p[i].x;
				if (abs(ny - y) <= 2 && abs(nx - x) <= 2) {
					visited[i] = true;
					q.push(make_pair(i, make_pair(ny, nx)));
				}
			}
		}
		t++;
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> T;
	for (int i = 0; i < n; i++) 
		cin >> p[i].x >> p[i].y;
	sort(p, p + n);
	cout << bfs() << '\n';
	return 0;
}