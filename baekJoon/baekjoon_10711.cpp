// 모래성
// 4:05

#include <iostream>
#include <queue>

using namespace std;

int h, w;
char arr[1001][1001];
int map[1001][1001] = { {0,}, };
int dy[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dx[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };

queue<pair<int, int>> q;

void find() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] != '.') {
				for (int d = 0; d < 8; d++) {
					if (arr[i + dy[d]][j + dx[d]] == '.')
						map[i][j]++;
					if (map[i][j] >= (arr[i][j] - '0')) {
						q.push(make_pair(i, j));
						break;
					}
				}
			}
		}
	}
}

int bfs() {
	int y, x, ny, nx, len, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			arr[y][x] = '.';
			for (int i = 0; i < 8; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (arr[ny][nx] != '.')
					map[ny][nx]++;
				if (map[ny][nx] == (arr[ny][nx] - '0')) 
					q.push(make_pair(ny, nx));
			}
		}
	}
	return t;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		cin >> arr[i];
	find();
	cout << bfs() << '\n';
	return 0;
}