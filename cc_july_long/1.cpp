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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	inp(a);
	int op = 0, codd = 0;

	fo(i, 0, a.size()) {
		if (a[i] & 1) {
			codd++;
			a[i]--;
		}
	}

	if (codd > 0)op += (codd % k) ? (codd / k + 1) : (codd / k);


	int cnt = 0;
	while (a.size() != 0) {
		int codd = 0;
		fo(i, 0, a.size()) {
			a[i] >>= 1;
			if (a[i] & 1) codd++;
		}
		vector<int> :: iterator itr;
		itr = remove(a.begin(), a.end(), 0);
		a.erase(itr, a.end());
		if (codd > 0)op += (codd % k) ? (codd / k + 1) : (codd / k);
	}
	cout << op  << "\n";

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