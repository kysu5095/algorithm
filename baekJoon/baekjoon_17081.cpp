// RPG Extreme

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int n, m;
char arr[101][101];
string command;
int dy[4] = { 0, 0, 1, -1 }; // R L D U
int dx[4] = { 1, -1, 0, 0 };

class ACTOR {
public:
	int y, x, LV, cur_hp, max_hp, att, weapon_att, def, weapon_def, cur_exp, max_exp, jewelry_cnt;
	map<string, int> Jewelry;
};
ACTOR actor;

class ENERMY {
public:
	int y, x, w, a, h, e;
	string name;
};
vector<ENERMY> enermy;
map<pair<int, int>, int> enermy_index;

class ITEM {
public:
	char type;
	int y, x, s;
	string _s;
};
vector<ITEM> item;
map<pair<int, int>, int> item_index;

int get_direction(char& c) {
	if (c == 'U') return 3;
	else if (c == 'D') return 2;
	else if (c == 'L') return 1;
	else return 0;
}

void game(int sy, int sx) {
	int& y = actor.y;
	int& x = actor.x;
	int d, turn;
	for (turn = 0; turn < command.size(); turn++) {
		d = get_direction(command[turn]);
		y += dy[d];
		x += dx[d];
		if (y < 0 || y == n || x < 0 || x == m || arr[y][x] == '#') {
			y -= dy[d];
			x -= dx[d];
		}
		if (arr[y][x] == '.') continue;
		else if (arr[y][x] == '^') {
			if (actor.Jewelry["DX"] == 0) actor.cur_hp -= 5;
			else actor.cur_hp -= 1;
			if (actor.cur_hp <= 0) {
				if (actor.Jewelry["RE"] == 1) {
					actor.Jewelry["RE"] = 0;
					actor.jewelry_cnt--;
					y = sy, x = sx, actor.cur_hp = actor.max_hp;
					continue;
				}
				actor.cur_hp = 0;
				break;
			}
		}
		else if (arr[y][x] == 'B') {
			arr[y][x] = '.';
			int idx = item_index[make_pair(y, x)];
			if (item[idx].type == 'W') actor.weapon_att = item[idx].s;
			else if (item[idx].type == 'A') actor.weapon_def = item[idx].s;
			else {
				string name = item[idx]._s;
				if (actor.Jewelry[name] == 1 || actor.jewelry_cnt == 4) continue;
				actor.Jewelry[name] = 1;
				actor.jewelry_cnt++;
			}
		}
		else {
			int idx = enermy_index[make_pair(y, x)];
			int enermy_hp = enermy[idx].h;
			bool first_turn = true;
			while (true) {
				if (first_turn && actor.Jewelry["HU"] == 1) actor.cur_hp = actor.max_hp;
				if (first_turn && actor.Jewelry["CO"] == 1) {
					if (actor.Jewelry["DX"] == 1) enermy[idx].h -= max(1, ((actor.att + actor.weapon_att) * 3 - enermy[idx].a));
					else enermy[idx].h -= max(1, ((actor.att + actor.weapon_att) * 2 - enermy[idx].a));
				}
				else enermy[idx].h -= max(1, (actor.att + actor.weapon_att - enermy[idx].a));
				if (enermy[idx].h <= 0) break;

				if (first_turn && actor.Jewelry["HU"] == 1) actor.cur_hp -= 0;
				else actor.cur_hp -= max(1, (enermy[idx].w - actor.def - actor.weapon_def));
				if (actor.cur_hp <= 0) break;

				first_turn = false;
			}

			if (enermy[idx].h <= 0) {
				if (actor.Jewelry["HR"] == 1) {
					actor.cur_hp += 3;
					if (actor.cur_hp > actor.max_hp) actor.cur_hp = actor.max_hp;
				}
				double exp = (double)enermy[idx].e;
				if (actor.Jewelry["EX"] == 1) exp *= 1.2;
				actor.cur_exp += (int)exp;
				if (actor.cur_exp >= actor.max_exp) {
					actor.LV++;
					actor.max_hp += 5;
					actor.att += 2;
					actor.def += 2;
					actor.cur_hp = actor.max_hp;
					actor.max_exp = actor.LV * 5;
					actor.cur_exp = 0;
				}
				if (arr[y][x] == 'M') break;
				arr[y][x] = '.';
			}
			else {
				if (actor.Jewelry["RE"] == 1) {
					actor.Jewelry["RE"] = 0;
					actor.jewelry_cnt--;
					enermy[idx].h = enermy_hp;
					y = sy, x = sx, actor.cur_hp = actor.max_hp;
					continue;
				}
				actor.cur_hp = 0;
				break;
			}
		}
	}
	bool finish = true;
	if (actor.cur_hp > 0) arr[y][x] = '@';
	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
	if (turn != command.size()) turn++, finish = false;
	cout << "Passed Turns : " << turn << '\n';
	cout << "LV : " << actor.LV << '\n';
	cout << "HP : " << actor.cur_hp << "/" << actor.max_hp << '\n';
	cout << "ATT : " << actor.att << "+" << actor.weapon_att << '\n';
	cout << "DEF : " << actor.def << "+" << actor.weapon_def << '\n';
	cout << "EXP : " << actor.cur_exp << "/" << actor.max_exp << '\n';
	if (actor.cur_hp <= 0) {
		if (arr[y][x] == '^') cout << "YOU HAVE BEEN KILLED BY SPIKE TRAP..\n";
		else cout << "YOU HAVE BEEN KILLED BY " << enermy[enermy_index[make_pair(y, x)]].name << "..\n";
	}
	else {
		if (finish) cout << "Press any key to continue.\n";
		else cout << "YOU WIN!\n";
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int sy, sx, enermy_cnt = 0, item_cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '@') sy = i, sx = j, arr[i][j] = '.';
			else if (arr[i][j] == 'M' || arr[i][j] == '&') enermy_cnt++;
			else if (arr[i][j] == 'B') item_cnt++;
		}
	}
	cin >> command;
	int y, x, w, a, h, e;
	string name;
	enermy.resize(enermy_cnt);
	for (int i = 0; i < enermy_cnt; i++) {
		cin >> y >> x >> name >> w >> a >> h >> e;
		y--;
		x--;
		enermy[i] = { y, x, w, a, h, e, name };
		enermy_index[make_pair(y, x)] = i;
	}

	char t;
	item.resize(item_cnt);
	for (int i = 0; i < item_cnt; i++) {
		cin >> y >> x >> t;
		y--;
		x--;
		if (t == 'O') {
			cin >> name;
			item[i] = { t, y, x, 0, name };
		}
		else {
			cin >> w;
			item[i] = { t, y, x, w };
		}
		item_index[make_pair(y, x)] = i;
	}

	actor = { sy, sx, 1, 20, 20, 2, 0, 2, 0, 0, 5, 0 };
	actor.Jewelry["HR"] = 0;
	actor.Jewelry["RE"] = 0;
	actor.Jewelry["CO"] = 0;
	actor.Jewelry["EX"] = 0;
	actor.Jewelry["DX"] = 0;
	actor.Jewelry["HU"] = 0;
	actor.Jewelry["CU"] = 0;
	game(sy, sx);
	return 0;
}