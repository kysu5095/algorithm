// 화물차

#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int n, m, sy, sx, fy, fx;
char arr[21][21];
int visited[21][21];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

class StreetLamp {
public:
	char flag;
	int ai, bi;
};
StreetLamp street[400];

void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = INT_MAX;
}

int get_sec(int& sec, int& d, int idx) {
	int left = street[idx].ai;
	int right = street[idx].bi;
	int total = left + right;
	int mod = sec % total;
	if (street[idx].flag == '-') {
		if (mod < left) {
			if (d < 2) return 1;
			else return (total - right - mod + 1);
		}
		else {
			if (d >= 2) return 1;
			else return (total - mod + 1);
		}
	}
	else {
		if (mod < right) {
			if (d >= 2) return 1;
			else return (total - left - mod + 1);
		}
		else {
			if (d < 2) return 1;
			else return (total - mod + 1);
		}
	}
}

void bfs() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(sy, sx)));
	visited[sy][sx] = 0;

	int y, x, ny, nx, sec;
	while (!pq.empty()) {
		y = pq.top().second.first;
		x = pq.top().second.second;
		sec = -pq.top().first;
		pq.pop();
		if (sec > visited[y][x]) continue;

		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m) continue;
			if (arr[ny][nx] == '.') continue;
			// 다음칸이 '#' 또는 'B' 인경우
			if ((arr[ny][nx] == '#' || arr[ny][nx] == 'B') && sec + 1 < visited[ny][nx]) {
				visited[ny][nx] = sec + 1;
				if (arr[ny][nx] == '#')
					pq.push(make_pair(-(sec + 1), make_pair(ny, nx)));
			}
			// 다음칸이 신호등인경우
			if (arr[ny][nx] - '0' >= 0 && arr[ny][nx] - '0' <= 9) {
				int nsec = sec + get_sec(sec, i, arr[ny][nx] - '0');
				if (nsec < visited[ny][nx]) {
					visited[ny][nx] = nsec;
					pq.push(make_pair(-nsec, make_pair(ny, nx)));
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		cin >> n >> m;
		if (!n && !m) break;
		char flag;
		int idx, ai, bi, cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 'A') sy = i, sx = j;
				else if (arr[i][j] == 'B') fy = i, fx = j;
				else if (arr[i][j] - '0' >= 0 && arr[i][j] - '0' <= 9) cnt++;
			}
		}
		for (int i = 0; i < cnt; i++) {
			cin >> idx >> flag >> ai >> bi;
			street[idx].flag = flag;
			street[idx].ai = ai;
			street[idx].bi = bi;
		}
		init();
		bfs();
		if (visited[fy][fx] == INT_MAX) cout << "impossible\n";
		else cout << visited[fy][fx] << '\n';
	}
	return 0;
}