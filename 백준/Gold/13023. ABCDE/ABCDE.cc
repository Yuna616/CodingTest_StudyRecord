#include <iostream>
#include <vector>
using namespace std;
int n, m;
bool isOkay;
vector<int>arr[2001];

bool visited[2001]= { false };

void dfs(int x, int depth) {
	if (depth == 5) {
		isOkay = true;
		return;
	}
	visited[x] = true;
	for (int v : arr[x]) {
		if (!visited[v]) {
			dfs(v, depth +1);
			if (isOkay)return;
		}
	}
	visited[x] = false;
}

int main() {
	isOkay = false;
	cin >> n >> m;
	
	for (int i = 0;i < m;i++) {
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	for (int i = 0;i < n;i++) {
		dfs(i, 1);
		if (isOkay)break;
	}
	if (isOkay) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}