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
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;


	vector<vector<int>> grp(n + 1);

	int start = 0;
	int cur = 0;
	fo(i, 0, n) {
		if (s[i] == '1') {
			start = i;
			cur = i;
			grp[i + 1].pb(i + 1);
			break;
		}
	}

	fo(j, start + 1, n) {
		if (s[j] == '1') {
			if (abs(j - cur) <= k) {
				grp[start + 1].pb(j + 1);
				cur = j;
			}
			else {
				grp[j + 1].pb(j + 1);
				start = j;
				cur = j;
				debug(grp);
			}
		}
	}

	int tg = 0;

	fo1(i, 1, n) if (grp[i].size() >= 1) tg++;
	debug(tg);

	int sind = 0;
	int se;
	fo(i, 0, n) {
		if (grp[i].size() >= 1) {
			sind = i;
			se = grp[i][grp[i].size() - 1];
			break;
		}
	}

	fo1(j, se + 1, n) {
		int temp = se + 1;
		if (grp[j].size() >= 1) {
			int temp1 = grp[j][grp[j].size() - 1];
			temp1 -= 1;
			if (abs(temp - temp1) <= k) tg--;
		}
	}
	debug(tg);
	debug(grp);
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