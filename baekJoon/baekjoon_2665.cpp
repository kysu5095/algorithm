// 미로만들기

#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int n;
char arr[51][51];
int visited[51][51];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(0, 0)));
	int y, x, ny, nx, b;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = INT_MAX;
	while (!pq.empty()) {
		y = pq.top().second.first;
		x = pq.top().second.second;
		b = -pq.top().first;
		pq.pop();
		if (b > visited[y][x]) continue;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
			if (arr[ny][nx] == '1') {
				if (b < visited[ny][nx]) {
					visited[ny][nx] = b;
					pq.push(make_pair(-b, make_pair(ny, nx)));
				}
			}
			else {
				if (b + 1 < visited[ny][nx]) {
					visited[ny][nx] = b + 1;
					pq.push(make_pair(-b - 1, make_pair(ny, nx)));
				}
			}
		}
	}
	return visited[n - 1][n - 1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << bfs() << '\n';
	return 0;
}