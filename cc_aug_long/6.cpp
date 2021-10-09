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

int find_opt(vector<vector<int>> alld, int start, int n) {
	//if (alld[n - 1][1] + start > alld[n - 1][2] || n == 0) return 0;'
	if (n == 0 || start + alld[n - 1][1] > alld[n - 1][2]) return 0;

	int x = alld[n - 1][1] + find_opt(alld, start + alld[n - 1][1], n - 1);
	int y = find_opt(alld, start, n - 1);
	wi2(x, y);
	return max(x, y);
}

bool sortbyratio(vector<int> a, vector<int> b) {
	//return ((float)(a[1]) / (float)(a[2])) < ((float)(b[1]) / (float)(b[2]));
	return a[1] < b[1];
}

bool comp(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}

void solve() {
	int n;
	cin >> n;

	vector<int> dur(n);
	inp(dur)
	vector<int> tl(n);
	inp(tl);

	vector<vector<int>> alld;
	fo(i, 0, n) if (dur[i] <= tl[i]) alld.pb({i + 1, dur[i], tl[i]});

	sort(all(alld), sortbyratio);
	debug(alld)

	//approach 1:check all possile permutation and keep the count of person
	//included in each permutation
	//print the particular permutation with max cnt of people included
	//(n*n!)
	int max_cnt = 0;
	vector<vector<int>> final;

	do {
		int start = 0;
		int cnt = 0;
		vector<vector<int>> v;
		for (auto x : alld) {
			if ((x[1] + start) > x[2]) break;
			cnt++;
			v.pb({x[0], start, x[1] + start});
			start += x[1];
		}
		if (cnt > max_cnt) {
			final = v;
			max_cnt = cnt;
		}
	} while (next_permutation(alld.begin(), alld.end(), comp));
	debug(final);
	debug(max_cnt);
	cout << max_cnt << "\n";
	for (auto x : final) cout << x[0] << "\t" << x[1] << "\t" << x[2] << "\n";

	/*int pn = alld.size();
	debug(pn);

	int tot = find_opt(alld, 0, pn);
	wi(tot);
	*/

	/*int start = 0;
	int cnt = 0;
	vector<vector<int>> v;

	for (auto x : alld) {
		if ((x[1] + start) > x[2]) break;
		cnt++;
		v.pb({x[0], start, x[1] + start});
		start += x[1];
	}

	cout << cnt << "\n";
	for (auto x : v) cout << x[0] << "\t" << x[1] << "\t" << x[2] << "\n";
	*/
	//for (auto x : v) cout << x[0] << "\t" << x[1] << "\t" << x[2] << "\n";
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