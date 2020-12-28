// 다리 만들기 2

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, m, cnt, res;
int arr[10][10] = { {0, }, };
bool visited[10][10] = { {false, }, };
int short_distance[7][7];

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<Point> island[6];

class Edge {
public:
	int start, end, d;

	bool operator <(const Edge& e) const {
		return d < e.d;
	}
};
vector<Edge> e;

void bfs(int _y, int _x) {
	queue<Point> q;
	q.push({ _y, _x });
	visited[_y][_x] = true;
	island[cnt].push_back({ _y, _x });
	arr[_y][_x] = cnt + 1;
	int y, x, ny, nx;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		for (int i = 0; i < 4; i++) {
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] && !visited[ny][nx]) {
				visited[ny][nx] = true;
				island[cnt].push_back({ ny, nx });
				arr[ny][nx] = cnt + 1;
				q.push({ ny, nx });
			}
		}
		q.pop();
	}
	cnt++;
}

int get_parent(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = get_parent(set, set[x]);
}

void uniopn_parent(int set[], int x, int y) {
	x = get_parent(set, x);
	y = get_parent(set, y);
	if (x < y) set[y] = x;
	else set[x] = y;
}

bool is_parent_same(int set[], int x, int y) {
	x = get_parent(set, x);
	y = get_parent(set, y);
	if (x == y) return true;
	else return false;
}

void mst() {
	int len;
	int set[7];
	for (int i = 1; i <= cnt; i++)
		set[i] = i;
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j < i; j++) {
			if (short_distance[i][j] != INT_MAX)
				e.push_back({ i, j, short_distance[i][j] });
		}
	}
	sort(e.begin(), e.end());
	len = e.size();
	for (int i = 0; i < len; i++) {
		if (!is_parent_same(set, e[i].start, e[i].end)) {
			res += e[i].d;
			uniopn_parent(set, e[i].start, e[i].end);
		}
	}
	for (int i = 1; i < cnt; i++) {
		if (get_parent(set, i) != get_parent(set, i + 1)) {
			res = -1;
			return;
		}
	}
}

void find_shortest_distance() {
	int len, y, x, ny, nx, dist;
	for (int tc = 0; tc < cnt; tc++) {
		len = island[tc].size();
		for (int i = 0; i < len; i++) {
			y = island[tc][i].y;
			x = island[tc][i].x;
			for (int j = 0; j < 4; j++) {
				dist = 0;
				ny = y;
				nx = x;
				while (true) {
					ny += p[j].y;
					nx += p[j].x;
					if (ny < 0 || ny >= n || nx < 0 || nx >= m || arr[ny][nx] == arr[y][x])
						break;
					if (arr[ny][nx]) {
						if (dist < 2) break;
						if (dist < short_distance[arr[y][x]][arr[ny][nx]]) 
							short_distance[arr[y][x]][arr[ny][nx]] = dist;

						break;
					}
					dist++;
				}
			}
		}
	}
}

void separate_island() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] && !visited[i][j]) 
				bfs(i, j);
		}
	}
	find_shortest_distance();
	mst();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cnt = 0;
	res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			short_distance[i][j] = INT_MAX;

	separate_island();
	cout << res << '\n';
	return 0;
}