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

const ll m = 1e9 + 7;

using namespace std;


void solve() {
	ll g, p;
	ll x;
	vector<ll> v(10);
	cin >> g >> p;

	fo(i, 0, 10) {
		cin >> x;
		v[i] = x;
	}

	reverse(v.begin(), v.end());

	ll temp = 10 - g;

	ll sum = 0;

	fo(k, 0, temp)
	sum += v[k];

	ll days = sum / p;
	ll rem = sum % p;

	ll min, max;

	min = days + 1;
	ll tot = v[temp] + rem;
	if (tot % p == 0)
		max = days + tot / p;
	else
		max = days + tot / p + 1;
	cout << min << "\t" << max << "\n";
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