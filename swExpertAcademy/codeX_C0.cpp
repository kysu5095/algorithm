// 로봇 //
/////////

#include <iostream>
#include <queue>

using namespace std;

int n, m; // 1~100이하 자연수
int arr[101][101]; // map 좌표
int visited[101][101][4] = { { {0, }, }, };

class Point {
public:
	int x, y, direct, sec; // direct : 방향, sec : 시간
};
Point p[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
queue<Point> q;

int bfs(int targetX, int targetY, int targetD) {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int direct = q.front().direct;
		int sec = q.front().sec;
		/////////////////////////////////
		///////   K칸 이동하기   /////////
		/////////////////////////////////
		int nx = x;
		int ny = y;

		for (int i = 1; i < 4; i++) {
			int tmpX = nx + p[direct].x;
			int tmpY = ny + p[direct].y;

			if (tmpX == targetX && tmpY == targetY && direct == targetD) {	// 종료조건 
				return sec + 1;
			}
			// Map 범위를 벗어나지 않고, 다음(K)칸이 0 이라면
			if (tmpX >= 0 && tmpX < m && tmpY >= 0 && tmpY < n && arr[tmpY][tmpX] == 0) {
				// 방문한 칸이라면 넘어감
				if (visited[tmpY][tmpX][direct] == 1) {
					nx = tmpX;
					ny = tmpY;
					continue;
				}
				//cout << "push " << i << "step  x : " << tmpX << "  y : " << tmpY << "  direct : " << direct << "  sec : " << sec + 1 << '\n';

				q.push({ tmpX, tmpY, direct, sec + 1 });
				visited[tmpY][tmpX][direct] = 1;
				nx = tmpX;
				ny = tmpY;
			}
			else
				break;
		}

		/////////////////////////////////
		///////   90도 회전하기   ////////
		/////////////////////////////////
		for (int i = 0; i < 2; i++) {
			int tmpDirect;
			if (i == 0) {	// 왼쪽 회전
				if (direct == 0) tmpDirect = 3;
				else if (direct == 1) tmpDirect = 2;
				else if (direct == 2) tmpDirect = 0;
				else if (direct == 3) tmpDirect = 1;
			}

			if (i == 1) {   // 오른쪽 회전
				if (direct == 0) tmpDirect = 2;
				else if (direct == 1) tmpDirect = 3;
				else if (direct == 2) tmpDirect = 1;
				else if (direct == 3) tmpDirect = 0;
			}

			if (x == targetX && y == targetY && tmpDirect == targetD) {	// 종료조건 
					//cout << "push direct  x : " << x << "  y : " << y << "  direct : " << tmpDirect << "  sec : " << sec + 1 << '\n';
				return sec + 1;

			}
			
			if (visited[y][x][tmpDirect] != 1) {
				q.push({ x, y, tmpDirect, sec + 1 });
				visited[y][x][tmpDirect] = 1;
			}
			// Map범위 확인하고, 회전한 다음칸이 0이며 방문하지 않았을 경우
			//int nx = x + p[tmpDirect].x;
			//int ny = y + p[tmpDirect].y;
			//if (nx >= 0 && nx < m && ny >= 0 && ny < n && arr[ny][nx] == 0 && visited[ny][nx][tmpDirect] != 1) {
			//	//cout << "push direct  x : " << x << "  y : " << y << "  direct : " << tmpDirect << "  sec : " << sec + 1 << '\n';
			//	q.push({ x, y, tmpDirect, sec + 1 });
			//}
		}

		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int tmpX, tmpY, tmpD;
	cin >> tmpY >> tmpX >> tmpD; // 현재 로봇 좌표와 방향 입력
	q.push({ tmpX - 1, tmpY - 1, tmpD - 1, 0 });
	visited[tmpY - 1][tmpX - 1][tmpD - 1] = 1;
	cin >> tmpY >> tmpX >> tmpD; // 목표 좌표와 방향 입력

	cout << bfs(tmpX - 1, tmpY - 1, tmpD - 1) << '\n';

	return 0;
}