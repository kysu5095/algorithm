// 복습 - 홈 방범 서비스
// 2:05 시작 - 35분 정지

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int test_case, n, m, len, res;
int arr[21][21];

class Point {
public:
	int y, x;
};
vector<Point> v;

void protect() {
	int size = 0;
	int cost, tmp;
	while (++size) {
		cost = (size * size) + ((size - 1) * (size - 1));
		if (cost > m * len)
			break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp = 0;
				for (int k = 0; k < len; k++) {
					if (abs(i - v[k].y) + abs(j - v[k].x) <= size - 1)
						tmp++;
				}
				if(cost <= m * tmp)
					res = res < tmp ? tmp : res;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		v.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j])
					v.push_back({ i, j });
			}
		}
		len = v.size();
		protect();
		cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <queue>
// #include <string.h>
// #include <algorithm>

// using namespace std;

// int n, m, res;
// int arr[21][21];
// bool visited[21][21];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };

// int bfs(int y, int x, int k) {
// 	memset(visited, false, sizeof(visited));
// 	int ny, nx, len, cnt = arr[y][x], sec = k - 1;
// 	queue<pair<int, int>> q;
// 	q.push(make_pair(y, x));
// 	visited[y][x] = true;
// 	while (sec--) {
// 		len = q.size();
// 		while (len--) {
// 			y = q.front().first;
// 			x = q.front().second;
// 			q.pop();
// 			for (int i = 0; i < 4; i++) {
// 				ny = y + dy[i];
// 				nx = x + dx[i];
// 				if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx]) continue;
// 				if (arr[ny][nx]) cnt++;
// 				q.push(make_pair(ny, nx));
// 				visited[ny][nx] = true;
// 			}
// 		}
// 	}
// 	if ((k * k) + ((k - 1) * (k - 1)) <= cnt * m) return cnt;
// 	else return 0;
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	//freopen("sample_input.txt", "r", stdin);
// 	int test_case, cnt;
// 	cin >> test_case;
// 	for (int tc = 1; tc <= test_case; tc++) {
// 		res = 0;
// 		cnt = 0;
// 		cin >> n >> m;
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++) {
// 				cin >> arr[i][j];
// 				if (arr[i][j]) cnt++;
// 			}
// 		}
// 		for (int k = 1; k <= n + n; k++) {
// 			if ((k * k) + ((k - 1) * (k - 1)) > m * cnt) break;
// 			for (int i = 0; i < n; i++) {
// 				for (int j = 0; j < n; j++) {
// 					int val = bfs(i, j, k);
// 					res = max(res, val);
// 				}
// 			}
// 		}
// 		cout << "#" << tc << " " << res << '\n';
// 	}
// 	return 0;
// }