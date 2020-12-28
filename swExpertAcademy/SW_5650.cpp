// 복습 - 핀볼게임
// 2:00

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int test_case, n, res;
int arr[101][101];

class Point {
public:
	int y, x;
};
Point p[4]{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<Point> warm_hole;

int block[6][4] = { {0, 0, 0, 0}, {1, 3, 0, 2}, {1, 2, 3, 0},
			   	    {2, 0, 3, 1}, {3, 0, 1, 2}, {1, 0, 3, 2} };

void put_ball() {
	int by, bx, bd, tmp, len = warm_hole.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!arr[i][j]) {
				for (int k = 0; k < 4; k++) {
					by = i, bx = j, bd = k;
					tmp = 0;
					while (true) {
						by += p[bd].y;
						bx += p[bd].x;
						if (by == i && bx == j) break;
						else if (arr[by][bx] == -1) break;

						if (by < 0 || by >= n || bx < 0 || bx >= n) {
							tmp <<= 1;
							tmp |= 1;
							break;
						}
						else if (arr[by][bx] >= 1 && arr[by][bx] <= 5) {
							bd = block[arr[by][bx]][bd];
							tmp++;
							continue;
						}
						else if (arr[by][bx] >= 6 && arr[by][bx] <= 10) {
							for (int l = 0; l < len; l++) {
								if (arr[by][bx] == arr[warm_hole[l].y][warm_hole[l].x] && (by != warm_hole[l].y || bx != warm_hole[l].x)) {
									by = warm_hole[l].y;
									bx = warm_hole[l].x;
									break;
								}
							}
						}
					}
					res = res < tmp ? tmp : res;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] >= 6 && arr[i][j] <= 10) 
					warm_hole.push_back({ i, j });
			}
		}
		put_ball();
		cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <utility>
// #include <algorithm>
 
// using namespace std;
 
// int n, res;
// int arr[101][101];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };
// int block[6][4] = { {0, 0, 0, 0},
//                     {1, 3, 0, 2},
//                     {1, 2, 3, 0},
//                     {2, 0, 3, 1},
//                     {3, 0, 1, 2},
//                     {1, 0, 3, 2} };
// pair<int, int> warmhole[11][2];
 
// int game(int y, int x, int d) {
//     int sy = y, sx = x;
//     int ny, nx, cnt = 0, next;
//     while (true) {
//         ny = y + dy[d];
//         nx = x + dx[d];
//         if (ny < 0 || ny == n || nx < 0 || nx == n) {
//             cnt <<= 1;
//             cnt |= 1;
//             return cnt;
//         }
//         if ((ny == sy && nx == sx) || arr[ny][nx] == -1) return cnt;
//         next = arr[ny][nx];
//         if (next == 0) {
//             y = ny;
//             x = nx;
//             continue;
//         }
//         else if (next >= 1 && next <= 5) {
//             y = ny;
//             x = nx;
//             d = block[next][d];
//             cnt++;
//             continue;
//         }
//         else {
//             if (ny == warmhole[next][0].first && nx == warmhole[next][0].second) {
//                 y = warmhole[next][1].first;
//                 x = warmhole[next][1].second;
//             }
//             else {
//                 y = warmhole[next][0].first;
//                 x = warmhole[next][0].second;
//             }
//         }
//     }
// }
 
// int main() {
//     cin.sync_with_stdio(0);
//     cin.tie(0);
//     //freopen("sample_input.txt", "r", stdin);
//     int test_case, val;
//     cin >> test_case;
//     for (int tc = 1; tc <= test_case; tc++) {
//         cin >> n;
//         res = 0;
//         int warm_idx[11] = { 0, };
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 cin >> arr[i][j];
//                 if (arr[i][j] >= 6 && arr[i][j] <= 10)
//                     warmhole[arr[i][j]][warm_idx[arr[i][j]]++] = make_pair(i, j);
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (arr[i][j] == 0) {
//                     for (int k = 0; k < 4; k++) {
//                         val = game(i, j, k);
//                         res = max(res, val);
//                     }
//                 }
//             }
//         }
//         cout << "#" << tc << " " << res << '\n';
//     }
//     return 0;
// }