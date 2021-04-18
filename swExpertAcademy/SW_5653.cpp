// 줄기세포배양

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int n, m, K;
int arr[405][405], t_arr[405][405];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

struct Point {
	int y, x, t, sz;
};
queue<Point> q;

int main() {
	//freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		memset(arr, 0, sizeof(arr));
		memset(t_arr, 0, sizeof(t_arr));
		scanf(" %d %d %d", &n, &m, &K);
		for (int i = 151; i < 151 + n; i++) {
			for (int j = 151; j < 151 + m; j++) {
				scanf(" %d", &arr[i][j]);
				if (arr[i][j]) q.push({ i, j, arr[i][j], arr[i][j] });
			}
		}

		for (int k = 0; k < K; k++) {
			int len = q.size();
			while (len--) {
				int y = q.front().y;
				int x = q.front().x;
				int t = q.front().t;
				int sz = q.front().sz;
				q.pop();
				if (arr[y][x] != sz) continue;

				if (t == 0) {
					for (int i = 0; i < 4; i++) {
						int ny = y + dy[i];
						int nx = x + dx[i];
						if (arr[ny][nx] == 0 && t_arr[ny][nx] == 0) {
							arr[ny][nx] = sz;
							t_arr[ny][nx] = k;
							q.push({ ny, nx, sz, sz });
						}
						else {
							if (arr[ny][nx] >= sz || t_arr[ny][nx] != k) continue;
							arr[ny][nx] = sz;
							q.push({ ny, nx, sz, sz });
						}
					}
				}
				if (t != -sz) q.push({ y, x, t - 1, sz });
			}
		}
		int ret = 0;
		while (!q.empty()) {
			int y = q.front().y;
			int x = q.front().x;
			int t = q.front().t;
			int sz = q.front().sz;
			q.pop();
			if (arr[y][x] != sz || t == -sz) continue;
			ret++;
		}
		printf("#%d %d\n", tc, ret);
	}
}