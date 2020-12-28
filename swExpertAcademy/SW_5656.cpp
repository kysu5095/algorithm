// ball이랑 breakwall 합치기
// arr말고 tmp를 부셔라
// down을 height쓰지 말고 arr로만 내리기

// 마지막것이 가장 효율적

#include <iostream>
#include <deque>

using namespace std;

int test_case, n, w, h, sum = 99999, problem = 1;
int arr[16][13] = { {0, }, };
int height[16] = { 0, };
class Point {
public:
	int y, x, size;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
deque<Point> v;

void down() {
	for (int i = 0; i < w; i++) {
		int cnt = 0;
		for (int j = 0; j < 16; j++)
			height[j] = 0;

		for (int j = h - 1; j >= 0; j--) {
			if (arr[j][i] != 0)
				height[cnt++] = arr[j][i];
		}
		cnt = 0;
		for (int j = h - 1; j >= 0; j--) {
			arr[j][i] = height[cnt++];
		}
	}
}

void breakWall() {
	if (v.empty())
		return;

	int x = v.front().x;
	int y = v.front().y;
	int size = v.front().size;
	v.pop_front();

	int wall = size;
	for (int i = 0; i < wall; i++) {
		for (int j = 0; j < 4; j++) {
			int nx = x + (p[j].x * i);
			int ny = y + (p[j].y * i);

			if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
				if (arr[ny][nx] > 1)
					v.push_back({ ny, nx, arr[ny][nx] });
				arr[ny][nx] = 0;
			}
		}
	}
	if (!v.empty())
		breakWall();
}

void ball(int x) {
	int y = 0;
	while (y < h && arr[y][x] == 0)
		y++;

	if (y == h) return;
	int size = arr[y][x];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 4; j++) {
			int nx = x + (p[j].x * i);
			int ny = y + (p[j].y * i);

			if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
				if (arr[ny][nx] > 1)
					v.push_back({ ny, nx, arr[ny][nx] });
				arr[ny][nx] = 0;
			}
		}
	}

	if (!v.empty())
		breakWall();

	down();
}

void dfs(int cnt, int x) {
	if (cnt == n) {
		int tmpCnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] != 0) tmpCnt++;
			}
		}
		sum = sum > tmpCnt ? tmpCnt : sum;
		return;
	}
	
	for (int i = 0; i < w; i++) {
		if(!v.empty())
			v.clear();
		int tmp[16][13] = { {0, } };
		for (int j = 0; j < 16; j++) {
			for (int k = 0; k < 13; k++) {
				tmp[j][k] = arr[j][k];
			}
		}
		ball(i); // 공 떨구기
		dfs(cnt + 1, i);
		
		for (int j = 0; j < 16; j++) {
			for (int k = 0; k < 13; k++) {
				arr[j][k] = tmp[j][k];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		sum = 99999;
		cin >> n >> w >> h;

		for (int j = 0; j < 16; j++) {
			for (int k = 0; k < 13; k++) {
				arr[j][k] = 0;
			}
		}

		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				cin >> arr[j][k];
			}
		}
		dfs(0, 0);
		cout << "#" << problem++ << " " << sum << '\n';
	}

	return 0;
}

// 복습, 하지만 시간 더 나옴
// // 벽돌 깨기

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <limits.h>
// #include <string.h>
// #include <queue>

// using namespace std;

// int test_case, n, w, h, res;
// int ball_local[4];
// int arr[16][13];
// int copy_map[16][13];

// class Point {
// public:
// 	int y, x;
// };
// Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

// void drop_map() {
// 	int idx, val;
// 	for (int j = 0; j < w; j++) {
// 		idx = h - 1;
// 		for (int i = h - 1; i >= 0; i--) {
// 			if (arr[i][j]) {
// 				val = arr[i][j];
// 				arr[i][j] = 0;
// 				arr[idx--][j] = val;
// 			}
// 		}
// 	}
// }

// void drop_ball() {
// 	queue<Point> q;
// 	int y, x, ny, nx, val, idx = 0;
// 	for (int i = 0; i < h; i++)
// 		for (int j = 0; j < w; j++)
// 			copy_map[i][j] = arr[i][j];

// 	for (int i = 0; i < n; i++) {
// 		idx = 0;
// 		while (idx != h && !arr[0 + idx][ball_local[i]])
// 			idx++;

// 		if (idx == h) continue;
// 		q.push({ idx, ball_local[i] });
// 		while (!q.empty()) {
// 			y = q.front().y;
// 			x = q.front().x;
// 			val = arr[y][x];
// 			arr[y][x] = 0;
// 			for (int j = 0; j < 4; j++) {
// 				ny = y;
// 				nx = x;
// 				for (int k = 1; k < val; k++) {
// 					ny += p[j].y;
// 					nx += p[j].x;
// 					if (ny >= 0 && ny < h && nx >= 0 && nx < w && arr[ny][nx]) {
// 						q.push({ ny, nx });
// 					}
// 				}
// 			}
// 			q.pop();
// 		}
// 		drop_map();
// 	}
// 	int tmp_res = 0;
// 	for (int i = 0; i < h; i++) {
// 		for (int j = 0; j < w; j++) {
// 			if (arr[i][j]) tmp_res++;
// 			arr[i][j] = copy_map[i][j];
// 		}
// 	}
// 	res = res > tmp_res ? tmp_res : res;
// }

// void dfs(int idx) {
// 	if (res == 0) return;
// 	if (idx == n) {
// 		//if (res == 0) return;
// 		drop_ball();
// 		return;
// 	}
// 	for (int i = 0; i < w; i++) {
// 		ball_local[idx] = i;
// 		dfs(idx + 1);
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	//freopen("input.txt", "r", stdin);
// 	cin >> test_case;
// 	for (int tc = 1; tc <= test_case; tc++) {
// 		res = INT_MAX;
// 		memset(arr, 0, sizeof(arr));
// 		memset(arr, 0, sizeof(ball_local));
// 		cin >> n >> w >> h;
// 		for (int i = 0; i < h; i++) {
// 			for (int j = 0; j < w; j++) {
// 				cin >> arr[i][j];
// 			}
// 		}
// 		dfs(0);
// 		cout << "#" << tc << " " << res << '\n';
// 	}
// 	return 0;
// }

// 복습 - 벽돌깨기
// 9:45

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <string.h>
// #include <limits.h>
// #include <queue>

// using namespace std;

// int test_case, n, w, h, ball_cnt, res;
// int arr[16][13];
// int tmp_arr[16][13];
// int ball[4];

// class Point {
// public:
// 	int y, x, val;
// };
// Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

// void falling_map() {
// 	int y, idx, val;
// 	for (int x = 0; x < w; x++) {
// 		y = h - 1;
// 		idx = h - 1;
// 		while (y >= 0) {
// 			if (arr[y][x]) {
// 				val = arr[y][x];
// 				arr[y][x] = 0;
// 				arr[idx--][x] = val;
// 			}
// 			y--;
// 		}
// 	}
// }

// void break_map(int _y, int _x) {
// 	queue<Point> q;
// 	q.push({ _y, _x, arr[_y][_x] });
// 	arr[_y][_x] = 0;
// 	ball_cnt--;
// 	int y, x, ny, nx, val;
// 	while (!q.empty()) {
// 		y = q.front().y;
// 		x = q.front().x;
// 		val = q.front().val;
// 		q.pop();
// 		for (int i = 1; i < val; i++) {
// 			for (int j = 0; j < 4; j++) {
// 				ny = y + (p[j].y * i);
// 				nx = x + (p[j].x * i);
// 				if (ny >= 0 && ny < h && nx >= 0 && nx < w && arr[ny][nx]) {
// 					if (arr[ny][nx] > 1)
// 						q.push({ ny, nx, arr[ny][nx] });
// 					arr[ny][nx] = 0;
// 					ball_cnt--;
// 				}
// 			}
// 		}
// 	}
// 	falling_map();
// }

// void falling_ball() {
// 	int y, x;
// 	int tmp_cnt = ball_cnt;
// 	for (int i = 0; i < n; i++) {
// 		y = 0;
// 		x = ball[i];
// 		while (y != h) {
// 			if (arr[y][x]) {
// 				if (arr[y][x] == 1) {
// 					ball_cnt--;
// 					arr[y][x] = 0;
// 					break;
// 				}
// 				break_map(y, x);
// 				break;
// 			}
// 			y++;
// 		}
// 	}
// 	res = res > ball_cnt ? ball_cnt : res;
// 	ball_cnt = tmp_cnt;
// }

// void copy_arr() {
// 	for (int i = 0; i < h; i++)
// 		for (int j = 0; j < w; j++)
// 			arr[i][j] = tmp_arr[i][j];
// }

// void dfs(int cnt) {
// 	if (!res) return;
// 	if (cnt == n) {
// 		falling_ball();
// 		copy_arr();
// 		return;
// 	}
// 	for (int i = 0; i < w; i++) {
// 		ball[cnt] = i;
// 		dfs(cnt + 1);
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	freopen("sample_input.txt", "r", stdin);
// 	cin >> test_case;
// 	for (int tc = 1; tc <= test_case; tc++) {
// 		res = INT_MAX;
// 		ball_cnt = 0;
// 		memset(arr, 0, sizeof(arr));
// 		memset(tmp_arr, 0, sizeof(tmp_arr));
// 		cin >> n >> w >> h;
// 		for (int i = 0; i < h; i++) {
// 			for (int j = 0; j < w; j++) {
// 				cin >> arr[i][j];
// 				tmp_arr[i][j] = arr[i][j];
// 				if (arr[i][j]) ball_cnt++;
// 			}
// 		}
// 		dfs(0);
// 		cout << "#" << tc << " " << res << '\n';
// 	}
// 	return 0;
// }

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <queue>
// #include <tuple>
// #include <algorithm>
// #include <limits.h>
 
// using namespace std;
 
// int n, w, h, res;
// int arr[16][13];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };
 
// void copy_arr(int tmp[][13], bool flag) {
//     for (int i = 0; i < h; i++) {
//         for (int j = 0; j < w; j++) {
//             if (flag) tmp[i][j] = arr[i][j];
//             else arr[i][j] = tmp[i][j];
//         }
//     }
// }
 
// void down_map() {
//     int y, idx, val;
//     for (int x = 0; x < w; x++) {
//         y = h - 1;
//         idx = h - 1;
//         while (y >= 0) {
//             if (arr[y][x]) {
//                 val = arr[y][x];
//                 arr[y][x] = 0;
//                 arr[idx--][x] = val;
//             }
//             y--;
//         }
//     }
// }
 
// void put_ball(int x) {
//     int y = 0;
//     while (true) {
//         if (y == h) break;
//         if (arr[y][x]) break;
//         y += dy[2];
//     }
//     if (y == h) return;
//     int ny, nx, cnt = arr[y][x] - 1;
//     queue<tuple<int, int, int>> q;
//     q.push(make_tuple(y, x, cnt));
//     arr[y][x] = 0;
//     while (!q.empty()) {
//         y = get<0>(q.front());
//         x = get<1>(q.front());
//         cnt = get<2>(q.front());
//         q.pop();
//         for (int i = 0; i < 4; i++) {
//             ny = y;
//             nx = x;
//             for (int j = 0; j < cnt; j++) {
//                 ny += dy[i];
//                 nx += dx[i];
//                 if (ny < 0 || ny == h || nx < 0 || nx == w) break;
//                 if (arr[ny][nx] == 0) continue;
//                 if (arr[ny][nx] == 1) {
//                     arr[ny][nx] = 0;
//                     continue;
//                 }
//                 q.push(make_tuple(ny, nx, arr[ny][nx] - 1));
//                 arr[ny][nx] = 0;
//             }
//         }
//     }
//     down_map();
// }
 
// void dfs(int cnt, int* sequence) {
//     if (cnt == n) {
//         int tmp[16][13];
//         copy_arr(tmp, true);
//         for (int i = 0; i < n; i++)
//             put_ball(sequence[i]);
//         int comp = 0;
//         for (int i = 0; i < h; i++)
//             for (int j = 0; j < w; j++)
//                 if (arr[i][j])
//                     comp++;
//         res = min(res, comp);
//         copy_arr(tmp, false);
//         return;
//     }
//     for (int i = 0; i < w; i++) {
//         if (sequence[cnt] == -1) {
//             sequence[cnt] = i;
//             dfs(cnt + 1, sequence);
//             sequence[cnt] = -1;
//         }
//     }
// }
 
// int main() {
//     cin.sync_with_stdio(0);
//     cin.tie(0);
//     //freopen("sample_input.txt", "r", stdin);
//     int test_case;
//     cin >> test_case;
//     for (int tc = 1; tc <= test_case; tc++) {
//         cin >> n >> w >> h;
//         for (int i = 0; i < h; i++)
//             for (int j = 0; j < w; j++)
//                 cin >> arr[i][j];
//         res = INT_MAX;
//         int sequence[4] = { -1, -1, -1, -1 };
//         dfs(0, sequence);
//         cout << "#" << tc << " " << res << '\n';
//     }
//     return 0;
// }