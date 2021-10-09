
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





ll find_fac(int n, int b)
{
	ll count = 0;
	for (int i = 1; i <= sqrt(n); i++) {

		if (n % i == 0) {

			if (n / i == i) {
				if (i < b) {
					//whatis(i);
					count++;
				}
			}


			else
			{
				if (i < b) {
					//whatis(i);
					count++;
				}
				if (n / i < b) {
					//whatis(n / i);
					count++;
				}
			}
		}
	}
	return count;
}

void solve() {
	int n, m;
	cin >> n >> m;
	ll res = 0;
	ll fac;
	ll c;
	ll temp;

	for (int i = 2; i <= n; i++) {
		temp = m - (m % i);
		//whatis(temp);
		//whatis(i);
		c = find_fac(temp, i);
		//whatis(c);
		res += c;
		//whatis(res);
		//for (auto i : v)
		//cout << i;
		//cout << "\n";

	}
	cout << res << "\n";
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

	for (int i = 2; i <= n; i++) {
		temp = m - (m % i);
		for (int j = 1; j < i; j++) {
			if (temp % j == 0)
				count++;
		}

	}
	cout << count << "\n";
	return 0;
}


