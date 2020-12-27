// 전쟁 - 전투

#include <iostream>
#include <queue>

using namespace std;

int n, m;
char arr[101][101];
bool visited[101][101] = { {false,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs(int _y, int _x, char& c) {
	queue<pair<int, int>> q;
	q.push(make_pair(_y, _x));
	visited[_y][_x] = true;
	int y, x, ny, nx, cnt = 1;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
			if (visited[ny][nx] || arr[ny][nx] != c) continue;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
			cnt++;
		}
	}
	return (cnt * cnt);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int white = 0, blue = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				if (arr[i][j] == 'W') white += bfs(i, j, arr[i][j]);
				else blue += bfs(i, j, arr[i][j]);
			}
		}
	}
	cout << white << " " << blue << '\n';
	return 0;
}