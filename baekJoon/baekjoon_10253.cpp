// 헨리

#include <iostream>

using namespace std;

int T, a, b;

int henry() {
	int x = 1;
	while (x++) {
		if (b <= a * x) {
			if (b == a * x) return x;
			a = (a * x) - b;
			b = b * x;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> a >> b;
		cout << henry() << '\n';
	}
	return 0;
}