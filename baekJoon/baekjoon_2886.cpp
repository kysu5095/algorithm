// 자리 전쟁

#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <queue>

using namespace std;

int r, c;
char arr[101][101];
bool visited[101][101];
int dis[101][101][2];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;

void bfs(int y, int x) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	int ny, nx, len, cnt = 0;
	while (!q.empty()) {
		cnt++;
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == r || nx < 0 || nx == c || visited[ny][nx]) continue;
				if (arr[ny][nx] == 'L') {
					if (dis[ny][nx][0] > cnt) {
						dis[ny][nx][0] = cnt;
						dis[ny][nx][1] = 1;
					}
					else if (dis[ny][nx][0] == cnt) {
						dis[ny][nx][1]++;
					}
				}
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> arr[i];
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'X')
				v.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			dis[i][j][0] = INT_MAX;
	for (int i = 0; i < v.size(); i++)
		bfs(v[i].first, v[i].second);

	int res = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (dis[i][j][1] >= 2)
				res++;
	cout << res << '\n';
	return 0;
}