// 체스판 여행 2

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, sy, sx;
int arr[10][10];
bool visited[3][102][11][11] = { {{{false,},},}, };
int dy[3][8] = { {-2, -2, 2, 2, -1, -1, 1, 1},
				 {-1, -1, 1, 1}, {0, 0, 1, -1} };
int dx[3][8] = { {-1, 1, -1, 1, -2, 2, -2, 2},
				 {-1, 1, -1, 1}, {1, -1, 0, 0} };
vector<int> v;

void bfs() {
	/* 변경횟수, 현재 말, 찾는 말 번호, 좌표 */
	queue<pair<pair<int, int>, pair<int, pair<int, int>>>> q;
	queue<pair<pair<int, int>, pair<int, int>>> tmp;
	for (int i = 0; i < 3; i++) {
		// 시작점에 모든 말(나이트,비숍,룩) 놓기
		q.push(make_pair(make_pair(0, i), make_pair(2, make_pair(sy, sx))));
		visited[i][2][sy][sx] = true;
	}
	int y, x, ny, nx, change, horse, target, idx, len, cnt = 1;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().second.second.first;
			x = q.front().second.second.second;
			change = q.front().first.first;
			horse = q.front().first.second;
			target = q.front().second.first;
			tmp.push(make_pair(make_pair(change, target), make_pair(y, x)));
			q.pop();
			if (horse == 0) idx = 8;
			else idx = 4;

			// 이동
			for (int i = 0; i < idx; i++) {
				ny = y + dy[horse][i];
				nx = x + dx[horse][i];
				while (true) {
					if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
					if (arr[ny][nx] == target) {
						if (arr[ny][nx] == n * n) v.push_back(change);
						else {
							if (!visited[horse][target + 1][ny][nx]) {
								visited[horse][target][ny][nx] = true;
								visited[horse][target + 1][ny][nx] = true;
								q.push(make_pair(make_pair(change, horse), make_pair(target + 1, make_pair(ny, nx))));
							}
						}
					}
					else {
						if (!visited[horse][target][ny][nx]) {
							visited[horse][target][ny][nx] = true;
							q.push(make_pair(make_pair(change, horse), make_pair(target, make_pair(ny, nx))));
						}
					}

					if (horse == 0) break;
					ny += dy[horse][i];
					nx += dx[horse][i];
				}
			}
		}
		if (v.size()) {
			sort(v.begin(), v.end());
			cout << cnt << " " << v[0] << '\n';
			return;
		}
		while (!tmp.empty()) {
			y = tmp.front().second.first;
			x = tmp.front().second.second;
			change = tmp.front().first.first;
			target = tmp.front().first.second;
			tmp.pop();
			for (int i = 0; i < 3; i++) {
				if (!visited[i][target][y][x]) {
					visited[i][target][y][x] = true;
					q.push(make_pair(make_pair(change + 1, i), make_pair(target, make_pair(y, x))));
				}
			}
		}
		cnt++;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			// 시작지점
			if (arr[i][j] == 1) {
				sy = i;
				sx = j;
			}
		}
	}
	bfs();
	return 0;
}

// 정답 소스
// #include <iostream>
// #include <algorithm>

// #define valid(y, x) ((y) > 0 && (y) <= n && (x) > 0 && (x) <= n)
// using namespace std;
// typedef pair<int, int> pii;
// constexpr int INF = 0x3f3f3f3f;

// int a[12][12];
// int min_cost[301][301];
// int min_change[301][301];
// int dp1[3][101];
// int dp2[3][301];
// int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
// int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
// int cy[] = { 1, -1, -1, 1 };
// int cx[] = { 1, -1, 1, -1 };
// int by[] = { 1, 0, 0, -1 };
// int bx[] = { 0, 1, -1, 0 };
// int n;

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(nullptr);

// 	cin >> n;
// 	memset(min_cost, INF, sizeof(min_cost));
// 	memset(min_change, INF, sizeof(min_change));
// 	memset(dp1, INF, sizeof(dp1));
// 	for (int i = 1; i <= n; ++i) {
// 		for (int j = 1; j <= n; ++j) {
// 			cin >> a[i][j];
// 		}
// 	}

// 	for (int i = 1; i <= n; ++i) {
// 		for (int j = 1; j <= n; ++j) {
// 			int y, x;
// 			for (int k = 8; k--;) {
// 				y = i + dy[k], x = j + dx[k];
// 				if (!valid(y, x)) continue;

// 				min_cost[a[i][j]][a[y][x]] = 1;
// 				min_change[a[i][j]][a[y][x]] = 0;
// 			}

// 			for (int k = 4; k--;) {
// 				y = i + cy[k], x = j + cx[k];
// 				while (valid(y, x)) {
// 					min_cost[a[i][j] + 100][a[y][x] + 100] = 1;
// 					min_change[a[i][j] + 100][a[y][x] + 100] = 0;
// 					y += cy[k], x += cx[k];
// 				}
// 			}

// 			for (int k = 4; k--;) {
// 				y = i + by[k], x = j + bx[k];
// 				while (valid(y, x)) {
// 					min_cost[a[i][j] + 200][a[y][x] + 200] = 1;
// 					min_change[a[i][j] + 200][a[y][x] + 200] = 0;
// 					y += by[k], x += bx[k];
// 				}
// 			}

// 			for (int k = 0; k < 3; ++k) {
// 				for (int l = k + 1; l < 3; ++l) {
// 					min_cost[a[i][j] + k * 100][a[i][j] + l * 100] = 1;
// 					min_change[a[i][j] + k * 100][a[i][j] + l * 100] = 1;
// 					min_cost[a[i][j] + l * 100][a[i][j] + k * 100] = 1;
// 					min_change[a[i][j] + l * 100][a[i][j] + k * 100] = 1;
// 				}
// 			}
// 		}
// 	}

// 	int len = n * n + 200;
// 	for (int k = 1; k <= len; ++k) {
// 		for (int i = 1; i <= len; ++i) {
// 			for (int j = 1; j <= len; ++j) {
// 				if (min_cost[i][j] > min_cost[i][k] + min_cost[k][j]) {
// 					min_cost[i][j] = min_cost[i][k] + min_cost[k][j];
// 					min_change[i][j] = min_change[i][k] + min_change[k][j];
// 				}
// 				else if (min_cost[i][j] == min_cost[i][k] + min_cost[k][j]) {
// 					min_change[i][j] = min(min_change[i][j], min_change[i][k] + min_change[k][j]);
// 				}
// 			}
// 		}
// 	}

// 	dp1[0][1] = dp1[1][1] = dp1[2][1] = 0;
// 	for (int i = 2; i <= n * n; ++i) {
// 		for (int k = 0; k < 3; ++k) {
// 			for (int l = 0; l < 3; ++l) {
// 				if (dp1[k][i] > dp1[l][i - 1] + min_cost[k * 100 + i][l * 100 + i - 1]) {
// 					dp1[k][i] = dp1[l][i - 1] + min_cost[k * 100 + i][l * 100 + i - 1];
// 					dp2[k][i] = dp2[l][i - 1] + min_change[k * 100 + i][l * 100 + i - 1];
// 				}
// 				else if (dp1[k][i] == dp1[l][i - 1] + min_cost[k * 100 + i][l * 100 + i - 1]) {
// 					dp2[k][i] = min(dp2[k][i], dp2[l][i - 1] + min_change[k * 100 + i][l * 100 + i - 1]);
// 				}
// 			}

// 		}
// 	}

// 	int a = INF, b = INF;
// 	for (int i = 0; i < 3; ++i) {
// 		if (a > dp1[i][n * n]) {
// 			a = dp1[i][n * n];
// 			b = dp2[i][n * n];
// 		}
// 		else if (a == dp1[i][n * n]) {
// 			b = min(b, dp2[i][n * n]);
// 		}
// 	}

// 	cout << a << ' ' << b;
// }