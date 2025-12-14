#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

bool visited[101];

int BFS(int start, vector<vector<int>>& v) {
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : v[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    for (auto& w : wires) {
        int a = w[0];
        int b = w[1];

        vector<vector<int>> v(n + 1);

        // 간선 하나 제거하고 그래프 구성
        for (auto& x : wires) {
            if (x == w) continue;
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }

        int cnt1 = BFS(a, v);
        int cnt2 = n - cnt1;

        answer = min(answer, abs(cnt1 - cnt2));
    }
    return answer;
}
