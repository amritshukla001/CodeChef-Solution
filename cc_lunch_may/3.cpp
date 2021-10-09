#include <bits/stdc++.h>
#include <unordered_map>
typedef long long ll;
typedef unsigned long long ull;
#define wi(x) cout << #x << " = " << x << endl;
#define wi2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define testcase     \
    long long testn; \
    cin >> testn;    \
    while (testn--)
#define fo(i, l, r) for (ll i = l; i < r; i++)
#define fo1(i, l, r) for (ll i = l; i <= r; i++)
#define pb push_back
#define disp(v) for(auto x:v) cout << x << "\t"

const int n = 1e7 + 7;

using namespace std;

vector<bool> prime(n, true);
vector<int> prime_prefix(n);

void prime_sieve() {
  prime[0] = prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= n; j += i) prime[j] = false;
    }
  }
}

void prec() {
  int cnt = 0;
  fo1(i, 1, n) {
    if (prime[i])
      cnt++;
    prime_prefix[i] = cnt;
  }
}

void solve() {
  int n;
  cin >> n;
  if (n == 2)
    cout << "1\n";
  else if (n == 3)
    cout << "2\n";
  else
    cout << 1 + (prime_prefix[n] - prime_prefix[n / 2]) << "\n";
}

int main() {
  IOS;
#ifndef ONLINE_JUDGE
  //for getting input from input.txt
  freopen("input.txt", "r", stdin);
  //for writing output to output.txt
  freopen("output.txt", "w" , stdout);
#endif
  prime_sieve();
  prec();
  //clock_t tStart=clock();
  testcase solve();
  //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  return 0;
}