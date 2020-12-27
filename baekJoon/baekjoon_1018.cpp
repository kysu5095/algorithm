// 체스판 다시 칠하기
// 11:15

#include <iostream>
#include <limits.h>
#include <string>
#include <algorithm>

using namespace std;

string W_board[8] = { "WBWBWBWB",
					  "BWBWBWBW",
					  "WBWBWBWB",
					  "BWBWBWBW",
					  "WBWBWBWB",
					  "BWBWBWBW",
					  "WBWBWBWB",
					  "BWBWBWBW" };

string B_board[8] = { "BWBWBWBW",
					  "WBWBWBWB",
					  "BWBWBWBW",
					  "WBWBWBWB",
					  "BWBWBWBW",
					  "WBWBWBWB",
					  "BWBWBWBW",
					  "WBWBWBWB" };
string str[51];
int n, m, res = INT_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w_val, b_val;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			w_val = 0;
			b_val = 0;
			for (int y = 0; y < 8; y++) {
				for (int x = 0; x < 8; x++) {
					if (str[y + i][x + j] != W_board[y][x]) w_val++;
					if (str[y + i][x + j] != B_board[y][x]) b_val++;
				}
			}
			res = min(res, min(w_val, b_val));
		}
	}
	cout << res << '\n';
	return 0;
}