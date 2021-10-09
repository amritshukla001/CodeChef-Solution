#include <bits/stdc++.h>
#include <unordered_map>
typedef long long ll;
typedef unsigned long long ull;
#define int long long
#define wi(x) cout << #x << " = " << x << endl;
#define wi2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define testcase     \
    long long testn; \
    cin >> testn;    \
    while (testn--)
#define fo(i, l, r) for (int i = l; i < r; i++)
#define fo1(i, l, r) for (int i = l; i <= r; i++)
#define fore(i, l, r) for (int i = l; i > r; i--)
#define fore1(i, l, r) for (int i = l; i >= r; i--)
#define pb push_back
#define inp(v) for (auto &x : v) cin >> x;
#define disp(v) \
    	cout << #v << "\t=\t"; \
    	for (const auto &x : v) cout << x << "\t"; \
		cout << "\n"; \

const int m = 1e9 + 7;

using namespace std;

/*Help:
https://www.geeksforgeeks.org/print-the-path-between-any-two-nodes-of-a-tree-dfs/
https://cp-algorithms.com/graph/lca.html
*/

struct LCA {
	vector<int> height, euler, first, segtree, par;
	vector<bool> visited;
	int n;

	LCA(vector<int> adj[], int nnode, int root = 1) {
		n = nnode;
		height.resize(n + 1);
		first.resize(n + 1);
		par.resize(n + 1);
		euler.reserve((n + 1) * 2);
		visited.assign(n + 1, false);
		dfs(adj, root);
		int m = euler.size();
		segtree.resize(m * 4);
		build(1, 0, m - 1);
	}

	void dfs(vector<int> adj[], int node, int p = -1, int h = 0) {
		visited[node] = true;
		height[node] = h;
		par[node] = p;
		first[node] = euler.size();
		euler.push_back(node);
		for (auto to : adj[node]) {
			if (!visited[to]) {
				dfs(adj, to, node, h + 1);
				euler.push_back(node);
			}
		}
	}

	void build(int node, int b, int e) {
		if (b == e) {
			segtree[node] = euler[b];
		} else {
			int mid = (b + e) / 2;
			build(node << 1, b, mid);
			build(node << 1 | 1, mid + 1, e);
			int l = segtree[node << 1], r = segtree[node << 1 | 1];
			segtree[node] = (height[l] < height[r]) ? l : r;
		}
	}

	int query(int node, int b, int e, int L, int R) {
		if (b > R || e < L)
			return -1;
		if (b >= L && e <= R)
			return segtree[node];
		int mid = (b + e) >> 1;

		int left = query(node << 1, b, mid, L, R);
		int right = query(node << 1 | 1, mid + 1, e, L, R);
		if (left == -1) return right;
		if (right == -1) return left;
		return height[left] < height[right] ? left : right;
	}

	int lca(int u, int v) {
		int left = first[u], right = first[v];
		if (left > right)
			swap(left, right);
		return query(1, 0, euler.size() - 1, left, right);
	}
};

bool sortbysec(pair<int, int> &a, pair<int, int> &b) {
	return a.second > b.second;
}

void solve() {
	int n, u, v;
	cin >> n;

	vector<int> adj[n + 1];

	fo(i, 1, n) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	LCA lcaobj = LCA(adj, n);

	vector<int> lvl = lcaobj.height;
	vector<int> par = lcaobj.par;

	int q;
	cin >> q;

	while (q--) {
		int node;
		cin >> node;

		vector<pair<int, int>> vnode(node);
		vector<int> nodes(node);

		int x;

		fo(i, 0, node) {
			cin >> x;
			vnode[i] = {x, lvl[x]};
			nodes[i] = x;
		}

		if (node == 1)
			cout << "NO\n";

		else {
			vector<bool> vpath(n + 1, false);
			sort(vnode.begin(), vnode.end(), sortbysec);

			int cnt = 1;
			int maxnode = vnode.begin()->first;

			while (1) {

				int nextnode = (vnode.begin() + cnt)->first;
				int lca = lcaobj.lca( maxnode, nextnode);

				if (!(lca == nextnode)) {
					while (maxnode != lca)
						vpath[maxnode] = true, maxnode = par[maxnode];

					vpath[maxnode] = true;

					while (nextnode != lca)
						vpath[nextnode] = true, nextnode = par[nextnode];
					break;
				}
				else if (cnt >= (node - 1)) break;
				else cnt++;
			}

			if (cnt == node - 1 && find(vpath.begin(), vpath.end(), true) == vpath.end())
				cout << "YES\n";
			else {
				bool ans = true;
				fo(i, 0, node) {
					if (!vpath[nodes[i]]) {
						ans = false;
						break;
					}
				}
				if (ans) cout << "YES\n";
				else cout << "NO\n";
			}

		}

	}

}




int32_t main() {
	IOS;
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w" , stdout);
#endif
	//clock_t tStart=clock();
	testcase solve();
	//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}