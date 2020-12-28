// 자외선을 피해 가기 //
//////////////////////

#include <iostream>
#include <string>

using namespace std;

int n;
int curSum = 10000001;
string str[101];
bool visited[101][101] = { {false, }, };

class Point {
public:
	int x, y;
};
Point p[4] = { {1, 0},{-1, 0},{0, 1},{0, -1} };

void dfs(int x, int y, int tmpSum) {
	tmpSum += (str[y][x] - '0');

	if (x == n - 1 && y == n - 1) {
		curSum = curSum > tmpSum ? tmpSum : curSum;
		return;
	}
	if (tmpSum > curSum) 
		return;

	for (int i = 0; i < 4; i++) {
		int nx = x + p[i].x;
		int ny = y + p[i].y;

		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx]) {
			visited[ny][nx] = true;
			dfs(nx, ny, tmpSum);
			visited[ny][nx] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	visited[0][0] = true;
	dfs(0, 0, 0);

	cout << curSum << '\n';

	return 0;
}