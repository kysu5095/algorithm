// Ladder1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int arr[101][101];
int dy[3] = { 0, 0, 1 };
int dx[3] = { -1, 1, 0 };

bool game(int x) {
	int y = 0;
	int ny, nx, d = 2;
	while (y < 100) {
		for (int i = 0; i < 3; i++) {
			if (d == 0 && i == 1) continue;
			if (d == 1 && i == 0) continue;
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == 100 || nx < 0 || nx == 100) continue;
			if (arr[ny][nx]) {
				if (arr[ny][nx] == 2) return true;
				if (ny == 99) return false;
				y = ny;
				x = nx;
				d = i;
				break;
			}
			if (ny == 99) return false;
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int test_case;
	for (int tc = 1; tc <= 10; tc++) {
		cin >> test_case;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> arr[i][j];
		for (int j = 0; j < 100; j++) {
			if (arr[0][j]) {
				if (game(j)) {
					cout << "#" << test_case << " " << j << '\n';
					break;
				}
			}
		}
	}
	return 0;
}