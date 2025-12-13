#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
int dxy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool visited[101][101];
int dist[101][101]={0};
int solution(vector<string> maps) {
    int answer = -1;
    int n = maps.size();
    int m = maps[0].length();
    int startx,starty;
    
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j]=='S'){
                startx=i;
                starty=j;
            }
        }
    }
    
    q.push({startx,starty});
    dist[startx][starty]=0;
    visited[startx][starty]=true;
    int findLaverTime=0;
    bool findlaver=false;
    while(!q.empty()){
        auto cur =q.front();
        int curX = cur.first;
        int curY= cur.second;
        q.pop();
        if(maps[curX][curY]=='L'){
            startx = curX;
            starty=curY;
            findLaverTime=dist[curX][curY];
            findlaver=true;
            break;
        }
        for(auto d: dxy){
            int x= curX+d[0];
            int y=curY+d[1];
            if(x>=0 && x<n && y>=0 &&y<m && !visited[x][y]&& maps[x][y]!='X'){
                dist[x][y]=dist[curX][curY]+1;
                visited[x][y]=true;
                q.push({x,y});
            }
        }
    }
    
    queue<pair<int,int>>pq;
    pq.push({startx,starty});
    memset(visited,false,sizeof(visited));
    memset(dist,0,sizeof(dist));
    bool findexit=false;
    visited[startx][starty]=true;
    while(!pq.empty()){
        auto cur =pq.front();
        int curX = cur.first;
        int curY= cur.second;
        pq.pop();
        if(maps[curX][curY]=='E'){
            answer=dist[curX][curY]+findLaverTime;
            findexit=true;
            break;
        }
        for(auto d: dxy){
            int x= curX+d[0];
            int y=curY+d[1];
            if(x>=0 && x<n && y>=0 &&y<m && !visited[x][y]&& maps[x][y]!='X'){
                dist[x][y]=dist[curX][curY]+1;
                visited[x][y]=true;
                pq.push({x,y});
            }
        }
    }
    if(!findlaver||!findexit){
        return -1;
    }
    return answer;
}