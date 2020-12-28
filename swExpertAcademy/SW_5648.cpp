// 원자 소멸 시뮬레이션

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int test_case, n, cnt, res;
int arr[4001][4001];
class Point {
public:
	int y, x, d, k;
};
Point p[4] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };
vector<Point> atom;

void move() {
	int y, x, d, k, len;
	while (cnt) {
		len = (int)atom.size();
		for (int i = 0; i < len; i++) {
			y = atom[i].y;
			x = atom[i].x;
			d = atom[i].d;
			k = atom[i].k;
			//if (k == 0) continue;
			if (k == 0) {
				atom.erase(atom.begin() + i);
				i--;
				len--;
				continue;
			}
			arr[y][x] = 0;

			y += p[d].y;
			x += p[d].x;
			if (x < 0 || x >= 4001 || y < 0 || y >= 4001) {
				atom[i].k = 0;
				cnt--;
				atom.erase(atom.begin() + i);
				i--;
				len--;
				continue;
			}
			atom[i].y = y;
			atom[i].x = x;
			arr[y][x] += k;
		}
		for (int i = 0; i < len; i++) {
			y = atom[i].y;
			x = atom[i].x;
			k = atom[i].k;
			if (k == 0) continue;
			if (arr[y][x] != k) {
				res += arr[y][x];
				arr[y][x] = 0;
				atom[i].k = 0;
				cnt--;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int y, x, d, k;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		cin >> n;
		cnt = 0;
		res = 0;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> d >> k;
			atom.push_back({ (y + 1000) * 2, (x + 1000) * 2, d, k });
			cnt++;
		}
		move();
		cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <vector>
// #include <set>
// #include <string.h>

// using namespace std;

// int n;
// int arr[4001][4001];
// int dy[4] = { 1, -1, 0, 0 };
// int dx[4] = { 0, 0, -1, 1 };

// class Point {
// public:
// 	int y, x, d, k;
// 	bool alive;
// };
// vector<Point> v;

// int game() {
// 	int y, x, ny, nx, d, k, len, cnt = v.size(), ret = 0;
// 	len = v.size();
// 	set<int> s;
// 	while (cnt) {
// 		for (int i = 0; i < len; i++) {
// 			if (!v[i].alive) continue;
// 			y = v[i].y;
// 			x = v[i].x;
// 			d = v[i].d;
// 			k = v[i].k;

// 			ny = y + dy[d];
// 			nx = x + dx[d];
// 			if (ny < 0 || ny > 4000 || nx < 0 || nx > 4000) {
// 				arr[y][x] = -1;
// 				v[i].alive = false;
// 				cnt--;
// 				continue;
// 			}
// 			if (arr[ny][nx] == -1) {
// 				arr[ny][nx] = i;
// 			}
// 			else {
// 				s.insert(arr[ny][nx]);
// 				s.insert(i);
// 			}
// 			v[i].y = ny;
// 			v[i].x = nx;
// 			arr[y][x] = -1;
// 		}
// 		if (!s.empty()) {
// 			cnt -= s.size();
// 			set<int>::iterator iter;
// 			for (iter = s.begin(); iter != s.end(); iter++) {
// 				ret += v[*iter].k;
// 				v[*iter].alive = false;
// 				arr[v[*iter].y][v[*iter].x] = -1;
// 			}
// 			s.clear();
// 		}
// 	}
// 	return ret;
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	//freopen("sample_input.txt", "r", stdin);
// 	int test_case, y, x, d, k;
// 	cin >> test_case;
// 	for (int tc = 1; tc <= test_case; tc++) {
// 		memset(arr, -1, sizeof(arr));
// 		v.clear();
// 		cin >> n;
// 		for (int i = 0; i < n; i++) {
// 			cin >> x >> y >> d >> k;
// 			x = (x + 1000) << 1;
// 			y = (y + 1000) << 1;
// 			arr[y][x] = i;
// 			v.push_back({ y, x, d, k, true });
// 		}
// 		cout << "#" << tc << " " << game() << '\n';
// 	}
// 	return 0;
// }