// 괄호 추가하기 //
//////////////////

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int len;
string problem;
int num[11] = { 0, };
char oper[10] = { 0, };

int cal(int n) {
	char tmp = oper[n];
	switch (tmp)
	{
	case '+':
		return num[n] + num[n + 1];
	case '-':
		return num[n] - num[n + 1];
	case '*':
		return num[n] * num[n + 1];
	default:
		break;
	}
}

void dfs(bool jud[], int cnt) {
	///////////////
	//  계산하기  //
	///////////////
	for (int i = cnt; i + 2 < problem.size(); i + 2) {
		if (!jud[i]) {
			jud[i] = jud[i + 2] = true;
			dfs(jud, i + 4);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int numCnt = 0;
	int operCnt = 0;
	bool jud[11] = { false, };
	queue<int> q;
	cin >> len >> problem;
	for (int i = 0; i < problem.size(); i++) {
		if (i / 2 == 0)
			num[numCnt++] = problem[i] - '0';
		else
			oper[operCnt++] = problem[i];
	}
	dfs(jud, 1);

	return 0;
}