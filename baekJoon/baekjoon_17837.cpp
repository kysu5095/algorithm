// 새로운 게임 2

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, res = 0;
int arr[13][13];

class Point {
public:
	int y, x, d, floor;
};
Point p[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
vector<Point> v;
vector<int> v_arr[13][13];

void move() {
	int y, x, d, ny, nx, floor;
	while (true) {
		res++;
		if (res > 1000) {
			res = -1;
			return;
		}
		for (int i = 0; i < m; i++) {
			d = v[i].d;
			y = v[i].y;
			x = v[i].x;
			ny = y + p[d].y;
			nx = x + p[d].x;
			floor = v[i].floor;
			// 파란색
			if (arr[ny][nx] == 2 || ny < 0 || ny >= n || nx < 0 || nx >= n) {
				if (d % 2 == 0) d += 1;
				else d -= 1;
				v[i].d = d;
				ny = y + p[d].y;
				nx = x + p[d].x;
				if (!(arr[ny][nx] == 2 || ny < 0 || ny >= n || nx < 0 || nx >= n)) {
					// 흰색
					if (arr[ny][nx] == 0) {
						for (int j = floor; j < v_arr[y][x].size(); j++) {
							v[v_arr[y][x][j]].y = ny;
							v[v_arr[y][x][j]].x = nx;
							v[v_arr[y][x][j]].floor = v_arr[ny][nx].size();
							v_arr[ny][nx].push_back(v_arr[y][x][j]);
							v_arr[y][x].erase(v_arr[y][x].begin() + j);
							j--;
						}
					}
					// 빨간색
					else if (arr[ny][nx] == 1) {
						for (int j = v_arr[y][x].size() - 1; j >= floor; j--) {
							v[v_arr[y][x][j]].y = ny;
							v[v_arr[y][x][j]].x = nx;
							v[v_arr[y][x][j]].floor = v_arr[ny][nx].size();
							v_arr[ny][nx].push_back(v_arr[y][x][j]);
							v_arr[y][x].pop_back();
						}
					}
					if (v_arr[ny][nx].size() >= 4) return;
				}
			}
			// 흰색
			else if (arr[ny][nx] == 0) {
				for (int j = floor; j < v_arr[y][x].size(); j++) {
					v[v_arr[y][x][j]].y = ny;
					v[v_arr[y][x][j]].x = nx;
					v[v_arr[y][x][j]].floor = v_arr[ny][nx].size();
					v_arr[ny][nx].push_back(v_arr[y][x][j]);
					v_arr[y][x].erase(v_arr[y][x].begin() + j);
					j--;
				}
				if (v_arr[ny][nx].size() >= 4) return;
			}
			// 빨간색
			else if (arr[ny][nx] == 1) {
				for (int j = v_arr[y][x].size() - 1; j >= floor; j--) {
					v[v_arr[y][x][j]].y = ny;
					v[v_arr[y][x][j]].x = nx;
					v[v_arr[y][x][j]].floor = v_arr[ny][nx].size();
					v_arr[ny][nx].push_back(v_arr[y][x][j]);
					v_arr[y][x].pop_back();
				}
				if (v_arr[ny][nx].size() >= 4) return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int y, x, d;
	int idx = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < m; i++) {
		cin >> y >> x >> d;
		v.push_back({ y - 1, x - 1, d - 1, 0 });
		v_arr[y - 1][x - 1].push_back(i);
	}
	move();
	cout << res << '\n';
	return 0;
}

// #include <iostream>
// #include <deque>
// #include <vector>
// using namespace std;

// int n, k;
// int arr[13][13];
// int dy[5] = { 0, 0, 0, -1, 1 };
// int dx[5] = { 0, 1, -1, 0, 0 };
// deque<int> dq[13][13];
// pair<int, pair<int, int>> horse[11];

// int get_index(int& y, int& x, int& idx) {
// 	int len = dq[y][x].size();
// 	for (int i = 0; i < len; i++) {
// 		if (dq[y][x][i] == idx) return i;
// 	}
// 	return -1;
// }

// void move_white(int& y, int& x, int& ny, int& nx, int& num) {
// 	int idx, j = get_index(y, x, num);
// 	int len = dq[y][x].size();
// 	for (int i = j; i < len; i++) {
// 		idx = dq[y][x][i];
// 		horse[idx].first = ny;
// 		horse[idx].second.first = nx;
// 		dq[ny][nx].push_back(idx);
// 	}
// 	for (int i = j; i < len; i++)
// 		dq[y][x].pop_back();
// }

// void move_red(int& y, int& x, int& ny, int& nx, int& num) {
// 	int idx, j = get_index(y, x, num);
// 	int len = dq[y][x].size();
// 	for (int i = len - 1; i >= j; i--) {
// 		idx = dq[y][x][i];
// 		horse[idx].first = ny;
// 		horse[idx].second.first = nx;
// 		dq[ny][nx].push_back(idx);
// 	}
// 	for (int i = len - 1; i >= j; i--)
// 		dq[y][x].pop_back();
// }

// bool game() {
// 	int y, x, ny, nx, d;
// 	for (int i = 0; i < k; i++) {
// 		y = horse[i].first;
// 		x = horse[i].second.first;
// 		d = horse[i].second.second;
// 		ny = y + dy[d];
// 		nx = x + dx[d];
// 		if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx] == 2) {
// 			if (d % 2 == 0) d--;
// 			else d++;
// 			ny = y + dy[d];
// 			nx = x + dx[d];
// 			horse[i].second.second = d;
// 			if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx] == 2) continue;
// 			else if (arr[ny][nx] == 0) move_white(y, x, ny, nx, i);
// 			else move_red(y, x, ny, nx, i);
// 		}
// 		else if (arr[ny][nx] == 0) move_white(y, x, ny, nx, i);
// 		else move_red(y, x, ny, nx, i);
// 		if (dq[ny][nx].size() >= 4) return true;
// 	}
// 	return false;
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int y, x, d;
// 	cin >> n >> k;
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < n; j++)
// 			cin >> arr[i][j];
// 	for (int i = 0; i < k; i++) {
// 		cin >> y >> x >> d;
// 		horse[i].first = y - 1;
// 		horse[i].second.first = x - 1;
// 		horse[i].second.second = d;
// 		dq[y - 1][x - 1].push_back(i);
// 	}
// 	int sec = 0;
// 	while (sec <= 1000) {
// 		sec++;
// 		if (game()) break;
// 	}
// 	if (sec > 1000) sec = -1;
// 	cout << sec << '\n';
// 	return 0;
// }

// #include <iostream>
// #include <deque>

// using namespace std;

// int n, k;
// bool flag = false;
// int dy[5] = { 0, 0, 0, -1, 1 };
// int dx[5] = { 0, 1, -1, 0, 0 };
// int map[13][13];
// deque<int> arr[13][13];
// deque<pair<int, pair<int, int>>> dq;

// int get_step(int& y, int& x, int& idx) {
// 	for (int i = 0; i < arr[y][x].size(); i++)
// 		if (arr[y][x][i] == idx)
// 			return i;
// }

// void go_white(int& y, int& x, int& ny, int& nx, int& idx) {
// 	int step = get_step(y, x, idx);
// 	for (int i = step; i < arr[y][x].size(); i++) {
// 		arr[ny][nx].push_back(arr[y][x][i]);
// 		dq[arr[y][x][i]].second.first = ny;
// 		dq[arr[y][x][i]].second.second = nx;
// 	}
// 	arr[y][x].erase(arr[y][x].begin() + step, arr[y][x].end());
// 	if (arr[ny][nx].size() >= 4) flag = true;
// }

// void go_red(int& y, int& x, int& ny, int& nx, int& idx) {
// 	int step = get_step(y, x, idx);
// 	for (int i = arr[y][x].size() - 1; i >= step; i--) {
// 		arr[ny][nx].push_back(arr[y][x][i]);
// 		dq[arr[y][x][i]].second.first = ny;
// 		dq[arr[y][x][i]].second.second = nx;
// 	}
// 	arr[y][x].erase(arr[y][x].begin() + step, arr[y][x].end());
// 	if (arr[ny][nx].size() >= 4) flag = true;
// }

// void go_blue(int& y, int& x, int& ny, int& nx, int& idx) {
// 	if (ny < 0 || ny == n || nx < 0 || nx == n || map[ny][nx] == 2) return;
// 	if (map[ny][nx] == 0) go_white(y, x, ny, nx, idx);
// 	else go_red(y, x, ny, nx, idx);
// }

// bool move_horse() {
// 	int y, x, ny, nx, d;
// 	for (int idx = 0; idx < k; idx++) {
// 		y = dq[idx].second.first;
// 		x = dq[idx].second.second;
// 		d = dq[idx].first;
// 		ny = y + dy[d];
// 		nx = x + dx[d];
// 		if (ny < 0 || ny == n || nx < 0 || nx == n || map[ny][nx] == 2) {
// 			if (d % 2 == 0) d--;
// 			else d++;
// 			dq[idx].first = d;
// 			ny = y + dy[d];
// 			nx = x + dx[d];
// 			go_blue(y, x, ny, nx, idx);
// 		}
// 		else if (map[ny][nx] == 0) go_white(y, x, ny, nx, idx);
// 		else go_red(y, x, ny, nx, idx);
// 		if (flag) return true;
// 	}
// 	return false;
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int y, x, d;
// 	cin >> n >> k;
// 	for (int i = 0; i < n; i++) 
// 		for (int j = 0; j < n; j++) 
// 			cin >> map[i][j];
// 	for (int i = 0; i < k; i++) {
// 		cin >> y >> x >> d;
// 		dq.push_back(make_pair(d, make_pair(y - 1, x - 1)));
// 		arr[y - 1][x - 1].push_back(i);
// 	}
// 	int t = 1;
// 	while (t <= 1000) {
// 		if (move_horse()) break;
// 		t++;
// 	}
// 	if (t == 1001) t = -1;
// 	cout << t << '\n';
// 	return 0;
// }