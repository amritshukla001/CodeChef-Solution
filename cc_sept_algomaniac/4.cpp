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
	cin >> s;

	int x, y;
	cin >> x >> y;

	//for turning to east direction
	int le1 = min(2 * x, 2 * y);
	int le2 = min(3 * x, y); //for S
	int le3 = min(x, 3 * y); //for N

	//for turning to west direction
	int lw1 = min(2 * x, 2 * y);
	int lw2 = min(x, 3 * y); //for S
	int lw3 = min(3 * x, y); // for N

	vector<int> te = {le1, le2, le3};
	vector<int> tw = {lw1, lw2, lw3};

	vector<int> pe(n);
	vector<int> sw(n);


	if (s[0] == 'E') pe[0] = 0;
	else if (s[0] == 'W') pe[0] = te[0];
	else if (s[0] == 'S') pe[0] = te[1];
	else pe[0] = te[2];


	if (s[n - 1] == 'W') sw[n - 1] = 0;
	else if (s[n - 1] == 'E') sw[n - 1] = tw[0];
	else if (s[n - 1] == 'S') sw[n - 1] = tw[1];
	else sw[n - 1] = tw[2];

	for (int i = 1; i < n; i++) {
		if (s[i] == 'E') pe[i] = pe[i - 1];
		else if (s[i] == 'W') pe[i] = te[0] + pe[i - 1];
		else if (s[i] == 'S') pe[i] = te[1] + pe[i - 1];
		else pe[i] = te[2] + pe[i - 1];
	}

	for (int i = n - 2; i >= 0; i--) {
		if (s[i] == 'W') sw[i] = sw[i + 1];
		else if (s[i] == 'E') sw[i] = tw[0] + sw[i + 1];
		else if (s[i] == 'S') sw[i] = tw[1] + sw[i + 1];
		else sw[i] = tw[2] + sw[i + 1];
	}


	vector<int> fin(n);

	fin[0] = min(pe[n - 1], sw[0]);

	fo(i, 1, n) fin[i] = pe[i - 1] + sw[i];

	debug(fin);

	int min = *min_element(all(fin));

	cout << min << "\n";

	debug(mp(pe, sw));
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