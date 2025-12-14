#include <string>
#include <vector>

using namespace std;
const long long mod = 1234567;

long long solution(int n) {
    long long dp[2001]={0};
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }

    return dp[n]%mod;
}