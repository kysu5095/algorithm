// 버스 갈아타기

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, k;
bool visited[5001];
class BUS {
public:
	int y1, x1, y2, x2;
	bool in(int& y, int& x) {
		return (y >= y1 && y <= y2 && x >= x1 && x <= x2);
	}
	bool in(BUS& b) {
		return (x1 <= b.x2 && x2 >= b.x1 && y1 <= b.y2 && y2 >= b.y1);
	}
};
vector<BUS> v;

int bfs(int& sy, int& sx, int& fy, int& fx) {
	queue<int> q;
	for (int i = 1; i <= k; i++) {
		if (v[i].in(sy, sx)) {
			q.push(i);
			visited[i] = true;
		}
	}
	int node, len, cnt = 1;
	while (true) {
		len = q.size();
		while (len--) {
			node = q.front();
			q.pop();
			if (v[node].in(fy, fx)) return cnt;
			for (int i = 1; i <= k; i++) {
				if (visited[i]) continue;
				if (v[node].in(v[i])) {
					q.push(i);
					visited[i] = true;
				}
			}
		}
		cnt++;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> k;
	v.resize(k + 2);
	int y1, x1, y2, x2, b;
	for (int i = 1; i <= k; i++) {
		cin >> b >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		v[b] = { y1, x1, y2, x2 };
	}
	cin >> x1 >> y1 >> x2 >> y2;
	cout << bfs(y1, x1, y2, x2) << '\n';
	return 0;
}

// // 버스 갈아타기

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <map>
// #include <algorithm>

// using namespace std;

// int n, m, k;
// bool visited[5001];
// pair<pair<int, int>, pair<int, int>> v[5001];
// vector<vector<int>> y_axis;
// vector<vector<int>> x_axis;
// int sy, sx, dy, dx;

// void check(int& y, int& x, bool flag, queue<int>& q) {
// 	if (flag) {
// 		for (int node : x_axis[x]) {
// 			if (visited[node]) continue;
// 			int y1 = v[node].first.first, y2 = v[node].second.first;
// 			if (y < y1 || y > y2) continue;
// 			q.push(node);
// 			visited[node] = true;
// 		}
// 	}
// 	else {
// 		for (int node : y_axis[y]) {
// 			if (visited[node]) continue;
// 			int x1 = v[node].first.second, x2 = v[node].second.second;
// 			if (x < x1 || x > x2) continue;
// 			q.push(node);
// 			visited[node] = true;
// 		}
// 	}
// }

// int bfs() {
// 	int y, x, y1, x1, y2, x2, node, len, change = 0;
// 	queue<int> q;
// 	check(sy, sx, true, q);
// 	check(sy, sx, false, q);

// 	while (!q.empty()) {
// 		change++;
// 		len = q.size();
// 		while (len--) {
// 			node = q.front();
// 			q.pop();

// 			y1 = v[node].first.first, x1 = v[node].first.second;
// 			y2 = v[node].second.first, x2 = v[node].second.second;
// 			y = y1, x = x1;
// 			if (x1 == x2) {
// 				for (int& node : x_axis[x1]) {
// 					if (visited[node]) continue;
// 					if (y1 > v[node].second.first || y2 < v[node].first.first) continue;
// 					q.push(node);
// 					visited[node] = true;
// 				}
// 				while (y >= y1 && y <= y2) {
// 					if (y == dy && x == dx) return change;
// 					check(y, x, false, q);
// 					y++;
// 				}
// 			}
// 			else {
// 				for (int& node : y_axis[y1]) {
// 					if (visited[node]) continue;
// 					if (x1 > v[node].second.second || x2 < v[node].first.second) continue;
// 					q.push(node);
// 					visited[node] = true;
// 				}
// 				while (x >= x1 && x <= x2) {
// 					if (y == dy && x == dx) return change;
// 					check(y, x, true, q);
// 					x++;
// 				}
// 			}
// 		}
// 	}
// 	return -1;
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int b, y1, x1, y2, x2;
// 	cin >> m >> n >> k;
// 	x_axis.resize(m + 2);
// 	y_axis.resize(n + 2);
// 	for (int i = 0; i < k; i++) {
// 		cin >> b >> x1 >> y1 >> x2 >> y2;
// 		if (x1 > x2) swap(x1, x2);
// 		if (y1 > y2) swap(y1, y2);
// 		v[b].first.first = y1, v[b].first.second = x1;
// 		v[b].second.first = y2, v[b].second.second = x2;
// 		if (x1 == x2) x_axis[x1].push_back(b);
// 		else y_axis[y1].push_back(b);
// 	}
// 	cin >> sx >> sy >> dx >> dy;
// 	cout << bfs() << '\n';
// 	return 0;
// }