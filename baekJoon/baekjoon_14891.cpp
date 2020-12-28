// 톱니바퀴 //
/////////////

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int k;
int maxSum = 0;
string str[4];

class Point {
public:
	int num, direct;
};
class Adjoin {
public:
	int left, right;
};
vector<Point> rotation;
vector<Adjoin> adjoin;

void spinWay(int num, int direct) {
	if (direct == 1) {	// 시계 방향
		if (adjoin[num].left - 1 < 0) adjoin[num].left = 7;
		else adjoin[num].left--;

		if (adjoin[num].right - 1 < 0) adjoin[num].right = 7;
		else adjoin[num].right--;
	}
	else { // 반시계 방향
		adjoin[num].left = (adjoin[num].left + 1) % 8;
		adjoin[num].right = (adjoin[num].right + 1) % 8;
	}
}

void check(int num, int direct, bool* visited) {
	int tmp = num;
	for (int i = 0; i < 4; i++) {
		if (visited[i]) {
			if (abs(i - num) == 2 || abs(i - num) == 0) spinWay(i, direct);
			else spinWay(i, direct * -1);
		}
	}


}

void spin(int num, int direct, bool* visited) {
	int tmp = num;
	visited[num] = true;
	/*cout << "=======돌리기 전=======\n";
	for (int i = 0; i < 4; i++) {
		cout << "left : " << adjoin[i].left << "(" << str[i][adjoin[i].left] << ")  right : " << adjoin[i].right << "(" << str[i][adjoin[i].right] << ")\n";
	}*/


	while (tmp < 3) { // 오른쪽 확인
		if (str[tmp][adjoin[tmp].right] - '0' != str[tmp + 1][adjoin[tmp + 1].left] - '0')
			visited[tmp + 1] = true;
		else
			break;

		tmp++;
	}
	tmp = num;
	while (tmp > 0) { // 왼쪽 확인
		if (str[tmp][adjoin[tmp].left] - '0' != str[tmp - 1][adjoin[tmp - 1].right] - '0')
			visited[tmp - 1] = true;
		else
			break;

		tmp--;
	}

	check(num, direct, visited);
	/*cout << "=======돌린 후=======\n";
	for (int i = 0; i < 4; i++) {
		cout << "left : " << adjoin[i].left << "(" << str[i][adjoin[i].left] << ")  right : " << adjoin[i].right << "(" << str[i][adjoin[i].right] << ")\n";
	}*/
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 12시부터 시계방향대로
	// N극 : 0    S극 : 1
	for (int i = 0; i < 4; i++) {
		cin >> str[i];
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		int num, direct;
		cin >> num >> direct;
		rotation.push_back({ num, direct });
	}

	// 초기 입접한 곳 설정
	adjoin.push_back({ 6, 2 });
	adjoin.push_back({ 6, 2 });
	adjoin.push_back({ 6, 2 });
	adjoin.push_back({ 6, 2 });

	for (int i = 0; i < k; i++) {
		bool visited[4] = { false, };
		spin(rotation[i].num - 1, rotation[i].direct, visited);
	}

	for (int i = 0; i < 4; i++) {
		if (str[i][(adjoin[i].left + 2) % 8] - '0' == 1) {	// S극
			if (i == 0) maxSum += 1;
			if (i == 1) maxSum += 2;
			if (i == 2) maxSum += 4;
			if (i == 3) maxSum += 8;
		}
	}

	cout << maxSum << '\n';

	return 0;
}

// #include <iostream>
// #include <string>
// #include <cstring>
// #include <deque>
// #include <cmath>

// using namespace std;

// int n, result = 0;
// bool visited[4] = { false, };
// deque<int> dq[4];
// string str[4];

// class Point {
// public:
// 	int cnt = 0, direction = 0;
// };
// Point p[101];

// void turn_right(int i) {
// 	dq[i].push_front(dq[i].back());
// 	dq[i].pop_back();
// }

// void turn_left(int i) {
// 	dq[i].push_back(dq[i].front());
// 	dq[i].pop_front();
// }

// void where_turn(int direction, int i) {
// 	if (direction == 1)
// 		turn_right(i);
// 	else
// 		turn_left(i);
// }

// void move() {
// 	for (int j = 0; j < n; j++) {
// 		memset(visited, false, sizeof(visited));
// 		int cnt = p[j].cnt;
// 		int direction = p[j].direction;
// 		visited[cnt] = true;

// 		while (cnt > 0) {
// 			if (dq[cnt][6] != dq[cnt - 1][2]) {
// 				visited[cnt - 1] = true;
// 				cnt--;
// 			}
// 			else
// 				break;
// 		}

// 		cnt = p[j].cnt;
// 		while (cnt < 3) {
// 			if (dq[cnt][2] != dq[cnt + 1][6]) {
// 				visited[cnt + 1] = true;
// 				cnt++;
// 			}
// 			else
// 				break;
// 		}

// 		cnt = p[j].cnt;
// 		for (int i = 0; i < 4; i++) {
// 			if (visited[i]) {
// 				if (abs(i - cnt) == 0 || abs(i - cnt) == 2)
// 					where_turn(direction, i);
// 				else
// 					where_turn(direction * -1, i);
// 			}
// 		}
// 	}
// 	for (int i = 0; i < 4; i++) {
// 		if (dq[i][0] == 1)
// 			result += pow(2, i);
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	for (int i = 0; i < 4; i++) 
// 		cin >> str[i];
// 	for (int i = 0; i < 4; i++) {
// 		for (int j = 0; j < str[i].size(); j++) {
// 			dq[i].push_back(str[i][j] - '0');
// 		}
// 	}
		
// 	int tmp;
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		cin >> tmp >> p[i].direction;
// 		p[i].cnt = tmp - 1;
// 	}

// 	move();
// 	cout << result << '\n';

// 	return 0;
// }