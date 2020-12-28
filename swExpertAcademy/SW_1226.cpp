// D4 : 미로1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int tc, sy, sx, fy, fx;
char arr[17][17];
bool visited[17][17];
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
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny == fy && nx == fx) return 1;
			if (ny < 0 || ny == 16 || nx < 0 || nx == 16 || visited[ny][nx] || arr[ny][nx] == '1') continue;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int TC = 10;
	while (TC--) {
		cin >> tc;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 16; i++) {
			cin >> arr[i];
			for (int j = 0; j < 16; j++) {
				if (arr[i][j] == '2') sy = i, sx = j;
				else if (arr[i][j] == '3') fy = i, fx = j;
			}
		}
		cout << "#" << tc << " " << bfs() << '\n';
	}
}