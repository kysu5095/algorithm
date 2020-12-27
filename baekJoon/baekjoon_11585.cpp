// 속타는 저녁 메뉴

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, res = 0, GCD;

int gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

vector<int> getPi(string& p) {
	int len = p.length();
	vector<int> pi(len, 0);
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

void KMP(string &s, string &p) {
	vector<int> pi = getPi(p);
	int n = s.length();
	int m = p.length();
	int j = 0;
	for (int i = 0; i < n - 1; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == N - 1) {
				res++;
				j = pi[j];
			}
			else j++;
		}
	}
	GCD = gcd(N, res);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	string s = "", p = "";
	char input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		p += input;
	}
	for (int i = 0; i < N; i++) {
		cin >> input;
		s += input;
	}
	s += s;
	KMP(s, p);
	cout << res / GCD << '/' << N / GCD << '\n';
	return 0;
}