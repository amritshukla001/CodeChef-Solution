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

	vector<int> num(n);
	vector<int> even;
	vector<int> odd;

	fo(i, 0, n) {
		cin >> num[i];
		if (num[i] % 2)
			odd.pb(num[i]);
		else
			even.pb(num[i]);
	}
	//disp(num);
	//disp(even);
	//disp(odd);

	for (auto i = even.begin(); i != even.end() ; ++i)
		cout << *i << "\t";

	for (auto i = odd.begin(); i != odd.end() ; ++i)
		cout << *i << "\t";
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