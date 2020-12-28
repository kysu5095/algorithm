// 원판 돌리기 //
////////////////

#include <iostream>
#include <deque>

using namespace std;

int n, m, t;
int x, d, k;
int result_sum = 0;
bool visited[52][52] = { {false, }, };
deque<int> q[52];
class Point {
public:
	int x, d, k;
};
deque<Point> command;

class Corinate {
public:
	int y, x;
};
deque<Point> erase_value;

void turn_right(int depth, int cnt) {
	for (int i = 0; i < cnt; i++) {
		int tmp = q[depth].back();
		q[depth].pop_back();
		q[depth].push_front(tmp);
	}
}

void turn_left(int depth, int cnt) {
	for (int i = 0; i < cnt; i++) {
		int tmp = q[depth].front();
		q[depth].pop_front();
		q[depth].push_back(tmp);
	}
}

void eraseValue() {
	bool is_turn = false;
	result_sum = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if(q[i][j] != -1) result_sum += q[i][j];
			if (q[i][j] != -1 && (q[i][j] == q[i][(j + 1) % m])) {
				visited[i][j] = visited[i][(j + 1) % m] = true;
				is_turn = true;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (q[j][i] != -1 && (q[j][i] == q[j + 1][i])) {
				visited[j][i] = visited[j + 1][i] = true;
				is_turn = true;
			}
		}
	}
	if (is_turn) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j])
					q[i][j] = -1;
			}
		}
	}
	else {
		int tmp_cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (q[i][j] != -1) tmp_cnt++;
			}
		}
		for (int i = 1; i <= n; i++) {
			double tmp_average = result_sum / (double)tmp_cnt;
			//cout << "AVERAGE : " << tmp_average << '\n';
			for (int j = 0; j < m; j++) {
				if (q[i][j] == -1) continue;
				if ((double)q[i][j] > tmp_average)
					q[i][j]--;
				else if ((double)q[i][j] < tmp_average)
					q[i][j]++;
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			cout << q[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void turn() {
	int size = command.size();
	for (int i = 0; i < size; i++) {
		int x = command[i].x;
		int d = command[i].d;
		int k = command[i].k;
		int multiple = 1;

		while (true) {
			if (x * multiple > n) break;

			if (d == 0)
				turn_right(x * multiple, k);
			else 
				turn_left(x * multiple, k);

			//cout << multiple << '\n';
			multiple++;
			//print();
		}
		eraseValue();
		//print();
	}
	result_sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if(q[i][j] != -1)
				result_sum += q[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int input;
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			q[i].push_back(input);
		}
	}
	for (int i = 0; i < t; i++) {
		cin >> x >> d >> k;
		command.push_back({ x, d, k });
	}
	turn();
	cout << result_sum << '\n';

	return 0;
}

// #include <iostream>
// #include <deque>
// #include <queue>

// using namespace std;

// int n, m, t;
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };
// deque<int> dq[51];

// void cal() {
// 	double cnt = 0, total = 0;
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			if (dq[i][j] == 0) continue;
// 			cnt++;
// 			total += dq[i][j];
// 		}
// 	}
// 	total /= cnt;
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			if (dq[i][j] == 0) continue;
// 			if ((double)dq[i][j] > total) dq[i][j]--;
// 			else if ((double)dq[i][j] < total) dq[i][j]++;
// 		}
// 	}
// }

// void find_cal() {
// 	int val, y, x, ny, nx;
// 	bool flag = false, is_find;
// 	for (int ty = 1; ty <= n; ty++) {
// 		for (int tx = 0; tx < m; tx++) {
// 			val = dq[ty][tx];
// 			if (val == 0) continue;
// 			queue<pair<int, int>> q;
// 			q.push(make_pair(ty, tx));
// 			dq[ty][tx] = 0;
// 			is_find = false;
// 			while (!q.empty()) {
// 				y = q.front().first;
// 				x = q.front().second;
// 				q.pop();
// 				for (int i = 0; i < 4; i++) {
// 					ny = y + dy[i];
// 					nx = x + dx[i];
// 					if (ny <= 0 || ny > n) continue;
// 					if (nx < 0) nx = m - 1;
// 					if (nx == m) nx = 0;
// 					if (dq[ny][nx] == 0 || dq[ny][nx] != val) continue;
// 					is_find = true;
// 					flag = true;
// 					dq[ny][nx] = 0;
// 					q.push(make_pair(ny, nx));
// 				}
// 			}
// 			if (!is_find) dq[ty][tx] = val;
// 		}
// 	}
// 	if (!flag) cal();
// }

// void rotation(int idx, int& d, int& k) {
// 	int tmp = idx;
// 	while (idx <= n) {
// 		if (d == 0) {
// 			for (int i = 0; i < k; i++) {
// 				dq[idx].push_front(dq[idx].back());
// 				dq[idx].pop_back();
// 			}
// 		}
// 		else {
// 			for (int i = 0; i < k; i++) {
// 				dq[idx].push_back(dq[idx].front());
// 				dq[idx].pop_front();
// 			}
// 		}
// 		idx += tmp;
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int x, d, k, input;
// 	cin >> n >> m >> t;
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			cin >> input;
// 			dq[i].push_back(input);
// 		}
// 	}
// 	while (t--) {
// 		cin >> x >> d >> k;
// 		rotation(x, d, k);
// 		find_cal();
// 	}
// 	int res = 0;
// 	for (int i = 1; i <= n; i++)
// 		for (int j = 0; j < m; j++)
// 			res += dq[i][j];
// 	cout << res << '\n';
// 	return 0;
// }