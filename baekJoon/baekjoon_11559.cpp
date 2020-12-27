// Puyo Puyo

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int res;
char arr[12][6];
bool visited[12][6] = { {false, }, };

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<Point> puyo;

void print() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}

bool bfs(int _y, int _x) {
	puyo.push_back({ _y, _x });
	queue<Point> q;
	q.push({ _y, _x });
	visited[_y][_x] = true;
	int y, x, ny, nx;
	char val = arr[_y][_x];
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny >= 0 && ny < 12 && nx >= 0 && nx < 6 && arr[ny][nx] == val && !visited[ny][nx]) {
				puyo.push_back({ ny, nx });
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}
	if (puyo.size() >= 4) return true;
	else return false;
}

void falling() {
	int len = puyo.size();
	for (int i = 0; i < len; i++)
		arr[puyo[i].y][puyo[i].x] = '.';

	int i, idx;
	for (int j = 0; j < 6; j++) {
		i = 12;
		idx = 11;
		while (i--) {
			if (arr[i][j] != '.') {
				if (i != idx) {
					arr[idx][j] = arr[i][j];
					arr[i][j] = '.';
				}
				idx--;
			}
		}
	}
}

bool find_puyo() {
	bool flag = true;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (!visited[i][j] && arr[i][j] != '.') {
				puyo.clear();
				if (bfs(i, j)) {
					falling();
					flag = false;
				}
			}
		}
	}
	if (!flag) return false;
	else return true;
}

void run() {
	while (true) {
		if (find_puyo()) break;
		memset(visited, false, sizeof(visited));
		res++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	res = 0;
	for (int i = 0; i < 12; i++)
		cin >> arr[i];
	run();
	cout << res << '\n';
	return 0;
}