// 청소년 상어

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int res = 0;
int arr[4][4];
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
pair<int, pair<int, int>> fish[17];

void copy_arr(int tmp[][4], int flag) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (flag) tmp[i][j] = arr[i][j];
			else arr[i][j] = tmp[i][j];
		}
	}
}

void copy_fish(pair<int, pair<int, int>> tmp_fish[17], int flag) {
	for (int i = 1; i <= 16; i++) {
		if (flag) {
			tmp_fish[i].first = fish[i].first;
			tmp_fish[i].second.first = fish[i].second.first;
			tmp_fish[i].second.second = fish[i].second.second;
		}
		else {
			fish[i].first = tmp_fish[i].first;
			fish[i].second.first = tmp_fish[i].second.first;
			fish[i].second.second = tmp_fish[i].second.second;
		}
	}
}

void dfs(int sy, int sx, int sd, int _sum, int cnt) {
	res = max(res, _sum);
	int y, x, d, ny, nx;
	/* move fish */
	for (int idx = 1; idx <= 16; idx++) {
		if (fish[idx].first == -1) continue;
		y = fish[idx].second.first;
		x = fish[idx].second.second;
		d = fish[idx].first;
		for (int i = 0; i < 8; i++) {
			ny = y + dy[(d + i) % 8];
			nx = x + dx[(d + i) % 8];
			if (ny < 0 || ny == 4 || nx < 0 || nx == 4 || !arr[ny][nx]) continue;
			if (arr[ny][nx] == -1) {
				arr[y][x]   = -1;
			}
			else {
				int next_num = arr[ny][nx];
				fish[next_num].second.first  = y;
				fish[next_num].second.second = x;
				arr[y][x] = next_num;
			}
			arr[ny][nx] = idx;
			fish[idx].second.first = ny;
			fish[idx].second.second = nx;
			fish[idx].first = (d + i) % 8;
			break;
		}
	}
	/* copy map */
	int tmp[4][4];
	copy_arr(tmp, 1);
	/* copy fish */
	pair<int, pair<int, int>> tmp_fish[17];
	copy_fish(tmp_fish, 1);

	/* move shark */
	y = sy;
	x = sx;
	for (int idx = 1; idx <= 3; idx++) {
		ny = y + (dy[sd] * idx);
		nx = x + (dx[sd] * idx);
		if (ny < 0 || ny == 4 || nx < 0 || nx == 4) break;
		if (arr[ny][nx] == -1) continue;
		int next_num = arr[ny][nx];
		int next_d   = fish[next_num].first;
		arr[y][x]   = -1;
		arr[ny][nx] = 0;
		fish[next_num].first = -1;
		dfs(ny, nx, next_d, _sum + next_num, cnt + 1);
		copy_arr(tmp, 0);
		copy_fish(tmp_fish, 0);
	}
	copy_arr(tmp, 0);
	copy_fish(tmp_fish, 0);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int num, direct;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> num >> direct;
			fish[num].first = direct - 1;
			fish[num].second.first = i;
			fish[num].second.second = j;
			arr[i][j] = num;
		}
	}
	int dy = fish[arr[0][0]].first;
	int _sum = arr[0][0];
	fish[arr[0][0]].first = -1;
	arr[0][0] = 0;
	dfs(0, 0, dy, _sum, 0);
	cout << res << '\n';
	return 0;
}

// #include <iostream>
// #include <algorithm>

// using namespace std;

// int res;
// int arr[4][4];
// int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1 };
// int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
// pair<pair<int, bool>, pair<int, int>> fish[17];

// void copy_arr(int tmp[][4], bool flag) {
// 	for (int i = 0; i < 4; i++) {
// 		for (int j = 0; j < 4; j++) {
// 			if (flag) tmp[i][j] = arr[i][j];
// 			else arr[i][j] = tmp[i][j];
// 		}
// 	}
// }

// void copy_fish(pair<pair<int, bool>, pair<int, int>> tmp[17], bool flag) {
// 	for (int i = 1; i <= 16; i++) {
// 		if (flag) tmp[i] = fish[i];
// 		else fish[i] = tmp[i];
// 	}
// }

// void move_fish(int& sy, int& sx) {
// 	int y, x, ny, nx, d, nd;
// 	bool alive;
// 	for (int idx = 1; idx <= 16; idx++) {
// 		y = fish[idx].second.first;
// 		x = fish[idx].second.second;
// 		d = fish[idx].first.first;
// 		alive = fish[idx].first.second;
// 		if (!alive) continue;
// 		for (int i = d; i < d + 9; i++) {
// 			nd = i % 8;
// 			ny = y + dy[nd];
// 			nx = x + dx[nd];
// 			if (ny < 0 || ny == 4 || nx < 0 || nx == 4) continue;
// 			if (ny == sy && nx == sx) continue;
// 			fish[idx].second.first = ny;
// 			fish[idx].second.second = nx;
// 			fish[idx].first.first = nd;
// 			if (arr[ny][nx] == 0) {
// 				arr[y][x] = 0;
// 				arr[ny][nx] = idx;
// 			}
// 			else {
// 				int next = arr[ny][nx];
// 				fish[next].second.first = y;
// 				fish[next].second.second = x;
// 				arr[y][x] = next;
// 				arr[ny][nx] = idx;
// 			}
// 			break;
// 		}
// 	}
// }

// void dfs(int y, int x, int d, int ret) {
// 	move_fish(y, x);
// 	int tmp[4][4];
// 	copy_arr(tmp, true);
// 	pair<pair<int, bool>, pair<int, int>> tmp_fish[17];
// 	copy_fish(tmp_fish, true);
// 	int ny, nx;
// 	for (int i = 1; i <= 3; i++) {
// 		ny = y + (dy[d] * i);
// 		nx = x + (dx[d] * i);
// 		if (ny < 0 || ny == 4 || nx < 0 || nx == 4) break;
// 		if (arr[ny][nx] == 0) continue;
// 		int idx = arr[ny][nx];
// 		int nd = fish[idx].first.first;
// 		arr[ny][nx] = 0;
// 		fish[idx].first.second = false;
// 		dfs(ny, nx, nd, ret + idx);
// 		copy_arr(tmp, false);
// 		copy_fish(tmp_fish, false);
// 	}
// 	res = max(res, ret);
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int a, b, d;
// 	for (int i = 0; i < 4; i++) {
// 		for (int j = 0; j < 4; j++) {
// 			cin >> a >> b;
// 			fish[a].first.first = b - 1;
// 			fish[a].first.second = true;
// 			fish[a].second.first = i;
// 			fish[a].second.second = j;
// 			arr[i][j] = a;
// 		}
// 	}
// 	res = arr[0][0];
// 	d = fish[arr[0][0]].first.first;
// 	fish[arr[0][0]].first.second = false;
// 	arr[0][0] = 0;
// 	dfs(0, 0, d, res);
// 	cout << res << '\n';
// 	return 0;
// }