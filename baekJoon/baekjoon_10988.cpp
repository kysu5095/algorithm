// 팰린드롬인지 확인하기

#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	bool flag = true;
	cin >> s;
	int ss = s.length();
	int len = s.length();
	len >>= 1;
	for (int i = 0; i < len; i++) {
		if (s[i] != s[ss - i - 1]) {
			flag = false;
			break;
		}
	}
	if (flag) cout << "1\n";
	else cout << "0\n";
	return 0;
}