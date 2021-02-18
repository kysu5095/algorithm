// 전구를 켜라

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX 0x7f

using namespace std;

int n, m;
char arr[501][501];
bool shape[501][501];
int visited[501][501][9];
int dy[9] = { 1, 1, 0, -1, -1, -1, 0, 1, 1 };
int dx[9] = { 0, -1, -1, -1, 0, 1, 1, 1, 0 };

class Point {
public:
	bool s;
	int y, x, d, c;
	bool operator < (const Point& p) const {
		return c > p.c;
	}
};

void bfs() {
	int y, x, ny, nx, d, c;
	bool s = true;
	priority_queue<Point> q;
	if (!shape[0][0]) s = false;
	if (s) {
		q.push({ true, 0, 0, 7, 0 });
		visited[0][0][7] = 0;
	}
	else {
		q.push({ true, 0, 0, 7, 1 });
		visited[0][0][7] = 1;
	}

	while (!q.empty()) {
		s = q.top().s;
		y = q.top().y; x = q.top().x;
		d = q.top().d; c = q.top().c;
		q.pop();
		if (c > visited[y][x][d]) continue;

		for (int i = d - 1; i <= d + 1; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny == n && nx == m) {
				cout << c << '\n';
				return;
			}
			if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
			if (i == d) {
				if (shape[ny][nx] == s) {
					if (c >= visited[ny][nx][i]) continue;
					q.push({ s, ny, nx, i, c });
					visited[ny][nx][i] = c;
				}
				else {
					if (c + 1 >= visited[ny][nx][i]) continue;
					q.push({ s, ny, nx, i, c + 1 });
					visited[ny][nx][i] = c + 1;
				}
			}
			else {
				if (shape[ny][nx] != s) {
					if (i == d - 1) {
						if (d == 3 || d == 7) {
							if (c >= visited[ny][nx][(d + 7) % 9]) continue;
							q.push({ !s, ny, nx, (d + 7) % 9, c });
							visited[ny][nx][(d + 7) % 9] = c;
						}
						else {
							if (c >= visited[ny][nx][(d + 6) % 8]) continue;
							q.push({ !s, ny, nx, (d + 6) % 8, c });
							visited[ny][nx][(d + 6) % 8] = c;
						}
					}
					else {
						if (d == 3 || d == 7) {
							if (c >= visited[ny][nx][(d + 2) % 8]) continue;
							q.push({ !s, ny, nx, (d + 2) % 8, c });
							visited[ny][nx][(d + 2) % 8] = c;
						}
						else {
							if (c >= visited[ny][nx][d + 2]) continue;
							q.push({ !s, ny, nx, d + 2, c });
							visited[ny][nx][d + 2] = c;
						}
					}
				}
				else {
					if (i == d - 1) {
						if (d == 3 || d == 7) {
							if (c + 1 >= visited[ny][nx][(d + 7) % 9]) continue;
							q.push({ !s, ny, nx, (d + 7) % 9, c + 1 });
							visited[ny][nx][(d + 7) % 9] = c + 1;
						}
						else {
							if (c + 1 >= visited[ny][nx][(d + 6) % 8]) continue;
							q.push({ !s, ny, nx, (d + 6) % 8, c + 1 });
							visited[ny][nx][(d + 6) % 8] = c + 1;
						}
					}
					else {
						if (d == 3 || d == 7) {
							if (c + 1 >= visited[ny][nx][(d + 2) % 8]) continue;
							q.push({ !s, ny, nx, (d + 2) % 8, c + 1 });
							visited[ny][nx][(d + 2) % 8] = c + 1;
						}
						else {
							if (c + 1 >= visited[ny][nx][d + 2]) continue;
							q.push({ !s, ny, nx, d + 2, c + 1 });
							visited[ny][nx][d + 2] = c + 1;
						}
					}
				}
			}
		}
	}
	cout << "NO SOLUTION\n";
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '/') shape[i][j] = false;
			else shape[i][j] = true;
		}
	}
	memset(visited, MAX, sizeof(visited));
	bfs();
	return 0;
}