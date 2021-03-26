// 비드맨

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, max_v = 0;
    long long total = 0;
	cin >> n;
	while (n--) {
		int input;
		cin >> input;
		total += input;
		max_v = max(max_v, input);
	}
	if (total - max_v > max_v) cout << (total & 1) << '\n';
	else cout << max_v - (total - max_v) << '\n';
	return 0;
}