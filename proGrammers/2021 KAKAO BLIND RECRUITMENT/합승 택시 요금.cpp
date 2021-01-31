// 합승 택시 요금
// 10:50 - 11:35

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#define ll long long

using namespace std;

ll arr[201][201] = { {0,}, };

void init(int& n, vector<vector<int>>& v) {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			if (i != j) arr[i][j] = INT_MAX;

	for (vector<int> idx : v) {
		arr[idx[0]][idx[1]] = idx[2];
		arr[idx[1]][idx[0]] = idx[2];
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	init(n, fares);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
	ll answer = INT_MAX;
	for (int i = 1; i <= n; i++)
		answer = min(answer, arr[s][i] + arr[i][a] + arr[i][b]);
	return answer;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	return 0;
}