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
	string s;
	cin >> s;
	if (s.at(0) == '1') {
		string s1 = "10";
		s.erase(0, 1);
		//wi(s);
		s1.insert(2, s);
		cout << s1 << "\n";
	}
	else {
		string s1 = "1";
		s1.insert(1, s);
		cout << s1 << "\n";
	}
	//wi(s);
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