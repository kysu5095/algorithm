// 큐빙 //
//////////

#include <iostream>
#include <string>

using namespace std;

int test_case, n;
string rotation;

void print(char side, char direct, string* dice) {
	cout << "Side : " << side << "  Direct : " << direct << '\n';
	for (int i = 0; i < 6; i++) {
		cout << i << "번째 면\n";
		for (int j = 0; j < 9; j++) {
			cout << dice[i][j];
			if (j % 3 == 2) cout << " ";
		}
		cout << '\n';
	}
}
void faceRotate(char side, char direct, string* dice) {
	int tmpSide;
	switch (side)
	{
	case 'U':
		tmpSide = 0;
		break;
	case 'D':
		tmpSide = 1;
		break;
	case 'F':
		tmpSide = 2;
		break;
	case 'B':
		tmpSide = 3;
		break;
	case 'L':
		tmpSide = 4;
		break;
	case 'R':
		tmpSide = 5;
		break;
	}
	string tmp = "";
	tmp += dice[tmpSide];
	if (direct == '+') {
		dice[tmpSide][0] = tmp[6];
		dice[tmpSide][1] = tmp[3];
		dice[tmpSide][2] = tmp[0];
		dice[tmpSide][3] = tmp[7];
		dice[tmpSide][5] = tmp[1];
		dice[tmpSide][6] = tmp[8];
		dice[tmpSide][7] = tmp[5];
		dice[tmpSide][8] = tmp[2];
	}
	else {
		dice[tmpSide][0] = tmp[2];
		dice[tmpSide][1] = tmp[5];
		dice[tmpSide][2] = tmp[8];
		dice[tmpSide][3] = tmp[1];
		dice[tmpSide][5] = tmp[7];
		dice[tmpSide][6] = tmp[0];
		dice[tmpSide][7] = tmp[3];
		dice[tmpSide][8] = tmp[6];
	}
}

void sideRotate(char side, char direct, string* dice) {
	string tmp[6];
	for (int i = 0; i < 6; i++) {
		tmp[i] += dice[i];
	}
	switch (side)
	{
	// 윗면
	case 'U':
		if (direct == '+') {
			for (int i = 0; i < 3; i++) {
				dice[4][i] = tmp[2][i];
				dice[2][i] = tmp[5][i];
				dice[5][i] = tmp[3][i];
				dice[3][i] = tmp[4][i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				dice[5][i] = tmp[2][i];
				dice[2][i] = tmp[4][i];
				dice[4][i] = tmp[3][i];
				dice[3][i] = tmp[5][i];
			}
		}

		break;
	//아랫면
	case 'D':
		if (direct == '+') {
			for (int i = 6; i < 9; i++) {
				dice[2][i] = tmp[4][i];
				dice[4][i] = tmp[3][i];
				dice[3][i] = tmp[5][i];
				dice[5][i] = tmp[2][i];
			}
		}
		else {
			for (int i = 6; i < 9; i++) {
				dice[2][i] = tmp[5][i];
				dice[5][i] = tmp[3][i];
				dice[3][i] = tmp[4][i];
				dice[4][i] = tmp[2][i];
			}
		}
		break;
	// 앞면
	case 'F':
		if (direct == '+') {
			for (int i = 0; i < 3; i++) {
				dice[0][i + 6] = tmp[4][8 - (3 * i)];
				dice[4][8 - (3 * i)] = tmp[1][2 - i];
				dice[1][2 - i] = tmp[5][i * 3];
				dice[5][i * 3] = tmp[0][i + 6];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				dice[0][i + 6] = tmp[5][3 * i];
				dice[5][3 * i] = tmp[1][2- i];
				dice[1][2 - i] = tmp[4][8 - (3 * i)];
				dice[4][8 - (3 * i)] = tmp[0][i + 6];
			}
		}
		break;
	// 뒷면
	case 'B':
		if (direct == '+') {
			for (int i = 0; i < 3; i++) {
				dice[0][i] = tmp[5][3 * (i + 1) - 1];
				dice[5][3 * (i + 1) - 1] = tmp[1][8 - i];
				dice[1][8 - i] = tmp[4][6 - (3 * i)];
				dice[4][6 - (3 * i)] = tmp[0][i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				dice[0][i] = tmp[4][6 - (3 * i)];
				dice[4][6 - (3 * i)] = tmp[1][8 - i];
				dice[1][8 - i] = tmp[5][3 * (i + 1) - 1];
				dice[5][3 * (i + 1) - 1] = tmp[0][i];
			}
		}
		break;
	// 왼쪽면
	case 'L':
		if (direct == '+') {
			for (int i = 0; i < 3; i++) {
				dice[0][3 * i] = tmp[3][8 - (3 * i)];
				dice[3][8 - (3 * i)] = tmp[1][3 * i];
				dice[1][3 * i] = tmp[2][3 * i];
				dice[2][3 * i] = tmp[0][3 * i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				dice[0][3 * i] = tmp[2][3 * i];
				dice[2][3 * i] = tmp[1][3 * i];
				dice[1][3 * i] = tmp[3][8 - (3 * i)];
				dice[3][8 - (3 * i)] = tmp[0][3 * i];
			}
		}
		break;
	// 오른쪽면
	case 'R':
		if (direct == '+') {
			for (int i = 0; i < 3; i++) {
				dice[0][3 * (i + 1) - 1] = tmp[2][3 * (i + 1) - 1];
				dice[2][3 * (i + 1) - 1] = tmp[1][3 * (i + 1) - 1];
				dice[1][3 * (i + 1) - 1] = tmp[3][6 - (3 * i)];
				dice[3][6 - (3 * i)] = tmp[0][3 * (i + 1) - 1];
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				dice[0][3 * (i + 1) - 1] = tmp[3][6 - (3 * i)];
				dice[3][6 - (3 * i)] = tmp[1][3 * (i + 1) - 1];
				dice[1][3 * (i + 1) - 1] = tmp[2][3 * (i + 1) - 1];
				dice[2][3 * (i + 1) - 1] = tmp[0][3 * (i + 1) - 1];
			}
		}
		break;
	}
}
void rotate(int cnt, string *dice) {
	for (int i = 0; i < cnt * 2; i += 2) {
		char side = rotation[i];
		char direct = rotation[i + 1];
		sideRotate(side, direct, dice);
		faceRotate(side, direct, dice);
	}
	for (int i = 0; i < 9; i++) {
		cout << dice[0][i];
		if (i % 3 == 2) cout << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		string dice[6] = { {"wwwwwwwww"}, {"yyyyyyyyy"}, {"rrrrrrrrr"}, {"ooooooooo"}, {"ggggggggg"}, {"bbbbbbbbb"} };
		rotation.clear();
		cin >> n;
		for (int j = 0; j < n; j++) {
			string tmp;
			cin >> tmp;
			rotation += tmp;
		}
		rotate(n, dice);
	}
	return 0;
}