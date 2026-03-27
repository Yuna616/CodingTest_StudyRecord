#include <iostream>
#include <vector>
using namespace std;


int main() {
	unsigned long long int n;
	cin >> n;
	vector<unsigned long long int>ti(n+1,0);
	vector<unsigned long long int>pi(n+1,0);
	vector<unsigned long long int>dp(n+2,0);

	for (int i = 1;i <= n;i++) {
		unsigned long long int a, b;
		cin >> a >> b;
		ti[i] = a;
		pi[i] = b;
	}
	unsigned long long int ans=0;
	for (int i = n;i > 0;i--) {
		unsigned long long int curT = ti[i];
		unsigned long long int curP = pi[i];
		if (curT + i <= n+1) {
			dp[i] = max(curP + dp[curT + i],ans);
		}
		else {
			dp[i] = dp[i+1];
		}
		if (ans < dp[i]) {
			ans = dp[i];
		}
	}
	cout << ans;
}