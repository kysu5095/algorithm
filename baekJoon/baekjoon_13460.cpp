// 구슬 탈출 2

#include <stdio.h>
#include <queue>

int n, m;
char arr[11][11];
bool visited[11][11][11][11];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
std::pair<int, int> p[2];

int bfs() {
	std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>> q;
	q.push(std::make_pair(p[0], p[1]));
	visited[p[0].first][p[0].second][p[1].first][p[1].second] = true;

	int ry, rx, by, bx, nry, nrx, nby, nbx, len, t = 0;
	bool rflag, bflag;
	while (!q.empty() && t < 10) {
		t++;
		len = q.size();
		while (len--) {
			ry = q.front().first.first;
			rx = q.front().first.second;
			by = q.front().second.first;
			bx = q.front().second.second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				nry = ry;
				nrx = rx;
				rflag = false;
				while (true) {
					nry += dy[i];
					nrx += dx[i];
					if (arr[nry][nrx] == '#') {
						nry -= dy[i];
						nrx -= dx[i];
						break;
					}
					if (arr[nry][nrx] == 'O') {
						rflag = true;
						break;
					}
				}
				nby = by;
				nbx = bx;
				bflag = false;
				while (true) {
					nby += dy[i];
					nbx += dx[i];
					if (arr[nby][nbx] == '#') {
						nby -= dy[i];
						nbx -= dx[i];
						break;
					}
					if (arr[nby][nbx] == 'O') {
						bflag = true;
						break;
					}
				}
				if (bflag) continue;
				if (rflag) return t;
				if (nry == nby && nrx == nbx) {
					if (i == 0) {
						if (rx < bx) nrx--;
						else nbx--;
					}
					else if (i == 1) {
						if (rx < bx) nbx++;
						else nrx++;
					}
					else if (i == 2) {
						if (ry < by) nry--;
						else nby--;
					}
					else {
						if (ry < by)nby++;
						else nry++;
					}
				}
				if (visited[nry][nrx][nby][nbx]) continue;
				q.push(std::make_pair(std::make_pair(nry, nrx), std::make_pair(nby, nbx)));
				visited[nry][nrx][nby][nbx] = true;
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'R') p[0] = std::make_pair(i, j);
			else if (arr[i][j] == 'B') p[1] = std::make_pair(i, j);
		}
	}
	printf("%d\n", bfs());
	return 0;
}