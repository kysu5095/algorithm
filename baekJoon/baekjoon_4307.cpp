// 개미 

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case, n, l, lo, max_t, min_t;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		max_t = 0, min_t = 0;
		cin >> n >> l;
		for (int i = 0; i < l; i++) {
			cin >> lo;
			int a_min = min(lo, n - lo);
			int a_max = max(lo, n - lo);
			min_t = max(min_t, a_min);
			max_t = max(max_t, a_max);
		}
		cout << min_t << " " << max_t << '\n';
	}
	return 0;
}