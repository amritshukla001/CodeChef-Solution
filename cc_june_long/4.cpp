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
#define disp(v) for(auto x:v) cout << x << "\t"

const ll m = 1e9 + 7;

const int MAXN = 1e6;

using namespace std;


vector<int> near1(vector<int> a, int n) {
	vector<int> n1(n + 1);
	int temp = -1;
	int x;
	for (x = 1; x <= n; x++) {
		if (a[x] == 1) {
			n1[x] = 0;
			temp = x;
		}
		else
			n1[x] = temp;
	}
	//disp(n1);
	//cout << "\n";
	return n1;
}

vector<int> near2(vector<int> a, int n) {
	vector<int> n2(n + 1);
	int temp = -1;
	int x;
	for (x = n; x >= 1; x--) {
		if (a[x] == 2) {
			n2[x] = 0;
			temp = x;
		}
		else
			n2[x] = temp;
	}
	//disp(n2);
	//cout << "\n";
	return n2;
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n + 1);

	fo1(i, 1, n) cin >> a[i];

	vector<int> n1 = near1(a, n);
	vector<int> n2 = near2(a, n);

	//near1(a, n);
	//near2(a, n);

	int b;

	/*disp(a);
	cout << "\n";
	disp(n1);
	cout << "\n";
	disp(n2);
	cout << "\n";
	*/
	fo1(i, 1, m)  {
		cin >> b;
		//wi(b);
		if (b == 1)
			cout << "0\n";
		else {
			int li = n1[b];
			int ri = n2[b];
			//wi2(li, ri);
			if (ri == 0 || li == 0)
				cout << "0\n";
			else if (ri == -1 && li == -1)
				cout << "-1" << "\t";
			else if (ri == -1)
				cout << b - li << "\t";
			else if (li == -1)
				cout << ri - b << "\t";
			else {
				int res = ((ri - b) <= (b - li)) ? (ri - b) : (b - li);
				cout << res << "\t";
			}
			//wi2(ri, li);
		}
	}
	cout << "\n";
}

int32_t main() {
	IOS;
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w" , stdout);
#endif
	//clock_t tStart = clock();
	testcase solve();
	//printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	return 0;
}