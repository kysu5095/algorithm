// 숫자키

#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#define MAX 100000

using namespace std;

int m, r;
int arr[6][5] = { {-1,-1,-1,-1,-1}, {-1,7,8,9,-1}, {-1,4,5,6,-1}, {-1,1,2,3,-1}, {-1,0,-1,-1,-1}, {-1,-1,-1,-1,-1} };
int visited[6][5][MAX+1];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> r;
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(4, 1)));
	memset(visited, -1, sizeof(visited));
	visited[4][1][0] = 0;
	while (!q.empty()) {
		int num = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		int next = (10 * num + arr[y][x]) % m;
		if (visited[y][x][next] == -1) {
			q.push(make_pair(next, make_pair(y, x)));
			visited[y][x][next] = visited[y][x][num] + 1;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (arr[ny][nx] == -1) continue;
			if (visited[ny][nx][num] == -1) {
				q.push(make_pair(num, make_pair(ny, nx)));
				visited[ny][nx][num] = visited[y][x][num] + 1;
			}
		}
	}
	int res = MAX + 1;
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 4; j++) {
			if (visited[i][j][r] == -1) continue;
			res = min(res, visited[i][j][r]);
		}
	}
	cout << res << '\n';
	return 0;
}