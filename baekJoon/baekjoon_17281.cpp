// 야구

#include <iostream>
#define INIT 7

using namespace std;

int n, ret = 0;
int arr[51][9], sequence[9];
bool visited[9];

int game() {
	int score = 0;
	int idx = 0;
	for (int inning = 0; inning < n; inning++) {
		int out_count = 0;
		int where_is = 0;
		while (out_count != 3) {
			int hit = arr[inning][sequence[idx]];
			idx = (idx + 1) % 9;
			if (hit == 0) {
				out_count++;
				continue;
			}

			where_is <<= hit;
			where_is |= (1 << (hit - 1));
			for (int i = 3; i <= 6; i++) score += ((where_is >> i) & 1);
			where_is &= INIT;
		}
	}
	return score;
}

void dfs(int cnt) {
	if (cnt == 9) {
		int score = game();
		ret = ret < score ? score : ret;
		return;
	}
	if (cnt == 3) {
		dfs(cnt + 1);
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (!visited[i]) {
			visited[i] = true;
			sequence[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	sequence[3] = 0;
	visited[0] = true;
	dfs(0);
	cout << ret << '\n';
	return 0;
}