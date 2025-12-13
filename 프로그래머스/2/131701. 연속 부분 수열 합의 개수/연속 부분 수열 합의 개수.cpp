#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int n=elements.size();
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    set<int>as;
    for(int i=0;i<n;i++){
        elements.push_back(elements[i]);
    }
    for(int len=1;len<=n;len++){
        for(int j=0;j<n;j++){
            int cnt=0;
            for(int i=j;i<j+len;i++){
                cnt+=elements[i];
            }
            as.insert(cnt);
        }
    }
    answer=as.size();
    return answer;
}