// 문명

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int arr[2001][2001] = { {0,}, };
int parent[100001];

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
queue<int> q;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

bool Union(int y, int x) {
	y = find(y);
	x = find(x);
	if (y == x) return false;
	if (y < x) parent[x] = y;
	else parent[y] = x;
	return true;
}

int bfs() {
	int y, x, ny, nx, t = 0;
	queue<int> qq;
	while (!q.empty()) {
		while (!q.empty()) {
			y = q.front() / n;
			x = q.front() % n;
			qq.push(q.front());
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + p[i].y;
				nx = x + p[i].x;
				if (ny >= 0 && ny < n && nx >= 0 && nx < n && arr[ny][nx] && arr[y][x] != arr[ny][nx]) {
					if (Union(arr[y][x], arr[ny][nx]))
						k--;
				}
			}
		}
		if (k == 1) break;

		while (!qq.empty()) {
			y = qq.front() / n;
			x = qq.front() % n;
			qq.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + p[i].y;
				nx = x + p[i].x;
				if (ny >= 0 && ny < n && nx >= 0 && nx < n && !arr[ny][nx]) {
					arr[ny][nx] = arr[y][x];
					q.push(ny * n + nx);
				}
			}
		}
		t++;
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int y, x;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		arr[y - 1][x - 1] = i + 1;
		parent[i + 1] = i + 1;
		q.push((y - 1) * n + x - 1);
	}
	cout << bfs() << '\n';
	return 0;
}