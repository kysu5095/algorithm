// 찾기

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getPi(string& p) {
	int j = 0;
	int len = p.size();
	vector<int> pi(len, 0);
	for (int i = 1; i < len; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> KMP(string& t, string& p) {
	vector<int> pi = getPi(p);
	vector<int> res;
	int j = 0;
	int len_t = t.size();
	int len_p = p.size();
	for (int i = 0; i < len_t; i++) {
		while (j > 0 && t[i] != p[j])
			j = pi[j - 1];
		if (t[i] == p[j]) {
			if (j == len_p - 1) {
				res.push_back(i - len_p + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string T, P;
	getline(cin, T);
	getline(cin, P);
	vector<int> v = KMP(T, P);
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] + 1 << '\n';
	return 0;
}