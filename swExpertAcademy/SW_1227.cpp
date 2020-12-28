// D4 : 미로2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int test_case, sy, sx, fy, fx;
int arr[101][101];
bool visited[101][101];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	visited[sy][sx] = true;
	int y, x, ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if (y == fy && x == fx) return 1;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == 100 || nx < 0 || nx == 100 || visited[ny][nx] || arr[ny][nx] == 1) continue;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}
	return 0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int TC = 10;
	while (TC--) {
		memset(visited, false, sizeof(visited));
		scanf("%d", &test_case);
		for(int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j) {
				scanf(" %1d", &arr[i][j]);
				if (arr[i][j] == 2) sy = i, sx = j;
				else if (arr[i][j] == 3) fy = i, fx = j;
			}
		printf("#%d %d\n", test_case, bfs());
	}
}