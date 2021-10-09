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
#define pb push_back
#define inp(v) for (auto &x : v) cin >> x;
#define disp(v)                      \
    for(auto x:v) cout << x << "\t"; \
    cout << "\n";

const ll m = 1e9 + 7;

using namespace std;

/*Help:
https://www.geeksforgeeks.org/print-the-path-between-any-two-nodes-of-a-tree-dfs/
https://cp-algorithms.com/graph/lca.html
*/

bool IsSubset(vector<int> A, vector<int> B)
{
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	return includes(A.begin(), A.end(), B.begin(), B.end());
}

bool sortbysec(pair<int, int> &a, pair<int, int> &b) {
	return a.second > b.second;
}

void dfs(vector<int> adj[], int node, int l,
         int p, int lvl[], int par[])
{
	lvl[node] = l;
	par[node] = p;

	for (int child : adj[node])
	{
		//wi(child);
		if (child != p)
			dfs(adj, child, l + 1, node, lvl, par);
	}
}

int LCA(int a, int b, int par[], int lvl[]) {

	if (lvl[a] > lvl[b])
		swap(a, b);


	int diff = lvl[b] - lvl[a];


	while (diff != 0)
	{
		b = par[b];
		diff--;
	}


	if (a == b)
		return a;

	while (a != b)
		a = par[a], b = par[b];

	return a;
}

void path(vector<int> adj[], int a, int b, int n, int par[], int lvl[], vector<int> &vpath) {

	int lca = LCA(a, b, par, lvl);

	//wi(lca);

	while (a != lca)
		vpath.push_back(a), a = par[a];

	vpath.push_back(a);

	vector<int> temp;

	while (b != lca)
		temp.push_back(b), b = par[b];

	reverse(temp.begin(), temp.end());

	for (int x : temp)
		vpath.push_back(x);
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

	/*
	for (auto x : adj) {
		for (auto y : x) {
			cout << y << "\t";
		}
		cout << "\n";
	}*/


	int lvl[n + 1];
	int par[n + 1];

	dfs(adj, 1, 0, -1, lvl, par);


	/*
	fo1(i, 1, n)
	cout << lvl[i] << "\t";

	cout << "\n";

	fo1(i, 1, n)
	cout << par[i] << "\t";

	cout << "\n";
	*/
	int q;
	cin >> q;

	//wi(q);

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

		//inp(nodes);
		//disp(nodes);

		if (node == 1)
			cout << "NO\n";

		else {
			sort(vnode.begin(), vnode.end(), sortbysec);

			/*for (auto x : vnode) {
				cout << x.first << "\t" << x.second;
				cout << "\n";
			}*/
			vector<int> vpath;
			int cnt = 1;
			int maxnode = vnode.begin()->first;



			while (1) {
				if (!(LCA( maxnode, (vnode.begin() + cnt)->first, par, lvl) == (vnode.begin() + cnt)->first)) {
					path(adj, vnode.begin()->first, (vnode.begin() + cnt)->first,  n, par, lvl, vpath);
					break;
				}
				else if (cnt >= (node - 1)) break;
				else cnt++;
				//wi(cnt);
				//disp(vpath);
				//disp(nodes);

			}
			if (cnt == (node - 1) && vpath.size() == 0) vpath = nodes;
			//disp(vpath);
			cout << ((IsSubset(vpath, nodes)) ? "YES\n" : "NO\n");

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