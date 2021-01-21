// 소코반

#include <iostream>
#include <string.h>

using namespace std;

int r, c, rest;
char arr[16][16], copy_arr[16][16];
char command[51];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}

int get_direct(char& d) {
	switch (d) {
	case 'U': return 0;
	case 'D': return 1;
	case 'L': return 2;
	case 'R': return 3;
	}
}

bool game(int y, int x) {
	int ny, nx, d, nny, nnx;
	int len = strlen(command);
	for (int idx = 0; idx < len; idx++) {
		if (!rest) break;
		d = get_direct(command[idx]);
		ny = y + dy[d];
		nx = x + dx[d];
		if (arr[ny][nx] == '#') continue;
		if (arr[ny][nx] == '.' || arr[ny][nx] == '+') {
			if (copy_arr[y][x] == '+') arr[y][x] = '+';
			else arr[y][x] = '.';
			y = ny;
			x = nx;
			if (arr[y][x] == '+') arr[y][x] = 'W';
			else arr[y][x] = 'w';
		}
		else {
			nny = ny + dy[d];
			nnx = nx + dx[d];
			if (arr[nny][nnx] == '#' || arr[nny][nnx] == 'b' || arr[nny][nnx] == 'B') continue;
			if (copy_arr[y][x] == '+') arr[y][x] = '+';
			else arr[y][x] = '.';
			if (arr[nny][nnx] == '+') {
				arr[nny][nnx] = 'B';
				rest--;
			}
			else arr[nny][nnx] = 'b';
			y = ny;
			x = nx;
			if (copy_arr[y][x] == '+') {
				arr[y][x] = 'W';
				rest++;
			}
			else arr[y][x] = 'w';
		}
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (arr[i][j] == '+') 
				return false;

	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int y, x, cnt = 0;
	while (true) {
		cin >> r >> c;
		if (!r && !c) break;
		cnt++;
		rest = 0;
		for (int i = 0; i < r; i++) {
			cin >> arr[i];
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == 'w') {
					y = i;
					x = j;
					copy_arr[i][j] = '.';
				}
				else if (arr[i][j] == 'W') {
					y = i;
					x = j;
					copy_arr[i][j] = '+';
					rest++;
				}
				else if (arr[i][j] == 'B') {
					copy_arr[i][j] = '+';
				}
				else if (arr[i][j] == '+') {
					copy_arr[i][j] = '+';
					rest++;
				}
				else copy_arr[i][j] = arr[i][j];
			}
		}
		cin >> command;
		if (game(y, x)) cout << "Game " << cnt << ": complete\n";
		else cout << "Game " << cnt << ": incomplete\n";
		print();
	}
	return 0;
}