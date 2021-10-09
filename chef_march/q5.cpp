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

ll func_max(ll a, ll b) {
	if (a > b)
		return a;
	return b;
}

ll func_min(ll a, ll b) {
	if (a > b)
		return b;
	return a;
}

ll solve(ll n, ll e, ll h, ll a, ll b, ll c) {

	if (n <= 0)
		return 0;
	ll ans = 1e15;
	ll temp;
	if (e >= 2 * n) {//for omelette
		ans = func_min(ans, n * a);
		//cout << "o" << "\n";
		//whatis(ans);
	}
	if (h >= 3 * n) {//for shake
		ans = func_min(ans, n * b);
		//cout << "s" << "\n";
		//whatis(ans);
	}
	if (h >= n && e >= n) {//for cake
		ans = func_min(ans, n * c);
		//cout << "c" << "\n";
		//whatis(ans);
	}
	if (h - n >= 2  && (h - n) >= 2 * (n - e)) {//for shake and cake
		if (b < c)
			temp = func_min(n - 1, (h - n) / 2);
		else
			temp = func_max((ll)1, n - e);
		ans = func_min(ans, temp * (b - c) + n * c);
		//cout << "s,c" << "\n";
		//whatis(ans);
	}
	if (e - n >= 1 && n - h <= e - n) {//for omelette and cake
		if (a < c)
			temp = func_min(n - 1, e - n);
		else
			temp = func_max((ll)1, n - h);
		ans = func_min(ans, temp * (a - c) + n * c);
		//cout << "o,c" << "\n";
		//whatis(ans);
	}
	if (6 * n - 2 * h + 4 <= 3 * e && e >= 2 ) { //for  omelette and  shake
		if (a < b)
			temp = func_min(n - 1, e / 2);
		else
			temp = func_max((ll)1, (3 * n - h) / 3);
		ans = func_min(ans, temp * (a - b) + n * b);
		//cout << "o,c" << "\n";
		//whatis(ans);
	}
	if (n >= 3 && e >= 3 && h >= 4) { //for omelette and cake and shake
		//cout << "o,s,c" << "\n";
		ans = func_min(ans, (a + b + c + solve(n - 3, e - 3, h - 4, a, b, c)));
		//whatis(ans);
	}

	return ans;
	//ll o = 2 * e, cm = 3 * h, cc = e + h;
	//cout << o << cm << cc;
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
		ll n, e, h, a, b, c;
		cin >> n >> e >> h >> a >> b >> c;
		ll ans = solve(n, e, h, a, b, c);
		if (ans == 1e15 || ans <= 0)
			cout << "-1\n";
		else
			cout << ans << "\n";
	}
	return 0;
}

