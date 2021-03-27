// 연료가 부족해

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

int r, c, n;
int dp[1005];
struct Point {
	int y, x, f;
	bool operator < (const Point& p) const {
		return y + x < p.y + p.x;
	}
};
std::vector<Point> v;

int distance(Point& p1, Point& p2) {
	return abs(p1.y - p2.y) + abs(p1.x - p2.x);
}

bool movable(Point& p1, Point& p2) {
	return (p1.y <= p2.y && p1.x <= p2.x);
}

bool promising(int& k) {
	memset(dp, -1, sizeof(dp));
	dp[0] = k;
	for (int i = 1; i < n + 2; i++) {
		for (int j = 0; j < i; j++) {
			if (!movable(v[j], v[i])) continue;
			if (dp[j] < distance(v[j], v[i])) continue;
			dp[i] = std::max(dp[i], dp[j] - distance(v[j], v[i]) + v[i].f);
		}
	}
	if (dp[n + 1] == -1) return false;
	else return true;
}

int main() {
	scanf("%d %d", &r, &c);
	scanf("%d", &n);
	v.resize(n + 2);
	v[0] = { 1, 1, 0 };
	v[n + 1] = { r, c, 0 };
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &v[i].y, &v[i].x, &v[i].f);
	std::sort(v.begin(), v.end());
	int start = 0, end = r + c, res;
	while (start <= end) {
		int mid = (start + end) >> 1;
		if (promising(mid)) {
			res = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}
	printf("%d\n", res);
}