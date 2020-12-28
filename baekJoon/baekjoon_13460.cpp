// 구슬 탈출2 //
///////////////

#include <iostream>
#include <queue>

using namespace std;

int n, m;
char arr[11][11];
class Cordinate {
public:
	int x, y;
};
Cordinate p[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

class Point {
public:
	int rx, ry, bx, by, cnt;
};
queue<Point> bead;

int move(Point& tmp, int d) {
	int ry = tmp.ry;
	int rx = tmp.rx;
	int by = tmp.by;
	int bx = tmp.bx;
	tmp.cnt += 1;
	int rFlag = 0, bFlag = 0;

	if ((arr[ry][rx] == 'O' || arr[by][bx] == 'O')) return 0;

	while (true) {
		// 둘 다 벽일경우
		if ((arr[tmp.ry + p[d].y][tmp.rx + p[d].x] == '#' && arr[tmp.by + p[d].y][tmp.bx + p[d].x] == '#')) break;
		// 구멍인지 확인
		if (arr[tmp.ry + p[d].y][tmp.rx + p[d].x] == 'O') rFlag = 1;
		if (arr[tmp.by + p[d].y][tmp.bx + p[d].x] == 'O') bFlag = 1;
		// 다음칸이 벽인지 확인
		if (arr[tmp.ry + p[d].y][tmp.rx + p[d].x] != '#') {
			tmp.ry += p[d].y;
			tmp.rx += p[d].x;
		}
		if (arr[tmp.by + p[d].y][tmp.bx + p[d].x] != '#') {
			tmp.by += p[d].y;
			tmp.bx += p[d].x;
		}
	}
	// 겹칠 경우
	if (tmp.ry == tmp.by && tmp.rx == tmp.bx) {
		switch (d)
		{
		case 0 : // 오른쪽
			if (rx > bx)
				tmp.bx -= 1;
			else 
				tmp.rx -= 1;
			break;
		case 1:  // 왼쪽
			if (rx > bx)
				tmp.rx += 1;
			else
				tmp.bx += 1;
			break;
		case 2:  // 아래쪽
			if (ry > by)
				tmp.by -= 1;
			else
				tmp.ry -= 1;
			break;
		case 3:  // 위쪽
			if (ry > by)
				tmp.ry += 1;
			else
				tmp.by += 1;
			break;
		default:
			break;
		}
	}
	// 움직이지 않은 경우
	if (ry == tmp.ry && rx == tmp.rx && by == tmp.by && bx == tmp.bx)
		return 0;
	if (bFlag == 1) return 0;
	if (rFlag == 1) return 2;
	return 1;
}

int bfs() {
	while (!bead.empty()) {
		for (int i = 0; i < 4; i++) {
			Point tmp = bead.front();
			if (tmp.cnt >= 10) return -1;
			int jud = move(tmp, i);
			if (jud == 1) bead.push(tmp);
			if (jud == 2) return tmp.cnt;
		}
		bead.pop();
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int rx, ry, bx, by;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i][j];
			if (arr[i][j] == 'R') {
				rx = j;
				ry = i;
				arr[i][j] = '.';
			}
			if (arr[i][j] == 'B') {
				bx = j;
				by = i;
				arr[i][j] = '.';
			}
		}
	}
	bead.push({ rx, ry, bx, by, 0 });
	cout << bfs() << '\n';

	return 0;
}
// // 구슬 탈출2 //
// ///////////////

// #include <iostream>
// #include <queue>

// using namespace std;

// int n, m;
// char arr[11][11];
// class Cordinate {
// public:
// 	int x, y;
// };
// Cordinate p[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

// class Point {
// public:
// 	int rx, ry, bx, by, cnt;
// };
// queue<Point> bead;

// int move(Point& tmp, int d) {
// 	int rx = tmp.rx + p[d].x;
// 	int ry = tmp.ry + p[d].y;
// 	int bx = tmp.bx + p[d].x;
// 	int by = tmp.by + p[d].y;
// 	int cnt = tmp.cnt;
// 	int rFlag = 0, bFlag = 0, rMeet = 0, bMeet = 0;

// 	while (true) {
// 		rFlag = 0, bFlag = 0;
// 		// 둘 다 벽일경우
// 		if (arr[ry][rx] == '#' && arr[by][bx] == '#') break;
// 		// 구멍인지 확인
// 		if (arr[ry][rx] == 'O') rFlag = 1;
// 		if (arr[by][bx] == 'O') bFlag = 1;
// 		// 벽도 아니고 겹치지도 않으면 이동
// 		if (arr[ry][rx] != '#' && (ry != by || rx != bx) && rMeet != 1) {
// 			ry += p[d].y;
// 			rx += p[d].x;
// 		}
// 		if (arr[by][bx] != '#' && (ry != by || rx != bx) && bMeet != 1) {
// 			by += p[d].y;
// 			bx += p[d].x;
// 		}
// 		// 다음칸이 벽인지 확인
// 		if (arr[ry][rx] == '#') {
// 			ry -= p[d].y;
// 			rx -= p[d].x;
// 			rMeet = 1;
// 		}
// 		if (arr[by][bx] == '#') {
// 			by -= p[d].y;
// 			bx -= p[d].x;
// 			bMeet = 1;
// 		}
// 		// 겹치면 끝
// 		if (ry == by && rx == bx) break;
// 	}
// 	tmp.rx = rx;
// 	tmp.ry = ry;
// 	tmp.bx = bx;
// 	tmp.by = by;
// 	tmp.cnt = cnt + 1;

// 	if (bFlag == 1) return 2;
// 	if (rFlag == 1) return 1;
// 	return 0;
// }

// int bfs() {
// 	while (!bead.empty()) {
// 		for (int i = 0; i < 4; i++) {
// 			Point tmp = bead.front();
// 			if (tmp.cnt > 10) return -1;
// 			int jud = move(tmp, i);
// 			if (jud == 0) bead.push(tmp);
// 			if (jud == 1) return tmp.cnt;
// 		}
// 		bead.pop();
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

// 	int rx, ry, bx, by;
// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		cin >> arr[i];
// 		for (int j = 0; j < m; j++) {
// 			arr[i][j] = arr[i][j];
// 			if (arr[i][j] == 'R') {
// 				rx = j;
// 				ry = i;
// 				arr[i][j] = '.';
// 			}
// 			if (arr[i][j] == 'B') {
// 				bx = j;
// 				by = i;
// 				arr[i][j] = '.';
// 			}
// 		}
// 	}
// 	bead.push({ rx, ry, bx, by, 1 });
// 	cout << bfs() << '\n';

// 	return 0;
// }

// // 구슬 탈출 2

// #include <iostream>
// #include <queue>

// using namespace std;

// int n, m;
// char arr[11][11];
// int dy[4] = { 0, 0, 1, -1 };v
// int dx[4] = { 1, -1, 0, 0 };

// int bfs(int _ry, int _rx, int _by, int _bx) {
// 	queue<pair<pair<int, int>, pair<int, int>>> q;
// 	q.push(make_pair(make_pair(_ry, _rx), make_pair(_by, _bx)));
// 	int ry, rx, by, bx, len, sec = 1;
// 	int nry, nrx, nby, nbx;
// 	bool rflag, bflag;
// 	while (!q.empty()) {
// 		len = q.size();
// 		while (len--) {
// 			ry = q.front().first.first;
// 			rx = q.front().first.second;
// 			by = q.front().second.first;
// 			bx = q.front().second.second;
// 			q.pop();
// 			for (int i = 0; i < 4; i++) {
// 				nry = ry; nrx = rx;
// 				nby = by; nbx = bx;
// 				rflag = false; bflag = false;
// 				while (true) {
// 					nry += dy[i]; nrx += dx[i];
// 					if (arr[nry][nrx] == '#') {
// 						nry -= dy[i]; nrx -= dx[i];
// 						break;
// 					}
// 					if (arr[nry][nrx] == 'O') {
// 						rflag = true;
// 						break;
// 					}
// 				}
// 				while (true) {
// 					nby += dy[i]; nbx += dx[i];
// 					if (arr[nby][nbx] == '#') {
// 						nby -= dy[i]; nbx -= dx[i];
// 						break;
// 					}
// 					if (arr[nby][nbx] == 'O') {
// 						bflag = true;
// 						break;
// 					}
// 				}
// 				if (bflag) continue;
// 				if (rflag) return sec;
// 				if (nry == nby && nrx == nbx) {
// 					if (i == 0) {
// 						if (rx < bx) nrx -= dx[i];
// 						else nbx -= dx[i];
// 					}
// 					else if (i == 1) {
// 						if (rx < bx) nbx -= dx[i];
// 						else nrx -= dx[i];
// 					}
// 					else if (i == 2) {
// 						if (ry < by) nry -= dy[i];
// 						else nby -= dy[i];
// 					}
// 					else {
// 						if (ry < by) nby -= dy[i];
// 						else nry -= dy[i];
// 					}
// 				}
// 				if (nry == ry && nrx == rx && nby == by && nbx == bx) continue;
// 				q.push(make_pair(make_pair(nry, nrx), make_pair(nby, nbx)));
// 			}
// 		}
// 		if (sec == 10) break;
// 		sec++;
// 	}
// 	return -1;
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int ry, rx, by, bx;
// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++) {
// 		cin >> arr[i];
// 		for (int j = 0; j < m; j++) {
// 			if (arr[i][j] == 'R') { ry = i; rx = j; }
// 			if (arr[i][j] == 'B') { by = i; bx = j; }
// 		}
// 	}
// 	cout << bfs(ry, rx, by, bx) << '\n';
// 	return 0;
// }