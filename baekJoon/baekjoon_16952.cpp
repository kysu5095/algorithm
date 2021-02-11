// 체스판 여행 2

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, sy, sx;
int arr[10][10];
bool visited[3][102][11][11] = { {{{false,},},}, };
int dy[3][8] = { {-2, -2, 2, 2, -1, -1, 1, 1},
				 {-1, -1, 1, 1}, {0, 0, 1, -1} };
int dx[3][8] = { {-1, 1, -1, 1, -2, 2, -2, 2},
				 {-1, 1, -1, 1}, {1, -1, 0, 0} };
vector<int> v;

void bfs() {
	/* 변경횟수, 현재 말, 찾는 말 번호, 좌표 */
	queue<pair<pair<int, int>, pair<int, pair<int, int>>>> q;
	queue<pair<pair<int, int>, pair<int, int>>> tmp;
	for (int i = 0; i < 3; i++) {
		// 시작점에 모든 말(나이트,비숍,룩) 놓기
		q.push(make_pair(make_pair(0, i), make_pair(2, make_pair(sy, sx))));
		visited[i][2][sy][sx] = true;
	}
	int y, x, ny, nx, change, horse, target, idx, len, cnt = 1;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().second.second.first;
			x = q.front().second.second.second;
			change = q.front().first.first;
			horse = q.front().first.second;
			target = q.front().second.first;
			tmp.push(make_pair(make_pair(change, target), make_pair(y, x)));
			q.pop();
			if (horse == 0) idx = 8;
			else idx = 4;

			// 이동
			for (int i = 0; i < idx; i++) {
				ny = y + dy[horse][i];
				nx = x + dx[horse][i];
				while (true) {
					if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
					if (arr[ny][nx] == target) {
						if (arr[ny][nx] == n * n) v.push_back(change);
						else {
							if (!visited[horse][target + 1][ny][nx]) {
								visited[horse][target][ny][nx] = true;
								visited[horse][target + 1][ny][nx] = true;
								q.push(make_pair(make_pair(change, horse), make_pair(target + 1, make_pair(ny, nx))));
							}
						}
					}
					else {
						if (!visited[horse][target][ny][nx]) {
							visited[horse][target][ny][nx] = true;
							q.push(make_pair(make_pair(change, horse), make_pair(target, make_pair(ny, nx))));
						}
					}

					if (horse == 0) break;
					ny += dy[horse][i];
					nx += dx[horse][i];
				}
			}
		}
		if (v.size()) {
			sort(v.begin(), v.end());
			cout << cnt << " " << v[0] << '\n';
			return;
		}
		while (!tmp.empty()) {
			y = tmp.front().second.first;
			x = tmp.front().second.second;
			change = tmp.front().first.first;
			target = tmp.front().first.second;
			tmp.pop();
			for (int i = 0; i < 3; i++) {
				if (!visited[i][target][y][x]) {
					visited[i][target][y][x] = true;
					q.push(make_pair(make_pair(change + 1, i), make_pair(target, make_pair(y, x))));
				}
			}
		}
		cnt++;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			// 시작지점
			if (arr[i][j] == 1) {
				sy = i;
				sx = j;
			}
		}
	}
	bfs();
	return 0;
}