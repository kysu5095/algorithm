// 숫자키

#include <iostream>
#include <queue>
#include <string.h>
#define MAX 100000

using namespace std;

int m, r;
int arr[6][5] = { {-1,-1,-1,-1,-1}, {-1,7,8,9,-1}, {-1,4,5,6,-1}, {-1,1,2,3,-1}, {-1,0,-1,-1,-1}, {-1,-1,-1,-1,-1} };
int visited[5][4][MAX + 1];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs() {
	memset(visited, -1, sizeof(visited));
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(4, 1)));
	visited[4][1][0] = 0;
	int y, x, ny, nx, num, nnum;
	while (!q.empty()) {
		y = q.front().second.first;
		x = q.front().second.second;
		num = q.front().first;
		q.pop();
		nnum = (10 * num + arr[y][x]) % m;
		if (nnum == r) return visited[y][x][num] + 1;
		if (visited[y][x][nnum] == -1) {
			q.push(make_pair(nnum, make_pair(y, x)));
			visited[y][x][nnum] = visited[y][x][num] + 1;
		}
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (arr[ny][nx] == -1) continue;
			if (visited[ny][nx][num] == -1) {
				q.push(make_pair(num, make_pair(ny, nx)));
				visited[ny][nx][num] = visited[y][x][num] + 1;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> r;
	cout << bfs() << '\n';
	return 0;
}