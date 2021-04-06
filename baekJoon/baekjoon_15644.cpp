// 구슬 탈출 3

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m;
char arr[11][11];
bool visited[11][11][11][11];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
char command[4] = { 'R', 'L', 'D', 'U' };

struct Point {
	int ry, rx, by, bx;
	string str;
};

void bfs(int ry, int rx, int by, int bx) {
	queue<Point> q;
	q.push({ ry, rx, by, bx, "" });
	visited[ry][rx][by][bx] = true;

	int nry, nrx, nby, nbx, len, t = 0;
	bool red, blue;
	while (t < 10) {
		t++;
		len = q.size();
		while (len--) {
			ry = q.front().ry, rx = q.front().rx;
			by = q.front().by, bx = q.front().bx;
			string str = q.front().str;
			q.pop();

			for (int i = 0; i < 4; i++) {
				nry = ry, nrx = rx;
				red = false;
				while (arr[nry + dy[i]][nrx + dx[i]] != '#') {
					nry += dy[i];
					nrx += dx[i];
					if (arr[nry][nrx] == 'O') {
						red = true;
						break;
					}
				}

				nby = by, nbx = bx;
				blue = false;
				while (arr[nby + dy[i]][nbx + dx[i]] != '#') {
					nby += dy[i];
					nbx += dx[i];
					if (arr[nby][nbx] == 'O') {
						blue = true;
						break;
					}
				}

				if (blue) continue;
				if (red) {
					cout << t << "\n";
					cout << str << command[i] << '\n';
					return;
				}
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
						if (ry < by) nby++;
						else nry++;
					}
				}
				if (visited[nry][nrx][nby][nbx]) continue;
				q.push({ nry, nrx, nby, nbx, str + command[i] });
				visited[nry][nrx][nby][nbx] = true;
			}
		}
	}
	cout << "-1\n";
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ry, rx, by, bx;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'R') ry = i, rx = j;
			else if(arr[i][j] == 'B') by = i, bx = j;
		}
	}
	bfs(ry, rx, by, bx);
	return 0;
}