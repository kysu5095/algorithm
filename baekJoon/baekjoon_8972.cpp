// 미친 아두이노

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>

using namespace std;

int r, c;
char arr[101][101];
int visited[101][101];
string command;

int dy[10] = { 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };
int dx[10] = { 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };

vector<pair<bool, pair<int, int>>> v;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int y, x;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> arr[i];
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'I') {
				y = i;
				x = j;
			}
			else if (arr[i][j] == 'R') v.push_back(make_pair(true, make_pair(i, j)));
		}
	}
	cin >> command;
	for (int X = 0; X < command.size(); X++) {
		arr[y][x] = '.';
		y += dy[command[X] - '0'];
		x += dx[command[X] - '0'];
		if (arr[y][x] == 'R') {
			cout << "kraj " << X + 1 << '\n';
			return 0;
		}
		arr[y][x] = 'I';

		for (auto& node : v) {
			if (!node.first) continue;
			int ny = node.second.first;
			int nx = node.second.second;
			arr[ny][nx] = '.';
			int min_val = INT_MAX;
			int d;
			for (int i = 1; i <= 9; i++) {
				int nny = ny + dy[i];
				int nnx = nx + dx[i];
				if (abs(y - nny) + abs(x - nnx) < min_val) {
					min_val = abs(y - nny) + abs(x - nnx);
					d = i;
				}
			}
			ny += dy[d];
			nx += dx[d];
			if (arr[ny][nx] == 'I') {
				cout << "kraj " << X + 1 << '\n';
				return 0;
			}
			node.second.first = ny;
			node.second.second = nx;
			visited[ny][nx]++;
		}

		for (auto& node : v) {
			if (!node.first) continue;
			if (visited[node.second.first][node.second.second] >= 2) node.first = false;
			else arr[node.second.first][node.second.second] = 'R';
		}
		memset(visited, 0, sizeof(visited));
	}
	for (int i = 0; i < r; i++)
		cout << arr[i] << '\n';
	return 0;
}