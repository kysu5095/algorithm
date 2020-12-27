// 후보 추천하기
// 5:40

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int student[101] = { 0, };
int recommand[1001];

class Point {
public:
	int day, num;
};
vector<Point> frame;

bool desc2(Point p1, Point p2) {
	return p1.num < p2.num;
}

bool desc(Point p1, Point p2) {
	if (student[p1.num] < student[p2.num]) return true;
	else if (student[p1.num] == student[p2.num]) {
		return p1.day < p2.day;
	}
	else
		return false;
}

int get_min() {
	sort(frame.begin(), frame.end(), desc);
	int num = frame[0].num;
	frame.erase(frame.begin());
	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int min_r, num, t = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> recommand[i];
	for (int i = 0; i < m; i++) {
		num = recommand[i];
		if (student[num]) {
			student[num]++;
			continue;
		}
		if (frame.size() == n) {
			min_r = get_min();
			student[min_r] = 0;
			frame.push_back({ t++, num });
			student[num]++;
		}
		else {
			frame.push_back({ t++, num });
			student[num]++;
			continue;
		}
	}
	sort(frame.begin(), frame.end(), desc2);
	for (int i = 0; i < frame.size(); i++)
		cout << frame[i].num << " ";
	cout << '\n';
	return 0;
}