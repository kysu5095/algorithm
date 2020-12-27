// 단지번호붙이기
// 4:50

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[26][26];
bool visited[26][26] = { {false,}, };

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<int> v;

void bfs(int _y, int _x) {
	queue<pair<int, int>> q;
	q.push(make_pair(_y, _x));
	visited[_y][_x] = true;
	int y, x, ny, nx, cnt = 1;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && arr[ny][nx]) {
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
				cnt++;
			}
		}
	}
	v.push_back(cnt);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %1d", &arr[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] && !visited[i][j])
				bfs(i, j);

	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);
	return 0;
}