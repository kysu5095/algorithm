// 알고스팟

#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int n, m;
char arr[101][101];
int visited[101][101];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0 ,0 };

int bfs() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(0, 0)));
	visited[0][0] = 0;
	int y, x, ny, nx, cost;
	while (!pq.empty()) {
		cost = -pq.top().first;
		y = pq.top().second.first;
		x = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
			if (!(arr[ny][nx] - '0')) {
				if (visited[ny][nx] > cost) {
					visited[ny][nx] = cost;
					pq.push(make_pair(-cost, make_pair(ny, nx)));
				}
			}
			else {
				if (visited[ny][nx] > cost + 1) {
					visited[ny][nx] = cost + 1;
					pq.push(make_pair(-(cost + 1), make_pair(ny, nx)));
				}
			}
		}
	}
	return visited[n - 1][m - 1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++)
			visited[i][j] = INT_MAX;
	}

	cout << bfs() << '\n';
	return 0;
}