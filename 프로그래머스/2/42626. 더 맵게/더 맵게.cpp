#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    bool okay=false;
    
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        if(cur>=K){
            okay=true;
            break;
        }
        if(cur<K){
            int cnt = (cur+pq.top()*2);
            pq.push(cnt);
            pq.pop();
            answer+=1;
        }
    }
    if(!okay){
        return -1;
    }
    return answer;
}