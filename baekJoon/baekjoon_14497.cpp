// 주난의 난(難)

#include <iostream>
#include <queue>

using namespace std;

int n, m;
char arr[301][301];
bool visited[301][301];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs(int sy, int sx) {
	queue<pair<int, int>> q, next_q;
	q.push(make_pair(sy, sx));
	visited[sy][sx] = true;
	int y, x, ny, nx, t = 0;
	while (true) {
		t++;
		while (!q.empty()) {
			y = q.front().first;
			x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx]) continue;
				if (arr[ny][nx] == '#') return t;
				if (arr[ny][nx] == '0') q.push(make_pair(ny, nx));
				else next_q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}

		while (!next_q.empty()) {
			q.push(next_q.front());
			next_q.pop();
		}
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int y1, x1, y2, x2;
	cin >> n >> m;
	cin >> y1 >> x1 >> y2 >> x2;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << bfs(y1 - 1, x1 - 1) << '\n';
	return 0;
}