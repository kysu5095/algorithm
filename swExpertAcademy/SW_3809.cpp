// // 화섭이의 정수 나열 //
// //////////////////////

// #include <iostream>
// #include <cstring>

// using namespace std;

// int arr[1000]{0, };

// int pi(int N){
//     int min = 0;
    
//     for(int i = 0; i < N; i++){ // 한자리수 찾기
//         if(arr[i] == min){  
//             min++;
//             i = -1;
//             if(min == 10) break;
//             continue;
//         }
//     }
//     if(min < 10) return min;

//     for(int i = 0; i < N - 1; i++){ // 두자리수 찾기
//         if((arr[i] * 10 + arr[i + 1]) == min){
//             min++;
//             i = -1;
//             if(min == 100) break;
//             continue;
//         }
//     }
//     if(min < 100) return min;

//     for(int i = 0; i < N - 2; i++){ // 세자리수 찾기
//         if((arr[i] * 100 + arr[i + 1] * 10 + arr[i + 2]) == min){
//             min++;
//             i = -1;
//             continue;
//         }
//     }
//     return min;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int T, N, num;
//     cin >> T;
//     for(int i = 0; i < T; i++){
//         cin >> N;
//         memset(arr, 0, sizeof(arr));
//         for(int j = 0; j < N; j++){
//             cin >> num;
//             arr[j] = num;
//         }
//         cout << "#" << i + 1 << " " << pi(N) <<'\n';
//     }

//     return 0;
// }

// 화섭이의 정수 나열

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int test_case, n, sum1, sum10, sum100;
	int arr[1001];
	bool cmp[1001];

	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		sum1 = 0, sum10 = 0, sum100 = 0;
		memset(cmp, false, sizeof(cmp));
		scanf(" %d", &n);
		for (int i = 0; i < n; i++) 
			scanf(" %d", &arr[i]);
		
		printf("#%d ", tc);
		// 1의 자리
		for (int i = 0; i < n; i++) {
			if (!cmp[arr[i]]) {
				cmp[arr[i]] = true;
				sum1 += arr[i];
			}
			if (sum1 == 45 && cmp[0]) break;
		}
		if (!cmp[0]) { // 0 확인
			printf("%d\n", 0);
			continue;
		}
		if (sum1 != 45) {
			for (int i = 1; i < 10; i++) {
				if (!cmp[i]) {
					printf("%d\n", i);
					break;
				}
			}
			continue;
		}

		// 10의 자리
		int tmp;
		for (int i = 0; i < n - 1; i++) {
			tmp = arr[i] * 10 + arr[i + 1];
			if (!cmp[tmp]) {
				cmp[tmp] = true;
				sum10 += tmp;
				if (sum10 == 4905) break;
			}
		}
		if (sum10 != 4905) {
			for (int i = 10; i < 100; i++) {
				if (!cmp[i]) {
					printf("%d\n", i);
					break;
				}
			}
			continue;
		}

		// 100의 자리
		for (int i = 0; i < n - 2; i++) {
			tmp = (arr[i] * 100) + (arr[i + 1] * 10) + arr[i + 2];
			if (!cmp[tmp]) {
				cmp[tmp] = true;
				sum100 += tmp;
				if (sum100 == 494595) break;
			}
		}
		if (sum100 != 494595) {
			for (int i = 100; i < 1000; i++) {
				if (!cmp[i]) {
					printf("%d\n", i);
					break;
				}
			}
			continue;
		}
		printf("%d\n", 1000);
	}
	return 0;
}