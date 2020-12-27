// 돌 던지기

#include <iostream>

using namespace std;

int r, c, n;
char arr[30001][31];
int top[30001][31];

bool is_left_right(int& y, int& x) {
	if (x - 1 < 0 || arr[y][x - 1] != '.' || arr[y + 1][x - 1] != '.') return false;
	return true;
}

bool is_right_right(int& y, int& x) {
	if (x + 1 == c || arr[y][x + 1] != '.' || arr[y + 1][x + 1] != '.') return false;
	return true;
}

void throw_stone(int x) {
	int y = top[0][x] - 1;
	int exist = y;
	while (true) {
		if (y == r - 1 || arr[y + 1][x] == 'X') break;
		if (arr[y + 1][x] == '.') { y++; break; }
		else {
			if (is_left_right(y, x)) {
				x--;
				y = top[y][x] - 1;
				exist = y;
			}
			else if (is_right_right(y, x)) {
				x++;
				y = top[y][x] - 1;
				exist = y;
			}
			else
				break;
		}
	}
	arr[y][x] = 'O';
	for (int i = y; i >= 0; i--) {
		if (top[i][x] != exist + 1) break;
		top[i][x] = y;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int x;
	cin >> r >> c;
	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++)
			top[i][j] = r - 1;

	for (int i = 0; i < r; i++) {
		cin >> arr[i];
		for (int j = 0; j < c; j++)
			if (arr[i][j] == 'X') 
				for (int k = i; k >= 0; k--)
					top[k][j] = i;
	}
	cin >> n;
	while (n--) {
		cin >> x;
		throw_stone(x - 1);
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

	return 0;
}