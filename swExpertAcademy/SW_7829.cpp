// D4 : 보물왕 태혁

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		int n, input;
		cin >> n;
		vector<int> v;
		while (n--) {
			cin >> input;
			v.push_back(input);
		}
		sort(v.begin(), v.end());
		cout << "#" << tc << " " << (v[0] * v[v.size() - 1]) << '\n';
	}
	return 0;
}