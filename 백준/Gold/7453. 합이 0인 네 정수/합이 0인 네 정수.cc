#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long A[4001] = { 0 };
long long B[4001] = { 0 };
long long C[4001] = { 0 };
long long D[4001] = { 0 };


vector<long long>E;
vector<long long>AB;


int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < 4;j++) {
			long long aa;
			cin >> aa;
			if (j == 0) {
				A[i] = aa;
			}
			else if (j == 1) {
				B[i] = aa;
			}
			else if (j == 2) {
				C[i] = aa;
			}
			else {
				D[i] =aa;
			}
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			long long cur = C[i] + D[j];
			E.push_back(cur);
		}
	}
	sort(E.begin(), E.end());

	long long ans = 0;

	// A + B
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long target = -(A[i] + B[j]);

			auto l = lower_bound(E.begin(), E.end(), target);
			auto r = upper_bound(E.begin(), E.end(), target);

			ans += (r - l);
		}
	}

	cout << ans;


}