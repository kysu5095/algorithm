// 묘수풀이: 모독

#include <iostream>
#include <algorithm>

using namespace std;

int n, m, cnt = 0;
int arr[2][8][2];
int order[9], turn[8];
bool visited[8] = { false, };
bool finish = false;

void modok() {
	bool judge = true;
	while (judge) {
		judge = false;
		for (int i = 1; i <= n; i++) {
			arr[0][i][1]--;
			if (arr[0][i][1]== 0) {
				judge = true;
			}
		}
		for (int i = 1; i <= m; i++) {
			arr[1][i][1]--;
			if (arr[1][i][1]== 0) {
				judge = true;
			}
		}
	}
}

bool promising() {
	bool judge = true;
	for (int i = 1; i <= n; i++)
		if (arr[0][i][1] > 0) judge = false;
	for (int i = 1; i <= m; i++)
		if (arr[1][i][1] > 0) judge = false;

	return judge;
}

void print(int flag) {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (order[i])
			cnt++;
	if (flag) cnt++;
	cout << cnt << '\n';

	if (flag) {
		if (flag == n + 1) {
			for (int i = 1; i <= n; i++)
				if (order[i])
					cout << "attack " << i << " " << order[i] << '\n';
			cout << "use modok\n";
		}
		else {
			for (int i = 1; i <= n; i++) {
				if(i == flag)
					cout << "use modok\n";
				else {
					if(order[i])
						cout << "attack " << i << " " << order[i] << '\n';
				}
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++)
			if (order[i])
				cout << "attack " << i << " " << order[i] << '\n';
	}
}

void dfs(int cnt, int flag) {
	if (finish) return;
	if (cnt == n + 1) {
		/*int tmp[2][8];
		for (int i = 1; i <= n; i++) tmp[0][i] = arr[0][i][1];
		for (int i = 1; i <= m; i++) tmp[1][i] = arr[1][i][1];
		if (flag == 0) {
			if (promising()) {
				finish = true;
				print(0);
				return;
			}
			modok();
			if (promising()) {
				finish = true;
				print(cnt);
				return;
			}
			for (int i = 1; i <= n; i++) arr[0][i][1] = tmp[0][i];
			for (int i = 1; i <= m; i++) arr[1][i][1] = tmp[1][i];
		}
		if (promising()) {
			finish = true;
			print(flag);
		}*/
		for (int i = 1; i <= n; i++) {
			int AK_1 = arr[0][turn[i]][0];
			int AK_2 = arr[1][order[turn[i]]][0];
			int HP_1 = arr[0][turn[i]][1];
			int HP_2 = arr[1][order[turn[i]]][1];
			if (HP_1 <= 0 || HP_2 <= 0 || (AK_1 >= HP_2 && AK_2 >= HP_1)) return;
		}
		return;
	}
	for (int i = 0; i <= m; i++) {
		if (i == 0) {
			order[turn[cnt]] = 0;
			dfs(cnt + 1, flag);
			continue;
		}
		/*if (flag == 0) {
			int tmp[2][8];
			for (int i = 1; i <= n; i++) tmp[0][i] = arr[0][i][1];
			for (int i = 1; i <= m; i++) tmp[1][i] = arr[1][i][1];
			modok();
			dfs(cnt, cnt);
			for (int i = 1; i <= n; i++) arr[0][i][1] = tmp[0][i];
			for (int i = 1; i <= m; i++) arr[1][i][1] = tmp[1][i];
			return;
		}*/
		order[turn[cnt]] = i;
		dfs(cnt + 1, flag);
		order[turn[cnt]] = 0;
		/*int AK_1 = arr[0][turn[cnt]][0];
		int AK_2 = arr[1][i][0];
		int HP_1 = arr[0][turn[cnt]][1];
		int HP_2 = arr[1][i][1];
		if (HP_1 <= 0 || HP_2 <= 0 || (AK_1 >= HP_2 && AK_2 >= HP_1)) {
			order[turn[cnt]] = 0;
			continue;
		}
		else {
			order[turn[cnt]] = i;
			arr[0][turn[cnt]][1] -= AK_2;
			arr[1][i][1] -= AK_1;
			dfs(cnt + 1, flag);
			order[turn[cnt]] = 0;
			arr[0][turn[cnt]][1] += AK_2;
			arr[1][i][1] += AK_1;
		}*/
	}
}

void sequence(int cnt) {
	if (finish) return;
	if (cnt == n + 1) {
		dfs(1, 0);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			turn[cnt] = i;
			sequence(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[0][i][0] >> arr[0][i][1];
	for (int i = 1; i <= m; i++)
		cin >> arr[1][i][0] >> arr[1][i][1];
	if (!n || !m) cout << "0\n";
	else {
		sequence(1);
		if (!finish) cout << "-1\n";
	}
	return 0;
}