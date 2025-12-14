#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    int S = brown+yellow;
    for(int width=S-1; width>0; width--){
        if(S%width==1)continue;
        
        int height = S/width;
        int y = (width-2)*(height-2);
        int b = S-y;
        
        if(y==yellow && b==brown){
            answer[0]=width;
            answer[1]=height;
            break;
        }
    }
    return answer;
}