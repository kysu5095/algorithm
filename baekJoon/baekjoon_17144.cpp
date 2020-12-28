// 미세먼지 안녕! //
///////////////////

#include <iostream>
#include <vector>

using namespace std;

int sum = 0;
int r, c, t;
int arr[52][52];

class Point {
public:
	int x, y;
};
Point p[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
Point unclockD[4] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };	// 반시계 방향
Point clockD[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };		// 시계 방향
vector<Point> air;
vector<Point> warm;

void condition() {
	for (int i = 0; i < 2; i++) {
		int x = air[i].x + 1;
		int y = air[i].y;
		int res[3] = { 0, };

		if (i == 0) {	// 반시계 방향
			int direct = 0; // 방향
			res[0] = x; res[1] = y; res[2] = arr[y][x];
			arr[y][x] = 0;
			while (1) {
				int tmpX = res[0];
				int tmpY = res[1];
				int tmpV = res[2];
				int nx = tmpX + unclockD[direct % 4].x;
				int ny = tmpY + unclockD[direct % 4].y;

				if (nx < 0 || nx >= c || ny < 0) direct++; // 방향 바꿔주기
				nx = tmpX + unclockD[direct % 4].x;
				ny = tmpY + unclockD[direct % 4].y;
				
				if (arr[ny][nx] == -1) { // 종료 조건
					break;
				}
				res[0] = nx; res[1] = ny; res[2] = arr[ny][nx];
				arr[ny][nx] = tmpV;
			}
		}
		else {	// 시계 방향
			int direct = 0; // 방향
			res[0] = x; res[1] = y; res[2] = arr[y][x];
			arr[y][x] = 0;
			while (1) {
				int tmpX = res[0];
				int tmpY = res[1];
				int tmpV = res[2];
				int nx = tmpX + clockD[direct % 4].x;
				int ny = tmpY + clockD[direct % 4].y;

				if (nx < 0 || nx >= c || ny >= r) direct++; // 방향 바꿔주기
				nx = tmpX + clockD[direct % 4].x;
				ny = tmpY + clockD[direct % 4].y;
				
				if (arr[ny][nx] == -1) { // 종료 조건
					break;
				}
				res[0] = nx; res[1] = ny; res[2] = arr[ny][nx];
				arr[ny][nx] = tmpV;
			}
		}
	}
}

void spread(int time) {
	for (int i = 0; i < time; i++) {			// 몇 초 동안 작동할 것인가
		int arr2[52][52] = { {0, } };			// 미세먼지 임시 저장 배열
		arr2[air[0].y][air[0].x] = -1;
		arr2[air[1].y][air[1].x] = -1;
		int warmSize = warm.size();

		for (int j = 0; j < warmSize; j++) {	// 미세먼지 퍼트리기
			int warmCnt = 0;					// 퍼진 방향의 개수

			for (int k = 0; k < 4; k++) {		// 네 방향 확인
				int nx = warm[j].x + p[k].x;
				int ny = warm[j].y + p[k].y;

				if (nx >= 0 && nx < c && ny >= 0 && ny < r && arr[ny][nx] != -1) {
					arr2[ny][nx] += arr[warm[j].y][warm[j].x] / 5;
					warmCnt++;
				}
			}
			arr2[warm[j].y][warm[j].x] += arr[warm[j].y][warm[j].x] - ((arr[warm[j].y][warm[j].x] / 5) * warmCnt);
			///////////////// j번째 미세먼지 퍼트리기 완료
		}
		//cout << '\n';
		//cout << "공기청정기 작동전\n";
		warm.clear(); // 미세먼지 정보 초기화
		for (int j = 0; j < r; j++) {	// 퍼진 미세먼지 뿌리기
			for (int k = 0; k < c; k++) {
				arr[j][k] = arr2[j][k];
				//cout << arr[j][k] << " ";
			}
			//cout << '\n';
		}
		//cout << '\n';
		//cout << "공기청정기 작동후\n"; 
		condition(); // 공기청정기 작동
		for (int j = 0; j < r; j++) {	// 한칸 이동된 미세먼지 정보 저장
			for (int k = 0; k < c; k++) {
				if (arr[j][k] != 0 && arr[j][k] != -1) warm.push_back({ k, j });
				//cout << arr[j][k] << " ";
			}
			//cout << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) air.push_back({ j, i });
			if (arr[i][j] != 0 && arr[i][j] != -1) warm.push_back({ j, i });
		}
	}
	spread(t);

	for (int i = 0; i < warm.size(); i++) {
		sum += arr[warm[i].y][warm[i].x];
	}
	cout << sum << '\n';

	return 0;
}

// #include <iostream>
// #include <queue>

// using namespace std;

// int r, c, t;
// int arr[51][51];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };
// int clock_dir[4] = { 0, 2, 1, 3 };
// int uclock_dir[4] = { 0, 3, 1, 2 };
// pair<int, int> air[2];

// void aircondition(int tmp[][51]) {
// 	for (int i = 0; i < r; i++)
// 		for (int j = 0; j < c; j++)
// 			arr[i][j] = tmp[i][j];
// 	int y = air[0].first;
// 	int x = air[0].second;
// 	int d = 0;
// 	y += dy[uclock_dir[d]];
// 	x += dx[uclock_dir[d]];
// 	arr[y][x] = 0;
// 	int ny, nx;
// 	while (true) {
// 		ny = y + dy[uclock_dir[d]];
// 		nx = x + dx[uclock_dir[d]];
// 		if (ny < 0 || ny == r || nx < 0 || nx == c) {
// 			d++;
// 			ny = y + dy[uclock_dir[d]];
// 			nx = x + dx[uclock_dir[d]];
// 		}
// 		if (ny == air[0].first && nx == air[0].second) break;
// 		arr[ny][nx] = tmp[y][x];
// 		y = ny;
// 		x = nx;
// 	}

// 	y = air[1].first;
// 	x = air[1].second;
// 	d = 0;
// 	y += dy[clock_dir[d]];
// 	x += dx[clock_dir[d]];
// 	arr[y][x] = 0;
// 	while (true) {
// 		ny = y + dy[clock_dir[d]];
// 		nx = x + dx[clock_dir[d]];
// 		if (ny < 0 || ny == r || nx < 0 || nx == c) {
// 			d++;
// 			ny = y + dy[clock_dir[d]];
// 			nx = x + dx[clock_dir[d]];
// 		}
// 		if (ny == air[1].first && nx == air[1].second) break;
// 		arr[ny][nx] = tmp[y][x];
// 		y = ny;
// 		x = nx;
// 	}
// }

// void spread() {
// 	queue<pair<int, int>> q;
// 	for (int i = 0; i < r; i++)
// 		for (int j = 0; j < c; j++)
// 			if (arr[i][j] > 0)
// 				q.push(make_pair(i, j));
// 	int tmp[51][51] = { {0,}, };
// 	tmp[air[0].first][air[0].second] = -1;
// 	tmp[air[1].first][air[1].second] = -1;

// 	int y, x, ny, nx, val, cnt;
// 	while (!q.empty()) {
// 		y = q.front().first;
// 		x = q.front().second;
// 		q.pop();
// 		cnt = 0;
// 		for (int i = 0; i < 4; i++) {
// 			ny = y + dy[i];
// 			nx = x + dx[i];
// 			if (ny < 0 || ny == r || nx < 0 || nx == c || tmp[ny][nx] == -1) continue;
// 			cnt++;
// 		}
// 		if (!cnt) continue;
// 		val = arr[y][x] / 5;
// 		tmp[y][x] = tmp[y][x] + (arr[y][x] - (val * cnt));
// 		if (!val) continue;
// 		for (int i = 0; i < 4; i++) {
// 			ny = y + dy[i];
// 			nx = x + dx[i];
// 			if (ny < 0 || ny == r || nx < 0 || nx == c || tmp[ny][nx] == -1) continue;
// 			tmp[ny][nx] += val;
// 		}
// 	}
// 	aircondition(tmp);
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int idx = 0;
// 	cin >> r >> c >> t;
// 	for (int i = 0; i < r; i++) {
// 		for (int j = 0; j < c; j++) {
// 			cin >> arr[i][j];
// 			if (arr[i][j] == -1) {
// 				air[idx].first = i;
// 				air[idx++].second = j;
// 			}
// 		}
// 	}
// 	while (t--) 
// 		spread();
// 	int res = 0;
// 	for (int i = 0; i < r; i++)
// 		for (int j = 0; j < c; j++)
// 			if (arr[i][j] > 0)
// 				res += arr[i][j];
// 	cout << res << '\n';
// 	return 0;
// }