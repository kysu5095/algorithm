// 지능형 기차
// 5:00

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cur = 0, res = 0;
	int first, second;
	for (int i = 0; i < 4; i++) {
		cin >> first >> second;
		cur += (second - first);
		res = res < cur ? cur : res;
	}
	cout << res << '\n';
	return 0;
}