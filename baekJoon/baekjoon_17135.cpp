// 캐슬 디펜스
// 11:45

#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>

using namespace std;

int n, m, d, enermy, tmp_res, res;
int arr[16][16];
int tmp_arr[16][16];
int kill_map[16][16] = { {0, }, };
bool visited[16][16];
int bow[3];

class Point {
public:
	int y, x;
};
Point p[3] = { {0, -1}, {-1, 0}, {0, 1} };

void copy_arr() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = tmp_arr[i][j];
}

void bfs(int _y, int _x, int idx) {
	memset(visited, false, sizeof(visited));
	queue<Point> q;
	q.push({ _y, _x });
	visited[_y][_x] = true;
	int y, x, ny, nx, nd;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		q.pop();
		nd = abs(n - y) + abs(bow[idx] - x);
		if (nd == d) return;

		for (int i = 0; i < 3; i++) {
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny >= 0 && nx >= 0 && nx < m && !visited[ny][nx]) {
				q.push({ ny, nx });
				visited[ny][nx] = true;
				if (arr[ny][nx]) {
					kill_map[ny][nx] = 1;
					return;
				}
			}
		}
	}
}

int kill() {
	int k = 0;
	for (int i = 0; i < 3; i++) {
		if (arr[n - 1][bow[i]]) kill_map[n - 1][bow[i]] = 1;
		else bfs(n - 1, bow[i], i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (kill_map[i][j]) {
				k++;
				tmp_res++;
				kill_map[i][j] = 0;
				arr[i][j] = 0;
			}
		}
	}
	return k;
}

int move() {
	int k = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) {
				arr[i][j] = 0;
				if (i == n - 1) k++;
				else arr[i + 1][j] = 1;
			}
		}
	}
	return k;
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		tmp_res = 0;
		int tmp = enermy;
		while (tmp) {
			tmp -= kill();
			tmp -= move();
		}
		copy_arr();
		res = res < tmp_res ? tmp_res : res;
		return;
	}
	for (int i = idx; i < m; i++) {
		bow[cnt] = i;
		dfs(i + 1, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			tmp_arr[i][j] = arr[i][j];
			if (arr[i][j])
				enermy++;
		}
	}
	dfs(0, 0);
	cout << res << '\n';
	return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <math.h>
// #include <set>

// using namespace std;

// int n, m, d, res = 0;
// bool arr[16][16];
// int arch[3];
// vector<pair<bool, pair<int, int>>> enermy;

// int game() {
// 	vector<pair<bool, pair<int, int>>> v = enermy;
// 	int y, x, ay = n, ax, distance, cnt = 0;
// 	int len = v.size();
// 	int res_enermy = len;
// 	while (res_enermy) {
// 		set<int> hunt;
// 		for (int idx = 0; idx < 3; idx++) {
// 			ax = arch[idx];
// 			vector<pair<int, pair<int, int>>> tmp;
// 			for (int i = 0; i < len; i++) {
// 				if (v[i].first == false) continue;
// 				y = v[i].second.first;
// 				x = v[i].second.second;
// 				distance = abs(ay - y) + abs(ax - x);
// 				if (distance <= d) tmp.push_back(make_pair(distance, make_pair(x, i)));
// 			}
// 			if (!tmp.empty()) {
// 				sort(tmp.begin(), tmp.end());
// 				hunt.insert(tmp[0].second.second);
// 			}
// 		}
		
// 		if (!hunt.empty()) {
// 			set<int>::iterator iter;
// 			for (iter = hunt.begin(); iter != hunt.end(); iter++) {
// 				v[*iter].first = false;
// 				cnt++;
// 				res_enermy--;
// 			}
// 		}

// 		for (int i = 0; i < len; i++) {
// 			if (v[i].first == false) continue;
// 			v[i].second.first++;
// 			if (v[i].second.first == n) {
// 				v[i].first = false;
// 				res_enermy--;
// 			}
// 		}
// 	}
// 	return cnt;
// }

// void dfs(int idx, int cnt) {
// 	if (cnt == 3) {
// 		int val = game();
// 		res = max(res, val);
// 		return;
// 	}
// 	for (int i = idx; i < m; i++) {
// 		arch[cnt] = i;
// 		dfs(i + 1, cnt + 1);
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n >> m >> d;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			cin >> arr[i][j];
// 			if (arr[i][j]) 
// 				enermy.push_back(make_pair(true, make_pair(i, j)));
// 		}
// 	}
// 	dfs(0, 0);
// 	cout << res << '\n';
// 	return 0;
// }