// 팩맨

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int T, m, n;
char arr[51][51];
bool visited[51][51][51][51];
pair<int, int> p[2];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
char dir[4] = { 'N', 'E', 'S', 'W' };

void bfs() {
	int ly, lx, ry, rx, nly, nlx, nry, nrx, len, t = 0;
	queue<pair<pair<int, int>, pair<vector<int>, pair<int, int>>>> q;
	ly = p[0].first, lx = p[0].second;
	ry = p[1].first, rx = p[1].second;
	vector<int> v;
	q.push(make_pair(make_pair(ly, lx), make_pair(v, make_pair(ry, rx))));
	visited[ly][lx][ry][rx] = true;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			ly = q.front().first.first, lx = q.front().first.second;
			ry = q.front().second.second.first, rx = q.front().second.second.second;
			vector<int> nv = q.front().second.first;
			if (ly == ry && lx == rx) {
				cout << t << " ";
				for (int& node : nv) cout << dir[node];
				cout << '\n';
				return;
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				nly = ly + dy[i] + n, nlx = lx + dx[i] + m;
				nry = ry + dy[i] + n, nrx = rx + dx[i] + m;
				nly %= n, nlx %= m;
				nry %= n, nrx %= m;
				if (arr[nly][nlx] == 'X') nly = ly, nlx = lx;
				if (arr[nly][nlx] == 'G') continue;
				if (arr[nry][nrx] == 'X') nry = ry, nrx = rx;
				if (arr[nry][nrx] == 'G') continue;
				if (visited[nly][nlx][nry][nrx]) continue;
				nv.push_back(i);
				q.push(make_pair(make_pair(nly, nlx), make_pair(nv, make_pair(nry, nrx))));
				visited[nly][nlx][nry][nrx] = true;
				nv.pop_back();
			}
		}
		t++;
	}
	cout << "IMPOSSIBLE\n";
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int idx = 0;
		memset(visited, false, sizeof(visited));
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 'P') 
					p[idx++] = make_pair(i, j);
			}
		}
		bfs();
	}
	return 0;
}