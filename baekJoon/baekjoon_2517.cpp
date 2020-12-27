#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

bool comp(const pii &a, const pii &b)
{
	return a.second < b.second;
}

void update(vector<int> &tree, int node, int start, int end, int idx)
{
	if (!(start <= idx && idx <= end))
		return;

	tree[node] += 1;

	if (start != end)
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, idx);
		update(tree, node * 2 + 1, mid + 1, end, idx);
	}

}
int query(vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (start > right || end < left)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;

	return query(tree, node * 2, start, mid, left, right) + query(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	int n;
	scanf("%d", &n);

	int h = (int)ceil(log2(500000));
	int tree_size = 1 << (1 + h);

	vector<pii> arr;
	vector<int> tree(tree_size);

	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		arr.push_back({ val, i });
	}

	sort(arr.begin(), arr.end());

	// 좌표 압축
	for (int i = 0; i < n; i++)
		arr[i].first = i;

	sort(arr.begin(), arr.end(), comp);

	for (int i = 0; i < n; i++)
	{
		int ans = i - query(tree, 1, 0, 500000, 0, arr[i].first) + 1;
		printf("%d\n", ans);

		update(tree, 1, 0, 500000, arr[i].first);
	}
	return 0;
}