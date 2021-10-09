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
	string s;
	cin >> s;

	int gp = 0;

	loop(i, s.length()) {

		if (i == 0) {
			if (s.at(0) == '1') gp++;
			continue;
		}

		if (s.at(i) == '1' && s.at(i) != s.at(i - 1))
			gp++;
	}
	cout << gp << "\n";
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

