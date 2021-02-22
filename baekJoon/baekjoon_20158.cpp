// 사장님 달려가고 있습니다

#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[101][101];
bool visited[101][101][4][17];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	for (int i = 0; i < 4; i++) {
		q.push(make_pair(make_pair(0, 0), make_pair(i, 0)));
		visited[0][0][i][0] = true;
	}
	int y, x, ny, nx, d, s, len, t = 0;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().first.first;
			x = q.front().first.second;
			d = q.front().second.first;
			s = q.front().second.second;
			q.pop();
			if (y == n - 1 && x == n - 1) return t;
			for (int i = 0; i < 4; i++) {
				ny = y, nx = x;
				bool flag = false;
				int next_s = (i == d) ? s + 1 : 1;
				for (int j = 1; j <= next_s; j++) {
					ny += dy[i];
					nx += dx[i];
					if (ny < 0 || ny == n || nx < 0 || nx == n) break;
					if (arr[ny][nx]) {
						if (t >= arr[ny][nx]) break;
						if (j == next_s && t + 1 == arr[ny][nx]) break;
					}
					if (j == next_s) flag = true;
				}
				if (flag) {
					if (visited[ny][nx][i][next_s]) continue;
					q.push(make_pair(make_pair(ny, nx), make_pair(i, next_s)));
					visited[ny][nx][i][next_s] = true;
				}
			}
		}
		t++;
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	int res = bfs();
	if (res == -1) cout << "Fired\n";
	else cout << res << '\n';
	return 0;
}