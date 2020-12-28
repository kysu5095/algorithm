// 내 선물을 받아줘 2

#include <iostream>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, cnt = 0;
	char str[1001];
	cin >> n;
	cin >> str;
	for (int i = 0; i < n - 1; i++) {
		if (str[i] == 'E' && str[i + 1] == 'W')
			cnt++;
	}
	if (!cnt) cout << "1\n";
	else cout << cnt << '\n';
	return 0;
}