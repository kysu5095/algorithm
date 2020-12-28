// A -> B

#include <iostream>
#include <queue>
#define MAX 1000000000

using namespace std;

int a, b;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	int cnt = 0;
	while (true) {
		if (a > b) {
			cout << "-1\n";
			break;
		}
		if (a == b) {
			cout << cnt + 1 << '\n';
			break;
		}
		if (b % 2 == 0)
			b >>= 1;
		else {
			if (b % 10 == 1) {
				b -= 1;
				b /= 10;
			}
			else {
				cout << "-1\n";
				break;
			}
		}
		cnt++;
	}
	return 0;
}