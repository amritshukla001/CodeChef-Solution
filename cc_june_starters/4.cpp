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

vector<pair<char, int>> solve_str(string s) {

	vector<pair<char, int>> cv;
	cv.pb({s[0], 1});

	fo(i, 1, s.length()) {
		if (s[i] == cv[cv.size() - 1].first) cv[cv.size() - 1].second++;
		else cv.pb({s[i], 1});

	}
	return cv;
}

void solve() {
	int l, h;
	cin >> l >> h;
	//wi2(l, h);
	string s;
	cin >> s;

	vector<pair<char, int>> cv = solve_str(s);

	bool ok = false;

	for (auto [ch, cnt] : cv) {
		//cout << ch << "\t" << cnt << "\n";
		if (ch == '1') continue;
		else {
			ok |= cnt >= h;
			if (ok) break;
			if (cnt > h / 2) h = 2 * (h - cnt);
			//wi(h);
		}
	}
	cout << (ok ? "YES\n" : "NO\n" );
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