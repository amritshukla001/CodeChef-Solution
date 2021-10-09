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

ll binpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

ll binmodpow(ll a, ll b) {
	if (b == 1)
		return a % m;
	ll res = 1;
	while (b > 0) {
		a = a % m;
		if (b & 1)
			res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

//Help: https://www.geeksforgeeks.org/shortest-path-unweighted-graph/
//void BFS(vector<int> adj[], int src, int v, int dist[])

//bool BFS(vector<int> adj[], int src, int dest, int v, int dist[])

void BFS(vector<int> adj[], int src, int v, int dist[]) {


	list<int> queue;
	bool visited[v + 1];

	for (int i = 1; i <= v; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
	}

	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);

	while (!queue.empty()) {
		int u = queue.front();
		//wi(u);
		queue.pop_front();

		for (int i = 0; i < adj[u].size(); i++) {

			if (!(visited[adj[u][i]])) {
				visited[adj[u][i]] = true;
				dist[adj[u][i]] = dist[u] + 1;

				queue.push_back(adj[u][i]);

				//wi(adj[u][i]);
				//wi2(dist[u], dist[adj[u][i]]);

				//if (adj[u][i] == dest)
				//return true;
			}
		}
	}

	//return false;
}


/*int findShortestDistance(vector<int> adj[], int s, int dest, int v)  {

	int  dist[v + 1];

	BFS(adj, s, dest, v,  dist);

	return dist[dest];
}*/

void solve() {
	int n, q, u, v;
	cin >> n >> q;

	vector<int> adj[n + 1];

	fo(i, 1, n) {
		cin >> u >> v;
		//wi2(u, v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	/*for (auto x : adj) {
		for (auto y : x) {
			cout << y << "\t";
		}
		cout << "\n";
	}*/

	while (q--) {
		int k, d;
		cin >> k >> d;
		//wi2(k, d);
		vector<int> node(k);
		inp(node);
		//disp(node);

		int cnt = 0;

		fo(i, 0, (k - 1)) {
			//wi(node[i]);

			int dist[n + 1];
			BFS(adj, node[i], n,  dist);

			fo(j, i + 1, k) {

				//wi2(node[i], node[j]);
				//int dis = findShortestDistance(adj, node[i], node[j], n);
				//if (dis == d) cnt++;
				//wi(dis);
				//cout << "\n";
				if (d == dist[node[j]]) cnt++;

				//fo1(i, 1, v)
				//cout << dist[i] << "\t";
				//cout << "\n";
			}
		}

		cout << cnt << "\n";
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