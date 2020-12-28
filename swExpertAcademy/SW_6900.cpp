// 주혁이의 복권 당첨

#include <iostream>

using namespace std;

class Jackpot {
public:
	char num[8];
	int prize;
};

Jackpot jackpot[101];
char lotto[1001][8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case, n, m, len, sum;
	bool flag;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		sum = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) 
			cin >> jackpot[i].num >> jackpot[i].prize;
		for (int i = 0; i < m; i++)
			cin >> lotto[i];

		for (int i = 0; i < m; i++) {
			flag = false;
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 8; k++) {
					if (jackpot[j].num[k] == '*') continue;
					if (jackpot[j].num[k] != lotto[i][k]) {
						flag = true;
						break;
					}
				}
				if (flag == false) { // 로또 당첨
					sum += jackpot[j].prize;
					break;
				}
				flag = false;
			}
		}
		cout << "#" << tc << " " << sum << '\n';
	}

	return 0;
}