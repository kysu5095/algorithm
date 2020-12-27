// 운동
// 3:45

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, m, M, T, R, min_v, t = 0;
	cin >> N >> m >> M >> T >> R;
	min_v = m;
	if (m + T > M) {
		cout << "-1\n";
		return 0;
	}
	while (N) {
		t++;
		if (m + T <= M) {
			m += T;
			N--;
		}
		else {
			m -= R;
			if (m < min_v)
				m = min_v;
		}
	}
	cout << t << '\n';
	return 0;
}