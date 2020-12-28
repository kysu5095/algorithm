// 새로운 게임

#include <iostream>
#include <vector>

using namespace std;

int n, k, cnt = 1;
int arr[13][13];
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };
vector<int> v[13][13];
class Horse {
public:
	int y, x, d, floor;
};
Horse horse[11];

void button1(int& y, int& x, int& ny, int& nx) {
	int len = v[y][x].size();
	for (int j = 0; j < len; j++) {
		int num = v[y][x][j];
		horse[num].y = ny;
		horse[num].x = nx;
		horse[num].floor = v[ny][nx].size();
		v[ny][nx].push_back(num);
	}
	v[y][x].clear();
}

void button2(int& y, int& x, int& ny, int& nx) {
	int len = v[y][x].size();
	for (int j = len - 1; j >= 0; j--) {
		int num = v[y][x][j];
		horse[num].y = ny;
		horse[num].x = nx;
		horse[num].floor = v[ny][nx].size();
		v[ny][nx].push_back(num);
	}
	v[y][x].clear();
}

bool game() {
	int y, x, d, floor, ny, nx, num, len;
	while (true) {
		if (cnt > 1000) break;
		for (int i = 0; i < k; i++) {
			y = horse[i].y;
			x = horse[i].x;
			d = horse[i].d;
			floor = horse[i].floor;
			ny = y + dy[d];
			nx = x + dx[d];
			if (floor) continue;
			if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx] == 2) {
				if (d % 2 == 1) d++;
				else d--;
				horse[i].d = d;
				ny = y + dy[d];
				nx = x + dx[d];
				if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx] == 2) continue;
				else if (arr[ny][nx] == 0) button1(y, x, ny, nx);
				else button2(y, x, ny, nx);
			}
			else if (arr[ny][nx] == 0) button1(y, x, ny, nx);
			else button2(y, x, ny, nx);
			if (v[ny][nx].size() >= 4) return true;
		}
		cnt++;
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int y, x, d;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v[i][j].clear();
	for (int i = 0; i < k; i++) {
		cin >> y >> x >> d;
		horse[i].y = y - 1;
		horse[i].x = x - 1;
		horse[i].d = d;
		horse[i].floor = 0;
		v[y - 1][x - 1].push_back(i);
	}
	if (!game()) cnt = -1;
	cout << cnt << '\n';
	return 0;
}