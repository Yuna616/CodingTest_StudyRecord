#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    //롤케이크를 두 조각으로 잘라서 동생과 한 조각씩 나눠 먹으려고 합니다. 
    // 크기 상관 없이 각 조각에 동일한 가짓수의 토핑이 올라가면 공평하게 롤케이크가 나누어진 것으로 생각
    int kind=0;
    set<int>st;
    int n=topping.size();
    vector<int>dpfront(n);
    vector<int>dpback(n);

    int answer = -1;
    st.insert(topping[0]);
    dpfront[0]=1;
    for(int i=1;i<n;i++){
        if(st.find(topping[i])==st.end()){
            dpfront[i]=dpfront[i-1]+1;
        }else{
            dpfront[i]=dpfront[i-1];
        }
        st.insert(topping[i]);
    }
    st.clear();
    dpback[n-1]=1;
    st.insert(topping[n-1]);
    for(int i=n-2;i>0;i--){
        if(st.find(topping[i])==st.end()){
            dpback[i]=dpback[i+1]+1;
        }else{
            dpback[i]=dpback[i+1];
        }
        st.insert(topping[i]);
    }
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(dpfront[i]==dpback[i+1]){
            cnt+=1;
        }
    }

    return cnt;
}