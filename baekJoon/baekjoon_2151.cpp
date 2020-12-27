// 거울 설치
// 9:30

#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>

using namespace std;

int n;
char arr[51][51];
int visited[51][51][4];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs(int _y, int _x) {
	int y, x, ny, nx, d, res = INT_MAX;
	memset(visited, -1, sizeof(visited));
	// 방향, y좌표, x좌표 저장
	queue<pair<int, pair<int, int>>> q;
	// 처음 나아갈 방향 지정
	for (int i = 0; i < 4; i++) {
		ny = _y + dy[i];
		nx = _x + dx[i];
		if (ny >= 0 && ny < n && nx >= 0 && nx < n && arr[ny][nx] != '*') {
			q.push(make_pair(i, make_pair(_y, _x)));
			visited[_y][_x][i] = 0;
		}
	}
	while (!q.empty()) {
		y = q.front().second.first;
		x = q.front().second.second;
		d = q.front().first;
		q.pop();
		// 반대편 문 도착
		if (arr[y][x] == '#' && (y != _y || x != _x)) {
			res = res > visited[y][x][d] ? visited[y][x][d] : res;
			continue;
		}
		// 현재 진행방향 그대로 나아감
		ny = y + dy[d];
		nx = x + dx[d];
		if (ny >= 0 && ny < n && nx >= 0 && nx < n && arr[ny][nx] != '*') {
			if (visited[ny][nx][d] == -1 || visited[ny][nx][d] > visited[y][x][d]) {
				visited[ny][nx][d] = visited[y][x][d];
				q.push(make_pair(d, make_pair(ny, nx)));
			}
		}
		// 거울을 설치
		if (arr[y][x] == '!') {
			// 0 : 동, 1 : 서, 2 : 남, 3 : 북
			if (d < 2) {
				for (int i = 2; i < 4; i++) {
					ny = y + dy[i];
					nx = x + dx[i];
					if (ny >= 0 && ny < n && nx >= 0 && nx < n && arr[ny][nx] != '*') {
						// 다음칸이 현재 칸보다 방문 횟수가 적을 때
						if (visited[ny][nx][i] == -1 || visited[ny][nx][i] > visited[y][x][d] + 1) {
							visited[ny][nx][i] = visited[y][x][d] + 1;
							q.push(make_pair(i, make_pair(ny, nx)));
						}
					}
				}
			}
			else {
				for (int i = 0; i < 2; i++) {
					ny = y + dy[i];
					nx = x + dx[i];
					if (ny >= 0 && ny < n && nx >= 0 && nx < n && arr[ny][nx] != '*') {
						// 다음칸이 현재 칸보다 방문 횟수가 적을 때
						if (visited[ny][nx][i] == -1 || visited[ny][nx][i] > visited[y][x][d] + 1) {
							visited[ny][nx][i] = visited[y][x][d] + 1;
							q.push(make_pair(i, make_pair(ny, nx)));
						}
					}
				}
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int y, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '#')
				y = i, x = j;
		}
	}
	cout << bfs(y, x) << '\n';
	return 0;
}