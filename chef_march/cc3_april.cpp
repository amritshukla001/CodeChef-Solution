#include <bits/stdc++.h>

#include <unordered_map>
typedef long long ll;
typedef unsigned long long ull;
#define whatis(x) cout << #x << " = " << x << endl;
#define whatis2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define testcase     \
    long long testn; \
    cin >> testn;    \
    while (testn--)
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loopn(i, n) for (ll i = 0; i <= n; i++)
#define loop1(i, n) for (ll i = 1; i < n; i++)
#define loop1n(i, n) for (ll i = 1; i <= n; i++)
#define vfor(i) for(auto i = (v).begin() ; i!= (v).end(); i++)

using namespace std;

void solve() {
	int j, n, k;
	cin >> n >> k;
	string chr;
	cin >> chr;
	int res = 0;
	int cons = 0;
	for (j = 0; j < n; j++) {

		//whatis(chr.at(j));

		if (chr.at(j) == '*') {
			res++;
			//cout << res;
		}
		else
			res = 0;
		if (res == k) {
			cons = 1;
			break;
		}
	}
	if (cons == 1)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	IOS;
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w" , stdout);
#endif
	testcase {
		solve();
	}
	return 0;
}

