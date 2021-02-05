// 귀농

#include <iostream>
#include <map>

using namespace std;

int n, cnt = 0;
int input[52][52], arr[52][52];

void MAKE_SUM() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = input[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
}

void LEFT_UP(int& y, int& x, map<int, int>& m) {
	for (int i = y; i > 0; i--) {
		for (int j = x; j > 0; j--) {
			int val = arr[y][x] - arr[i - 1][x] - arr[y][j - 1] + arr[i - 1][j - 1];
			m[val]++;
		}
	}
}

void RIGHT_DOWN(int& y, int& x, map<int, int>& m) {
	for (int i = y + 1; i <= n; i++) {
		for (int j = x + 1; j <= n; j++) {
			int val = arr[i][j] - arr[y][j] - arr[i][x] + arr[y][x];
			cnt += m[val];
		}
	}
}

void RIGHT_UP(int& y, int& x, map<int, int>& m) {
	for (int i = y; i > 0; i--) {
		for (int j = x; j <= n; j++) {
			int val = arr[y][j] - arr[i - 1][j] - arr[y][x - 1] + arr[i - 1][x - 1];
			m[val]++;
		}
	}
}

void LEFT_DOWN(int& y, int& x, map<int, int>& m) {
	for (int i = y + 1; i <= n; i++) {
		for (int j = x - 1; j > 0; j--) {
			int val = arr[i][x - 1] - arr[y][x - 1] - arr[i][j - 1] + arr[y][j - 1];
			cnt += m[val];
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> input[i][j];
	MAKE_SUM();
	map<int, int> m;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			LEFT_UP(i, j, m);
			RIGHT_DOWN(i, j, m);
			m.clear();
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 2; j <= n; j++) {
			RIGHT_UP(i, j, m);
			LEFT_DOWN(i, j, m);
			m.clear();
		}
	}
	cout << cnt << '\n';
	return 0;
}