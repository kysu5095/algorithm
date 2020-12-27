// 공
// 1:45

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, a, b, tmp;
	int cup[4] = { 0, 1, 2, 3 };
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		tmp = cup[a];
		cup[a] = cup[b];
		cup[b] = tmp;
	}
	for(int i = 1; i <= 3; i++)
		if(cup[i] == 1)
			cout << i << '\n';
	return 0;
}