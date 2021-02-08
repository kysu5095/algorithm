// 화학실험

#include <iostream>

using namespace std;

int n, m, res = 0;
int arr[101][2];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1];
	cin >> m;
	bool flag;
	for (int val = 2; val <= 101000; val++) {
		flag = true;
		for (int i = 0; i < n; i++) {
			if (val - arr[i][1] <= 0) { flag = false; break; }
			float x = (float)(val - arr[i][1]) / (float)arr[i][0];
			if (x != (int)x) { flag = false; break; }
			res += (int)x;
		}
		if (res > m) break;
		if (flag && res == m) {
			cout << val << '\n';
			return 0;
		}
		res = 0;
	}
	cout << "0\n";
	return 0;
}