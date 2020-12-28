// Baaaaaaaaaduk2 (Easy)

#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m, res = 0;
int arr[21][21];
bool visited[21][21];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
class Point {
public:
	int y, x;
};
Point p[2];

int bfs(queue<Point>& q) {
	int y, x, ny, nx, cnt = 1;
	bool flag = true;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
			if (arr[ny][nx] == 0) { flag = false; continue; }
			if (visited[ny][nx]) continue;
			if (arr[ny][nx] == 2) {
				q.push({ ny, nx });
				visited[ny][nx] = true;
				cnt++;
			}
		}
	}
	if (!flag) return 0;
	return cnt;
}

void dfs(int y, int x, int cnt) {
	if (cnt == 2) {
		int ny, nx, val = 0;
		memset(visited, false, sizeof(visited));
		queue<Point> q;
		visited[p[0].y][p[0].x] = true;
		visited[p[1].y][p[1].x] = true;
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < 4; i++) {
				ny = p[j].y + dy[i];
				nx = p[j].x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx]) continue;
				if (arr[ny][nx] == 2) {
					q.push({ ny, nx });
					visited[ny][nx] = true;
					val += bfs(q);
				}
 			}
			while (!q.empty())
				q.pop();
		}
		res = max(res, val);
		return;
	}
	if (y >= n) return;
	if (x >= m) {dfs(y + 1, 0, cnt); return;}
	if (arr[y][x] == 0) {
		arr[y][x] = 1;
		p[cnt].y = y;
		p[cnt].x = x;
		dfs(y, x + 1, cnt + 1);
		arr[y][x] = 0;
	}
	dfs(y, x + 1, cnt);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	dfs(0, 0, 0);
	cout << res << '\n';
	return 0;
}