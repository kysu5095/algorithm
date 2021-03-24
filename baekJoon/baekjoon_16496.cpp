// 큰 수 만들기

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<string> v;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	bool flag = false;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (stoi(v[i]) != 0) flag = true;
	}
	if (!flag) {
		cout << "0\n";
		return 0;
	}
	sort(v.begin(), v.end(), [](string& str1, string& str2) {
		if (str1 + str2 > str2 + str1) return true;
		else return false;
		});
	for (int i = 0; i < n; i++)	cout << v[i];
	cout << '\n';
	return 0;
}