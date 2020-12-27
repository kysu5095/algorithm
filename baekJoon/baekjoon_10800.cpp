#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

struct Ball {
	int color, size, idx;
};

bool operator<(Ball const a, Ball const b) {
	if (a.size == b.size) return a.color < b.color;
	return a.size > b.size;
}

int N;
Ball ball[200001];
int color_sum[200001], sum;
int size_cnt[2001];
int ans[200001];

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		scanf("%d%d", &ball[n].color, &ball[n].size);
		ball[n].idx = n;
		size_cnt[ball[n].size]++;
	}
	sort(ball + 1, ball + N + 1);

	for (int n = N; n >= 1; n--) {
		color_sum[ball[n].color] += ball[n].size;
		sum += ball[n].size;
	}

	for (int n = 1; n <= N; n++) {
		int lidx = lower_bound(ball + n, ball + N + 1, ball[n]) - ball;
		int uidx = upper_bound(ball + n, ball + N + 1, ball[n]) - ball;
		// uidx - lidx 는 [n, end] 구간에서 지금 공과 똑같은 상태의 공 갯수
		ans[ball[n].idx] = sum - color_sum[ball[n].color] -
			(size_cnt[ball[n].size] - (uidx - lidx)) * ball[n].size;
		sum -= ball[n].size;
		color_sum[ball[n].color] -= ball[n].size;
		size_cnt[ball[n].size]--;
	}
	for (int n = 1; n <= N; n++)
		printf("%d\n", ans[n]);
	return 0;
}
