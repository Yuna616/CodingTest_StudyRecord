#include <iostream>
#include <vector>

using namespace std;


struct UnionFind {
	vector<int>parent;
	UnionFind(int n) :parent(n+1) {
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}
	
	int find(int a) {
		if (parent[a] == a) {
			return a;
		}
		return parent[a] = find(parent[a]);

	}
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a != b)parent[b] = a;
	}

	bool same(int a, int  b) {
		a = find(a);
		b = find(b);
		if (a == b)return true;
		return false;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	UnionFind uf(n);
	for (int i = 0; i < m; i++) {
		int e,a, b;
		cin >>e>> a >> b;
		if (e == 0) {
			uf.unite(a, b);
		}
		if (e == 1) {
			if (uf.same(a, b)) {
				cout << "YES" << "\n";
				;
			}
			else {
				cout << "NO" << "\n";
			}
		}
	}

}