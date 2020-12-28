// 가랏! RC카!

#include <iostream>

using namespace std;

int test_case, n, res = 0;
int curSpeed = 0;

void go(int c, int s) {
	if (c == 1) {
		curSpeed += s;
		res += curSpeed;
	}
	else if (c == 2) {
		if (curSpeed < s)
			curSpeed = 0;
		else
			curSpeed -= s;

		res += curSpeed;
	}
	else {
		res += curSpeed;
	}
}

int main() {
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		res = 0, curSpeed = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int c = 0, s = 0;
			cin >> c;
			if (c != 0)
				cin >> s;

			go(c, s);
		}
		cout << "#" << i + 1 << " " << res << '\n';
	}
}