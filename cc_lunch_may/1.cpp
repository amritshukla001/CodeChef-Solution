#include <bits/stdc++.h>
#include <unordered_map>
typedef long long ll;
typedef unsigned long long ull;
#define wi(x) cout << #x << " = " << x << endl;
#define wi2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define testcase     \
    long long testn; \
    cin >> testn;    \
    while (testn--)
#define fo(i, l, r) for (ll i = l; i < r; i++)
#define fo1(i, l, r) for (ll i = l; i <= r; i++)
#define pb push_back
#define disp(v) for(auto x:v) cout << x << "\t"

const ll m = 1e9 + 7;

using namespace std;



void solve() {
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	int minm = (abs(c - a)) + (abs(d - b));

	if (k < minm)
		cout << "No\n";
	else {
		k -= minm;
		if (k % 2 == 0)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}


int main() {
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