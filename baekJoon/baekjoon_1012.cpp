// 유기농 배추
// 1:20

#include <iostream>
#include <string.h>

using namespace std;

int test_case, m, n, k;
int arr[51][51];
bool visited[51][51];

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void dfs(int y, int x) {
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + p[i].y;
		nx = x + p[i].x;
		if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && arr[ny][nx]) {
			visited[ny][nx] = true;
			dfs(ny, nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int y, x, res;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] && !visited[i][j]) {
					visited[i][j] = true;
					dfs(i, j);
					res++;
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}

