#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n,S;
	cin >> n>>S;
	vector<int>arr(n, 0);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	int i = 0;
	int j = 0;
	int cur = arr[i];
	int maxLen = 1e9;
	while (j<n) {
		if (cur >= S) {
			if (j - i + 1 < maxLen) {
				maxLen = j - i + 1;
			}
			cur -= arr[i];
			i += 1;

		}
		else {
			j += 1;
			if (j < n) cur += arr[j];
		}
	}
	if (maxLen == 1e9) {
		cout << 0;
	}
	else {
		cout << maxLen;
	}

}