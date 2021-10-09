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


using namespace std;

const int maxm = 5e5 + 5;

vector<int> v[maxm + 1];

void solve() {

	int n, m;
	cin >> n >> m;

	//wi2(n, m);

	int temp, l, r, rfac, mid;
	ll ans = 0;

	fo1(b, 2, n) {
		temp = b * (m / b);
		if (temp > 0) {
			l = 0;
			r = v[temp].size() - 1;
			rfac = 0;
			//wi(temp);
			//wi2(l, r);
			while (l <= r) {
				mid = (l + r) >> 1;
				if (v[temp][mid] < b) {
					rfac = mid + 1;
					l = mid + 1;
				}
				else
					r = mid - 1;
			}
			/*use lower bound
			rfac=lower_bound(v[temp].begin(),v[temp].end(),b)-v[temp].begin();
			*/
			//wi(rfac);
			ans += rfac;
		}
		else
			ans += (b - 1);

	}
	cout << ans << "\n";
}

int main() {
	IOS;
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w" , stdout);
#endif
	for (int i = 1; i <= maxm; i++) {
		for (int j = i; j <= maxm; j += i) {
			v[j].push_back(i);
		}
	}
	testcase solve();
	return 0;
}