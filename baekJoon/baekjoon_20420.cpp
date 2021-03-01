// 화살표 미로 (Normal)

#include <iostream>
#include <queue>

using namespace std;

int r, c, k;
char arr[51][51];
bool visited[51][51][151][151];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

class Point {
public:
	int y, x, L, R;
};

int get_direction(char& d) {
	if (d == 'U') return 0;
	else if (d == 'D') return 2;
	else if (d == 'L') return 1;
	return 3;
}

bool bfs() {
	queue<Point> q;
	q.push({ 0, 0, k, k });
	visited[0][0][k][k] = true;
	int y, x, ny, nx, L, R, nL, nR, d, nd;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		L = q.front().L;
		R = q.front().R;
		q.pop();

		d = get_direction(arr[y][x]);
		ny = y + dy[d];
		nx = x + dx[d];
		if (!(ny < 0 || ny == r || nx < 0 || nx == c || visited[ny][nx][L][R])) {
			if (ny == r - 1 && nx == c - 1) return true;
			q.push({ ny, nx, L, R });
			visited[ny][nx][L][R] = true;
		}
		
		nL = L;
		nd = d;
		for (int i = 0; i < 3; i++) {
			if (--nL < 0) break;
			nd = (nd + 1) % 4;
			ny = y + dy[nd];
			nx = x + dx[nd];
			if (ny < 0 || ny == r || nx < 0 || nx == c || visited[ny][nx][nL][R]) continue;
			if (ny == r - 1 && nx == c - 1) return true;
			q.push({ ny, nx, nL, R });
			visited[ny][nx][nL][R] = true;
		}

		nR = R;
		nd = d;
		for (int i = 0; i < 3; i++) {
			if (--nR < 0) break;
			nd = (nd + 3) % 4;
			ny = y + dy[nd];
			nx = x + dx[nd];
			if (ny < 0 || ny == r || nx < 0 || nx == c || visited[ny][nx][L][nR]) continue;
			if (ny == r - 1 && nx == c - 1) return true;
			q.push({ ny, nx, L, nR });
			visited[ny][nx][L][nR] = true;
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++)
		cin >> arr[i];
	if (bfs()) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}