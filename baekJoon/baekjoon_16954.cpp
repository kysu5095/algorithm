// 움직이는 미로 탈출

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

char arr[8][8];
bool visited[8][8][5096];
int dy[9] = { 0, -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[9] = { 0, -1, 0, 1, 1, 1, 0, -1, -1 };
struct WALL {
	bool end;
	int y, x;
};
vector<WALL> v;

int bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(7, 0));
	visited[7][0][0] = true;
	int y, x, ny, nx, len, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();

			if (arr[y][x] == '#') continue;
			for (int i = 0; i < 8; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny == 0 && nx == 7) return 1;
				if (ny < 0 || ny == 8 || nx < 0 || nx == 8 || visited[ny][nx][t] || arr[ny][nx] == '#') continue;
				q.push(make_pair(ny, nx));
				visited[ny][nx][t] = true;
			}
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i].end) continue;
			arr[v[i].y][v[i].x] = '.';
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i].end) continue;
			if (++v[i].y == 8) {
				v[i].end = true;
				continue;
			}
			arr[v[i].y][v[i].x] = '#';
		}
	}
	return 0;
}

int main() {
	for (int i = 0; i < 8; i++) {
		scanf("%s", arr[i]);
		for (int j = 0; j < 8; j++)
			if (arr[i][j] == '#') v.push_back({ false, i, j });
	}
	printf("%d\n", bfs());
	return 0;
}