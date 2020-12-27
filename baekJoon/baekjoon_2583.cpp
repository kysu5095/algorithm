// 영역 구하기
// 2:00

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k, t;
int arr[101][101] = { {0,}, };
bool visited[101][101] = { {false,}, };

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<int> v;

void dfs(int y, int x) {
	t++;
	visited[y][x] = true;
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + p[i].y;
		nx = x + p[i].x;
		if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && !arr[ny][nx])
			dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int y1, x1, y2, x2, res = 0;;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++)
			for (int k = x1; k < x2; k++)
				arr[j][k] |= 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!arr[i][j] && !visited[i][j]) {
				t = 0;
				dfs(i, j);
				v.push_back(t);
				res++;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << res << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << '\n';
	return 0;
}