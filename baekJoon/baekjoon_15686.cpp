//  치킨 배달  //
////////////////

#include <iostream>
#include <algorithm>
//#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int minChicken = 99999;
int arr[51][51];
bool visited[13] = { false, };
int maxChicken[13] = { 0, };

class Point {
public:
	int x, y, len;
};
// Point p[4] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0} };
vector<Point> home;         // 모든 집의 좌표
vector<Point> chicken;      // 모든 치킨집의 좌표
vector<Point> surviveCh;    // 살아남은 M개의 치킨집의 좌표
//queue<Point> q;

// void cleanQ() {
// 	queue<Point> empty;
// 	swap(q, empty);
// }
//
//int bfs(int x, int y) {
//	bool visite[51][51] = { {false, }, };
//	cleanQ();
//	q.push({ x, y, 0 });
//
//	while (!q.empty()) {
//		int tmpx = q.front().x;
//		int tmpy = q.front().y;
//		int tmplen = q.front().len;
//
//		for (int i = 0; i < surviveCh.size(); i++) {
//			if (tmpx == surviveCh[i].x && tmpy == surviveCh[i].y) {
//				return tmplen;
//			}
//		}
//
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nextX = tmpx + p[i].x;
//			int nextY = tmpy + p[i].y;
//
//			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && !visite[nextY][nextX]) {
//				visite[nextY][nextX] = true;
//				q.push({ nextX, nextY, tmplen + 1 });
//			}
//		}
//	}
//}

int route(int x, int y) {
	int lenX, lenY;
	int len = 99999;
	for (int i = 0; i < surviveCh.size(); i++) {
		lenX = abs(x - surviveCh[i].x);
		lenY = abs(y - surviveCh[i].y);
		len = min(len, lenX + lenY);
	}
	return len;
}

void dfs(int cnt, int idx) {
	if (cnt == m) {
		int len = 0;
		for (int i = 0; i < home.size(); i++) {
			len += route(home[i].x, home[i].y);
		}
		minChicken = min(minChicken, len);
		return;
	}

	for (int i = idx; i < chicken.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			surviveCh.push_back(chicken[i]);
			dfs(cnt + 1, i + 1);
			visited[i] = false;
			surviveCh.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) home.push_back({ j, i });
			if (arr[i][j] == 2) chicken.push_back({ j, i });
		}
	}

	dfs(0, 0);
	cout << minChicken << '\n';

	return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int n, m, result = 987654321;
// bool visited[13] = { false, };

// class Point {
// public:
// 	int y = 0, x = 0;
// };
// Point tmp[13];
// vector<Point> home;
// vector<Point> chicken;

// void calculate() {
// 	int val, res = 0;
// 	int size = home.size();
// 	for (int i = 0; i < size; i++) {
// 		val = abs(tmp[0].y - home[i].y) + abs(tmp[0].x - home[i].x);
// 		for (int j = 1; j < m; j++) 
// 			val = val > abs(tmp[j].y - home[i].y) + abs(tmp[j].x - home[i].x) ? abs(tmp[j].y - home[i].y) + abs(tmp[j].x - home[i].x) : val;
		
// 		res += val;
// 	}
// 	result = result > res ? res : result;
// }

// void dfs(int cnt, int idx) {
// 	if (cnt == m) {
// 		calculate();
// 		return;
// 	}

// 	int size = chicken.size();
// 	for (int i = idx; i < size; i++) {
// 		if (!visited[i]) {
// 			visited[i] = true;
// 			tmp[cnt].y = chicken[i].y;
// 			tmp[cnt].x = chicken[i].x;
// 			dfs(cnt + 1, i + 1);
// 			visited[i] = false;
// 		}
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int tmp;
// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> tmp;
// 			if (tmp == 1)
// 				home.push_back({ i, j });
// 			if (tmp == 2) 
// 				chicken.push_back({ i, j });
// 		}
// 	}
// 	dfs(0, 0);
// 	cout << result << '\n';

// 	return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <math.h>
// #include <limits.h>

// using namespace std;

// int n, m, res = INT_MAX;
// int arr[51][51];
// bool closed[14] = { false, };
// vector<pair<int, int>> house;
// vector<pair<int, int>> chicken;

// void get_chicken_distance() {
// 	int hy, hx, cy, cx, compare = 0;
// 	for (int i = 0; i < (int)house.size(); i++) {
// 		hy = house[i].first;
// 		hx = house[i].second;
// 		int min_distance = INT_MAX;
// 		for (int j = 0; j < (int)chicken.size(); j++) {
// 			if (closed[j]) continue;
// 			cy = chicken[j].first;
// 			cx = chicken[j].second;
// 			min_distance = min(min_distance, (abs(hy - cy) + abs(hx - cx)));
// 		}
// 		compare += min_distance;
// 	}
// 	res = min(res, compare);
// }

// void dfs(int idx, int cnt) {
// 	if (cnt == m) {
// 		get_chicken_distance();
// 		return;
// 	}
// 	if (idx == (int)chicken.size()) return;
// 	closed[idx] = true;
// 	dfs(idx + 1, cnt + 1);
// 	closed[idx] = false;
// 	dfs(idx + 1, cnt);
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> arr[i][j];
// 			if (arr[i][j] == 1) house.push_back(make_pair(i, j));
// 			else if (arr[i][j] == 2) chicken.push_back(make_pair(i, j));
// 		}
// 	}
// 	m = chicken.size() - m;
// 	dfs(0, 0);
// 	cout << res << '\n';
// 	return 0;
// }