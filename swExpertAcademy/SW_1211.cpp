// D4 : Ladder2

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

int res, cordinate;
bool arr[101][101];
bool visited[101][101];
int dy[4] = { 1, 0, 0 };
int dx[4] = { 0, 1, -1 };

bool isRight(int &y, int &x) {
	if (y < 0 || y == 100 || x < 0 || x == 100 || !arr[y][x] || visited[y][x]) return false;
	else return true;
}

void bfs(int _x) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(0, _x)));
	visited[0][_x] = true;
	int y, x, d, ny, nx, len, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			y = q.front().second.first;
			x = q.front().second.second;
			d = q.front().first;
			q.pop();
			if (y == 99) {
				if (res > t) {
					res = t;
					cordinate = _x;
				}
				return;
			}
			if (d == 0) {
				bool flag = true;
				for (int i = 1; i <= 2; i++) {
					ny = y + dy[i];
					nx = x + dx[i];
					if (isRight(ny, nx)) {
						visited[ny][nx] = true;
						q.push(make_pair(i, make_pair(ny, nx)));
						flag = false;
						break;
					}
				}
				if (flag) {
					ny = y + dy[d];
					nx = x + dx[d];
					if (isRight(ny, nx)) {
						visited[ny][nx] = true;
						q.push(make_pair(d, make_pair(ny, nx)));
					}
				}
			}
			// >>>
			else if (d == 1) {
				for (int i = 0; i <= 1; i++) {
					ny = y + dy[i];
					nx = x + dx[i];
					if (isRight(ny, nx)) {
						visited[ny][nx] = true;
						q.push(make_pair(i, make_pair(ny, nx)));
						break;
					}
				}
			}
			// <<<
			else {
				for (int i = 0; i <= 2; i += 2) {
					ny = y + dy[i];
					nx = x + dx[i];
					if (isRight(ny, nx)) {
						visited[ny][nx] = true;
						q.push(make_pair(i, make_pair(ny, nx)));
						break;
					}
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int test_case;
	int TC = 10;
	while (TC--) {
		res = INT_MAX;
		cin >> test_case;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> arr[i][j];
		for (int i = 0; i < 100; i++)
			if (arr[0][i])
				bfs(i);
		cout << "#" << test_case << " " << cordinate << '\n';
	}
	return 0;
}