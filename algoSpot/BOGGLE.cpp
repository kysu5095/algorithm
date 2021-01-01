// 보글 게임

#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

int test_case, n;
char arr[5][5];
bool visit[11][5][5];
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
string str;

bool dynamic_programing(int y, int x, int idx) {
	if (idx == str.length() - 1) return true;
	visit[idx][y][x] = true;

	int ny, nx;
	for (int i = 0; i < 8; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny == 5 || nx < 0 || nx == 5 || visit[idx + 1][ny][nx]) continue;
		if (arr[ny][nx] != str[idx + 1]) continue;
		if (dynamic_programing(ny, nx, idx + 1)) return true;
	}
	return false;
}

void find_word() {
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == str[0] && dynamic_programing(i, j, 0)) {
				cout << str << " YES\n";
				return;
			}
		}
	}
	cout << str << " NO\n";
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> test_case;
	while (test_case--) {
		for (int i = 0; i < 5; i++)
			cin >> arr[i];
		cin >> n;
		for (int i = 0; i < n; i++) {
			str.clear();
			cin >> str;
			find_word();
		}
	}
	return 0;
}