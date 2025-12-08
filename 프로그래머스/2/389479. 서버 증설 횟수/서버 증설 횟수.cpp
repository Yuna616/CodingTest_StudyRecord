#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int arr[24] = {0};  // 각 시간대에 운영 중인 서버 수

    for(int i=0;i<=23;i++){
        int curServer=arr[i];
        if(players[i]>=m){
            int mustServer = players[i]/m;
            if(mustServer>curServer){
                for(int j=i;j<k+i;j++){
                    if(j>23)continue;
                    arr[j]+=(mustServer-curServer);
                }
                answer+=mustServer-curServer;
            }
        }
    }

    return answer;
}
