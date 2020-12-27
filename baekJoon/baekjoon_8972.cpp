// 미친 아두이노

#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

int r, c, y, x;
char arr[101][101];
bool visited[101][101][2] = { { {false, }, }, };
char command[101];
int dy[10] = { 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };
int dx[10] = { 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };
vector<pair<bool, pair<int, int>>> v;

int game() {
	int ny, nx, d, len, ry, rx, nry, nrx, nnry, nnrx, dist, mdist;
	bool state;
	int sz = (int)strlen(command);
	for (int i = 0; i < sz; i++) {
		d = command[i] - '0';
		ny = y + dy[d];
		nx = x + dx[d];
		if (arr[ny][nx] == 'R') return i + 1;
		arr[y][x] = '.';
		arr[ny][nx] = 'I';
		y = ny;
		x = nx;

		len = v.size();
		for (int idx = 0; idx < len; idx++) {
			ry = v[idx].second.first;
			rx = v[idx].second.second;
			state = v[idx].first;
			if (!state) continue;
			arr[ry][rx] = '.';

			mdist = 1000;
			for (int j = 1; j < 10; j++) {
				nry = ry + dy[j];
				nrx = rx + dx[j];
				dist = abs(nry - y) + abs(nrx - x);
				if (dist < mdist) {
					mdist = dist;
					nnry = nry;
					nnrx = nrx;
				}
			}
			if (arr[nnry][nnrx] == 'I') return i + 1;
			if (visited[nnry][nnrx][0]) {
				visited[nnry][nnrx][1] = true;
				v[idx].first = false;
				v[idx].second.first = nnry;
				v[idx].second.second = nnrx;
				continue;
			}
			visited[nnry][nnrx][0] = true;
			v[idx].second.first = nnry;
			v[idx].second.second = nnrx;
		}
		for (int idx = 0; idx < len; idx++) {
			if (!v[idx].first) continue;
			ry = v[idx].second.first;
			rx = v[idx].second.second;
			if (visited[ry][rx][1]) v[idx].first = false;
			else arr[ry][rx] = 'R';
		}
		memset(visited, false, sizeof(visited));
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> arr[i];
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'I') y = i, x = j;
			else if (arr[i][j] == 'R') v.push_back(make_pair(true, make_pair(i, j)));
		}
	}
	cin >> command;
	int res = game();
	if (res != -1) cout << "kraj " << res << '\n';
	else {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				cout << arr[i][j];
			cout << '\n';
		}
	}
	return 0;
}