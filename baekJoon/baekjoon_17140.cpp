// 이차원 배열과 연산 //
// for문 연산횟수 줄이기
// 회전행렬 다시 구하기(회전하는거 구해서 다시))
// map사용해보기
//////////////////////

#include <iostream>
#include <queue>

using namespace std;

int row, colum, k;
int maxR = 3, maxC = 3, sec = 0;
int arr[101][101] = { {0, }, };
int tmp[101][101] = { {0, }, };
int countArr[101] = { 0, };

class Point {
public:
	int num, cnt;

	bool operator < (const Point& p) const {
		if (this->cnt < p.cnt) return false;
		else if (this->cnt == p.cnt) {
			if (this->num < p.num) return false;
			else return true;
		}
		else return true;
	}
};
priority_queue<Point> pq;

void clearTmp() {
	for (int i = 0; i < 101; i++)
		countArr[i] = 0;
	while (!pq.empty())
		pq.pop();
}

void copyArrA() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			tmp[i][j] = arr[i][j];
			arr[i][j] = 0;
		}
	}
}

void copyArrB() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			arr[i][j] = tmp[i][j];
		}
	}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 101; j++) {
			int t = arr[i][j];
			arr[i][j] = arr[100 - i][j];
			arr[100 - i][j] = t;
		}
	}
}

void turnRight() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			tmp[j][100 - i] = arr[i][j];
			arr[i][j] = 0;
		}
	}
}

void turnLeft() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			tmp[100 - j][i] = arr[i][j];
		}
	}
}

void counting(int flag) {
	if (flag == 1) maxC = 0;
	else if (flag == 2) maxR = 0;

	for (int i = 0; i < 101; i++) {
		clearTmp();
		for (int j = 0; j < 101; j++) {
			countArr[tmp[i][j]]++;
		}
		for (int j = 1; j < 101; j++) {
			if (countArr[j] != 0)
				pq.push({ j, countArr[j] });
		}
		int cnt = 0;
		int size = pq.size() * 2;
		// R
		if (flag == 1)
			maxC = maxC < size ? size : maxC;
		// C
		else if (flag == 2)
			maxR = maxR < size ? size : maxR;

		while (!pq.empty()) {
			arr[i][cnt++] = pq.top().num;
			arr[i][cnt++] = pq.top().cnt;
			pq.pop();
		}
	}
}

void cal() {
	while (sec <= 100) {
		if (arr[row - 1][colum - 1] == k)
			return;
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				tmp[i][j] = 0;
			}
		}

		if (maxR >= maxC) {
			copyArrA();
			counting(1);
		}
		else {
			turnRight();
			counting(2);
			turnLeft();
			copyArrB();
		}
		sec++;
	}
	sec = -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> row >> colum >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	cal();
	cout << sec << '\n';

	return 0;
}