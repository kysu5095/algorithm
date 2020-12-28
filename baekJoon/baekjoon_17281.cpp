// 야구
// 3:25

#include <iostream>

using namespace std;

int n, res;
int arr[51][10];
int turn[9] = { 0, };

void game() {
	int score = 0;
	int idx = 0;
	int base, out, grade;

	for (int i = 0; i < n; i++) {
		// 0000 | 0000
		base = 0;
		out = 0;
		while (true) {
			if (out == 3) break;
			grade = arr[i][turn[idx++] - 1];
			if (!grade) out++;
			else {
				base |= 1;
				base <<= grade;
				score += ((base >> 4 & 1) + (base >> 5 & 1) + (base >> 6 & 1) + (base >> 7 & 1));
				base &= 15;
			}
			if (idx == 9) idx = 0;
		}
	}
	res = res < score ? score : res;
}

void dfs(int cnt) {
	if (cnt == 10) {
		game();
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (!turn[i]) {
			turn[i] = cnt;
			dfs(cnt + 1);
			turn[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	res = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	turn[3] = 1;
	dfs(2);
	cout << res << '\n';
	return 0;
}