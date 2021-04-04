// 미네랄 2

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int r, c, n;
char arr[101][101];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void down_cluster(vector<pair<int, int>>& v) {
	bool find = false;
	int cnt = 0;
	while (!find) {
		cnt++;
		for (auto& node: v) {
			if (node.first + cnt == r || arr[node.first + cnt][node.second] == 'x') {
				find = true;
				break;
			}
		}
	}

	for (auto& node : v)
		arr[node.first + cnt - 1][node.second] = 'x';
}

void redraw_cluster(int& y, int& x, vector<pair<int, int>>& v) {
	for (auto& node : v)
		arr[node.first][node.second] = 'x';
}

void boom(int _y, int _x) {
	queue<pair<int, int>> q;
	q.push(make_pair(_y, _x));

	vector<pair<int, int>> v;
	v.push_back(make_pair(_y, _x));
	arr[_y][_x] = '.';

	bool find = false;
	int y, x, ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if (y == r - 1) {
			find = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == r || nx < 0 || nx == c || arr[ny][nx] == '.') continue;
			q.push(make_pair(ny, nx));
			arr[ny][nx] = '.';
			v.push_back(make_pair(ny, nx));
		}
	}
	if (find) redraw_cluster(_y, _x, v);
	else down_cluster(v);
}

void throw_stick(int y, int d) {
	int x;
	if (d) x = c - 1;
	else x = 0;

	while (x >= 0 && x < c) {
		if (arr[y][x] == 'x') {
			arr[y][x] = '.';
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny == r || nx < 0 || nx == c || arr[ny][nx] == '.')continue;
				boom(ny, nx);
			}
			break;
		}
		x += dx[d];
	}
}

int main() {
	scanf(" %d %d", &r, &c);
	for (int i = 0; i < r; i++) scanf("%s", arr[i]);
	scanf(" %d", &n);
	for(int i = 0; i < n; i++) {
		int input;
		scanf(" %d", &input);
		if (i % 2) throw_stick(r - input, 1);
		else throw_stick(r - input, 0);
	}
	for (int i = 0; i < r; i++) printf("%s\n", arr[i]);
	return 0;
}