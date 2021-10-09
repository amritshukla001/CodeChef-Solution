#include <bits/stdc++.h>

#include <unordered_map>
typedef long long ll;
typedef unsigned long long ull;
#define whatis(x) cout << #x << " = " << x << endl;
#define whatis2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define testcase     \
    long long testn; \
    cin >> testn;    \
    while (testn--)
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loopn(i, n) for (ll i = 0; i <= n; i++)
#define loop1(i, n) for (ll i = 1; i < n; i++)
#define loop1n(i, n) for (ll i = 1; i <= n; i++)
#define vfor(i) for(auto i = (v).begin() ; i!= (v).end(); i++)

using namespace std;



void solve() {
	int n;
	cin >> n;

	int arr[n + 1];

	int count = 0, flag = 0;

	loop1n(i, n) cin >> arr[i];

	sort(arr + 1, arr + n + 1);

	loop1n(i, n) {
		if (arr[i] > i) {
			flag = 1;
			break;
		}
		else {
			count += i - arr[i];
		}
	}

	if (flag == 1 || (count % 2 == 0 && flag == 0))
		cout << "Second\n";
	else
		cout << "First\n";
}

int main() {
	IOS;
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w" , stdout);
#endif
	testcase {
		solve();
	}
	return 0;
}

