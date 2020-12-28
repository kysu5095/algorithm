// 모노미노도미노

#include <iostream>

using namespace std;

int n, point = 0;
int arr[2][6][4];

/* 블럭 내리기 */
void down_arr(int idx) {
	int y;
	for (int i = 5; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (!arr[idx][i][j] || arr[idx][i][j] == 3) continue; /* 3은 2와 짝이어서 그냥 넘어감(2에서 처리해주기 때문) */
			if (arr[idx][i][j] == 1) {
				for (y = i + 1; y < 6; y++)
					if (arr[idx][y][j]) break;
				y--;
				arr[idx][i][j] = 0;
				arr[idx][y][j] = 1;
			}
			else { /* 2일 경우(1 * 2 block의 앞부분) */
				for (y = i + 1; y < 6; y++)
					if (arr[idx][y][j] || arr[idx][y][j + 1]) break;
				y--;
				arr[idx][i][j] = 0; arr[idx][i][j + 1] = 0;
				arr[idx][y][j] = 2; arr[idx][y][j + 1] = 3;
			}
		}
	}
}
/* 연한칸에 블럭이 존재하는지 판별 */
bool is_overflow(int idx) {
	bool flag1, flag2;
	flag1 = false; flag2 = false;
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 4; x++) {
			if (y == 0 && arr[idx][y][x]) flag1 = true;
			if (y == 1 && arr[idx][y][x]) flag2 = true;
		}
	}
	if (flag2) {
		for (int x = 0; x < 4; x++)
			arr[idx][5][x] = 0;
	}
	if (flag1) {
		for (int x = 0; x < 4; x++)
			arr[idx][4][x] = 0;
	}
	if (flag1 || flag2) return true;
	else return false;
}
/*  
// 행이 다 찬 곳이 있는지 검사
// 모든 행 지우고 배열을 내림
// 한번이라도 지운 행이 있다면(cnt==4) 다시 처음부터 검사(idx--)
*/
void is_full(int idx) {
	int cnt;
	bool flag = false;
	for (int y = 5; y >= 0; y--) {
		cnt = 0;
		for (int x = 0; x < 4; x++)
			if (arr[idx][y][x]) cnt++;

		if (cnt == 4) {
			flag = true;
			point++;
			for (int x = 0; x < 4; x++)
				arr[idx][y][x] = 0;
		}
	}
	if (flag) {
		down_arr(idx);
		is_full(idx);
	}
}
/* 1 * 1 block */
void down_1_1(int x, int idx) {
	int y = 0;
	while (true) {
		if (arr[idx][y][x]) {
			arr[idx][y - 1][x] = 1;
			break;
		}
		if (y == 5) {
			arr[idx][y][x] = 1;
			break;
		}
		y++;
	}
}
/* 1 * 2 block */
void down_1_2(int x, int idx) {
	int y = 0, _x = x + 1;
	while (true) {
		if (arr[idx][y][x] || arr[idx][y][_x]) {
			arr[idx][y - 1][x] = 2;
			arr[idx][y - 1][_x] = 3;
			break;
		}
		if (y == 5) {
			arr[idx][y][x] = 2;
			arr[idx][y][_x] = 3;
			break;
		}
		y++;
	}
}
/* 2 * 1 block */
void down_2_1(int x, int idx) {
	int y = 0;
	while (true) {
		if (arr[idx][y][x]) {
			arr[idx][y - 1][x] = 1;
			arr[idx][y - 2][x] = 1;
			break;
		}
		if (y == 5) {
			arr[idx][y][x] = 1;
			arr[idx][y - 1][x] = 1;
			break;
		}
		y++;
	}
}

void print() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[0][i][j] << " ";
		}
		cout << "   ";
		for (int j = 0; j < 4; j++) {
			cout << arr[1][i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int y, x, t;
	cin >> n;
	while (n--) {
		cin >> t >> y >> x;
		if (t == 1) {	   /* 1x1 block */
			down_1_1(x, 0);
			down_1_1(y, 1);
		}
		else if (t == 2) { /* 1*2 block */
			down_1_2(x, 0);
			down_2_1(y, 1);
		}
		else {			   /* 2*1 block */
			down_2_1(x, 0);
			down_1_2(y, 1);
		}
		is_full(0); /* 행이 꽉찬 경우가 있는지 */
		is_full(1); /* 행이 꽉찬 경우가 있는지 */
		if (is_overflow(0)) { /* 연한칸에 블럭이 있는지 */
			down_arr(0);		 /* 있다면 내리고 행 검사 */
			is_full(0);
		}
		if (is_overflow(1)) { /* 연한칸에 블럭이 있는지 */
			down_arr(1);		 /* 있다면 내리고 행 검사 */
			is_full(1);
		}
		//print();
	}
	int cnt = 0;
	for (int idx = 0; idx < 2; idx++)
		for (int y = 0; y < 6; y++)
			for (int x = 0; x < 4; x++)
				if (arr[idx][y][x])
					cnt++;
	cout << point << '\n';
	cout << cnt << '\n';
	return 0;
}