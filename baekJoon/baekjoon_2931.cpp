// 가스관

#include <iostream>
#include <queue>

using namespace std;

int r, c;
char arr[26][26];
bool visited[26][26] = { {false,}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int pipe[8][4] = { {0, 0, 0, 0}, {0, 0, 1, 1}, {1, 1, 0, 0}, {1, 1, 1, 1},
				   {1, 0, 1, 0}, {1, 0, 0, 1}, {0, 1, 0, 1}, {0, 1, 1, 0} };

int get_pipe_num(char p) {
	switch (p)
	{
	case 124: return 1;
	case '-': return 2;
	case '+': return 3;
	case '1': return 4;
	case '2': return 5;
	case '3': return 6;
	case '4': return 7;
	default: return 0;
	}
}

char return_pipe_character(int p) {
	switch (p)
	{
	case 1: return 124;
	case 2: return '-';
	case 3: return '+';
	case 4: return '1';
	case 5: return '2';
	case 6: return '3';
	case 7: return '4';
	}
}

bool is_range(int y, int x) {
	if (y < 0 || y == r || x < 0 || x == c) return false;
	else return true;
}

void construct_pipe(int _y, int _x) {
	int y = _y;
	int x = _x;
	int ny, nx, n_pipe, d;
	bool check;
	for (int i = 1; i <= 7; i++) {
		check = true;
		for (int j = 0; j < 4; j++) {
			ny = y + dy[j];
			nx = x + dx[j];
			if (pipe[i][j] && !is_range(ny, nx)) {
				check = false;
				break;
			}
			if (!is_range(ny, nx)) continue;
			if (pipe[i][j] && arr[ny][nx] == '.') {
				check = false;
				break;
			}
			n_pipe = get_pipe_num(arr[ny][nx]);
			if (j % 2 == 0) d = j + 1;
			else d = j - 1;
			if (pipe[i][j] && !pipe[n_pipe][d]) {
				check = false;
				break;
			}
			if (!pipe[i][j] && pipe[n_pipe][d]) {
				check = false;
				break;
			}
		}
		if (check) {
			cout << _y + 1 << " " << _x + 1 << " " << return_pipe_character(i) << '\n';
			return;
		}
	}
}

void find(int _y, int _x) {
	queue<pair<int, int>> q;
	visited[_y][_x] = true;
	int y, x, ny, nx, pny, pnx, d, p, n_p;
	for (int i = 0; i < 4; i++) {
		ny = _y + dy[i];
		nx = _x + dx[i];
		if (!is_range(ny, nx)) continue;
		if (arr[ny][nx] != '.' && arr[ny][nx] != 'Z') {
			n_p = get_pipe_num(arr[ny][nx]);
			if (i % 2 == 0) d = i + 1;
			else d = i - 1;
			if (pipe[n_p][d]) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
				break;
			}
		}
	}
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		p = get_pipe_num(arr[y][x]);
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (!pipe[p][i]) continue;
			ny = y + dy[i];
			nx = x + dx[i];
			if (!is_range(ny, nx) || visited[ny][nx]) continue;
			if (arr[ny][nx] == '.') {
				for (int j = 0; j < 4; j++) {
					pny = ny + dy[j];
					pnx = nx + dx[j];
					if (!is_range(pny, pnx)) continue;
					if (pny == y && pnx == x) continue;
					if (arr[pny][pnx] == '.') continue;
					n_p = get_pipe_num(arr[pny][pnx]);
					if (j % 2 == 0) d = j + 1;
					else d = j - 1;
					if (pipe[n_p][d]) {
						construct_pipe(ny, nx);
						return;
					}
				}
			}
			else {
				n_p = get_pipe_num(arr[ny][nx]);
				if (i % 2 == 0) d = i + 1;
				else d = i - 1;
				if (pipe[n_p][d]) {
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int y, x;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> arr[i];
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'M') {
				y = i;
				x = j;
			}
		}
	}
	find(y, x);
	return 0;
}