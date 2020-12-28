// 두 동전
// 10:35

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int n, m;
char arr[21][21];
bool visited[21][21][21][21] = {{{{false,},},},};
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

vector<pair<int, int>> v;

bool is_range(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	else return false;
}

int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(v[0].first, v[0].second), make_pair(v[1].first, v[1].second)));
	visited[v[0].first][v[0].second][v[1].first][v[1].second] = true;
	int y_1, x_1, y_2, x_2, ny_1, nx_1, ny_2, nx_2, len, t = 0;
	bool flag_1, flag_2;
	while (!q.empty()) {
		t++;
		if (t > 10) break;
		len = q.size();
		while (len--) {
			y_1 = q.front().first.first;
			x_1 = q.front().first.second;
			y_2 = q.front().second.first;
			x_2 = q.front().second.second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny_1 = y_1 + dy[i];
				nx_1 = x_1 + dx[i];
				ny_2 = y_2 + dy[i];
				nx_2 = x_2 + dx[i];
				flag_1 = is_range(ny_1, nx_1);
				flag_2 = is_range(ny_2, nx_2);
				if (!flag_1 && flag_2) return t;
				if (flag_1 && !flag_2) return t;
				if (!flag_1 && !flag_2) continue;
				if (arr[ny_1][nx_1] == '#') {
					ny_1 = y_1;
					nx_1 = x_1;
				}
				if (arr[ny_2][nx_2] == '#') {
					ny_2 = y_2;
					nx_2 = x_2;
				}
				if (!visited[ny_1][nx_1][ny_2][nx_2]) {
					visited[ny_1][nx_1][ny_2][nx_2] = true;
					q.push(make_pair(make_pair(ny_1, nx_1), make_pair(ny_2, nx_2)));
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'o')
				v.push_back(make_pair(i, j));
		}
	}
	cout << bfs() << '\n';
	return 0;
}