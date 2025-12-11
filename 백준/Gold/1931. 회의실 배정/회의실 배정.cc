#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> meetings;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		meetings.push_back(make_pair(start, end));
	}

	// 종료 시간 기준으로 정렬 (같으면 시작 시간 오름차순)
	sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
		});

	int count = 0;
	int last_end = 0;

	for (int i = 0; i < n; i++) {
		int start = meetings[i].first;
		int end = meetings[i].second;

		if (start >= last_end) {
			count++;
			last_end = end;
		}
	}

	cout << count << endl;
	return 0;
}
