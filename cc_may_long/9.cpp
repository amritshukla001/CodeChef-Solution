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

/*Euclidean algorithms (Basic and Extended)
Taken from GFG
https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
*/
// Function to return
// gcd of a and b

//https://www.google.com/search?q=gcd+method+to+find+factors+of+a+number+gfg&client=safari&rls=en&sxsrf=ALeKk02SSe4eSG2rnSOd95RN8E1xrWBOkA%3A1621054341420&ei=hVOfYN6EGdO-3LUPnoiDiAg&oq=gcd+method+to+find+factors+of+a+number+gfg&gs_lcp=Cgdnd3Mtd2l6EAMyBQgAEM0COgcIABBHELADOggIIRAWEB0QHjoFCCEQoAE6BAghEBU6BwghEAoQoAFQ5EhY_m1g63FoAXACeACAAc8CiAHOCpIBBTItNC4xmAEAoAEBqgEHZ3dzLXdpesgBCMABAQ&sclient=gws-wiz&ved=0ahUKEwie27mB8srwAhVTH7cAHR7EAIEQ4dUDCA0&uact=5
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}


void solve() {
	int k;
	cin >> k;

	int sum;
	int res;

	for (int i = 1; i <= 2 * k; i++) {
		res = gcd(k + i * i, k + (i + 1) * (i + 1));
		sum += res;
	}
	cout << sum << "\n";
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

