#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    int left=0;
    int right=people.size()-1;
    sort(people.begin(),people.end(),greater<int>());
    
    while(left<=right){
        if(left==right){
            answer++;
            break;
        }
        
        if(people[left]+ people[right]<=limit){
            answer+=1;
            left+=1;
            right-=1;
        }else{
            answer+=1;
            left+=1;
        }
    }
    return answer;
}