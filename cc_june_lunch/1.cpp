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

bool check(char mat[][]) {
	cout << mat[1][1];
	return true;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	char mat[n + 1][m + 1];

	int tele = n * m;
	int sub = k * k;
	int x, y;

	bool found;

	fo1(i, 1, tele) {
		cin >> x >> y;
		wi2(x, y);
		if (i % 2)
			mat[x][y] = 'A';
		else
			mat[x][y] = 'B';

		if (i >= sub - 1) {
			found = check(mat);
			if (found == true)
				break;
		}
	}
	fo1 (i, 1, n) {
		fo1 (j, 1, m)
		cout << mat[i][j] << "\t";
		cout << "\n";
	}
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