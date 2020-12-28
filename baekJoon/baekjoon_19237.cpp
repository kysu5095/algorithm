// 어른상어

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
int arr[21][21][2] = { { {0, }, }, };
int tmp[21][21][2];
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };
int shark[401][5][4];

class Point {
public:
	int y, x, sz, d;
};
Point p[401];

int move() {
	queue<Point> q;
	for (int i = 1; i <= m; i++)
		q.push(p[i]);
	int y, x, ny, nx, sz, d, len, cnt = 1;
	bool flag;
	while (true) {
		if (cnt > 1001) return -1;
		len = q.size();
		if (len == 1) return cnt - 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < 2; k++)
					tmp[i][j][k] = arr[i][j][k];
		while (len--) {
			y = q.front().y;
			x = q.front().x;
			sz = q.front().sz;
			d = q.front().d;
			flag = true;
			q.pop();

			for (int i = 0; i < 4; i++) {
				ny = y + dy[shark[sz][d][i]];
				nx = x + dx[shark[sz][d][i]];
				if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
				if (arr[ny][nx][0] == 0 || arr[ny][nx][0] < cnt || arr[ny][nx][0] - k == cnt) {
					y = ny;
					x = nx;
					d = shark[sz][d][i];
					flag = false;
					break;
				}
			}
			if (flag) {
				for (int j = 0; j < 4; j++) {
					ny = y + dy[shark[sz][d][j]];
					nx = x + dx[shark[sz][d][j]];
					if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx][1] != sz) continue;
					y = ny;
					x = nx;
					d = shark[sz][d][j];
					break;
				}
			}
			if (tmp[y][x][0] - k == cnt) continue;
			tmp[y][x][0] = k + cnt;
			tmp[y][x][1] = sz;
			q.push({ y, x, sz, d });
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < 2; k++)
					arr[i][j][k] = tmp[i][j][k];
		cnt++;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int sz, d;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j][0];
			if (arr[i][j][0] != 0) {
				p[arr[i][j][0]] = { i, j, arr[i][j][0] };
				arr[i][j][1] = arr[i][j][0];
				arr[i][j][0] = k;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> d;
		p[i].d = d;
	}
	 
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= 4; j++) 
			for (int k = 0; k < 4; k++) 
				cin >> shark[i][j][k];
	cout << move() << '\n';
	return 0;
}

// #include <iostream>

// using namespace std;

// int n, m, k, res = 0;
// int arr[21][21][2];
// int dy[5] = { 0, -1, 1, 0, 0 };
// int dx[5] = { 0, 0, 0, -1, 1 };
// int shark_d[401][5][4];
// pair<pair<bool, int>, pair<int, int>> shark[401];

// void put_smell(int &sec) {
// 	int y, x;
// 	for (int i = 1; i <= m; i++) {
// 		if (!shark[i].first.first) continue;
// 		y = shark[i].second.first;
// 		x = shark[i].second.second;
// 		arr[y][x][0] = i;
// 		arr[y][x][1] = sec + k;
// 	}
// }

// void move_shark() {
// 	int y, x, ny, nx, d, nd;
// 	bool flag;
// 	int tmp[21][21] = { { 0, }, };
// 	for (int idx = 1; idx <= m; idx++) {
// 		if (!shark[idx].first.first) continue;
// 		y = shark[idx].second.first;
// 		x = shark[idx].second.second;
// 		d = shark[idx].first.second;
// 		flag = false;
// 		for (int i = 0; i < 4; i++) {
// 			ny = y + dy[shark_d[idx][d][i]];
// 			nx = x + dx[shark_d[idx][d][i]];
// 			if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
// 			if (res - arr[ny][nx][1] <= 0) continue;
// 			flag = true;
// 			shark[idx].second.first = ny;
// 			shark[idx].second.second = nx;
// 			shark[idx].first.second = shark_d[idx][d][i];
// 			if (tmp[ny][nx] == 0) {
// 				tmp[ny][nx] = idx;
// 			}
// 			else {
// 				if (idx < tmp[ny][nx]) {
// 					shark[tmp[ny][nx]].first.first = false;
// 					tmp[ny][nx] = idx;
// 				}
// 				else {
// 					shark[idx].first.first = false;
// 				}
// 			}
// 			break;
// 		}
// 		// can't find
// 		if (!flag) {
// 			for (int i = 0; i < 4; i++) {
// 				ny = y + dy[shark_d[idx][d][i]];
// 				nx = x + dx[shark_d[idx][d][i]];
// 				if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
// 				if (arr[ny][nx][0] != idx) continue;
// 				shark[idx].second.first = ny;
// 				shark[idx].second.second = nx;
// 				shark[idx].first.second = shark_d[idx][d][i];
// 				tmp[ny][nx] = idx;
// 				break;
// 			}
// 		}
// 	}
// }

// bool is_alive_alone() {
// 	for (int i = 2; i <= m; i++)
// 		if (shark[i].first.first) return false;
// 	return true;
// }

// void move() {
// 	while (res <= 1000) {
// 		put_smell(res);
// 		res++;
// 		move_shark();
// 		if (is_alive_alone()) break;
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int d;
// 	cin >> n >> m >> k;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> arr[i][j][0];
// 			if (arr[i][j][0]) {
// 				shark[arr[i][j][0]].first.first = true;
// 				shark[arr[i][j][0]].second.first = i;
// 				shark[arr[i][j][0]].second.second = j;
// 			}
// 		}
// 	}
// 	for (int i = 1; i <= m; i++) {
// 		cin >> d;
// 		shark[i].first.second = d;
// 	}
// 	for (int i = 1; i <= m; i++) 
// 		for (int j = 1; j <= 4; j++) 
// 			for (int k = 0; k < 4; k++)
// 				cin >> shark_d[i][j][k];

// 	move();
// 	if (res > 1000) res = -1;
// 	cout << res << '\n';
// 	return 0;
// }