// 알파벳

#include <iostream>
#include <string>

using namespace std;

int r, c, res = 0;
string arr[21];
bool visited[27] = { false, };

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void dfs(int y, int x, int cnt) {
	visited[arr[y][x] - 'A'] = true;
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + p[i].y;
		nx = x + p[i].x;
		if (ny >= 0 && ny < r && nx >= 0 && nx < c && !visited[arr[ny][nx] - 'A']) {
			visited[arr[ny][nx] - 'A'] = true;
			dfs(ny, nx, cnt + 1);
			visited[arr[ny][nx] - 'A'] = false;
		}
	}
	res = res < cnt ? cnt : res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> arr[i];

	dfs(0, 0, 1);
	cout << res << '\n';
	return 0;
}