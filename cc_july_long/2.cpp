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

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}


void solve() {
	int n;
	cin >>  n;

	vector<int> sal(n);
	vector<int> fgcd(n);
	vector<int> bgcd(n);

	inp(sal);

	fgcd[0] = sal[0];
	bgcd[0] = sal[n - 1];


	fo(i, 1, n) {
		fgcd[i] = gcd(fgcd[i - 1], sal[i]);
		bgcd[i] = gcd(bgcd[i - 1], sal[n - i - 1]);
	}

	vector<int> minnotes(n);

	int sum = 0;
	for (auto x : sal) sum += x;

	minnotes[0] = (sum - sal[0] + bgcd[n - 2]) / bgcd[n - 2];
	minnotes[n - 1] = (sum - sal[n - 1] + fgcd[n - 2]) / fgcd[n - 2];

	fo(i, 1, n - 1) {
		int nsum = sum - sal[i];

		int ngcd = gcd(fgcd[i - 1], bgcd[n - 2 - i]);

		int minn = (nsum + ngcd) / ngcd;

		minnotes[i] = minn;
	}

	cout << *min_element(minnotes.begin(), minnotes.end()) << "\n";
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