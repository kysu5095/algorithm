// 로봇 청소기
// 2:20

#include <iostream>
#include <deque>
#include <queue>
#include <limits.h>
#include <string.h>

using namespace std;

int w, h, vy, vx, res;
char arr[21][21];
int map[11][11];
bool visited[21][21];
int virus[12];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
deque<pair<int, int>> dq;

void dfs(int cnt) {
	if (cnt == dq.size()) {
		int t = 0;
		for (int i = 0; i < dq.size() - 1; i++)
			t += map[virus[i]][virus[i + 1]];
		res = res > t ? t : res;
		return;
	}
	for (int i = 1; i < dq.size(); i++) {
		if (!virus[i]) {
			virus[i] = cnt;
			dfs(cnt + 1);
			virus[i] = 0;
		}
	}
}

bool bfs(int sy, int sx) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	visited[sy][sx] = true;
	int y, x, ny, nx, len, cnt = dq.size() - 1, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny >= 0 && ny < h && nx >= 0 && nx < w && arr[ny][nx] != 'x' && !visited[ny][nx]) {
					if (arr[ny][nx] != '.') {
						map[arr[sy][sx] - '0'][arr[ny][nx] - '0'] = t;
						map[arr[ny][nx] - '0'][arr[sy][sx] - '0'] = t;
						cnt--;
						if (!cnt) return true;
					}
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
				}
			}
		}
	}
	return false;
}

bool get_distance() {
	for (int i = 0; i < dq.size(); i++) {
		if(!bfs(dq[i].first, dq[i].second))
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		cin >> w >> h;
		if (!w && !h) break;
		memset(virus, 0, sizeof(virus));
		dq.clear();
		res = INT_MAX;
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			cin >> arr[i];
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == '*')
					dq.push_back(make_pair(i, j));
				else if (arr[i][j] == 'o')
					vy = i, vx = j;
			}
		}
		dq.push_front(make_pair(vy, vx));
		for (int i = 0; i < dq.size(); i++) {
			arr[dq[i].first][dq[i].second] = (cnt + '0');
			cnt++;
		}
		if (get_distance()) {
			dfs(1);
			cout << res << '\n';
		}
		else cout << "-1\n";
	}
	return 0;
}