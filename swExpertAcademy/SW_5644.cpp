// 복습 - 무선충전
// 6:10

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

int test_case, m, a, res;
int arr[10][10];
int move_a[101];
int move_b[101];
bool visited_a[9];
bool visited_b[9];

class Point {
public:
	int y, x, c, p;
};
Point p[5] = { {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector<Point> bc;

void move() {
	int ay = 0, ax = 0;
	int by = 9, bx = 9;
	int tmp, tmp2;
	int cnt = 0;
	while (cnt != m + 1) {
		memset(visited_a, false, sizeof(visited_a));
		memset(visited_b, false, sizeof(visited_b));
		for (int i = 0; i < a; i++) {
			if (abs(ay - bc[i].y) + abs(ax - bc[i].x) <= bc[i].c) visited_a[i] = true;
			if (abs(by - bc[i].y) + abs(bx - bc[i].x) <= bc[i].c) visited_b[i] = true;
		}
		tmp = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				if (visited_a[i] || visited_b[j]) {
					tmp2 = 0;
					if (i == j) tmp2 += bc[i].p;
					else {
						if (visited_a[i]) tmp2 += bc[i].p;
						if (visited_b[j]) tmp2 += bc[j].p;
					}
					tmp = tmp < tmp2 ? tmp2 : tmp;
				}
			}
		}
		res += tmp;
		ay += p[move_a[cnt]].y, ax += p[move_a[cnt]].x;
		by += p[move_b[cnt]].y, bx += p[move_b[cnt++]].x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);
	int y, x, c, pp;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		bc.clear();
		cin >> m >> a;
		for (int i = 0; i < m; i++)
			cin >> move_a[i];
		for (int i = 0; i < m; i++)
			cin >> move_b[i];
		for (int i = 0; i < a; i++) {
			cin >> x >> y >> c >> pp;
			bc.push_back({ y - 1, x - 1, c , pp });
		}
		move();
		cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <vector>
// #include <string.h>
// #include <math.h>
// #include <algorithm>

// using namespace std;

// int m, a;
// int route[2][101];
// bool visited[2][8];
// int dy[5] = { 0, -1, 0, 1, 0 };
// int dx[5] = { 0, 0, 1, 0, -1 };
// vector<pair<pair<int, int>, pair<int, int>>> v;

// int game() {
// 	int y1 = 0, x1 = 0;
// 	int y2 = 9, x2 = 9;
// 	int sec = 0, ret = 0;
// 	int dist1, dist2;
// 	while (sec <= m) {
// 		memset(visited, false, sizeof(visited));
// 		for (int i = 0; i < a; i++) {
// 			dist1 = abs(y1 - v[i].first.first) + abs(x1 - v[i].first.second);
// 			dist2 = abs(y2 - v[i].first.first) + abs(x2 - v[i].first.second);
// 			if (dist1 <= v[i].second.first) visited[0][i] = true;
// 			if (dist2 <= v[i].second.first) visited[1][i] = true;
// 		}
// 		int tmp = 0;
// 		for (int i = 0; i < a; i++) {
// 			for (int j = 0; j < a; j++) {
// 				int tmp2 = 0;
// 				if (visited[0][i] || visited[1][j]) {
// 					if (i == j) tmp2 = v[i].second.second;
// 					else {
// 						if (visited[0][i]) tmp2 += v[i].second.second;
// 						if (visited[1][j]) tmp2 += v[j].second.second;
// 					}
// 				}
// 				tmp = max(tmp, tmp2);
// 			}
// 		}
// 		y1 += dy[route[0][sec]]; x1 += dx[route[0][sec]];
// 		y2 += dy[route[1][sec]]; x2 += dx[route[1][sec]];
// 		ret += tmp;
// 		sec++;
// 	}
// 	return ret;
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	//freopen("sample_input.txt", "r", stdin);
// 	int test_case, y, x, c, p;
// 	cin >> test_case;
// 	for (int tc = 1; tc <= test_case; tc++) {
// 		v.clear();
// 		cin >> m >> a;
// 		for (int i = 0; i < 2; i++)
// 			for (int j = 0; j < m; j++)
// 				cin >> route[i][j];
// 		for (int i = 0; i < a; i++) {
// 			cin >> x >> y >> c >> p;
// 			v.push_back(make_pair(make_pair(y - 1, x - 1), make_pair(c, p)));
// 		}
// 		cout << "#" << tc << " " << game() << '\n';
// 	}
// 	return 0;
// }