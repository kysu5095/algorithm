// //  N-Queen  //
// ///////////////

// #include <iostream>
// #include <cstdlib>

// using namespace std;

// int arr[10] = {0, };
// int sum = 0;

// bool isPromising(int row){
//     for(int i = 0; i < row; i++){
//         if(arr[row] == arr[i] || abs(row - i) == abs(arr[row] - arr[i]))
//             return false;
//     }

//     return true;
// }

// int isQueen(int row, int n){
//     if(row >= n) return ++sum;

//     for(int i = 0; i < n; i++){
//         arr[row] = i;

//         if(isPromising(row))
//             isQueen(row + 1, n);

//         arr[row] = 0;
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int test_csae;
//     cin >> test_csae;
//     for(int i = 0; i < test_csae; i++){
//         int n;
//         cin >> n;
//         isQueen(0, n);

//         cout << "#" << i + 1 << " " << sum << '\n';
//         sum = 0;
//     }

//     return 0;
// }

// N-Queen

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int res;
int chess[11];

void dfs(int row, int n) {
	if (row == n) {
		res++;
		return;
	}
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		chess[row] = i;
		for (int j = 0; j < row; j++) {
			if (chess[row] == chess[j]) {
				flag = false;
				break;
			}
			if (row - j == abs(chess[row] - chess[j])) {
				flag = false;
				break;
			}
		}
		if (flag) 
			dfs(row + 1, n);
		flag = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int test_case, n;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		memset(chess, 0, sizeof(chess));
		cin >> n;
		dfs(0, n);
		cout << "#" << tc << " " << res << '\n';
	}
}