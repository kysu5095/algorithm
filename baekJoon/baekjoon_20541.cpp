// 앨범정리

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int n, idx = 0;

class Album {
public:
	int parent = 0;
	string name;
	set<string> s;
	map<string, int> m;
	set<string> picture;
};

vector<Album> v;

void Mkalb(string& str) {
	Album& album = v[idx];
	set<string>::iterator iter = album.s.find(str);
	if (iter != album.s.end()) {
		cout << "duplicated album name\n";
		return;
	}
	Album child_album;
	child_album.parent = idx;
	child_album.name = str;
	album.s.insert(str);
	album.m.insert(make_pair(str, (int)v.size()));
	v.push_back(child_album);
}

pair<int, int> dfs_delete(int child_idx) {
	Album album = v[child_idx];
	if (album.s.empty()) return make_pair(0, (int)album.picture.size());
	set<string>::iterator iter;
	pair<int, int> delete_album = make_pair(0, 0);
	for (iter = album.s.begin(); iter != album.s.end(); iter++) {
		pair<int, int> tmp_album = dfs_delete(album.m[*iter]);
		delete_album.first += tmp_album.first;
		delete_album.second += tmp_album.second;
	}
	delete_album.first += (int)album.s.size();
	delete_album.second += (int)album.picture.size();
	return delete_album;
}

void Rmalb(string& str) {
	Album& album = v[idx];
	pair<int, int> delete_album = make_pair(0, 0);
	if (!album.s.empty()) {
		set<string>::iterator iter;
		set<string>::reverse_iterator riter;
		if (!str.compare("-1")) {
			iter = album.s.begin();
			delete_album = dfs_delete(album.m[*iter]);
			delete_album.first++;
			string tmp = *iter;
			album.s.erase(iter);
			album.m.erase(tmp);
		}
		else if (!str.compare("0")) {
			while(!album.s.empty()) {
				iter = album.s.begin();
				pair<int, int> tmp_album = dfs_delete(album.m[*iter]);
				delete_album.first  += tmp_album.first;
				delete_album.second += tmp_album.second;
				delete_album.first++;
				string tmp = *iter;
				album.s.erase(iter);
				album.m.erase(tmp);
			}
		}
		else if (!str.compare("1")) {
			riter = album.s.rbegin();
			delete_album = dfs_delete(album.m[*riter]);
			delete_album.first++;
			string tmp = *riter;
			album.s.erase(--riter.base());
			album.m.erase(tmp);
		}
		else {
			iter = album.s.find(str);
			if (iter != album.s.end()) {
				delete_album = dfs_delete(album.m[*iter]);
				delete_album.first++;
				string tmp = *iter;
				album.s.erase(iter);
				album.m.erase(tmp);
			}
		}
	}
	cout << delete_album.first << " " << delete_album.second << '\n';
}

void Insert(string& str) {
	Album& album = v[idx];
	set<string>::iterator iter = album.picture.find(str);
	if (iter != album.picture.end()) {
		cout << "duplicated photo name\n";
		return;
	}
	album.picture.insert(str);
}

void Delete(string& str) {
	Album& album = v[idx];
	int cnt = 0;
	if (!album.picture.empty()) {
		set<string>::iterator iter;
		set<string>::reverse_iterator riter;
		if (!str.compare("-1")) {
			iter = album.picture.begin();
			album.picture.erase(iter);
			cnt++;
		}
		else if (!str.compare("0")) {
			cnt += (int)album.picture.size();
			album.picture.erase(album.picture.begin(), album.picture.end());
		}
		else if (!str.compare("1")) {
			riter = album.picture.rbegin();
			album.picture.erase(--riter.base());
			cnt++;
		}
		else {
			iter = album.picture.find(str);
			if (iter != album.picture.end()) {
				album.picture.erase(iter);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
}

void Ca(string& str) {
	Album album = v[idx];
	if (!str.compare("..")) {
		if (idx)
			idx = album.parent;
	}
	else if (!str.compare("/")) {
		idx = 0;
	}
	else {
		set<string>::iterator iter = album.s.find(str);
		if (iter != album.s.end())
			idx = album.m[str];
	}
	cout << v[idx].name << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	Album album;
	album.name = "album";
	v.push_back(album);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string command, parameter;
		cin >> command >> parameter;
		if (!command.compare("mkalb")) Mkalb(parameter);
		else if (!command.compare("rmalb")) Rmalb(parameter);
		else if (!command.compare("insert")) Insert(parameter);
		else if (!command.compare("delete")) Delete(parameter);
		else if (!command.compare("ca")) Ca(parameter);
	}
	return 0;
}