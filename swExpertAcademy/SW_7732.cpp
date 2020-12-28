// 시간 개념

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case, cur_total, meet_total;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		string cur_time, meet_time;
		cin >> cur_time >> meet_time;
		cur_total = ((((cur_time[0] - '0') * 10) + (cur_time[1] - '0')) * 60 * 60)
			+ (((cur_time[3] - '0') * 10) + (cur_time[4] - '0')) * 60
			+ ((cur_time[6] - '0') * 10) + (cur_time[7] - '0');
		meet_total = ((((meet_time[0] - '0') * 10) + (meet_time[1] - '0')) * 60 * 60)
			+ (((meet_time[3] - '0') * 10) + (meet_time[4] - '0')) * 60
			+ ((meet_time[6] - '0') * 10) + (meet_time[7] - '0');
		if (cur_total > meet_total)
			meet_total += 86400;

		meet_total -= cur_total;
		cout << "#" << tc << " ";
		cout << setw(2) << setfill('0') << meet_total / 3600 << ":";
		meet_total %= 3600;
		cout << setw(2) << setfill('0') << meet_total / 60 << ":";
		meet_total %= 60;
		cout << setw(2) << setfill('0') << meet_total << '\n';
	}
	return 0;
}