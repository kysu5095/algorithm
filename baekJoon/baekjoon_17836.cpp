// 공주님을 구해라!
// 12:05

#include <iostream>
#include <queue>

using namespace std;

int n, m, t, res;
int arr[101][101];
bool visited[101][101][2] = { { {false, } ,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

bool bfs() {
	queue<pair<bool, pair<int, int>>> q;
	q.push(make_pair(false, make_pair(0, 0)));
	visited[0][0][0] = true;
	int y, x, ny, nx, len, time = 0;
	bool flag;
	for (int time = 0; time <= t; time++) {
		len = q.size();
		while (len--) {
			y = q.front().second.first;
			x = q.front().second.second;
			flag = q.front().first;
			q.pop();
			if (y == n - 1 && x == m - 1) {
				res = time;
				return true;
			}
			if (arr[y][x] == 2) flag = true;
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
				if (flag && visited[ny][nx][flag]) continue;
				if (!flag && visited[ny][nx][flag]) continue;
				if (!flag && arr[ny][nx] == 1) continue;
				visited[ny][nx][flag] = true;
				q.push(make_pair(flag, make_pair(ny, nx)));
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	if (bfs()) cout << res << '\n';
	else cout << "Fail\n";
	return 0;
}