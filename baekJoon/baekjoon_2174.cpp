// 로봇 시뮬레이션
// 4:30

#include <iostream>

using namespace std;

int a, b, n, m, res = 0;
int error_n1, error_n2;
int arr[101][101] = { {0,}, };

class Point {
public:
	int y, x, d;
};
Point p[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
Point robot[101];

void print() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

bool move(int num, char rotate, int repeat) {
	while (repeat--) {
		int y = robot[num].y;
		int x = robot[num].x;
		int d = robot[num].d;
		int ny, nx;
		switch (rotate){
		case 'L':
			robot[num].d = (d + 3) % 4;
			break;
		case 'R':
			robot[num].d = (d + 1) % 4;
			break;
		case 'F':
			ny = y + p[d].y;
			nx = x + p[d].x;
			if (ny < 0 || ny == b || nx < 0 || nx == a) {
				res = 1;
				error_n1 = num + 1;
				return false;
			}
			if (arr[ny][nx]) {
				res = 2;
				error_n1 = num + 1;
				error_n2 = arr[ny][nx];
				return false;
			}
			arr[y][x] = 0;
			arr[ny][nx] = num + 1;
			robot[num].y = ny;
			robot[num].x = nx;
			break;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int y, x;
	char d;
	cin >> a >> b;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d;
		robot[i].y = b - y;
		robot[i].x = x - 1;
		switch (d){
		case 'E': robot[i].d = 0; break;
		case 'S': robot[i].d = 1; break;
		case 'W': robot[i].d = 2; break;
		case 'N': robot[i].d = 3; break;
		}
		arr[robot[i].y][robot[i].x] = i + 1;
	}
	bool flag = true;
	for (int i = 0; i < m; i++) {
		cin >> y >> d >> x;
		if (flag && !move(y - 1, d, x))
			flag = false;
	}
	if (!res) 
		cout << "OK\n";
	else if(res == 1)
		cout << "Robot " << error_n1 << " crashes into the wall\n";
	else if(res == 2) 
		cout << "Robot " << error_n1 << " crashes into robot " << error_n2 << '\n';
	return 0;
}