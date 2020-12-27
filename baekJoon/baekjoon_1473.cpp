// 미로 탈출

#define MAX 1 << 8
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m;
char arr[8][8] = { {0, }, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int door[4][4] = { {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 1, 1}, {1, 1, 0, 0} };
bool visited[8][8][MAX + 1][MAX + 1] = { { { {false,},},}, };
int row_flag, col_flag;

bool is_rotate(int& y, int& x, int& row, int& col) {
	if (((!(row_flag >> y & row)) && (col_flag >> x & col)) || (((row_flag >> y & row)) && !(col_flag >> x & col))) return false;
	else return true;

}

int bfs() {
	row_flag = 1 << (n - 1);
	col_flag = 1 << (m - 1);
	int row = (1 << n) - 1;
	int col = (1 << m) - 1;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(row, col), make_pair(0, 0)));
	visited[0][0][row][col] = true;
	int y, x, ny, nx, c_door, n_door, nd, len, t = 0;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().second.first;
			x = q.front().second.second;
			row = q.front().first.first;
			col = q.front().first.second;
			q.pop();
			if (y == n - 1 && x == m - 1) return t;
			if (arr[y][x] == 'A') c_door = 0;
			else if (arr[y][x] == 'B') continue;
			else {
				// 돌아감
				if (!is_rotate(y, x, row, col)) {
					if (arr[y][x] == 'C') c_door = 3;
					else c_door = 2;
				}
				// 안돌아감
				else {
					if (arr[y][x] == 'C') c_door = 2;
					else c_door = 3;
				}
			}

			for (int d = 0; d < 4; d++) {
				if (!door[c_door][d]) continue;
				ny = y + dy[d];
				nx = x + dx[d];
				if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
				if (arr[ny][nx] == 'B') continue;
				if (d % 2 == 0) nd = d + 1;
				else nd = d - 1;
				// 다음칸 A
				if (arr[ny][nx] == 'A') {
					if (!visited[ny][nx][row][col]) {
						visited[ny][nx][row][col] = true;
						q.push(make_pair(make_pair(row, col), make_pair(ny, nx)));
					}
				}

				// 다음칸 C or D
				else {
					// 다음칸이 회전하지 않았음
					if (is_rotate(ny, nx, row, col)) {
						// 반대편 문 O
						if (door[arr[ny][nx] - 'A'][nd]) {
							if (!visited[ny][nx][row][col]) {
								visited[ny][nx][row][col] = true;
								q.push(make_pair(make_pair(row, col), make_pair(ny, nx)));
							}
						}
					}
					// 다음칸이 회전함
					else {
						if (arr[ny][nx] == 'C') n_door = 3;
						else n_door = 2;

						// 반대편 문 O
						if (door[n_door][nd]) {
							if (!visited[ny][nx][row][col]) {
								visited[ny][nx][row][col] = true;
								q.push(make_pair(make_pair(row, col), make_pair(ny, nx)));
							}
						}
					}
				}
				int tmp_row = row_flag >> y;
				int tmp_col = col_flag >> x;
				tmp_row = row ^ tmp_row;
				tmp_col = col ^ tmp_col;
				if (!visited[y][x][tmp_row][tmp_col]) {
					visited[y][x][tmp_row][tmp_col] = true;
					q.push(make_pair(make_pair(tmp_row, tmp_col), make_pair(y, x)));
				}
			}
		}
		t++;
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << bfs() << '\n';
	return 0;
}