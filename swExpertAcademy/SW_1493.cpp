// 수의 새로운 연산

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class Point {
public:
	int x, y;
};

Point pointToCordi(int num) {
	int row = 1, sum = 0;
	Point p;
	while (true) {
		sum += row;
		if (num <= sum) break;
		row++;
	}
	int tmp = 1 + (row * (row - 1)) / 2;
	p.x = 1 + num - tmp;
	p.y = row - (num - tmp);
	return p;
}

int cordiToResult(int x, int y) {
	int row = x + y - 1;
	int val = 1 + (row * (row - 1)) / 2;
	return val + (x - 1);
}

int main() {
	int test_case, left, right;
	Point l, r;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		scanf(" %d %d", &left, &right);
		l = pointToCordi(left);
		r = pointToCordi(right);
		printf("#%d %d\n", tc, cordiToResult(l.x + r.x, l.y + r.y));
	}
	return 0;
}