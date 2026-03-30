#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>arr(n, 0);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int x;
	cin >> x;
	int i, j;
	i = 0;
	j = n - 1;
	int ans = 0;
	while (i < j) {
		if (arr[i] + arr[j] == x) {
			ans += 1;
			i += 1;
			j -= 1;
		}
		else if (arr[i] + arr[j] > x) {
			j -= 1;
		}
		else {
			i += 1;
		}
	}
	cout << ans;
}