#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1; i < arr.size(); i++){
        int g = gcd(answer, arr[i]);
        answer = answer / g * arr[i];
    }
    
    return answer;
}
