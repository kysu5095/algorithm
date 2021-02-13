// 하늘에서 별똥별이 빗발친다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, l, K;
vector<pair<int, int>> v;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> l >> K;
	v.resize(K);
	for (int i = 0; i < K; i++)
		cin >> v[i].second >> v[i].first;
	int res = 0;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			int cnt = 0;
			for (int k = 0; k < K; k++) {
				int _y = v[i].first;
				int _x = v[j].second;
				int y = v[k].first;
				int x = v[k].second;
				if (y >= _y && y <= _y + l && x >= _x && x <= _x + l)
					cnt++;
			}
			res = max(res, cnt);
		}
	}
	cout << K - res << '\n';
	return 0;
}