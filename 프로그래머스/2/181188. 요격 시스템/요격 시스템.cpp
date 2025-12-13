#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(),targets.end(),[](const vector<int>arr1, const vector<int>arr2){return arr1[1]<arr2[1];});
    int last=-1;
    for(auto & e:targets){
        if(e[0]>=last){
            answer+=1;
            last=e[1];
        }
    }
    
    return answer;
}