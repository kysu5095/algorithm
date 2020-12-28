// 미네랄 2

#include <iostream>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int r, c, cnt;
int bar[101];
char arr[101][101];
bool visited[101][101];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;

void falling() {
	int y, x, add = 0;
	bool flag = true;
	int len = v.size();
	while (flag) {
		add++;
		for (int i = 0; i < len; i++) {
			y = v[i].first + add;
			x = v[i].second;
			if (y == r || arr[y][x] == 'x') {
				flag = false;
				break;
			}
		}
	}
	add--;
	for (int i = 0; i < len; i++)
		arr[v[i].first + add][v[i].second] = 'x';
}

bool bfs(int y, int x) {
	int ny, nx, len;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	v.push_back(make_pair(y, x));
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == r || nx < 0 || nx == c) continue;
			if (visited[ny][nx] || arr[ny][nx] == '.') continue;
			if (ny == r - 1) {
				v.clear();
				return false;
			}
			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
			v.push_back(make_pair(ny, nx));
		}
	}
	len = v.size();
	for (int i = 0; i < len; i++)
		arr[v[i].first][v[i].second] = '.';
	return true;
}

void game(int y, int x, bool flag) {
	int ny, nx;
	while (x >= 0 && x != c) {
		if (arr[y][x] == 'x') {
			arr[y][x] = '.';
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				memset(visited, false, sizeof(visited));
				if (ny < 0 || ny == r || nx < 0 || nx == c || visited[ny][nx]) continue;
				if (arr[ny][nx] == '.') continue;
				if (bfs(ny, nx)) {
					falling();
					v.clear();
					break;
				}
			}
			break;
		}
		if (flag) x++;
		else x--;
	}
}


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
		cin >> bar[i];
	for (int i = 0; i < cnt; i++) {
		if (i % 2 == 0) game(r - bar[i], 0, true);
		else game(r - bar[i], c - 1, false);
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	return 0;
}