#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int>mp;
    for(int i=0;i<tangerine.size();i++){
        int cur = tangerine[i];
        mp[cur]+=1;
    }
    vector<pair<int,int>>arr(mp.begin(),mp.end());
    sort(arr.begin(),arr.end(),[](const pair<int,int>& a, const pair<int,int>&b){
        return a.second>b.second;
    });
    int cnt=0;
    for(auto & e:arr){
        int curHuman=e.second;
        if(k>0){
            k-=curHuman;
            cnt++;
        }else{
            break;
        }
    }
    return cnt;
}