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

/*in a string of length n
in 0-based indexing
d(i,j)=j-i if j>=i
d(i,j)=n-i+j
for n=2
01
10
11
for n=3
001 100 010
101 110 011 not possible
111 possible
for n=4
0001
1010 0101
d must be multiple of n
for n=4 d=0,2
for n=5
00001
10101 01010 00101 not possible
10101 10011 not possible
for n=6
if cnt(1)=1 possible
d=2 101010 010101 possible
d=3 101010 possible
d=4 100010 not possiblw
*/

vector<int> factarr(100005);

void calcfact(int n) {

}
void solve() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	calcfact(n);
	vector<int> num(n);
	int cnt = 0;
	fo (i, 0, n) {
		num[i] = s.at(i) - '0';
		if (num[i] == 1) cnt++;
	}
	if (cnt == 1)
		cout << "0\n";
	else  {

	}
	disp(num);
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