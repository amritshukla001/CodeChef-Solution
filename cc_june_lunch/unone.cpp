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

bool sortbysec(pair<int, int>&a, pair<int, int>&b) {
	return a.second >= b.second;
}

void res(unordered_map<int, int> &m) {
	vector<pair<int, int>> mp;
	for (auto it : m)
		mp.pb(it);
	sort(mp.begin(), mp.end(), sortbysec);

	for (auto& it : mp) {

		cout << it.first << "\t";
	}
	cout << "\n";
}

void solve() {
	int n;
	cin >> n;
	unordered_map<int, int> num;

	int x;

	fo(i, 0, n) {
		cin >> x;
		int temp = x;
		num[temp] = 0;
		while (x > 0) {
			//wi(x);
			if (!(x & 1)) {
				//wi(num[temp]);
				num[temp]++;
			}
			x >>= 1;
		}
	}

	res(num);

	//for (auto x : num)
	//cout << x.first << x.second << "\n";
	//disp(num);
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