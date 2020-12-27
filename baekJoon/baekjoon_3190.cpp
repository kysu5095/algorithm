// 뱀
// 11:40

#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int n, k, l;
int arr[101][101] = { {0,}, };

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
queue<pair<int, char>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int y, x, d, t = 0;
	char c;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		arr[y - 1][x - 1] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> y >> c;
		q.push(make_pair(y, c));
	}
	deque<pair<int, int>> dq;
	dq.push_back(make_pair(0, 0));
	arr[0][0] = 9;
	int tt = q.front().first;
	char command = q.front().second;
	q.pop();

	y = 0, x = 0, d = 0;
	while (true) {
		t++;
		y += p[d].y;
		x += p[d].x;
		if (y < 0 || y == n || x < 0 || x == n) break;
		if (arr[y][x] == 1) {
			dq.push_back(make_pair(y, x));
			arr[y][x] = 9;
		}
		else if (arr[y][x] == 0) {
			dq.push_back(make_pair(y, x));
			arr[y][x] = 9;
			arr[dq.front().first][dq.front().second] = 0;
			dq.pop_front();
		}
		else if (arr[y][x] == 9) break;

		if (t == tt) {
			// L : (0 > 3) (1 > 2) (2 > 0) (3 > 1)
			// R : (0 > 2) (1 > 3) (2 > 1) (3 > 0)
			if (command == 'L') {
				switch (d){
				case 0: d = 3; break;
				case 1: d = 2; break;
				case 2: d = 0; break;
				case 3: d = 1; break;
				}
			}
			else {
				switch (d) {
				case 0: d = 2; break;
				case 1: d = 3; break;
				case 2: d = 1; break;
				case 3: d = 0; break;
				}
			}
			if (!q.empty()) {
				tt = q.front().first;
				command = q.front().second;
				q.pop();
			}
		}
	}

	cout << t << '\n';
	return 0;
}

// #include <iostream>
// #include <deque>

// using namespace std;

// int n, k;
// int arr[101][101];
// char command[10001];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	char input;
// 	int y, x, val;
// 	cin >> n;
// 	cin >> k;
// 	for (int i = 0; i < k; i++) {
// 		cin >> y >> x;
// 		arr[y - 1][x - 1] = -1;
// 	}
// 	cin >> k;
// 	for (int i = 0; i < k; i++) {
// 		cin >> val >> input;
// 		command[val] = input;
// 	}
// 	arr[0][0] = 1;
// 	int sec = 1;
// 	int d = 0;
// 	int ny, nx;
// 	deque<pair<int, int>> dq;
// 	dq.push_back(make_pair(0, 0));
// 	while (true) {
// 		y = dq.back().first;
// 		x = dq.back().second;
// 		ny = y + dy[d];
// 		nx = x + dx[d];
// 		if (ny < 0 || ny == n || nx < 0 || nx == n) break;
// 		if (arr[ny][nx] == 1) break;
// 		dq.push_back(make_pair(ny, nx));
// 		if (arr[ny][nx] != -1) {
// 			arr[dq.front().first][dq.front().second] = 0;
// 			dq.pop_front();
// 		}
// 		arr[ny][nx] = 1;
// 		if (command[sec] == 'L') {
// 			if (d == 0) d = 3;
// 			else if (d == 1) d = 2;
// 			else if (d == 2) d = 0;
// 			else d = 1;
// 		}
// 		if (command[sec] == 'D') {
// 			if (d == 0) d = 2;
// 			else if (d == 1) d = 3;
// 			else if (d == 2) d = 1;
// 			else d = 0;
// 		}
// 		sec++;
// 	}
// 	cout << sec << '\n';
// 	return 0;
// }