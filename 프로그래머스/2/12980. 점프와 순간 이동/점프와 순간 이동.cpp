#include <iostream>
#include <queue>
using namespace std;
int solution(int n)
{
    int ans = 0;
    while(n > 0){
        if(n % 2 == 1){
            ans++;   // 점프
            n--;
        }
        n /= 2;     // 순간이동
    }
    return ans;
}
