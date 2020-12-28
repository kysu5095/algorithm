// 구슬탈출
// 6:50

#include <iostream>
#include <queue>

using namespace std;

int n, m, t = 10, res = 0;
char arr[11][11];

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
queue <pair<pair<int, int>, pair<int, int>>> q;

bool bfs() {
	int ry, rx, by, bx, nry, nrx, nby, nbx, len, t1, t2;
	int flag1, flag2;
	len = q.size();
	while (len--) {
		ry = q.front().first.first;
		rx = q.front().first.second;
		by = q.front().second.first;
		bx = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			t1 = 0, t2 = 0;
			nry = ry + p[i].y, nrx = rx + p[i].x;
			flag1 = 0, flag2 = 0;
			while (true) {
				if (arr[nry][nrx] == '#') {
					nry -= p[i].y;
					nrx -= p[i].x;
					break;
				}
				if (arr[nry][nrx] == 'O') {
					flag1 = 2;
					break;
				}
				nry += p[i].y;
				nrx += p[i].x;
				t1++;
			}

			nby = by + p[i].y, nbx = bx + p[i].x;
			while (true) {
				if (arr[nby][nbx] == '#') {
					nby -= p[i].y;
					nbx -= p[i].x;
					break;
				}
				if (arr[nby][nbx] == 'O') {
					flag2 = 2;
					break;
				}
				nby += p[i].y;
				nbx += p[i].x;
				t2++;
			}
			if (flag2 == 2) continue;
			if (flag1 == 2) return true;
			if (nry == nby && nrx == nbx) {
				if (t1 > t2) {
					nry -= p[i].y;
					nrx -= p[i].x;
				}
				else {
					nby -= p[i].y;
					nbx -= p[i].x;
				}
			}
			if (nry == ry && nrx == rx && nby == by && nbx == bx) continue;
			q.push(make_pair(make_pair(nry, nrx), make_pair(nby, nbx)));
		}
	}
	return false;
}

void move(int ry, int rx, int by, int bx) {
	q.push(make_pair(make_pair(ry, rx), make_pair(by, bx)));
	while (t--) {
		if (bfs()) {
			res = 1;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ry, rx, by, bx;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R')
				ry = i, rx = j;
			else if (arr[i][j] == 'B')
				by = i, bx = j;
		}
	}
	arr[ry][rx] = '.';
	arr[by][bx] = '.';
	move(ry, rx, by, bx);
	cout << res << '\n';
	return 0;
}