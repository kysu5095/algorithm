// 벽 부수고 이동하기2

#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int n, m, k;
char map[1001][1001];
bool visited[1001][1001][11] = { { {false,},}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs() {
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(k, make_pair(0, 0)));
	visited[0][0][k] = true;
	int y, x, ny, nx, key, len, t = 1;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().second.first;
			x = q.front().second.second;
			key = q.front().first;
			if (y == n - 1 && x == m - 1) return t;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
				if ((map[ny][nx] - '0') == 0 && !visited[ny][nx][key]) {
					q.push(make_pair(key, make_pair(ny, nx)));
					visited[ny][nx][key] = true;
				}
				else if ((map[ny][nx] - '0') == 1 && key && !visited[ny][nx][key - 1]) {
					q.push(make_pair(key - 1, make_pair(ny, nx)));
					visited[ny][nx][key - 1] = true;
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
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	cout << bfs() << '\n';
	return 0;
}