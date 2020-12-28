// 구슬탈출 4
// 8:30

#include <iostream>
#include <queue>

using namespace std;

int n, m;
char arr[11][11];
bool visited[11][11][11][11] = { { { {false,},},}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs(int _ry, int _rx, int _by, int _bx) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(_ry, _rx), make_pair(_by, _bx)));
	visited[_ry][_rx][_by][_bx] = true;
	int ry, rx, by, bx, nry, nrx, nby, nbx, rcnt, bcnt, len, t = 0;
	bool rflag, bflag;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			ry = q.front().first.first;
			rx = q.front().first.second;
			by = q.front().second.first;
			bx = q.front().second.second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				nry = ry, nrx = rx;
				nby = by, nbx = bx;
				rcnt = 0, bcnt = 0;
				rflag = true, bflag = true;
				while (true) {
					nry += dy[i];
					nrx += dx[i];
					if (arr[nry][nrx] == 'O') {
						rflag = false;
						break;
					}
					if (arr[nry][nrx] == '#') {
						nry -= dy[i];
						nrx -= dx[i];
						break;
					}
					rcnt++;
				}
				while (true) {
					nby += dy[i];
					nbx += dx[i];
					if (arr[nby][nbx] == 'O') {
						bflag = false;
						break;
					}
					if (arr[nby][nbx] == '#') {
						nby -= dy[i];
						nbx -= dx[i];
						break;
					}
					bcnt++;
				}
				if (!bflag) continue;
				if (!rflag) return t;
				if (nry == nby && nrx == nbx) {
					if (rcnt > bcnt) nry -= dy[i], nrx -= dx[i];
					else nby -= dy[i], nbx -= dx[i];
				}
				if (nry == ry && nrx == rx && nby == by && nbx == bx) continue;
				if (visited[nry][nrx][nby][nbx]) continue;
				visited[nry][nrx][nby][nbx] = true;
				q.push(make_pair(make_pair(nry, nrx), make_pair(nby, nbx)));
			}
		}
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int ry, rx, by, bx;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'R') {
				ry = i, rx = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				by = i, bx = j;
				arr[i][j] = '.';
			}
		}
	}
	cout << bfs(ry, rx, by, bx) << '\n';
	return 0;
}