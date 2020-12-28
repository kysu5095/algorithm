//  경사로  //
/////////////

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int n, l;   // 2 <= n <= 100,  1 <= l <= n
int route = 0;
int arr[101][101][2];
int arr2[101][101][2];

class Point {
public:
	int x, y;
};
Point p[2] = { {1, 0}, {0, 1} }; // 오른쪽 or 아래쪽만 이동 가능

void copyArr() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j][0] = arr2[i][j][0];
			arr[i][j][1] = arr2[i][j][1];
		}
	}
}

// 앞쪽에 벽 세우기
bool foreWall(int x, int y, int flag) {
	for (int i = 0; i < l; i++) {
		if (x + (p[flag].x * i) >= n || y + (p[flag].y * i) >= n) return false; // 범위초과
		if (arr[y][x][0] - arr[y + (p[flag].y * i)][x + (p[flag].x * i)][0] != 0) return false; // 높이 일정치 않음
	}
	// 해당칸에 경사로 있다는걸 저장
	for (int i = 0; i < l; i++) {
		arr[y + (p[flag].y * i)][x + (p[flag].x * i)][1] = 1;
	}

	return true;
}

// 뒷쪽에 벽 세우기
bool backWall(int x, int y, int flag) {
	for (int i = 0; i < l; i++) {
		if (x - (p[flag].x * i) < 0 || y - (p[flag].y * i) < 0) return false; // 범위초과
		if (arr[y - (p[flag].y * i)][x - (p[flag].x * i)][0] - arr[y][x][0] != 0) return false; // 높이 일정치 않음
		if (arr[y - (p[flag].y * i)][x - (p[flag].x * i)][1] == 1) return false; // 경사로 있음
	}
	return true;
}

// 가로 보기
bool inclineW(int cnt) {
	int flag = 0;
	int isIncline = 0;
	for (int i = 0; i < n - 1; i++) {
		if (abs(arr[cnt][i][0] - arr[cnt][i + 1][0]) > 1) return false; // 차이 2이상 return

		if (arr[cnt][i][0] - arr[cnt][i + 1][0] < 0) { // 뒷칸이 더 높을경우
			// 높이 일정치 않을경우
			if (!backWall(i, cnt, flag)) 
				return false;
		}

		else if (arr[cnt][i][0] - arr[cnt][i + 1][0] > 0) { // 앞칸이 더 높을경우
			if (foreWall(i + 1, cnt, flag)) {
				if (l == 1) continue;
				i += (l - 1);
			}
			// 높이 일정치 않을경우
			else
				return false;
		}
	}
	return true;
}

// 세로 보기
bool inclineH(int cnt) {
	int flag = 1;
	int isIncline = 0;
	for (int i = 0; i < n - 1; i++) {
		if (abs(arr[i][cnt][0] - arr[i + 1][cnt][0]) > 1) return false; // 차이 2이상 return

		if (arr[i][cnt][0] - arr[i + 1][cnt][0] < 0) { // 뒷칸이 더 높을경우
			// 높이 일정치 않을경우
			if (!backWall(cnt, i, flag))
				return false;
		}

		else if (arr[i][cnt][0] - arr[i + 1][cnt][0] > 0) { // 앞칸이 더 높을경우
			if (foreWall(cnt, i + 1, flag)) {
				if (l == 1) continue;
				i += (l - 1);
			}
			// 높이 일정치 않을경우
			else
				return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr2[i][j][0];
			arr2[i][j][1] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		copyArr();
		if (inclineW(i)) route++;
		copyArr();
		if (inclineH(i)) route++;
	}

	cout << route << '\n';

	return 0;
}