#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int test_case, h, w, o, f;
int arr[101][101];
bool visited[101][101];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

bool bfs(int sy, int sx, int fy, int fx) {
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(f, make_pair(sy, sx)));
	visited[sy][sx] = true;
	int y, x, d, ny, nx, len;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().second.first;
			x = q.front().second.second;
			d = q.front().first;
			q.pop();
			if (d == 0) continue;
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == h || nx < 0 || nx == w || visited[ny][nx]) continue;
				if ((arr[y][x] - arr[ny][nx] >= 0) || (arr[ny][nx] - arr[y][x] <= d)) {
					if (ny == fy && nx == fx) return true;
					visited[ny][nx] = true;
					q.push(make_pair(d - 1, make_pair(ny, nx)));
				}
			}
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int tc, sy, sx, fy, fx, y, x, d;
	cin >> tc;
	while (tc--) {
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
		cin >> h >> w >> o >> f;
		cin >> sy >> sx >> fy >> fx;
		while (o--) {
			cin >> y >> x >> d;
			arr[y - 1][x - 1] = d;
		}
		if (bfs(sy - 1, sx - 1, fy - 1, fx - 1)) cout << "잘했어!!\n";
		else cout << "인성 문제있어??\n";
	}
	return 0;
}