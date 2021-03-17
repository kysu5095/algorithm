// Piet

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, arr_idx = 0;
char map[101][101];
int arr[101][101];
bool visited[101][101];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v[100001];
vector<char> command;

class Point {
public:
	int y, x;
};

bool compare_left(pair<int, int>& p1, pair<int, int>& p2) {
	return p1.second < p2.second;
}

bool compare_right(pair<int, int>& p1, pair<int, int>& p2) {
	return p1.second > p2.second;
}

bool compare_up(pair<int, int>& p1, pair<int, int>& p2) {
	return p1.first < p2.first;
}

bool compare_down(pair<int, int>& p1, pair<int, int>& p2) {
	return p1.first > p2.first;
}

void bfs(int y, int x, char& ch) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	v[arr_idx].push_back(make_pair(y, x));
	arr[y][x] = arr_idx;
	int ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m || map[ny][nx] != ch || visited[ny][nx]) continue;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
			v[arr_idx].push_back(make_pair(ny, nx));
			arr[ny][nx] = arr_idx;
		}
	}
	arr_idx++;
}

void sort_block(int& block, int& dp) {
	switch (dp)
	{
	case 0: sort(v[block].begin(), v[block].end(), compare_up); break;
	case 1: sort(v[block].begin(), v[block].end(), compare_right); break;
	case 2: sort(v[block].begin(), v[block].end(), compare_down); break;
	case 3: sort(v[block].begin(), v[block].end(), compare_left); break;
	}
}

void get_point(Point& p, int& block, int& cc) {
	p.y = v[block][0].first;
	p.x = v[block][0].second;
	for (auto& node : v[block]) {
		if (cc == 0) {
			if (node.second != v[block][0].second) break;
			p.y = min(p.y, node.first);
		}
		else if (cc == 1) {
			if (node.first != v[block][0].first) break;
			p.x = max(p.x, node.second);
		}
		else if (cc == 2) {
			if (node.second != v[block][0].second) break;
			p.y = max(p.y, node.first);
		}
		else {
			if (node.first != v[block][0].first) break;
			p.x = min(p.x, node.second);
		}
	}
}

bool is_right(Point& p, int& block, int& dp) {
	int ny = p.y + dy[dp];
	int nx = p.x + dx[dp];
	if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] != 'X') {
		block = arr[ny][nx];
		command.push_back(map[ny][nx]);
		return true;
	}
	return false;
}

void Piet() {
	command.push_back(map[0][0]);
	int block = arr[0][0];
	int dp = 1, cc = 0;
	Point p;
	int ny, nx;
	while (true) {
		sort_block(block, dp);
		get_point(p, block, cc);
		if (is_right(p, block, dp)) continue;
		
		cc = (cc + 2) % 4;
		get_point(p, block, cc);
		if (is_right(p, block, dp)) continue;
		
		dp = (dp + 1) % 4;
		cc = (cc + 1) % 4;
		sort_block(block, dp);
		get_point(p, block, cc);
		if (is_right(p, block, dp)) continue;

		cc = (cc + 2) % 4;
		get_point(p, block, cc);
		if (is_right(p, block, dp)) continue;

		dp = (dp + 1) % 4;
		cc = (cc + 1) % 4;
		sort_block(block, dp);
		get_point(p, block, cc);
		if (is_right(p, block, dp)) continue;

		cc = (cc + 2) % 4;
		get_point(p, block, cc);
		if (is_right(p, block, dp)) continue;

		dp = (dp + 1) % 4;
		cc = (cc + 1) % 4;
		sort_block(block, dp);
		get_point(p, block, cc);
		if (is_right(p, block, dp)) continue;

		cc = (cc + 2) % 4;
		get_point(p, block, cc);
		if (is_right(p, block, dp)) continue;
		break;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> map[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 'X' && !visited[i][j]) bfs(i, j, map[i][j]);
			if (map[i][j] == 'X') arr[i][j] = -1;
		}
	}
	Piet();
	for (auto& node : command) cout << node;
	cout << '\n';
	return 0;
}