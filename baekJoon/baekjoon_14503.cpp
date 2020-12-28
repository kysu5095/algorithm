// 로봇 청소기 //
////////////////

#include <iostream>
#include <vector>

using namespace std;

int n, m;
int vaccumCnt = 0;
int arr[51][51];

class Point {
public:
	int x, y, direct;
};
Point p[4] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
vector<Point> vaccum;

void cleaning(int x, int y, int direct, int cleanCnt, bool jud) { // direct = 방향
	/////////////
	// 종료조건 //
	/////////////
	if (jud) {
		vaccumCnt++;
		arr[y][x] = 9; // 청소
	}
	
	int nx = x + p[(direct + 3) % 4].x;
	int ny = y + p[(direct + 3) % 4].y;
	if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
		if (arr[ny][nx] == 0) { // 청소X
			cleaning(nx, ny, (direct + 3) % 4, 0, true);
		}
		if (arr[ny][nx] == 9) { // 청소O
			cleaning(x, y, (direct + 3) % 4, cleanCnt + 1, false);
		}
		if (arr[ny][nx] == 1 || cleanCnt == 4) { // 벽 or 네 방향 모두 청소 완료
			int tmpX = x + p[(direct + 2) % 4].x;
			int tmpY = y + p[(direct + 2) % 4].y;

			if (tmpX >= 0 && tmpX < m && tmpY >= 0 && tmpY < n && arr[tmpY][tmpX] != 1) {
				cleaning(tmpX, tmpY, direct, 0, false);
			}
			else return;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x, y, direct;
	cin >> n >> m >> x >> y >> direct;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	vaccum.push_back({ x, y, direct });
	cleaning(x, y, direct, 0, true);

	cout << vaccumCnt << '\n';

	return 0;
}

// #include<iostream>

// using namespace std;

// int n, m, clean_cnt = 0;
// int arr[51][51] = { {0, }, };
// class Point {
// public:
// 	int y, x, d;
// };
// Point p[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
// Point robot;

// void print() {
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			cout << arr[i][j] << " ";
// 		}
// 		cout << '\n';
// 	}
// 	cout << '\n';
// }

// void clean() {
// 	bool jud = true;
// 	int cnt = 0;
// 	while (true) {
// 		int x = robot.x;
// 		int y = robot.y;
// 		int d = robot.d;
// 		//cout << y << "  " << x << "  " << d << '\n';

// 		if (jud) {
// 			arr[y][x] = 9;
// 			clean_cnt++;
// 		}
// 		// 현재 방향의 왼쪽을 봄
// 		int nx = x + p[(d + 3) % 4].x;
// 		int ny = y + p[(d + 3) % 4].y;
// 		if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
// 			// 청소 가능
// 			if (arr[ny][nx] == 0) {
// 				robot.x = nx;
// 				robot.y = ny;
// 				robot.d = (d + 3) % 4;
// 				jud = true;
// 				cnt = 0;
// 				continue;
// 			}
// 			// 사방이 청소되어 있거나 벽일 경우
// 			if (cnt == 4) {
// 				// 바라본 방향의 뒤쪽으로 이동
// 				nx = x + p[(d + 2) % 4].x;
// 				ny = y + p[(d + 2) % 4].y;
// 				if (arr[ny][nx] != 1) {
// 					robot.x = nx;
// 					robot.y = ny;
// 					jud = false;
// 					cnt = 0;
// 					continue;
// 				}
// 				else
// 					break;
// 			}
// 			// 청소되어 있을경우
// 			robot.d = (d + 3) % 4;
// 			jud = false;
// 			cnt += 1;
// 			continue;
// 		}
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int x, y, d;
// 	cin >> n >> m;
// 	cin >> robot.y >> robot.x >> robot.d;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			cin >> arr[i][j];
// 		}
// 	}
// 	clean();
// 	cout << clean_cnt << '\n';

// 	return 0;
// }

// 로봇 청소기
// 5:50

// #include <iostream>

// using namespace std;

// int n, m, t = 0;
// int arr[51][51];
// bool visited[51][51] = { false };

// class Point {
// public:
// 	int y, x;
// };
// Point p[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int y, x, d, ny, nx, nd, rotate;
// 	bool flag = true;
// 	cin >> n >> m;
// 	cin >> y >> x >> d;
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < m; j++)
// 			cin >> arr[i][j];

// 	while (flag) {
// 		rotate = 0;
// 		if (!arr[y][x]) {
// 			arr[y][x] = 2;
// 			t++;
// 		}

// 		// (0 > 3 > 2 >> 1 >> 0)
// 		for (int i = 0; i < 4; i++) {
// 			d = (d + 3) % 4;
// 			ny = y + p[d].y;
// 			nx = x + p[d].x;
// 			if(!arr[ny][nx]){
// 				y = ny;
// 				x = nx;
// 				break;
// 			}
// 		// (0 > 2) (1 > 3)
// 			if (i == 3) {
// 				nd = (d + 2) % 4;
// 				y += p[nd].y;
// 				x += p[nd].x;
// 				if (arr[y][x] == 1) 
// 					flag = false;
// 				break;
// 			}
// 		}
// 	}
// 	cout << t << '\n';
// 	return 0;
// }

// #include <iostream>

// using namespace std;

// int n, m, cnt = 0;
// int arr[51][51];
// int dy[4] = { -1, 0, 1, 0 };
// int dx[4] = { 0, 1, 0, -1 };

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int y, x, d;
// 	cin >> n >> m;
// 	cin >> y >> x >> d;
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < m; j++)
// 			cin >> arr[i][j];
// 	int ny, nx, nd, tmpd;
// 	bool flag = true, game = true;
// 	while (game) {
// 		if (flag) {
// 			arr[y][x] = 9;
// 			cnt++;
// 		}
// 		tmpd = d;
// 		for (int i = 0; i < 4; i++) {
// 			nd = (tmpd + 3) % 4;
// 			ny = y + dy[nd];
// 			nx = x + dx[nd];
// 			if (arr[ny][nx] == 0) {
// 				y = ny;
// 				x = nx;
// 				d = nd;
// 				flag = true;
// 				break;
// 			}
// 			if (i == 3) {
// 				nd = (d + 2) % 4;
// 				y += dy[nd];
// 				x += dx[nd];
// 				flag = false;
// 				if (arr[y][x] == 1) game = false;
// 				break;
// 			}
// 			tmpd = nd;
// 		}
// 	}
// 	cout << cnt << '\n';
// 	return 0;
// }