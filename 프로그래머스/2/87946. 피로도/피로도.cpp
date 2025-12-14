#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[8];   // 던전 최대 8개
int answer = 0;

void DFS(const vector<vector<int>>& dungeons, int curM, int cnt) {
    answer = max(answer, cnt);

    for (int i = 0; i < dungeons.size(); i++) {
        int need = dungeons[i][0];
        int cost = dungeons[i][1];

        if (!visited[i] && curM >= need) {
            visited[i] = true;
            DFS(dungeons, curM - cost, cnt + 1);
            visited[i] = false; // 백트래킹
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    DFS(dungeons, k, 0);
    return answer;
}
