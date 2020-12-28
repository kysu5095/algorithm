// Maaaaaaaaaze
// 3:20

#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>

using namespace std;

int res = INT_MAX;
int map[5][5][5] = { { {0,},}, };
int arr[5][5][5] = { { {0,},}, };
int sequence[5] = { -1, };
bool visited[5][5][5] = { { {false,},}, };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

void rotate(int idx) {
	int tmp[5][5] = { {0,}, };
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			tmp[i][j] = arr[idx][i][j];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			arr[idx][i][j] = tmp[4 - j][i];
}

void bfs() {
	memset(visited, false, sizeof(visited));
	queue < pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(0, 0)));
	visited[0][0][0] = true;
	int z, y, x, nz, ny, nx, len, t = 0;
	while (!q.empty()) {
		t++;
		if(t >= res) return;
		len = q.size();
		while (len--) {
			z = q.front().first;
			y = q.front().second.first;
			x = q.front().second.second;
			q.pop();
			for (int i = 0; i < 6; i++) {
				nz = z + dz[i];
				ny = y + dy[i];
				nx = x + dx[i];
				if (nz < 0 || nz > 4 || ny < 0 || ny > 4 || nx < 0 || nx > 4) continue;
				if (visited[nz][ny][nx] || !arr[nz][ny][nx]) continue;
				if (nz == 4 && ny == 4 && nx == 4) {
					res = res > t ? t : res;
					return;
				}
				q.push(make_pair(nz, make_pair(ny, nx)));
				visited[nz][ny][nx] = true;
			}
		}
	}
}

void create_map() {
	for (int i = 0; i < 4; i++) {
		rotate(0);
		if (!arr[0][0][0]) continue;
		for (int j = 0; j < 4; j++) {
			rotate(1);
			for (int k = 0; k < 4; k++) {
				rotate(2);
				for (int n = 0; n < 4; n++) {
					rotate(3);
					for (int m = 0; m < 4; m++) {
						rotate(4);
						if (!arr[4][4][4])continue;
						bfs();
					}
				}
			}
		}
	}
}

void build_map(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)
					arr[i][j][k] = map[sequence[i]][j][k];
		create_map();
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (sequence[i] == -1) {
			sequence[i] = cnt;
			build_map(cnt + 1);
			sequence[i] = -1;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> map[i][j][k];
	for (int i = 0; i < 5; i++)
		sequence[i] = -1;
	build_map(0);
	if (res == INT_MAX) res = -1;
	cout << res << '\n';
	return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <limits.h>
// #include <queue>
// #include <tuple>
// #include <string.h>

// using namespace std;

// int res = INT_MAX;
// int arr[5][5][5], tmp[5][5][5];
// bool visited[5][5][5];
// int dy[6] = { 0, 0, 1, -1, 0, 0 };
// int dx[6] = { 1, -1, 0, 0, 0, 0 };
// int dz[6] = { 0, 0, 0, 0, 1, -1 };
// int sequence[5] = { -1, -1, -1, -1, -1}, rotate_map[5];

// void copy_arr(bool flag) {
// 	for (int i = 0; i < 5; i++) {
// 		for (int j = 0; j < 5; j++) {
// 			for (int k = 0; k < 5; k++) {
// 				if (flag) tmp[i][j][k] = arr[i][j][k];
// 				else arr[i][j][k] = tmp[i][j][k];
// 			}
// 		}
// 	}
// }

// void make_arr() {
// 	for (int i = 0; i < 5; i++)
// 		for (int j = 0; j < 5; j++)
// 			for (int k = 0; k < 5; k++)
// 				arr[i][j][k] = tmp[sequence[i]][j][k];
// }

// void rotate_arr() {
// 	int cnt;
// 	for (int i = 0; i < 5; i++) {
// 		cnt = rotate_map[i];
// 		for (int j = 0; j < cnt; j++) {
// 			int arr2[5][5];
// 			for (int n = 0; n < 5; n++)
// 				for (int m = 0; m < 5; m++)
// 					arr2[n][m] = arr[i][n][m];
// 			for (int n = 0; n < 5; n++)
// 				for (int m = 0; m < 5; m++)
// 					arr[i][n][m] = arr2[4 - m][n];

// 		}
// 	}
// }

// int bfs() {
// 	memset(visited, false, sizeof(visited));
// 	queue<tuple<int, int, int>> q;
// 	q.push(make_tuple(0, 0, 0));
// 	visited[0][0][0] = true;
// 	int y, x, z, ny, nx, nz, len, cnt = 0;
// 	while (!q.empty()) {
// 		cnt++;
// 		if (cnt > res) return -1;
// 		len = q.size();
// 		while (len--) {
// 			y = get<0>(q.front());
// 			x = get<1>(q.front());
// 			z = get<2>(q.front());
// 			q.pop();
// 			for (int i = 0; i < 6; i++) {
// 				ny = y + dy[i];
// 				nx = x + dx[i];
// 				nz = z + dz[i];
// 				if (ny < 0 || ny == 5 || nx < 0 || nx == 5 || nz < 0 || nz == 5) continue;
// 				if (ny == 4 && nx == 4 && nz == 4) return cnt;
// 				if (visited[ny][nx][nz] || !arr[ny][nx][nz]) continue;
// 				q.push(make_tuple(ny, nx, nz));
// 				visited[ny][nx][nz] = true;
// 			}
// 		}
// 	}
// 	return -1;
// }

// void rotate_sequence(int cnt) {
// 	if (cnt == 5) {
// 		copy_arr(true);
// 		make_arr();
// 		rotate_arr();
// 		if (arr[0][0][0] && arr[4][4][4]) {
// 			int ret = bfs();
// 			if (ret == -1) ret = INT_MAX;
// 			res = min(res, ret);
// 		}
// 		copy_arr(false);
// 		return;
// 	}
// 	for (int i = 0; i < 4; i++) {
// 		rotate_map[cnt] = i;
// 		rotate_sequence(cnt + 1);
// 	}
// }

// void board_sequence(int cnt) {
// 	if (cnt == 5) {
// 		rotate_sequence(0);
// 		return;
// 	}
// 	for (int i = 0; i < 5; i++) {
// 		if (sequence[i] == -1) {
// 			sequence[i] = cnt;
// 			board_sequence(cnt + 1);
// 			sequence[i] = -1;
// 		}
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	for (int i = 0; i < 5; i++)
// 		for (int j = 0; j < 5; j++)
// 			for (int k = 0; k < 5; k++)
// 				cin >> arr[i][j][k];
// 	board_sequence(0);
// 	if (res == INT_MAX) res = -1;
// 	cout << res << '\n';
// 	return 0;
// }