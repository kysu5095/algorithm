// NxM 보드 완주하기

#include <iostream>
#include <string.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, m, block, turn;
char arr[31][31];
bool visited[31][31];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void dfs(int y, int x, int d, int turn_cnt, int block_cnt) {
	if (block_cnt == block) {
		turn = min(turn, turn_cnt);
		return;
	}
	int ny = y;
	int nx = x;
	while (true) {
		ny += dy[d];
		nx += dx[d];
		if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx] || arr[ny][nx] == '*') break;
		visited[ny][nx] = true;
		block_cnt++;
	}
	
	ny -= dy[d];
	nx -= dx[d];
	if ((turn_cnt + 1 < turn) && (ny != y || nx != x)) {
		for (int i = 0; i < 4; i++) {
			if (i == d) continue;
			if (d % 2) { if (i == d - 1) continue; }
			else { if (i == d + 1) continue; }
			dfs(ny, nx, i, turn_cnt + 1, block_cnt);
		}
	}

	while (true) {
		if (ny == y && nx == x) break;
		visited[ny][nx] = false;
		block_cnt--;
		ny -= dy[d];
		nx -= dx[d];
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int TC = 1;
	while (cin >> n >> m) {
		block = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			for (int j = 0; j < m; j++)
				if (arr[i][j] == '.') block++;
		}
		memset(visited, false, sizeof(visited));
		turn = INT_MAX;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == '.') {
					for (int k = 0; k < 4; k++) {
						visited[i][j] = true;
						dfs(i, j, k, 0, 1);
						visited[i][j] = false;
					}
				}
			}
		}
		
		if (turn == INT_MAX) turn = -1;
		cout << "Case " << TC << ": " << turn << '\n';
		TC++;
	}
	return 0;
}