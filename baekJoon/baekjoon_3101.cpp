// 토끼의 이동

#include <iostream>
#define ll long long

using namespace std;

ll N, k;
char command[300001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	ll y = 0, x = 0;
	ll val, idx, differ, res = 1;
	cin >> N >> k;
	cin >> command;
	for (int i = 0; i < k; i++) {
		switch (command[i]) {
			case 'U': y--; break;
			case 'D': y++; break;
			case 'R': x++; break;
			case 'L': x--; break;
		}
		differ = (x + y);
		if (differ < N) {
			val = (differ * (differ + 1) / 2);
			if (differ % 2 == 0) val += (x + 1);
			else val += (y + 1);
		}
		else {
			idx = (N * 2) - (differ + 1);
			val = (N * N) - ((idx * (idx + 1)) / 2) + 1;
			if ((x + y) % 2 == 0) val += (N - y - 1);
			else val += (N - x - 1);
		}
		res += val;
		//cout << command[i] << " (" << y << "," << x << ") :" << val << "(" << res << ")" <<'\n';
	}
	cout << res << '\n';
	return 0;
}