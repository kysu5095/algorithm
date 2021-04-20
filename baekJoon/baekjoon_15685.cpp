// 드래콘 커브

#include <stdio.h>
#include <vector>

using namespace std;

int n;
bool arr[101][101];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
vector<int> v;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int y, x, d, g;
		scanf(" %d %d %d %d", &x, &y, &d, &g);
		arr[y][x] = true;
		y += dy[d];
		x += dx[d];
		arr[y][x] = true;
		v.push_back(d);
		int len;
		while (g--) {
			len = v.size();
			while (len--) {
				d = (v[len] + 1) % 4;
				y += dy[d];
				x += dx[d];
				arr[y][x] = true;
				v.push_back(d);
			}
		}
		v.clear();
	}
	int ret = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (arr[i][j] && arr[i + 1][j] && arr[i + 1][j + 1] && arr[i][j + 1])
				ret++;
	printf("%d\n", ret);
	return 0;
}