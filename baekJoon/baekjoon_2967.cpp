// 그리스-로마 건축

#include <iostream>
#include <algorithm>

using namespace std;

int r, c, cnt = 0, remain;
char arr[101][101];
int map[101][101];
bool visited[101][101] = { {false,}, };
pair<int, int> res[2];

bool promising(int& y, int& x, int& val) {
	for (int i = y; i < y + val; i++)
		for (int j = x; j < x + val; j++)
			if (arr[i][j] == '.')
				return false;

	return true;
}

int getMaxValue(int& y, int& x) {
	if (arr[y][x] == '.') return 0;
	int left = 0;
	int right = min(r - y, c - x);
	int mid, res;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (promising(y, x, mid)) {
			left = mid + 1;
			res = mid;
		}
		else right = mid - 1;
	}
	return res;
}

int fill_first() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j]) {
				for (int y = i; y < i + map[i][j]; y++)
					for (int x = j; x < j + map[i][j]; x++)
						visited[y][x] = true;
				res[0].first = i;
				res[0].second = j;
				return (map[i][j] * map[i][j]);
			}
		}
	}
}

void find_second() {
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (!map[y][x]) continue;
			int y1 = res[0].first, x1 = res[0].second;
			int y2 = y1 + map[y1][x1] - 1, x2 = x1 + map[y1][x1] - 1;
			int y3 = y, x3 = x;
			int y4 = y + map[y][x] - 1, x4 = x + map[y][x] - 1;
			int count = map[y][x] * map[y][x];
			if (!(x1 > x4 || x2 < x3 || y1 > y4 || y2 < y3)) {
				int left_y = max(y1, y3);
				int left_x = max(x1, x3);
				int right_y = min(y2, y4);
				int right_x = min(x2, x4);
				int height = right_y - left_y + 1;
				int width = right_x - left_x + 1;
				count -= (height * width);
			}
			if (remain - count == 0) {
				res[1].first = y;
				res[1].second = x;
				return;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> arr[i];
		for (int j = 0; j < c; j++)
			if (arr[i][j] == 'x')
				cnt++;
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			map[i][j] = getMaxValue(i, j);
	remain = fill_first();
	remain = cnt - remain;
	find_second();
	for (int i = 0; i < 2; i++) {
		int y = res[i].first;
		int x = res[i].second;
		cout << y + 1 << " " << x + 1 << " " << map[y][x] << '\n';
	}
	return 0;
}