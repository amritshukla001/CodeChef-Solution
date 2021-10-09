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
    for(auto &x:v) cout << x << "\t"; \
    cout << "\n";

const ll m = 1e9 + 7;
const ll allnum = 1e5 + 1;
using namespace std;

vector<int> a(allnum);
vector<int> pa(allnum);

ll binpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

ll binmodpow(ll a, ll b) {
	if (b == 1)
		return a % m;
	ll res = 1;
	while (b > 0) {
		a = a % m;
		if (b & 1)
			res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

int findnum(vector<int> &num) {
	int temp = num.size() - 1;
	int n;
	for (auto x : num) {
		n += (x * pow(10, temp));
		temp--;
	}
	return n;
}

void finddig(int x, vector<int> &num) {
	int temp = x;
	int dig;
	int cdig = 0;

	while (temp != 0) {
		dig = temp % 10;
		cdig++;
		temp /= 10;
		num.pb(dig);
	}
	reverse(num.begin(), num.end());

	vector<int> nnum = num;
	nnum.pop_back();


	reverse(nnum.begin(), nnum.end());

	num.insert(num.end(), nnum.begin(), nnum.end());
}

void allchefora() {
	fo(i, 1, allnum) {
		vector<int> num;
		finddig(i, num);
		int n = findnum(num);
		a[i] = n;
	}
}

void prefixchefora() {
	int psum = a[1];
	pa[1] = a[1];
	fo(i, 2, allnum) {
		psum += a[i];
		pa[i] = psum;
	}
}

void solve() {
	int l, r;
	cin >> l >> r;

	int sumex = pa[r] - pa[l];

	cout << binmodpow(a[l], sumex) << "\n";
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
	allchefora();
	prefixchefora();
	testcase solve();
	//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}