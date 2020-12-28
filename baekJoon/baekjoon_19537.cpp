// 전투 시뮬레이션

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int n, h, w, m, k;
int arr[501][501] = { {0,}, };
int map[501][501] = { {0,}, };
int visited[501][501] = { {0, }, };
int slope[10];
int dy[4] = { 0 ,0 ,1 ,-1 };
int dx[4] = { 1, -1, 0, 0 };

class Unit {
public:
	int m, t, y, x;
};
vector<Unit> v;

bool is_enermy(int& y, int& x, int& t) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny == h || nx < 0 || nx == w) continue;
		if (map[ny][nx] && v[map[ny][nx]].t != t) return true;
	}
	return false;
}

bool move(int& u, int& _y, int& _x) {
	if (map[_y][_x]) return false;
	if (slope[arr[_y][_x]] == -1) return false;
	int y = v[u].y, x = v[u].x;
	int s = v[u].m, t = v[u].t;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(s, make_pair(y, x)));
	visited[y][x] = s;
	int ny, nx, ns;
	while (!pq.empty()) {
		s = pq.top().first;
		y = pq.top().second.first;
		x = pq.top().second.second;
		pq.pop();
		if (s < visited[y][x]) continue;

		/* 다음칸으로 이동가능한지 판별 */
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == h || nx < 0 || nx == w) continue;
			ns = s - slope[arr[ny][nx]];
			if (slope[arr[ny][nx]] == -1 || ns < 0) continue;
			if (ny == _y && nx == _x) return true;
			if (map[ny][nx] && v[map[ny][nx]].t != t) continue;
			if (is_enermy(ny, nx, t)) continue;
			if (ns <= visited[ny][nx]) continue;
			pq.push(make_pair(ns, make_pair(ny, nx)));
			visited[ny][nx] = ns;
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, d;
	cin >> n >> h >> w;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= n; i++)
		cin >> slope[i];

	v.push_back({ 0, 0, 0, 0 }); /* 1번 index부터 시작하기위해 넣어줌 */
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c >> d;
		v.push_back({ a, b, c, d });
		map[c][d] = i; /* 맵에 유닛 표시 */
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c;
		memset(visited, 0, sizeof(visited));
		if (move(a, b, c)) { /* 명령 수행 */
			map[b][c] = a;
			map[v[a].y][v[a].x] = 0;
			v[a].y = b;
			v[a].x = c;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << v[i].y << " " << v[i].x << '\n';
	return 0;
}