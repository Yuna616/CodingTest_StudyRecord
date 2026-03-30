#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long int n;

int main() {
	cin >> n;
	vector<long long> arr(n,0);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	int i, j;
	i = 0;
	j = n - 1;
	long long minusMax = -2000000000;
	long long plusMax = 2000000000;
	int ansi = 0;
	int ansj=0;
	sort(arr.begin(), arr.end());

	while (i < j) {
		long long cur = arr[i] + arr[j];
		if (cur<0) {
			if (cur > minusMax) {
				minusMax = cur;
				if (llabs(cur) < plusMax) {
					ansi = i;
					ansj = j;
				}
			}
			i += 1;
		}
		else if (cur > 0) {
			if (cur < plusMax) {
				plusMax = cur;
				if (plusMax < abs(minusMax)) {
					ansi = i;
					ansj = j;
				}
			}
			j -= 1;
		}
		else {
			ansi = i;
			ansj = j;
			break;
		}
	}
	cout << arr[ansi] << " " << arr[ansj];

}