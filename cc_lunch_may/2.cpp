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

const ll m = 1e9 + 7;

using namespace std;

void updatestr(string &s, int ind) {
	if (s[ind] == '0')
		s[ind] = '1';
	else
		s[ind] = '0';
}

int findd(string s, int n) {
	int d = 0;
	char ch = s[0];
	fo(i, 1, n) {
		//wi(i);
		if (s[i - 1] == s[i])
			d += 2;
		else
			d += 1;
	}
	return d;
}

void solve() {

	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	int pos, temp;
	int d = 0;
	d = findd(s, n);
	//wi(d);
	//wi2(n, k);
	//wi(s);
	//wi(d);

	fo1(i, 1, k) {
		//wi(i);
		cin >> pos;
		temp = pos - 1;
		//wi(temp);
		//wi2(pos, temp);
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		if (temp == 0) {
			if (s[0] == s[1])
				d--;
			else
				d++;
		}
		else if (temp == (n - 1)) {
			if (s[n - 1] == s[n - 2])
				d--;
			else
				d++;
		}
		else {
			if (s[temp] == s[temp + 1])
				d--;
			else
				d++;
			if (s[temp] == s[temp - 1])
				d--;
			else
				d++;
		}

		cout << d << "\n";
		//wi(d);
		updatestr(s, pos - 1);
		//wi(s);
		// wi(s);
	}
}

int main() {
	IOS;
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w" , stdout);
#endif
	//clock_t tStart=clock();
	testcase solve();
	//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}