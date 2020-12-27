// 설탕배달

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, res = 0;
	cin >> n;
	while (true) {
		if (n % 5 == 0) {
			cout << n / 5 + res << '\n';
			break;
		}
		else if (n < 0) {
			cout << "-1\n";
			break;
		}
		n -= 3;
		res++;
	}
	return 0;
}