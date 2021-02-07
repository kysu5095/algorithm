// 미로 만들기

#include <iostream>
#include <queue>

using namespace std;

int n;
char arr[51][51];
bool visited[51][51] = { {false,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(0, 0)));
	visited[0][0] = true;

	int y, x, c, ny, nx;
	while (!pq.empty()) {
		y = pq.top().second.first;
		x = pq.top().second.second;
		c = -pq.top().first;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx]) continue;
			if (ny == n - 1 && nx == n - 1) return c;
			if (arr[ny][nx] == '1') pq.push(make_pair(-c, make_pair(ny, nx)));
			else pq.push(make_pair(-(c + 1), make_pair(ny, nx)));
			visited[ny][nx] = true;
		}
	}
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