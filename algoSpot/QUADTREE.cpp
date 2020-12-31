// 쿼드 트리 뒤집기

#include <iostream>
#include <string>

using namespace std;

int test_case;
string str;

string dfs(int& idx) {
	idx++;
	if (str[idx] == 'b') return "b";
	if (str[idx] == 'w') return "w";
	string upLeft = dfs(idx);
	string upRight = dfs(idx);
	string downLeft = dfs(idx);
	string downRight = dfs(idx);

	return "x" + downLeft + downRight + upLeft + upRight;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int idx;
	cin >> test_case;
	while (test_case--) {
		idx = -1;
		str.clear();
		cin >> str;
		cout << dfs(idx) << '\n';
	}
	return 0;
}