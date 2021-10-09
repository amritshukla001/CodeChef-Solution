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

	vector<int> a(n);
	vector<int> b(n);

	inp(a);
	inp(b);

	debug(mp(a, b));

	vector<vector<int>> bina(n, vector<int>(32, 0));
	vector<vector<int>> binb(n, vector<int>(32, 0));

	debug(mp(bina, binb));

	fo(i, 0, n)	{
		int x = a[i], y = b[i];
		int bi = 0;

		while (x != 0) {
			bina[i][bi] = x & 1;
			x >>= 1;
			bi++;
		}

		bi = 0;
		while (y != 0) {
			binb[i][bi] = y & 1;
			y >>= 1;
			bi++;
		}
	}

	debug(mp(bina, binb));

	vector<int> state(n, -1);

	for (int i = 31; i >= 0; i--) {
		bool sb = true;
		fo(j, 0, n) {
			if (state[j] == 0 and bina[j][i] == 0) {
				sb = false;
				break;
			}
			else if (state[j] == 1 and binb[j][i] == 0) {
				sb = false;
				break;
			}
			else if (bina[j][i] == 0 and binb[j][i] == 0) {
				sb = false;
				break;
			}
		}
		if (sb) {
			fo(j, 0, n) {
				if (state[j] != -1) continue;
				else if (bina[j][i] == 0) state[j] = 1;
				else if (binb[j][i] == 0) state[j] = 0;
			}
		}
	}

	debug(state);

	int ans;
	int cnt = 0;

	if (state[0] == 0 || state[0] == -1) ans = a[0];
	else  {
		ans = b[0];
		cnt++;
	}


	fo(j, 1, n) {
		if (state[j] == 0 || state[j] == -1) ans &= a[j];
		else  {
			ans &= b[j];
			cnt++;
		}
	}

	cout << ans << " " << cnt << "\n";
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