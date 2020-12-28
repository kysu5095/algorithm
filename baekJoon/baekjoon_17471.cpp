// 게리맨더링

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int n, min_gap = 10000;
int arr[11];
bool is_team[11];
vector<int> v[11];

bool bfs(vector<int> team) {
	if (team.size() == 1) return true;
	int len = team.size(), val;
	bool visited[11] = { false };
	visited[team[0]] = true;
	queue<int> q;
	q.push(team[0]);
	while (!q.empty()) {
		val = q.front();
		for (int i = 0; i < v[val].size(); i++) {
			for (int j = 0; j < len; j++) {
				if (v[val][i] == team[j] && !visited[team[j]]) {
					visited[team[j]] = true;
					q.push(team[j]);
					break;
				}
			}
		}
		q.pop();
	}
	for (int i = 0; i < len; i++) {
		if (!visited[team[i]])
			return false;
	}
	return true;
}

void dfs(int idx, int cnt, vector<int> team_A, vector<int> team_B) {
	if (idx == cnt) {
		for (int i = 0; i < n; i++) {
			if (is_team[i]) team_A.push_back(i);
			else team_B.push_back(i);
		}
		if (bfs(team_A) && bfs(team_B)) {
			int min_A = 0, min_B = 0;
			for (int i = 0; i < team_A.size(); i++) min_A += arr[team_A[i]];
			for (int i = 0; i < team_B.size(); i++) min_B += arr[team_B[i]];
			min_A = abs(min_A - min_B);
			min_gap = min_gap > min_A ? min_A : min_gap;
		}
		team_A.clear();
		team_B.clear();
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!is_team[i]) {
			is_team[i] = true;
			dfs(idx + 1, cnt, team_A, team_B);
			is_team[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int input, input2;
	vector<int> team_A;
	vector<int> team_B;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < input; j++) {
			cin >> input2;
			v[i].push_back(input2 - 1);
		}
	}
	for (int i = 1; i <= n / 2; i++) 
		dfs(0, i, team_A, team_B);
	if(min_gap != 10000)
		cout << min_gap << '\n';
	else
		cout << -1 << '\n';
	return 0;
}