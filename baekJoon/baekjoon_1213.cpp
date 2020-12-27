// 팰린드롬 만들기

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int cnt = 0;
char odd;
int arr[26] = { 0, };
string s;

void palindrome() {
	string ans = "", reverse_ans, tmp;
	for (int i = 0; i < 26; i++) {
		if (!arr[i]) continue;
		for (int j = 0; j < arr[i] >> 1; j++)
			ans += i + 'A';
	}
	tmp = ans;
	reverse(tmp.begin(), tmp.end());
	if (!cnt)
		cout << ans + tmp << '\n';
	else
		cout << ans + odd + tmp << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	for (int i = 0; i < s.length(); i++) 
		arr[s[i] - 'A']++;
	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2) {
			odd = i + 'A';
			cnt++;
		}
	}
	if (cnt > 1) {
		cout << "I'm Sorry Hansoo" << '\n';
		return 0;
	}
	palindrome();
	return 0;
}