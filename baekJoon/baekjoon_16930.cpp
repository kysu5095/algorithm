// 달리기

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int n, m, k;
char arr[1001][1001];
int visited[1001][1001];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs(int sy, int sx, int fy, int fx) {
	int y, x, ny, nx, len, t = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	memset(visited, -1, sizeof(visited));
	visited[sy][sx] = 0;

	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				for (int j = 1; j <= k; j++) {
					ny = y + dy[i] * j;
					nx = x + dx[i] * j;
					if (ny < 0 || ny == n || nx < 0 || nx == m || arr[ny][nx] == '#') break;
					if (ny == fy && nx == fx) return t;
					if (visited[ny][nx] == -1) {
						q.push(make_pair(ny, nx));
						visited[ny][nx] = t;
					}
					else if (visited[ny][nx] == t) continue;
					else break;
				}
			}
		}
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int sy, sx, fy, fx;
	cin >> sy >> sx >> fy >> fx;
	cout << bfs(sy - 1, sx - 1, fy - 1, fx - 1) << '\n';
	return 0;
}