#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int round=0;
    
    int left=a;
    int right=b;
    while(left!=right){
        answer+=1;
        if(left%2==1){
            left=(left+1)/2;
        }else if(left%2==0){
            left=left/2;
        }
        if(right%2==1){
            right=(right+1)/2;
        }else if(right%2==0){
            right=right/2;
        }
        
    }

    return answer;
}