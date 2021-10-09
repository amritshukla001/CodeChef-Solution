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

void find_places(int n, int x, vector<int> &ind, vector<int> &dig) {
	int cind = 0;
	while (n > 0) {
		int digit = n % 10;
		if (digit == x) ind.pb(cind);
		n /= 10;
		cind++;
		dig.pb(digit);
	}
}
void solve() {
	int n, x;
	cin >> n >> x;
	//wi(n);

	vector<int> ind;
	vector<int> dig;

	find_places(n, x, ind, dig);

	debug(ind);
	debug(dig);

	if (ind.size() == 0) cout << 0 << "\n";
	else {
		int max_ind = ind[ind.size() - 1];
		debug(max_ind);


		if (x == 0) {
			int fnzero = -1;
			fo(i, 0, dig.size())
			if (dig[i] > 0) {
				fnzero = i;
				break;
			}

			int nn = 0;
			int frm = -1;

			bool found = true;
			fo(i, 0, ind.size()) {
				if (ind[i] < fnzero) nn += pow(10, ind[i]);
				else {
					found = false;
					break;
				}
			}

			if (found) cout << nn << "\n";
			else {
				fo(i, fnzero, max_ind) {
					if (i == fnzero)
						nn += ((11 - dig[i]) * pow(10, i));
					else
						nn += ((10 - dig[i]) * pow(10, i));
				}
				cout << nn << "\n";
			}

		}
		else {
			bool checkp = true;
			int nn = 0;
			fo(i, 0, max_ind) {
				if (dig[i] == 0 and checkp)
					continue;
				else if (checkp) {
					nn += ((10 - dig[i]) * pow(10, i));
					checkp = false;
				}
				else
					nn += ((9 - dig[i]) * pow(10, i));
			}
			debug(dig);

			if (!checkp) {
				if (x == 9) {
					fo(i, max_ind + 1, dig.size()) {
						if (dig[i] != 8) break;
						nn += pow(10, i);
					}
					cout << nn << "\n";
				}
				else
					cout << nn << "\n";
			}
			else {
				if (x == 9) {
					int nn = pow(10, max_ind);
					fo(i, max_ind + 1, dig.size()) {
						if (dig[i] != 8) break;
						nn += pow(10, i);
					}
					cout << nn << "\n";
				}
				else {
					int nn = pow(10, max_ind);
					cout << nn << "\n";
				}
			}
		}
		debug(dig);
	}
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