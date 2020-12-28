// 주사위 굴리기 //

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, x, y, k;
int arr[21][21] = { {0, }, };
int dice[6] = { 0, };

class Point {
public:
	int x, y;
};
Point p[4] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

bool outMap(int direct) {
	int nx = x + p[direct - 1].x;
	int ny = y + p[direct - 1].y;
	if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
		x = nx;
		y = ny;
		return true;
	}
	return false;
}

void checkMap() {
	if (arr[y][x] == 0) {
		arr[y][x] = dice[5];
	}
	else {
		dice[5] = arr[y][x];
		arr[y][x] = 0;
	}
}

void roll(int direct) {
	if (!outMap(direct)) return;

	int tmpDice[6];
	copy(dice, dice + 6, tmpDice);
	
	switch (direct)
	{
	// 동
	case 1:
		dice[0] = tmpDice[2];
		dice[2] = tmpDice[5];
		dice[3] = tmpDice[0];
		dice[5] = tmpDice[3];
		break;
	// 서
	case 2:
		dice[0] = tmpDice[3];
		dice[2] = tmpDice[0];
		dice[3] = tmpDice[5];
		dice[5] = tmpDice[2];
		break;
	// 북
	case 3:
		dice[0] = tmpDice[1];
		dice[1] = tmpDice[5];
		dice[4] = tmpDice[0];
		dice[5] = tmpDice[4];
		break;
	// 남
	case 4:
		dice[0] = tmpDice[4];
		dice[1] = tmpDice[0];
		dice[4] = tmpDice[5];
		dice[5] = tmpDice[1];
		break;
	}

	checkMap();
	cout << dice[0] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		roll(tmp);
	}

	return 0;
}

// #include <iostream>

// using namespace std;

// int n, m, k, y, x;
// int map[21][21];
// int arr[6] = { 0, }, tmp[6];
// int dy[5] = { 0, 0, 0, -1, 1 };
// int dx[5] = { 0, 1, -1, 0, 0 };

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int d;
// 	cin >> n >> m >> y >> x >> k;
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < m; j++)
// 			cin >> map[i][j];
// 	while (k--) {
// 		cin >> d;
// 		y += dy[d];
// 		x += dx[d];
// 		if (y < 0 || y == n || x < 0 || x == m) {
// 			y -= dy[d];
// 			x -= dx[d];
// 			continue;
// 		}
// 		for (int i = 0; i < 6; i++)
// 			tmp[i] = arr[i];
// 		switch (d)
// 		{
// 		case 1:
// 			arr[0] = tmp[3];
// 			arr[1] = tmp[1];
// 			arr[2] = tmp[0];
// 			arr[3] = tmp[5];
// 			arr[4] = tmp[4];
// 			arr[5] = tmp[2];
// 			break;
// 		case 2:
// 			arr[0] = tmp[2];
// 			arr[1] = tmp[1];
// 			arr[2] = tmp[5];
// 			arr[3] = tmp[0];
// 			arr[4] = tmp[4];
// 			arr[5] = tmp[3];
// 			break;
// 		case 3:
// 			arr[0] = tmp[1];
// 			arr[1] = tmp[5];
// 			arr[2] = tmp[2];
// 			arr[3] = tmp[3];
// 			arr[4] = tmp[0];
// 			arr[5] = tmp[4];
// 			break;
// 		case 4:
// 			arr[0] = tmp[4];
// 			arr[1] = tmp[0];
// 			arr[2] = tmp[2];
// 			arr[3] = tmp[3];
// 			arr[4] = tmp[5];
// 			arr[5] = tmp[1];
// 			break;
// 		}
// 		if (map[y][x]) {
// 			arr[5] = map[y][x];
// 			map[y][x] = 0;
// 		}
// 		else {
// 			map[y][x] = arr[5];
// 		}
// 		cout << arr[0] << '\n';
// 	}
// 	return 0;
// }