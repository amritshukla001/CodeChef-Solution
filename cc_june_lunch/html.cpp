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


void solve() {
	string s;
	cin >> s;
	//wi(s);

	if (s.length() > 3) {
		if (s.at(0) == '<' && s.at(1) == '/' && s.at(s.length() - 1) == '>') {
			int flag = 0;
			fo1(i, 2, s.length() - 2) {
				char ch = s.at(i);
				if (!(ch >= 97 && ch <= 122 || ch >= 48 && ch <= 57)) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				cout << "Error" << "\n";
			else cout << "Success" << "\n";
		}
		else
			cout << "Error" << "\n";
	}
	else
		cout << "Error" << "\n";
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