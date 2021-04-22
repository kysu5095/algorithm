// 소코반

#include <stdio.h>
#include <string.h>

int r, c, box;
char arr[17][17];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
char command[52];

int get_direction(char ch) {
	if (ch == 'R') return 0;
	else if (ch == 'L') return 1;
	else if (ch == 'D') return 2;
	else return 3;
}

bool game(int y, int x) {
	for (int ch = 0; ch < strlen(command); ch++) {
		int d = get_direction(command[ch]);
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (arr[ny][nx] == '#') continue;
		else if (arr[ny][nx] == '.') {
			if (arr[y][x] == 'W') arr[y][x] = '+';
			else arr[y][x] = '.';
			arr[ny][nx] = 'w';
		}
		else if (arr[ny][nx] == '+') {
			if (arr[y][x] == 'W') arr[y][x] = '+';
			else arr[y][x] = '.';
			arr[ny][nx] == 'W';
		}
		else if (arr[ny][nx] == 'b' || arr[ny][nx] == 'B') {
			int nny = ny + dy[d];
			int nnx = nx + dx[d];
			if (arr[nny][nnx] == '#' || arr[nny][nnx] == 'b' || arr[nny][nnx] == 'B') continue;
			
			if (arr[y][x] == 'W') arr[y][x] = '+';
			else arr[y][x] = '.';

			if (arr[nny][nnx] == '+') arr[nny][nnx] = 'B';
			else arr[nny][nnx] = 'b';

			if (arr[ny][nx] == 'B') arr[ny][nx] = 'W';
			else arr[ny][nx] = 'w';

			if (arr[ny][nx] == 'W' && arr[nny][nnx] == 'b') box++;
			else if (arr[ny][nx] == 'w' && arr[nny][nnx] == 'B') box--;
		}
		y = ny;
		x = nx;
		if (box == 0) return true;
	}
	return false;
}

int main() {
	int cnt = 1;
	while (true) {
		int y, x;
		scanf(" %d %d", &r, &c);
		if (!r && !c) break;
		box = 0;
		for (int i = 0; i < r; i++) {
			scanf("%s", arr[i]);
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == 'w' || arr[i][j] == 'W') y = i, x = j;
				else if (arr[i][j] == 'b') box++;
			}
		}
		scanf("%s", command);
		printf("Game %d: ", cnt);
		if (game(y, x)) printf("complete\n");
		else printf("incomplete\n");
		for (int i = 0; i < r; i++) printf("%s\n", arr[i]);
		cnt++;
	}
	return 0;
}