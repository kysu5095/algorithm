// 낚시왕 //
///////////

#include <iostream>
#include <queue>

using namespace std;

int r, c, m, sum = 0;
int arr[102][102] = { {0, }, };

class Point {
public:
	int y, x, speed, direct, size;

	bool operator < (const Point& p) const {
		if (this->size < p.size) return true;
		else return false;
	}
};
Point p[4] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
deque<Point> dq[102][102];

void turnDirect(int& direct) {
	if (direct == 0) direct = 1;
	else if (direct == 1) direct = 0;
	else if (direct == 2) direct = 3;
	else if (direct == 3) direct = 2;
}

void eatShark(priority_queue<Point> pq[][102]) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!pq[i][j].empty()) {
				dq[i][j].push_back(pq[i][j].top());
				arr[i][j] = 1;
			}
		}
	}
}

void moveShark() {
	priority_queue<Point> pq[102][102];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 1) {
				int x = j;
				int y = i;
				int speed = dq[i][j].back().speed;
				int direct = dq[i][j].back().direct;
				int size = dq[i][j].back().size;
				int tmp = speed;
				if (direct == 0 || direct == 1) tmp %= (2 * (r - 1));
				if (direct == 2 || direct == 3) tmp %= (2 * (c - 1));

				while (tmp > 0) {
					x += p[direct].x;
					y += p[direct].y;
					if (x < 0 || x >= c || y < 0 || y >= r) {
						turnDirect(direct);
						x += (2 * p[direct].x);
						y += (2 * p[direct].y);
					}
					tmp--;
				}
				arr[i][j] = 0;
				dq[i][j].pop_back();
				pq[y][x].push({ y, x, speed, direct, size });
			}
		}
	}
	eatShark(pq);
}

void catchShark(int colum) {
	for (int i = 0; i < r; i++) {
		if (!dq[i][colum].empty()) {
			sum += dq[i][colum].front().size;
			m--;
			arr[i][colum] = 0;
			dq[i][colum].pop_back();
			return;
		}
	}
}

void movePerson() {
	for (int i = 0; i < c; i++) {
		if (m == 0) return;

		catchShark(i);
		moveShark();
	}
}
	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		int sr, sc, s, d, z;
		cin >> sr >> sc >> s >> d >> z;
		dq[sr - 1][sc - 1].push_back({ sr - 1, sc - 1, s, d - 1, z });
		arr[sr - 1][sc - 1] = 1;
	}
	movePerson();
	cout << sum << '\n';

	return 0;
}

// // 낚시왕
// // 11:45

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string.h>

// using namespace std;

// int r, c, m, res;
// int arr[101][101] = { {0, }, };

// class Point {
// public:
// 	int y, x, s, d, z;
// };
// Point p[4] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
// vector<Point> shark;

// bool desc(Point p1, Point p2) {
// 	return p1.z > p2.z;
// }

// void catch_shark(int idx) {
// 	int len = shark.size();
// 	for (int i = 0; i < r; i++) {
// 		if (arr[i][idx]) {
// 			res += arr[i][idx];
// 			for (int j = 0; j < len; j++) {
// 				if (shark[j].y == i && shark[j].x == idx) {
// 					shark.erase(shark.begin() + j);
// 					return;
// 				}
// 			}
// 		}
// 	}
// }

// void move_shark() {
// 	int y, x, s, d, z, len;
// 	memset(arr, 0, sizeof(arr));
// 	sort(shark.begin(), shark.end(), desc);
// 	len = shark.size();
// 	for (int j = 0; j < len; j++) {
// 		y = shark[j].y, x = shark[j].x;
// 		s = shark[j].s, d = shark[j].d; z = shark[j].z;
// 		if (d == 0 || d == 1) s %= ((r - 1) * 2);
// 		else s %= ((c - 1) * 2);
// 		for (int k = 0; k < s; k++) {
// 			y += p[d].y;
// 			x += p[d].x;
// 			if (y < 0) { y = 1, d = 1; }
// 			else if (y == r) { y = r - 2, d = 0; }
// 			else if (x < 0) { x = 1, d = 2; }
// 			else if (x == c) { x = c - 2, d = 3; }
// 		}
// 		if (arr[y][x]) {
// 			shark.erase(shark.begin() + j);
// 			j--;
// 			len--;
// 			continue;
// 		}
// 		arr[y][x] = z;
// 		shark[j].y = y, shark[j].x = x;
// 		shark[j].d = d;
// 	}
// }

// void move() {
// 	for (int i = 0; i < c; i++) {
// 		catch_shark(i);
// 		if (shark.empty()) break;
// 		move_shark();
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	res = 0;
// 	int sr, sc, ss, sd, sz;
// 	cin >> r >> c >> m;
// 	for (int i = 0; i < m; i++) {
// 		cin >> sr >> sc >> ss >> sd >> sz;
// 		shark.push_back({ sr - 1, sc - 1, ss, sd - 1, sz });
// 		arr[sr - 1][sc - 1] = sz;
// 	}
// 	move();
// 	cout << res << '\n';
// 	return 0;
// }

// #include <iostream>
// #include <vector>
// #include <string.h>

// using namespace std;

// int r, c, m, res = 0;
// int arr[101][101], tmp[101][101];
// int dy[5] = { 0, -1, 1, 0, 0 };
// int dx[5] = { 0, 0, 0, 1, -1 };

// class Shark {
// public:
// 	int y, x, s, d, z, idx;
// 	bool live;
// };
// vector<Shark> v;

// void catch_shark(int& x) {
// 	int y = 0;
// 	while (y != r) {
// 		if (arr[y][x] >= 0) {
// 			res += v[arr[y][x]].z;
// 			v[arr[y][x]].live = false;
// 			break;
// 		}
// 		y++;
// 	}
// }

// void move_shark() {
// 	memset(tmp, -1, sizeof(tmp));
// 	int y, x, ny, nx, s, d, z, len = v.size();
// 	for (int idx = 0; idx < len; idx++) {
// 		if (!v[idx].live) continue;
// 		y = v[idx].y; x = v[idx].x;
// 		s = v[idx].s; d = v[idx].d; z = v[idx].z;
// 		if (d <= 2) s %= ((r - 1) << 1);
// 		else s %= ((c - 1) << 1);
// 		while (s--) {
// 			ny = y + dy[d];
// 			nx = x + dx[d];
// 			if (ny < 0 || ny == r || nx < 0 || nx == c) {
// 				if (d % 2 == 0) d--;
// 				else d++;
// 				ny = y + dy[d];
// 				nx = x + dx[d];
// 			}
// 			y = ny;
// 			x = nx;
// 		}
// 		v[idx].y = y; v[idx].x = x; v[idx].d = d;
// 		if (tmp[y][x] == -1) tmp[y][x] = idx;
// 		else {
// 			if (z < v[tmp[y][x]].z) v[idx].live = false;
// 			else {
// 				v[tmp[y][x]].live = false;
// 				tmp[y][x] = idx;
// 			}
// 		}
// 	}
// 	for (int i = 0; i < r; i++)
// 		for (int j = 0; j < c; j++)
// 			arr[i][j] = tmp[i][j];
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	memset(arr, -1, sizeof(arr));
// 	int y, x, s, d, z, idx;
// 	cin >> r >> c >> m;
// 	for (int i = 0; i < m; i++) {
// 		cin >> y >> x >> s >> d >> z;
// 		v.push_back({ y - 1, x - 1, s, d, z, i, true });
// 		arr[y - 1][x - 1] = i;
// 	}
// 	for (int i = 0; i < c; i++) {
// 		catch_shark(i);
// 		move_shark();
// 	}
// 	cout << res << '\n';
// 	return 0;
// }