// 주사위 윷놀이 //
//////////////////

/////////////////////////////////////////////////
/// 맵을 직접 만드는게 편하다 함
/////////////////////////////////////////////////

#include <iostream>

using namespace std;

int result = 0;
int turn[10] = { 0, };
int red_line[21];
int blue_line1[8] = { 10, 13, 16, 19, 25, 30, 35, 40 };
int blue_line2[7] = { 20, 22, 24, 25, 30, 35, 40 };
int blue_line3[8] = { 30, 28, 27, 26, 25, 30, 35, 40 };

// 말의 대한 정보
class Dice {
public:
	// where : 어떤 라인에 있는지 (0 : red_line, 1 : blue_line1 ,,,)
	// cnt : 해당 라인의 몇번째 칸에 있는지
	// value : 현재 해당말이 있는 점수판의 점수
	int where = 0, cnt = 0, value = 0;
};
Dice dice[4];

// 말이 움직일 수 있는지 검사
// horse : 움직일 말의 번호
// move_cnt : 움직일 칸의 개수
// sum : 현재까지의 점수
bool move_horse(int horse, int move_cnt, int& sum) {
	int where = dice[horse].where;
	int cnt = dice[horse].cnt;
	int value = dice[horse].value;

	if (where == 0) { // red_line
		// 현재위치 + 움직일 칸 >= 말판의 끝
		if (cnt + move_cnt >= 21) {
			dice[horse].where = 4;
			dice[horse].value = 99;
			return true;
		}
		// 이동하려는 칸에 말이 존재하면 false
		for (int i = 0; i < 4; i++) {
			if (i == horse)	continue;
			if (red_line[cnt + move_cnt] == dice[i].value) {
				if (where == dice[i].where)
					return false;
				if ((cnt + move_cnt) % 5 == 0)
					return false;
			}
		}

		sum += red_line[cnt + move_cnt];
		// 도착한 위치가 파랑칸일 경우
		if ((cnt + move_cnt) % 5 == 0 && (cnt + move_cnt != 20)) {
			dice[horse].where = (cnt + move_cnt) / 5;
			dice[horse].cnt = 0;
		}
		else {
			dice[horse].cnt += move_cnt;
		}
		dice[horse].value = red_line[cnt + move_cnt];

		return true;
	}
	else if (where == 1) { // blue_line1
		// 현재위치 + 움직일 칸 >= 말판의 끝
		if (cnt + move_cnt >= 8) {
			dice[horse].where = 4;
			dice[horse].value = 99;
			return true;
		}
		// 이동하려는 칸에 말이 존재하면 false
		for (int i = 0; i < 4; i++) {
			if (i == horse)	continue;
			if (blue_line1[cnt + move_cnt] == dice[i].value) {
				if (dice[i].where != 0)
					return false;
				if (dice[i].value == 40)
					return false;
			}
		}

		sum += blue_line1[cnt + move_cnt];
		dice[horse].cnt += move_cnt;
		dice[horse].value = blue_line1[cnt + move_cnt];
		return true;
	}
	else if (where == 2) { // blue_line2
		// 현재위치 + 움직일 칸 >= 말판의 끝
		if (cnt + move_cnt >= 7) {
			dice[horse].where = 4;
			dice[horse].value = 99;
			return true;
		}
		// 이동하려는 칸에 말이 존재하면 false
		for (int i = 0; i < 4; i++) {
			if (i == horse)	continue;
			if (blue_line2[cnt + move_cnt] == dice[i].value) {
				if (dice[i].where != 0)
					return false;
				if (dice[i].value == 40)
					return false;
			}
		}

		sum += blue_line2[cnt + move_cnt];
		dice[horse].cnt += move_cnt;
		dice[horse].value = blue_line2[cnt + move_cnt];
		return true;
	}
	else if (where == 3) { // blue_line3
		// 현재위치 + 움직일 칸 >= 말판의 끝
		if (cnt + move_cnt >= 8) {
			dice[horse].where = 4;
			dice[horse].value = 99;
			return true;
		}
		// 이동하려는 칸에 말이 존재하면 false
		for (int i = 0; i < 4; i++) {
			if (i == horse)	continue;
			if (blue_line3[cnt + move_cnt] == dice[i].value) {
				if (dice[i].where != 0)
					return false;
				if (dice[i].value == 40)
					return false;
			}
		}

		sum += blue_line3[cnt + move_cnt];
		dice[horse].cnt += move_cnt;
		dice[horse].value = blue_line3[cnt + move_cnt];
		return true;
	}
	else { // where == 4 >> 말판의 끝까지 도달
		return false;
	}
}

void dfs(int cnt, int sum) {
	// 10번 이동을 마친 경우 종료
	if (cnt == 10) {
		result = result < sum ? sum : result;
		return;
	}

	//// 모든 말이 말판의 끝에 도달해 있을 경우 종료
	//for (int i = 0; i < 4; i++) {
	//	if (dice[i].where == 4 && i == 3) {
	//		result = result < sum ? sum : result;
	//		return;
	//	}
	//}
	int tmp = sum;
	for (int i = 0; i < 4; i++) {
		Dice tmp_dice = dice[i];
		if (move_horse(i, turn[cnt], sum)) {
			dfs(cnt + 1, sum);
			// dfs 이전상태로 초기화
			sum = tmp;
			dice[i] = tmp_dice;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i <= 20; i++)
		red_line[i] = i * 2;

	for (int i = 0; i < 10; i++) {
		cin >> turn[i];
	}
	dfs(0, 0);

	cout << result << '\n';
	return 0;
}