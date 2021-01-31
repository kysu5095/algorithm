// 메뉴 리뉴얼
// 4:35 - 5:30

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int max_len[11] = { 0, };
bool visited[11] = { false, };
set<string> s;
map<string, int> m;

void dfs(string& original, string& des, int idx, int cnt, int& goal) {
	if (cnt == goal) {
		s.insert(des);
		m[des]++;
		max_len[(int)des.size()] = max(max_len[(int)des.size()], m[des]);
		return;
	}
	for (int i = idx; i < original.size(); i++) {
		des.push_back(original[i]);
		dfs(original, des, i + 1, cnt + 1, goal);
		des.pop_back();
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	int len;
	for (string order : orders) {
		string str = "";
		sort(order.begin(), order.end());
		len = order.size();
		for (int i = 2; i <= len; i++)
			dfs(order, str, 0, 0, i);
	}
	for (int idx : course)
		visited[idx] = true;

	vector<string> answer;
	set<string>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		if (m[*iter] <= 1) continue;
		string str = *iter;
		if (!visited[(int)str.size()]) continue;
		if (max_len[(int)str.size()] != m[*iter]) continue;
		answer.push_back(*iter);
	}
	sort(answer.begin(), answer.end());
	return answer;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	return 0;
}