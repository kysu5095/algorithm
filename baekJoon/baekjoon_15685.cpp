// 드래곤 커브 //
////////////////

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, x, y, d, g;
int cnt = 0;
int arr[101][101] = { {0,}, };

class Point {
public:
	int x, y, direct;
};
Point p[4] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };

void square() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j] == 1 && arr[i + 1][j + 1] == 1) {
				cnt++;
			}
		}
	}
}

void dragon(stack<Point>& s) {
	stack<Point> tmp = s;
	int x = tmp.top().x;
	int y = tmp.top().y;
	int d = tmp.top().direct;

	while (!tmp.empty()) {
		d = (tmp.top().direct + 1) % 4;
		x += p[d].x;
		y += p[d].y;
		s.push({ x, y, d });
		tmp.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<Point> s;
		cin >> x >> y >> d >> g;
		arr[y][x] = 1;
		s.push({ x + p[d].x, y + p[d].y, d });
		for (int j = 0; j < g; j++) {
			dragon(s);
		}
		while (!s.empty()) {
			arr[s.top().y][s.top().x] = 1;
			s.pop();
		}
	}
	
	square();
	cout << cnt << '\n';

	return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int n;
// bool arr[101][101] = { {false,}, };
// int dy[4] = { 0, -1, 0, 1 };
// int dx[4] = { 1, 0, -1, 0 };

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n;
// 	int y, x, d, g;
// 	int nd, len;
// 	while (n--) {
// 		cin >> x >> y >> d >> g;
// 		arr[y][x] = true;
// 		y += dy[d];
// 		x += dx[d];
// 		arr[y][x] = true;
// 		vector<int> v;
// 		v.push_back(d);
// 		while (g--) {
// 			len = v.size();
// 			while (len--) {
// 				d = (v[len] + 1) % 4;
// 				y += dy[d];
// 				x += dx[d];
// 				arr[y][x] = true;
// 				v.push_back(d);
// 			}
// 		}
// 	}
// 	int res = 0;
// 	for (int i = 0; i < 100; i++) {
// 		for (int j = 0; j < 100; j++) {
// 			if (!arr[i][j]) continue;
// 			if (!arr[i][j + 1]) continue;
// 			if (!arr[i + 1][j + 1]) continue;
// 			if (!arr[i + 1][j]) continue;
// 			res++;
// 		}
// 	}
// 	cout << res << '\n';
// 	return 0;
// }