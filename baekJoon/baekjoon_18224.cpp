// 미로에 갇힌 건우

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m;
bool arr[501][501], visited[501][501][21];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

bool terminate(int& y, int& x) {
	return (y == n - 1 && x == n - 1);
}

void bfs() {
	queue< pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0][0] = true;
	int y, x, ny, nx, len, t = 0, sun = 1, day = 1;
	while (!q.empty()) {
		int before_sun = sun;
		if (++t % m == 0) {
			sun ^= 1;
			if (sun) {
				day++;
				t = 0;
			}
		}
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx][t]) continue;
				if (!arr[ny][nx]) {
					if (terminate(ny, nx)) {
						string str = sun ? "sun" : "moon";
						cout << day << " " << str << '\n';
						return;
					}
					q.push(make_pair(ny, nx));
					visited[ny][nx][t] = true;
				}
				else {
					if (before_sun) continue;
					while (true) {
						ny += dy[i];
						nx += dx[i];
						if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx][t]) break;
						if (!arr[ny][nx]) {
							if (terminate(ny, nx)) {
								string str = sun ? "sun" : "moon";
								cout << day << " " << str << '\n';
								return;
							}
							q.push(make_pair(ny, nx));
							visited[ny][nx][t] = true;
							break;
						}
					}
				}
			}
		}
	}
	cout << "-1\n";
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	if (n == 1) cout << "1 sun\n";
	else bfs();
	return 0;
}