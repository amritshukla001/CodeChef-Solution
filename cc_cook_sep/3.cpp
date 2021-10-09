#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define testcase     \
    long long testn; \
    cin >> testn;    \
    while (testn--)

#define wi(x) cout << #x << " = " << x << endl;
#define wi2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define fo(i, l, r) for (int i = l; i < r; i++)
#define fo1(i, l, r) for (int i = l; i <= r; i++)
#define fore(i, l, r) for (int i = l; i > r; i--)
#define fore1(i, l, r) for (int i = l; i >= r; i--)
#define mp make_pair
#define fr first
#define sc second
#define pb push_back
#define mem1(ar)   memset(ar,-1,sizeof(a))
#define mem0(ar)   memset(ar,0,sizeof(a))
#define inp(v) for (auto &x : v) cin >> x;
#define disp(v)                      \
    for(const auto &x:v) cout << x << "\t"; \
    cout << "\n";
#define all(v) v.begin(),v.end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())

template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}

const ll m = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

/*---------------------------------------------------------------------------------------------------------------------------*/
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*---------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b >>= 1;} return res;}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
/*---------------------------------------------------------------------------------------------------------------------------*/

void solve() {
	int n;
	cin >> n;
	string s;
	string p;
	cin >> s >> p;

	int c0 = 0, c1 = 0;
	int nc0 = 0, nc1 = 0;

	fo(i, 0, n) {
		if (s[i] == p[i]) {
			if (s[i] == '0') nc0++;
			else nc1++;
		}
		else if (s[i] == '0') c1++;
		else c0++;
	}
	pair<int, int> rem;
	bool fo = false;

	if (c1 > c0) rem = {1, c1 - c0};
	else if (c0 > c1) rem = {0, c0 - c1};
	else fo = true;

	debug(rem);
	if (fo) cout << "YES\n";
	else {
		if (rem.fr == 1) {
			if (nc0 + c0 >= 2 || (nc0 + c0 == 1 and nc1 + (c1 - c0) >= 1)) fo = true;
		}
		else if (rem.fr == 0) {
			if (nc1 + c1 >= 2 || (nc1 + c1 == 1 and nc0 + (c0 - c1) >= 1)) fo = true;
		}
		if (fo == true) cout << "YES\n";
		else {
			cout << "NO\n";
		}
	}
	debug(mp(c0, c1));
	debug(mp(nc0, nc1));
	//wi(n);
}

int32_t main() {
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w" , stdout);
	freopen("Error.txt", "w", stderr);
#endif
	//clock_t tStart=clock();
	testcase solve();
	//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}