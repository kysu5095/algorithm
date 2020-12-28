// 드래곤 앤 던전

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int n;
long long ATK;
vector <pair<int, pair<int, int>>> v;

bool game(long long HP) {
	long long atk = ATK;
	long long hp = HP;
	int enermy_atk, enermy_hp;
	long long val;
	int len = v.size();
	for (int i = 0; i < len; i++) {
		if (v[i].first == 1) {
			enermy_atk = v[i].second.first;
			enermy_hp = v[i].second.second;
			
			if (enermy_hp % atk)
				val = enermy_hp / atk + 1;
			else
				val = enermy_hp / atk;
			hp -= enermy_atk * (val - 1);
			if (hp <= 0)
				return false;
			/*if (enermy_hp / atk > hp / enermy_atk)
				return false;
			if(enermy_hp % atk)
				hp -= (enermy_hp / atk) * enermy_atk;
			else 
				hp -= (enermy_hp / atk) * enermy_atk;*/
			/*if ((enermy_hp - 1) / atk > (hp - 1) / enermy_atk)
				return false;
			hp -= (enermy_hp - 1) / atk * enermy_atk;*/
		}
		else {
			atk += v[i].second.first;
			if (hp + v[i].second.second >= HP)
				hp = HP;
			else
				hp += v[i].second.second;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, a, h;
	long long start, mid, last, res;

	cin >> n >> ATK;
	for (int i = 0; i < n; i++) {
		cin >> t >> a >> h;
		v.push_back(make_pair(t, make_pair(a, h)));
	}
	start = 1;
	last = LLONG_MAX;
	while (start <= last) {
		mid = (start >> 1) + (last >> 1);
		if (game(mid)) {
			last = mid - 1;
			res = mid;
		}
		else
			start = mid + 1;
	}
	cout << res << '\n';
	return 0;
}