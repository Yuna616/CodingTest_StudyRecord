#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;

    // 소수 생성
    for (int i = 2; i <= n; i++) {
        bool sosu = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                sosu = false;
                break;
            }
        }
        if (sosu) arr.push_back(i);
    }

    int i = 0, j = 0;
    int sum = 0;
    int ans = 0;

    while (true) {
        if (sum >= n) {
            if (sum == n) ans++;
            sum -= arr[i++];
        }
        else {
            if (j == arr.size()) break;
            sum += arr[j++];
        }
    }

    cout << ans;
}