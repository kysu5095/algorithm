// 적록색약

#include <iostream>
#include <string.h>

using namespace std;

int n;
char arr[101][101];
bool visited[101][101];

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int ny, nx;

void dfs1(int y, int x, char color) {
	for (int i = 0; i < 4; i++) {
		ny = y + p[i].y;
		nx = x + p[i].x;
		if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && arr[ny][nx] == color) {
			visited[ny][nx] = true;
			dfs1(ny, nx, color);
		}
	}
	return;
}

void dfs2(int y, int x, char color) {
	for (int i = 0; i < 4; i++) {
		ny = y + p[i].y;
		nx = x + p[i].x;
		if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx]) {
			if (arr[ny][nx] != color && color == 'B') continue;
			if (color == 'R' || color == 'G') {
				if (arr[ny][nx] == 'B') continue;
			}
			visited[ny][nx] = true;
			dfs2(ny, nx, color);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a = 0, b = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				dfs1(i, j, arr[i][j]);
				a++;
			}
		}
	}

	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				dfs2(i, j, arr[i][j]);
				b++;
			}
		}
	}

	cout << a << " " << b << '\n';
	return 0;
}