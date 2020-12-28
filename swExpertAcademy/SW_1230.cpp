// 암호문 3

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void insert_data(int start, int cnt){
    int len = start;
    int num;
    while(cnt--){
        cin >> num;
        v.insert(v.begin() + len, num);
        len++;
    }
}

void delete_data(int start, int cnt){
    v.erase(v.begin() + start, v.begin() + start + cnt);
}

void add_data(int cnt){
    int num;
    while(cnt--){
        cin >> num;
        v.push_back(num);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int array_length, num, cnt, start, end;
    char c;
    for(int tc = 1; tc <= 10; tc++){
        cin >> array_length;
        v.clear();
        while(array_length--){
            cin >> num;
            v.push_back(num);
        }

        cin >> cnt;
        while(cnt--){
            cin >> c;
            switch (c)
            {
            case 'I':{
                cin >> start >> end;
                insert_data(start, end);
                break;
            }
            case 'D':{
                cin >> start >> end;
                delete_data(start, end);
                break;
            }
            case 'A':{
                cin >> start;
                add_data(start);
                break;
            }
            }
        }
        cout << "#" << tc << " ";
        for(int i = 0; i < 10; i++){
            cout << v[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}