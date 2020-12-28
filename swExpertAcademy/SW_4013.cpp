// 복습 - 특이한 자석
// 8:25

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <deque>
#include <math.h>

using namespace std;

int test_case, k, res;
int visited[4];
deque<int> dq[4];

class Point {
public:
	int n, d;
};
deque<Point> dq2;

void right_rotation(int num) {
	dq[num].push_front(dq[num].back());
	dq[num].pop_back();
}

void left_rotation(int num) {
	dq[num].push_back(dq[num].front());
	dq[num].pop_front();
}

void is_visited(int num, int d) {
	visited[num] = d;
	if (num) {
		if (dq[num][6] != dq[num - 1][2] && !visited[num - 1])
			is_visited(num - 1, d * -1);
	}
	if (num != 3) {
		if (dq[num][2] != dq[num + 1][6] && !visited[num + 1])
			is_visited(num + 1, d * -1);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);
	int input, input2;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		for (int i = 0; i < 4; i++)
			dq[i].clear();
		dq2.clear();
		cin >> k;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> input;
				dq[i].push_back(input);
			}
		}
		for (int i = 0; i < k; i++) {
			cin >> input >> input2;
			dq2.push_back({ input - 1, input2 });
		}
		for (int i = 0; i < k; i++) {
			memset(visited, 0, sizeof(visited));
			is_visited(dq2[i].n, dq2[i].d);
			for (int j = 0; j < 4; j++) {
				if (visited[j] == 1)
					right_rotation(j);
				else if (visited[j] == -1)
					left_rotation(j);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (dq[i][0])
				res += pow(2, i);
		}
		cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}