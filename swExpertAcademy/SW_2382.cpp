// 복습 - 미생물 격리
// 10:00

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int test_case, n, m, k, res;
int arr[105][105];

class Point {
public:
	int y, x, s, d;
};
Point p[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<Point> warm;

bool desc(Point p1, Point p2) {
	return p1.s > p2.s;
}

void move() {
	int y, x, s, d, len;
	while (m--) {
		memset(arr, 0, sizeof(arr));
		sort(warm.begin(), warm.end(), desc);
		len = warm.size();
		for (int i = 0; i < len; i++) {
			y = warm[i].y;
			x = warm[i].x;
			s = warm[i].s;
			d = warm[i].d;
			if (!s) {
				warm.erase(warm.begin() + i, warm.end());
				break;
			}
			y += p[d].y;
			x += p[d].x;
			warm[i].y = y;
			warm[i].x = x;
			if (y == 0 || y == n - 1 || x == 0 || x == n - 1) {
				s >>= 1;
				warm[i].s = s;
				if (s) {
					if (d & 1) warm[i].d -= 1;
					else warm[i].d += 1;
				}
				continue;
			}
			if (arr[y][x]) {
				warm[arr[y][x] - 1].s += s;
				warm[i].s = 0;
			}
			else 
				arr[y][x] = i + 1;
		}
	}
	len = warm.size();
	for (int i = 0; i < len; i++) 
		res += warm[i].s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);
	int y, x, s, d;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		warm.clear();
		res = 0;
		memset(arr, 0, sizeof(arr));
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			cin >> y >> x >> s >> d;
			warm.push_back({ y, x, s, d - 1 });
		}
		move();
		cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <vector>
// #include <limits.h>
// #include <algorithm>
// #include <string.h>

// using namespace std;

// int n, m, k;
// int arr[101][101];
// int dy[5] = { 0, -1, 1, 0, 0 };
// int dx[5] = { 0, 0, 0, -1, 1 };

// class Point {
// public:
// 	int y, x, sz, d;
// 	bool alive;
// };
// vector<Point> v;

// int game() {
// 	int y, x, ny, nx, sz, d, len = v.size();
// 	while (m--) {
// 		memset(arr, 0, sizeof(arr));
// 		for (int i = 0; i < len; i++) {
// 			if (!v[i].alive) continue;
// 			y = v[i].y; x = v[i].x;
// 			sz = v[i].sz; d = v[i].d;
// 			ny = y + dy[d]; nx = x + dx[d];
// 			if (ny == 0 || ny == n - 1 || nx == 0 || nx == n - 1) {
// 				sz >>= 1;
// 				if (sz == 0) {
// 					v[i].alive = false;
// 					continue;
// 				}
// 				if (d % 2 == 0) d--;
// 				else d++;
// 			}
// 			arr[ny][nx] += i;
// 			v[i].y = ny; v[i].x = nx;
// 			v[i].sz = sz; v[i].d = d;
// 			/*else if (arr[ny][nx] >= 0) {
// 				if (sz > v[arr[ny][nx]].sz) {
// 					v[arr[ny][nx]].alive = false;
// 					sz += v[arr[ny][nx]].sz;
// 					arr[ny][nx] = i;
// 				}
// 				else {
// 					v[i].alive = false;
// 					v[arr[ny][nx]].sz += sz;
// 				}
// 			}
// 			else arr[ny][nx] += i;*/
// 		}
// 		for (int i = 0; i < len; i++) {
// 			if (!v[i].alive) continue;
// 			y = v[i].y;
// 			x = v[i].x;
// 			sz = v[i].sz;
// 			if (arr[y][x] == i) continue;
// 			int total = sz;
// 			vector<pair<int, int>> tmp;
// 			tmp.push_back(make_pair(-sz, i));
// 			for (int j = 0; j < len; j++) {
// 				if (i == j) continue;
// 				if (!v[j].alive) continue;
// 				ny = v[j].y;
// 				nx = v[j].x;
// 				sz = v[j].sz;
// 				if (y == ny && x == nx) {
// 					tmp.push_back(make_pair(-sz, j));
// 					total += sz;
// 				}
// 			}
// 			sort(tmp.begin(), tmp.end());
// 			v[tmp[0].second].sz = total;
// 			for (int j = 1; j < (int)tmp.size(); j++)
// 				v[tmp[j].second].alive = false;
// 		}
// 	}
// 	int val = 0;
// 	for (int i = 0; i < len; i++)
// 		if (v[i].alive) val += v[i].sz;
// 	return val;
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	//freopen("sample_input.txt", "r", stdin);
// 	int test_case, y, x, sz, d;
// 	cin >> test_case;
// 	for (int tc = 1; tc <= test_case; tc++) {
// 		v.clear();
// 		cin >> n >> m >> k;
// 		for (int i = 0; i < k; i++) {
// 			cin >> y >> x >> sz >> d;
// 			v.push_back({ y, x, sz, d, true });
// 		}
// 		cout << "#" << tc << " " << game() << '\n';
// 	}
// 	return 0;
// }