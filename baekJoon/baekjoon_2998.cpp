// 8진수

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int len = s.length();
	int cnt = 0;
	len %= 3;
	while (len && len != 3) {
		cnt++;
		len++;
	}
	while (cnt--) 
		s.insert(0, "0");
	len = s.length();
	cnt = 2;
	int val = 0;
	string res = "";
	for (int i = 0; i < len; i++) {
		if (i % 3 == 0 && i) {
			res += to_string(val);
			cnt = 2;
			val = 0;
		}
		val += (s[i] - '0') * pow(2, cnt--);
	}
	res += to_string(val);
	cout << res << '\n';
	return 0;
}