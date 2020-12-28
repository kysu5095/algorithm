// 국경

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int n;
bool flag = false;
char map[4][4];
char arr[12][20];
bool visited[12][20] = { {false,}, };
bool visited2[12][20];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int ndy[4] = { 0, 0, 2, -2 };
int ndx[4] = { 4, -4, 0, 0 };

void print() {
	cout << "yes\n";
	for (int i = 0; i < (n << 1) + 3; i++) {
		for (int j = 0; j < (n << 2) + 3; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}

bool bfs(int y, int x) {
	char charactor = arr[y][x];
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited2[y][x] = true;
	int ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (i < 2 && arr[ny + dy[i]][nx + dx[i]] == '|') continue;
			if (i >= 2 && arr[ny][nx] == '-') continue;
			ny = y + ndy[i];
			nx = x + ndx[i];
			if (ny <= 0 || ny >= (n << 1) + 2 || nx <= 0 || nx >= (n << 2) + 2 || visited2[ny][nx]) continue;
			if (charactor == '.') {
				if (arr[ny][nx] != '.') charactor = arr[ny][nx];
			}
			else {
				if (arr[ny][nx] != '.' && arr[ny][nx] != charactor) return false;
			}
			q.push(make_pair(ny, nx));
			visited2[ny][nx] = true;
		}
	}
	return true;
}

// 겹치는 동물 있는지 판단
bool find() {
	memset(visited2, false, sizeof(visited2));
	for (int i = 2; i < (n << 1) + 2; i += 2) {
		for (int j = 3; j < (n << 2) + 2; j += 4) {
			if (!visited2[i][j]) {
				if (!bfs(i, j)) return false;
			}
		}
	}
	return true;
}

// 국경 만들기
void dfs(int y, int x) {
	if (flag) return;
	// 끝까지 도착
	if (y == ((n << 1) + 1) && x == ((n << 2) + 1)) {
		//print();
		if (find()) {
			print();
			flag = true;
		}
		return;
	}
	int ny, nx;
	for (int d = 0; d < 4; d++) {
		ny = y + ndy[d];
		nx = x + ndx[d];
		if (ny <= 0 || ny >= (n << 1) + 2 || nx <= 0 || nx >= (n << 2) + 2 || visited[ny][nx]) continue;
		visited[ny][nx] = true;
		if (d < 2) {
			for (int i = 1; i <= 3; i++)
				arr[y + (dy[d] * i)][x + (dx[d] * i)] = '-';
			dfs(ny, nx);
			for (int i = 1; i <= 3; i++)
				arr[y + (dy[d] * i)][x + (dx[d] * i)] = ' ';
		}
		else {
			arr[y + dy[d]][x + dx[d]] = '|';
			dfs(ny, nx);
			arr[y + dy[d]][x + dx[d]] = ' ';
		}
		visited[ny][nx] = false;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int y = 0, x = 0;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 20; j++)
			arr[i][j] = ' ';
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	// 기본적인 맵 만들기
	for (int i = 0; i < (n << 1) + 3; i++) {
		for (int j = 0; j < (n << 2) + 3; j++) {
			if (i == 0 || i == ((n << 1) + 2) || j == 0 || j == ((n << 2) + 2)) {
				arr[i][j] = '#';
				continue;
			}
			if ((i % 2) && (j % 4 == 1)) {
				arr[i][j] = '+';
				continue;
			}
			if (!(i % 2) && (j % 4 == 3)) {
				arr[i][j] = map[y][x++];
				if (x == n) {
					y++;
					x = 0;
				}
				continue;
			}
		}
	}
	visited[1][1] = true;
	dfs(1, 1);
	if (!flag) cout << "no\n";
	return 0;
}