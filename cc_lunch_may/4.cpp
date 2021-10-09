#include <bits/stdc++.h>
#include <unordered_map>

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
#define disp(v) for(auto x:v) cout << x << "\t"

const int m = 1e9 + 7;

using namespace std;

//kadane's algo to find max sum of continguous subarray
//this does not handle the cae when all the numbers are neative
int maxsubarray(int arr[], int n) {
	int cur = 0;
	int ans = INT_MIN;

	fo(i, 0, n) {
		cur += arr[i];
		//wi2(arr[i], max_pt);
		ans = max(cur, ans);
		if (cur < 0)
			cur = 0;
		wi(ans);
	}
	return ans;
}

//for k=1
void solve1(vector<int> a, int n) {
	int cur = 0;
	int ans = INT_MIN;
	fo(i, 0, n) {
		cur += a[i];
		ans = max(cur, ans);
		if (cur < 0) cur = 0;
	}
	cout << ans << "\n";
}

//for k=2
void solve2(vector<int> a, int n) {
	vector<int> pre(n);
	vector<int> suf(n);

	int cur = 0, ans = INT_MIN;

	fo(i, 0, n) {
		cur += a[i];
		ans = max(cur, ans);
		pre[i] = ans;
		if (cur < 0) cur = 0;
	}

	//wi2(ans, cur);

	cur = 0;
	ans = INT_MIN;

	for (int j = n - 1; j > 0; j--) {
		cur += a[j];
		ans = max(cur, ans);
		suf[j] = ans;
		if (cur < 0) cur = 0;
	}

	int sc;
	int res = INT_MIN;

	fo(i, 0, n - 1) {
		sc = pre[i] + 2 * suf[i + 1];
		res = max(sc, res);
	}

	cout << res << "\n";
}

void solve() {
	int n, k;
	cin >> n >> k;

	//wi2(n, k);
	vector<int> a(n);

	fo(i, 0, n) cin >> a[i];

	if (k == 1) solve1(a, n);
	else if (k == 2) solve2(a, n);
	else exit(0);
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
//https://www.codechef.com/users/chutiya12
//https://www.codechef.com/users/maximo278