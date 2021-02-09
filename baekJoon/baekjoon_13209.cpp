// 검역소

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <limits.h>
#define ll long long
#define MAX 100000
using namespace std;

int T, n, k, cnt;
ll arr[MAX + 2];
bool visited[MAX + 2];
vector<int> v[MAX + 2];

ll dfs(int idx, ll& max_val){
    ll sum_val = arr[idx];
    priority_queue<ll> pq;
    visited[idx] = true;

    for(int i = 0; i < v[idx].size(); i++){
        if(visited[v[idx][i]]) continue;
        ll val = dfs(v[idx][i], max_val);
        sum_val += val;
        pq.push(val);
    }
    while(!pq.empty() && sum_val > max_val){
        sum_val -= pq.top();
        pq.pop();
        cnt++;
    }
    return sum_val;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    int A, B;
    ll l, r, m, res;
    while(T--){
        l = r = res = 0;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            v[i].clear();
            l = max(l, arr[i]);
            r += arr[i];
        }
        for(int i = 0; i < n - 1; i++){
            cin >> A >> B;
            v[A].push_back(B);
            v[B].push_back(A);
        }
        while(l <= r){
            memset(visited, false, sizeof(visited));
            m = (l + r) >> 1;
            cnt = 0;
            dfs(1, m);
            if(cnt <= k){
                res = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        cout << res << '\n';
    }
    return 0;
}