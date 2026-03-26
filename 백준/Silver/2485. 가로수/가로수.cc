#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int dist[100001];

int gcd(int a, int b) {
	int r = a % b;
	if (r == 0) {
		return b;
	}
	else {
		return gcd(b, r);
	}
}
int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0;i < n-1;i++) {
		dist[i] = arr[i+1] - arr[i];
	}
	int curgcd = dist[0];

	for (int i = 1;i < n - 1;i++) {
		curgcd = gcd(curgcd, dist[i]);
	}

	for (int i = 0;i < n - 1;i++) {
		ans += (dist[i] / curgcd) - 1;
	}

	cout << ans;
	return 0;
}