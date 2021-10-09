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
	int D, d, A, B, C;
	cin >> D >> d >> A >> B >> C;
	int temp = D * d;
	if (temp < 10)
		cout << "0\n";
	else if (temp >= 10 && temp < 21)
		cout << A << "\n";
	else if (temp >= 21 && temp < 42)
		cout << B << "\n";
	else
		cout << C << "\n";
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