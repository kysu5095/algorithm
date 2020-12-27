// 바이러스

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
bool check[101];

vector<int> getPi(vector<int>& v) {
	int j = 0;
	int len = v.size();
	vector<int> pi(len, 0);
	for (int i = 1; i < len; i++) {
		while (j > 0 && v[i] != v[j])
			j = pi[j - 1];
		if (v[i] == v[j])
			pi[i] = ++j;
	}
	return pi;
}

bool KMP(vector<int> &v, vector<int>& p, vector<int>& pi) {
	int n = v.size();
	int m = p.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && v[i] != p[j])
			j = pi[j - 1];
		if (v[i] == p[j]) {
			if (j == m - 1) {
				return true;
			}
			else
				j++;
		}
	}
	return false;
}

bool virus(vector<int> v[101]) {
	for (int idx = 0; idx < v[0].size() - k + 1; idx++) {
		memset(check, false, sizeof(check));
		vector<int> tmp;
		for (int i = 0; i < k; i++)
			tmp.push_back(v[0][i + idx]);
		vector<int> pi = getPi(tmp);

		for (int i = 1; i < n; i++)
			check[i] = KMP(v[i], tmp, pi);
		pi.clear();
		reverse(tmp.begin(), tmp.end());
		pi = getPi(tmp);
		for (int i = 1; i < n; i++) {
			if (check[i]) continue;
			check[i] = KMP(v[i], tmp, pi);
		}
		
		bool flag = true;
		for (int i = 1; i < n; i++) {
			if (!check[i]) {
				flag = false;
				break;
			}
		}
		if (flag) return true;
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int input, len;
	vector<int> v[101];
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> len;
		for (int j = 0; j < len; j++) {
			cin >> input;
			v[i].push_back(input);
		}
	}
	if(virus(v)) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}