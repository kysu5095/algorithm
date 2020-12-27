/*
소들은 농부 존의 농장을 탈출하는 대담한 계획을 세웠다.
그들은 작은 고무 보트를 구했고 한 밤중에 농장 경계에 흐르는 강을 보트를 타고 건너려는 계획이다.
그 계획은 완벽해 보였다. 작은 고무 보트가 소들의 무게를 견디지 못한다는 사실을 알기 전까지는…

N마리의 소(1≤N≤20)들의 무게는 각각 W_1, …, W_N이다.
보트가 침몰하지 않을 만큼 가벼운 소들을 선별해야 한다.
불행하게도, 소들은 산수를 못하기로 유명하다.
10진법을 사용하는 소들은 소들의 무게를 더하다가 자리올림이 발생하는 경우 그 소는 보트를 사용하기에는 너무 무거운 소라고 판단한다.
자리올림이 발생하지 않고 더할 수 있는 무게가 보트를 사용할 수 있는 가벼운 무게이다.

당신이 할 일은 소들을 도와서 보트를 탈 수 있는 소들의 최대 수를 구하는 것이다.
즉, 소들의 무게들을 모두 더했을 때 자리올림이 발생하지 않게 하는 소들의 최대 수를 구하는 것이다.
첫 줄에 소들의 수 N(1≤N≤20)이 주어진다.
두 번째 줄부터 N 줄에 걸쳐 각 소의 무게(W_i)가 입력된다. (정수, 1≤W_i≤100,000,000)

무게를 모두 더했을 때 어떤 자리에서도 자리올림이 발생하지 않는 소들의 최대 수를 출력하라.

input
5
522
6
84
7311
19

output
3

10
4052075
14301521
8935122
111197
1607375
13814352
3324840
1062385
2087584
3090360

output
2
*/

//////////////////////////////////////////////
//   위 내코드 : 더럽고 느림
//   아래 동연이형 코드 : 빠르고 간결
//   아래 동엽이형
//////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int n;
int maxCow = 1;
int tmpSum = 0;
int cowSum[21] = { 0, };
string str[21];

bool cal(int idx) {
	int tmpCnt = 0;
	for (int i = str[idx].size() - 1; i > -1; i--) {
		if (cowSum[tmpCnt] + str[idx][i] - '0' < 10) {
			tmpCnt++;
		}
		else {
			return false;
		}
	}

	tmpCnt = 0;
	for (int i = str[idx].size() - 1; i > -1; i--) {
		cowSum[tmpCnt] += str[idx][i] -'0';
		tmpCnt++;
	}
	return true;
}

void dfs(int cnt, int cow, int idx, bool *visited) {
	for (int i = idx; i < n; i++) {
		int tmpArr[21];
		for (int j = 0; j < 21; j++) {
			tmpArr[j] = cowSum[j];
		}
		if (!visited[i] && cal(i)) {
			maxCow = max(maxCow, cnt + 1);
			visited[i] = true;
			dfs(cnt + 1, cow, i + 1, visited);
			visited[i] = false;
			for (int j = 0; j < 21; j++) {
				cowSum[j] = tmpArr[j];
			}
		}
	}
}

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		cin >> str[i];
// 	}
// 	while (n > 0) {
// 		bool visited[21] = { false, };
// 		int cowSum[21] = { 0, };
// 		dfs(0, n, 0, visited);
// 		n--;
// 	}
// 	cout << maxCow << '\n';

// 	return 0;
// }

// #include <stdio.h>
 
// int n, num, result = 1;
// int cow[30];
 
// int check(int num, int cowNum)
// {
//     while (num && cowNum) {
//         if (num % 10 + cowNum % 10 >= 10)
//             return 0;
 
//         num /= 10;
//         cowNum /= 10;
//     }
 
//     return 1;
// }
 
// void dfs(int idx, int sum, int count)
// {
//     result = result > count ? result : count;
 
//     for (int i = idx; i < n; i++)
//         if (cow[i] && check(sum, cow[i])) {
//             int temp = cow[i];
//             num = sum + cow[i];
//             dfs(i + 1, num, count + 1);
//             cow[i] = temp;
//         }
// }
 
// int main(void)
// {
//     scanf("%d", &n);
 
//     for (int i = 0; i < n; i++)
//         scanf("%d", &cow[i]);
 
//     dfs(0, 0, 0);
//     printf("%d\n", result);
 
//     return 0;
// }



// #include <iostream>
 
// #define MAX 21
// #define MAX_LEN 10
// using namespace std;

// int N;
// char tempW[MAX][MAX_LEN];
// char W[MAX][MAX_LEN];
// int maxCows;
 
// void pull();
// void dfs(int count, int idx, char curW[MAX_LEN]);
// bool availableAdd(char curW[MAX_LEN], char addW[MAX_LEN]);
// void add(char retW[MAX_LEN],char curW[MAX_LEN], char addW[MAX_LEN]);
// void test();
// void test(char t[MAX_LEN]);
// void testAdd(char t[MAX_LEN]);
 
// int main(void)
// {
//     // 여기서부터 작성
//     maxCows = 0;
//     cin >> N;
//     for (int n = 1; n <= N; n++)
//     {
//         cin >> tempW[n];
//     }
//     pull();
//     char temp[MAX_LEN];
//     for (int i = 0; i < MAX_LEN; i++)
//     {
//         temp[i] = '0';
//     }
//     for (int i = 1; i < MAX; i++)
//     {
//         dfs(0, i, temp);
//     }
//     cout << maxCows << endl;
//     return 0;
// }
// void pull() {
//     for (int n = 1; n <= N; n++)
//     {
//         int k = MAX_LEN - 1;
//         for (int i = MAX_LEN - 1; i >= 0; i--)
//         {
//             if ('0' <= tempW[n][i] && tempW[n][i] <= '9')
//                 W[n][k--] = tempW[n][i];
//         }
//     }
// }
// void dfs(int count, int idx, char curW[MAX_LEN]) {
//     if (count >= N)return;
 
 
//     if (availableAdd(curW, W[idx])) {//자리올림 방생 X
//         if (maxCows < count + 1)maxCows = count + 1;
//         char temp[MAX_LEN];
 
//         add(temp, curW, W[idx]);
 
//         for (int i = idx + 1; i <= N; i++)
//         {
//             dfs(count + 1, i, temp);
//         }
//     }
// }
 
// bool availableAdd(char curW[MAX_LEN], char addW[MAX_LEN]) {
//     for (int i = MAX_LEN - 1; i >= 0; i--)
//     {
//         if ('0' <= addW[i] && addW[i] <= '9') {
//             char c = curW[i] + addW[i] - '0';
//             if ('9' < c)return false;
//         }
//     }
//     return true;
// }
 
// void add(char retW[MAX_LEN], char curW[MAX_LEN], char addW[MAX_LEN]) {
//     for (int i = MAX_LEN - 1; i >= 0; i--)
//     {
//         retW[i] = curW[i];
//         if ('0' <= addW[i] && addW[i] <= '9') {
//             retW[i] = curW[i] + addW[i] - '0';
//         }
//     }
// }