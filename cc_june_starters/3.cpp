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
	int n;
	cin >> n;

	unordered_map<string, int> m;
	vector<pair<int, string>> tc;

	string s;
	int c;

	fo(i, 0, 3 * n) {
		cin >> s >> c;
		m[s] += c;
	}


	for (auto x : m) {
		//cout << x.first << "\t" << x.second << "\n";
		tc.pb(make_pair(x.second, x.first));
	}


	/*for (auto x : tc) {
		cout << x.first << "\t" << x.second << "\n";
	}*/

	sort(tc.begin(), tc.end());

	for (auto x : tc) {
		cout << x.first << "\t";
	}

	cout << "\n";
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