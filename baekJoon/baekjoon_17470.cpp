// 배열 돌리기 5

#include <stdio.h>
#include <algorithm>

int n, m, r;
int arr[101][101], res[101][101], tmp[51][51], tmp2[51][51];
struct Info {
	bool up_down, left_right;
	int rocation, rotation;
}state[4];

void _1_operator() { 
	for (int i = 0; i < 4; i++) {
		//state[i].up_down ^= true;
		(state[i].rotation & 1 ? state[i].left_right : state[i].up_down) ^= true;
		int& rocation = state[i].rocation;
		switch (rocation) {
		case 0:	rocation = 3; break;
		case 1:	rocation = 2; break;
		case 2:	rocation = 1; break;
		case 3:	rocation = 0; break;
		}
	}
}

void _2_operator() { 
	for (int i = 0; i < 4; i++) {
		//state[i].left_right ^= true;
		(state[i].rotation & 1 ? state[i].up_down : state[i].left_right) ^= true;
		int& rocation = state[i].rocation;
		switch (rocation) {
		case 0:	rocation = 1; break;
		case 1:	rocation = 0; break;
		case 2:	rocation = 3; break;
		case 3:	rocation = 2; break;
		}
	}
}

void _3_operator() {
	for (int i = 0; i < 4; i++) {
		state[i].rocation = (state[i].rocation + 1) % 4;
		state[i].rotation = (state[i].rotation + 1) % 4;
	}
}

void _4_operator() {
	for (int i = 0; i < 4; i++) {
		state[i].rocation = (state[i].rocation + 3) % 4;
		state[i].rotation = (state[i].rotation + 3) % 4;
	}
}

void _5_operator() {
	for (int i = 0; i < 4; i++) 
		state[i].rocation = (state[i].rocation + 1) % 4;
}

void _6_operator() {
	for (int i = 0; i < 4; i++) 
		state[i].rocation = (state[i].rocation + 3) % 4;
}

void copy_arr(int& idx) {
	int y, x;
	switch (idx) {
	case 0: y = 0, x = 0;      break;
	case 1: y = 0, x = m >> 1; break;
	case 2: y = n >> 1, x = m >> 1; break;
	case 3: y = n >> 1, x = 0;      break;
	}
	for (int i = 0; i < (n >> 1); i++)
		for (int j = 0; j < (m >> 1); j++)
			tmp[i][j] = arr[y + i][x + j];
}

void change_up_down(int& idx) {
	if (!state[idx].up_down) return;
	int _n = n >> 1;
	int _m = m >> 1;
	for (int i = 0; i < _n; i++)
		for (int j = 0; j < _m; j++)
			tmp2[i][j] = tmp[i][j];
	for (int i = 0; i < _n; i++)
		for (int j = 0; j < _m; j++)
			tmp[i][j] = tmp2[_n - 1 - i][j];
}

void change_left_right(int& idx) {
	if (!state[idx].left_right) return;
	int _n = n >> 1;
	int _m = m >> 1;
	for (int i = 0; i < _n; i++)
		for (int j = 0; j < _m; j++)
			tmp2[i][j] = tmp[i][j];
	for (int i = 0; i < _n; i++)
		for (int j = 0; j < _m; j++)
			tmp[i][j] = tmp2[i][_m - 1 - j];
}

void change_rotation(int& idx, int& cnt) {
	int _n = n >> 1;
	int _m = m >> 1;
	for (int _cnt = 0; _cnt < cnt; _cnt++) {
		for (int i = 0; i < _n; i++)
			for (int j = 0; j < _m; j++)
				tmp2[i][j] = tmp[i][j];
		for (int i = 0; i < _m; i++)
			for (int j = 0; j < _n; j++)
				tmp[i][j] = tmp2[_n - 1 - j][i];
		std::swap(_n, _m);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %d", &arr[i][j]);
	for (int i = 0; i < 4; i++) {
		state[i].left_right = false;
		state[i].up_down = false;
		state[i].rocation = i;
		state[i].rotation = 0;
	}
	for (int i = 0; i < r; i++) {
		int input;
		scanf(" %d", &input);
		switch (input) {
		case 1:	_1_operator(); break;
		case 2:	_2_operator(); break;
		case 3:	_3_operator(); break;
		case 4:	_4_operator(); break;
		case 5:	_5_operator(); break;
		case 6:	_6_operator(); break;
		}
	}
	for (int idx = 0; idx < 4; idx++) {
		copy_arr(idx);
		change_up_down(idx);
		change_left_right(idx);
		change_rotation(idx, state[idx].rotation);

		int y, x, _n, _m;

		if (state[idx].rotation % 2 == 0) _n = n >> 1, _m = m >> 1;
		else _n = m >> 1, _m = n >> 1;

		if (state[idx].rocation == 0) y = 0, x = 0;
		else if (state[idx].rocation == 1) y = 0, x = _m;
		else if (state[idx].rocation == 2) y = _n, x = _m;
		else y = _n, x = 0;

		for (int i = 0; i < _n; i++)
			for (int j = 0; j < _m; j++)
				res[i + y][j + x] = tmp[i][j];
	}

	if (state[0].rotation % 2) std::swap(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}