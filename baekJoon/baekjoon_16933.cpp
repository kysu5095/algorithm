// 벽 부수고 이동하기 3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int n, m, k;
int arr[1001][1001];
bool visited[1001][1001][11] = { { {false, },}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs() {
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(0, 0)));
	visited[0][0][0] = true;
	int y, x, w, ny, nx, len, t = 1;
	bool day = true;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			w = q.front().first;
			y = q.front().second.first;
			x = q.front().second.second;
			q.pop();
			if (y == n - 1 && x == m - 1) return t;

			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
				// 벽 만남
				if (arr[ny][nx]) {
					// 부실 수 있냐?
					if (w < k && !visited[ny][nx][w + 1]) {
						// 낮 >> 부시고 이동
						if (day) {
							visited[ny][nx][w + 1] = true;
							q.push(make_pair(w + 1, make_pair(ny, nx)));
						}
						// 밤 >> 현재 위치 그대로, 칸만 증가
						else
							q.push(make_pair(w, make_pair(y, x)));
					}
				}
				// 벽 X
				else {
					if (!visited[ny][nx][w]) {
						visited[ny][nx][w] = true;
						q.push(make_pair(w, make_pair(ny, nx)));
					}
				}
			}
		}
		day = !day;
		t++;
	}
	return -1;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);
	printf("%d\n", bfs());
	return 0;
}