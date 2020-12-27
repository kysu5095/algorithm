// 치즈
// 2:50

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int n, m, cnt = 0;
int arr[101][101];
bool visited[101][101];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs() {
	int y, x, ny, nx, t = 0;
	while (cnt) {
		t++;
		memset(visited, false, sizeof(visited));
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		visited[0][0] = true;
		while (!q.empty()) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
					if (!visited[ny][nx] && !arr[ny][nx]) {
						visited[ny][nx] = true;
						q.push(make_pair(ny, nx));
					}
					else if (arr[ny][nx]) {
						if (visited[ny][nx]) {
							arr[ny][nx] = 0;
							cnt--;
						}
						else visited[ny][nx] = true;
					}
				}
			}
		}
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) cnt++;
		}
	}
	cout << bfs() << '\n';
	return 0;
}