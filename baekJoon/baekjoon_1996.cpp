// 지뢰 찾기
// 4:40

#include <iostream>
#include <string.h>

using namespace std;

int n;
char arr[1001][1001];
char map[1001][1001];

class Point {
public:
	int y, x;
};
Point p[8] = { {-1 ,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ny, nx, val;
	memset(map, '0', sizeof(map));
	cin >> n;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != '.') {
				val = arr[i][j] - '0';
				map[i][j] = '*';
				for (int k = 0; k < 8; k++) {
					ny = i + p[k].y;
					nx = j + p[k].x;
					if (ny >= 0 && ny < n && nx >= 0 && nx < n && map[ny][nx] != '*' && map[ny][nx] != 'M') {
						if ((map[ny][nx] - '0') + val >= 10) map[ny][nx] = 'M';
						else map[ny][nx] = (((map[ny][nx] - '0') + val) + '0');
					}
				}
			}
		}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}