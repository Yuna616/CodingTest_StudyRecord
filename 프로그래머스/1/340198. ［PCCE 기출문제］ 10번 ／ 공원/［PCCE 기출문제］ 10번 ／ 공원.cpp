#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;
int n,m;

bool isOkay(vector<vector<string>>&park, int i,int j,int l){
    bool okay=false;
    for(int a=i;a<i+l;a++){
        for(int b=j;b<j+l;b++){
            if(a<0||a>=n || b<0 && b>=m)continue;
            if(park[a][b]!="-1")return false;
        }
    }
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;

    sort(mats.begin(), mats.end(),greater<>());

    n = park.size();        // 행 개수
    m = park[0].size();     // 열 개수

    for(int curMat:mats){
        for (int i = 0; i <= n-curMat; i++) {           
            for (int j = 0; j <= m-curMat; j++) {
                if(isOkay(park,i,j,curMat)){
                    answer = max(answer,curMat);
                }
                
            }
        }
    }
    
    if(answer==0)return -1;
    return answer;
}
