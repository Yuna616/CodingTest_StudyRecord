#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
	vector<int>parent;
	UnionFind(int n) :parent(n+1) {
		for (int i = 1;i <= n;i++) {
			parent[i] = i;
		}
	}
	int find(int x) {
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = find(parent[x]);
	}
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a != b)parent[b] = a;
	}

};


int main() {
	int n,m;
	cin >> n;
	cin >> m;
	UnionFind uf(n);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			int a;
			cin >> a;
			if (a == 1) {
				uf.unite(i, j);
			}
		}
	}
	vector<int>plan(m,0);
	for (int i = 0;i < m;i++) {
		cin >> plan[i];
	}
	int root = uf.find(plan[0]);

	bool flag = true;
	for (int city : plan) {
		if (uf.find(city) != root) {
			cout << "NO" << "\n";
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "YES";
	}
}