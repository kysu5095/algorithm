// 고급 작품

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, k, q;
char arr[1001][1001];
vector<vector<string>> v;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int h, w;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = '.';
	cin >> k;
	v.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> h >> w;
		v[i].resize(h);
		for (int j = 0; j < h; j++)
			cin >> v[i][j];
	}
	cin >> q;
	int num, y, x;
	while (q--) {
		cin >> num >> y >> x;
		for (int i = 0; i < v[num - 1].size(); i++) 
			for (int j = 0; j < v[num - 1][i].size(); j++) 
				arr[y + i][x + j] = v[num - 1][i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}