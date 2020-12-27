// 상범 빌딩
// 9:35

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int f, r, c, res;
char arr[31][31][31];
bool visited[31][31][31];

class Point {
public:
	int l, y, x;
};
Point p[6] = { {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0} };

int bfs(int _sl, int _sy, int _sx) {
	queue<Point> q;
	q.push({ _sl, _sy, _sx });
	visited[_sl][_sy][_sx] = true;
	int l, y, x, nl, ny, nx, len, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			l = q.front().l;
			y = q.front().y;
			x = q.front().x;
			q.pop();
			for (int i = 0; i < 6; i++) {
				nl = l + p[i].l;
				ny = y + p[i].y;
				nx = x + p[i].x;
				if (nl >= 0 && nl < f && ny >= 0 && ny < r && nx >= 0 && nx < c && !visited[nl][ny][nx] && (arr[nl][ny][nx] == '.' || arr[nl][ny][nx] == 'E')) {
					if (arr[nl][ny][nx] == 'E')
						return t;
					visited[nl][ny][nx] = true;
					q.push({ nl, ny, nx });
				}
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sl, sy, sx;
	while (true) {
		cin >> f >> r >> c;
		if (!f && !r && !c) break;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < f; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S')
						sl = i, sy = j, sx = k;
				}
			}
		}
		res = bfs(sl, sy, sx);
		if (!res) cout << "Trapped!\n";
		else cout << "Escaped in " << res << " minute(s).\n";
	}
	return 0;
}