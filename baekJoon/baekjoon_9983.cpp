// 더 푸르게

#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>
#include <vector>

using namespace std;

int w, h, res;
char arr[11][11];
int dy[3][8] = { {0, 0, 1, -1}, 
			     {-1, -1, 1, 1 }, 
			     {-1, -2, -2, -1, 1, 2, 2, 1} };
int dx[3][8] = { {1, -1, 0, 0 }, 
				 {-1, 1, 1, -1}, 
				 {-2, -1, 1, 2, 2, 1, -1, -2} };
vector<pair<int, int>> v;

bool King(int y, int x) {
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[0][i];
		nx = x + dx[0][i];
		if (ny < 0 || ny == h || nx < 0 || nx == w) continue;
		if (arr[ny][nx] != 'E') return false;
	}
	for (int i = 0; i < 4; i++) {
		ny = y + dy[1][i];
		nx = x + dx[1][i];
		if (ny < 0 || ny == h || nx < 0 || nx == w) continue;
		if (arr[ny][nx] != 'E') return false;
	}
	return true;
}

bool Queen(int y, int x) {
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y, nx = x;
		while (true) {
			ny += dy[0][i];
			nx += dx[0][i];
			if (ny < 0 || ny == h || nx < 0 || nx == w) break;
			if (arr[ny][nx] != 'E') return false;
		}
	}
	for (int i = 0; i < 4; i++) {
		ny = y, nx = x;
		while (true) {
			ny += dy[1][i];
			nx += dx[1][i];
			if (ny < 0 || ny == h || nx < 0 || nx == w) break;
			if (arr[ny][nx] != 'E') return false;
		}
	}
	return true;
}

bool Rook(int y, int x) {
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y, nx = x;
		while (true) {
			ny += dy[0][i];
			nx += dx[0][i];
			if (ny < 0 || ny == h || nx < 0 || nx == w) break;
			if (arr[ny][nx] != 'E') return false;
		}
	}
	return true;
}

bool Bishop(int y, int x) {
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y, nx = x;
		while (true) {
			ny += dy[1][i];
			nx += dx[1][i];
			if (ny < 0 || ny == h || nx < 0 || nx == w) break;
			if (arr[ny][nx] != 'E') return false;
		}
	}
	return true;
}

bool Knight(int y, int x) {
	int ny, nx;
	for (int i = 0; i < 8; i++) {
		ny = y + dy[2][i];
		nx = x + dx[2][i];
		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if (arr[ny][nx] != 'E') return false;
	}
	return true;
}

bool promising() {
	int y, x;
	bool flag;
	for (int i = 0; i < v.size(); i++) {
		y = v[i].first;
		x = v[i].second;
		if (arr[y][x] == 'E') continue;
		switch (arr[y][x])
		{
		case 'K':
			flag = King(y, x);
			break;
		case 'Q':
			flag = Queen(y, x);
			break;
		case 'R':
			flag = Rook(y, x);
			break;
		case 'B':
			flag = Bishop(y, x);
			break;
		case 'N':
			flag = Knight(y, x);
			break;
		}
		if (!flag) return false;
	}
	return true;
}

void removePieces(int idx, int del) {
	if (del >= res) return;
	if (idx == v.size()) {
		if (promising()) res = del;
		return;
	}
	int y = v[idx].first;
	int x = v[idx].second;
	char ch = arr[y][x];
	arr[y][x] = 'E';
	removePieces(idx + 1, del + 1);
	arr[y][x] = ch;
	removePieces(idx + 1, del);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string start, end;
	while (cin >> start) {
		res = INT_MAX;
		v.clear();
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] != 'E')
					v.push_back(make_pair(i, j));
			}
		}
		removePieces(0, 0);
		cout << "Minimum Number of Pieces to be removed: " << res << '\n';
		cin >> end;
	}
	return 0;
}