// 모래성 쌓기

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <queue>
#include <string.h>

using namespace std;

int h, w;
char arr[1001][1001];
int visited[1001][1001];
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int bfs(queue<pair<int, int>>& q) {
	int y, x, ny, nx, len, sec = 0, cnt;
	while (!q.empty()) {
		cnt = 0;
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == h || nx < 0 || nx == w || !visited[ny][nx]) continue;
				visited[ny][nx] -= 1;
				if (!visited[ny][nx]) {
					q.push(make_pair(ny, nx));
					cnt++;
				}
			}
		}
		if (!cnt) break;
		sec++;
	}
	return sec;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("sample_input.txt", "r", stdin);
	int test_case;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		memset(visited, 0, sizeof(visited));
		queue<pair<int, int>> q;
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			cin >> arr[i];
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == '.') q.push(make_pair(i, j));
				else visited[i][j] = (arr[i][j] - '0');
			}
		}
		cout << "#" << tc << " " << bfs(q) << '\n';
	}
	return 0;
}