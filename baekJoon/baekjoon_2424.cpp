// 부산의 해적

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int n, m;
char arr[701][701];
int map[701][701];
bool visited[701][701];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void make_pirate(int vy, int vx) {
	memset(map, -1, sizeof(map));
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(vy, vx));
	visited[vy][vx] = true;

	int y, x, ny, nx, len, t = 0;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			if (map[y][x] == -1) map[y][x] = t;

			for (int i = 0; i < 4; i++) {
				ny = y;
				nx = x;
				while (true) {
					ny += dy[i];
					nx += dx[i];
					if (ny < 0 || ny == n || nx < 0 || nx == m || arr[ny][nx] == 'I') break;
					if (map[ny][nx] >= 0) continue;
					map[ny][nx] = t;
				}
			}

			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx] || arr[ny][nx] == 'I') continue;
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
		t++;
	}
}

bool find_treasure(int sy, int sx) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	visited[sy][sx] = true;

	int y, x, ny, nx, len, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx] || arr[ny][nx] == 'I') continue;
				if (map[ny][nx] <= t) continue;
				if (arr[ny][nx] == 'T') return true;
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}
	return false;
}

int main() {
	int sy, sx, vy, vx;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'Y') sy = i, sx = j;
			else if (arr[i][j] == 'V') vy = i, vx = j;
		}
	}
	make_pirate(vy, vx);
	if (find_treasure(sy, sx)) printf("YES\n");
	else printf("NO\n");
	return 0;
}