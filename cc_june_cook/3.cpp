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


void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> root(n);
	inp(root);
	//disp(root);
	sort(root.begin(), root.end());
	//disp(root);
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;

		int cp = 0, cn = 0;
		int ind = lower_bound(root.begin(), root.end(), x) - root.begin();

		cn = root.size() - ind;
		cp = ind;
		//wi2(x, ind);
		//wi2(cp, cn);

		if (x == root[ind]) cout << "0\n";
		else if (cn == 0) cout << "POSITIVE\n";
		else if (cn % 2 == 0) cout << "POSITIVE\n";
		else cout << "NEGATIVE\n";

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
	solve();
	//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}