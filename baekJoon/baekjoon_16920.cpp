// 확장 게임

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m, p;
char arr[1001][1001];
int speed[10], cnt[10];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> v[10];

void bfs() {
	queue<pair<int, int>> q[10];
	for (int i = 1; i <= p; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			q[i].push(make_pair(v[i][j].first, v[i][j].second));
			cnt[i]++;
		}
	}

	int y, x, ny, nx, len;
	while (true) {
		bool end = true;
		for (int i = 1; i <= p; i++) {
			if (!q[i].empty()) {
				end = false;
				break;
			}
		}
		if (end) break;

		for (int idx = 1; idx <= p; idx++) {
			for (int s = 0; s < speed[idx]; s++) {
				len = q[idx].size();
				if (!len) break;
				while (len--) {
					y = q[idx].front().first;
					x = q[idx].front().second;
					q[idx].pop();

					for (int i = 0; i < 4; i++) {
						ny = y + dy[i];
						nx = x + dx[i];
						if (ny < 0 || ny == n || nx < 0 || nx == m || arr[ny][nx] != '.') continue;
						q[idx].push(make_pair(ny, nx));
						arr[ny][nx] = (idx + '0');
						cnt[idx]++;
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 1; i <= p; i++) scanf(" %d", &speed[i]);
	for (int i = 0; i < n; i++) {
		scanf(" %s", arr[i]);
		for (int j = 0; j < m; j++) {
			if (arr[i][j] >= '1' && arr[i][j] <= '9')
				v[(arr[i][j] - '0')].push_back(make_pair(i, j));
		}
	}
	bfs();
	for (int i = 1; i <= p; i++) printf("%d ", cnt[i]);
	printf("\n");
	return 0;
}