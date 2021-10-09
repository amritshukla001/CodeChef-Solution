#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define wi(x) cout << #x << " = " << x << endl;
#define wi2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;

int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w" , stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		long n, i, x = 0, b[33], count = 0, kc;
		cin >> n >> kc;
		wi2(n, kc);
		vector<int>v[n];
		int a[n], c[n];
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (i = 0; i < n; i++)
		{
			cout << a[i];
		}

		cout << "\n";

		sort(a, a + n);

		for (i = 0; i < n; i++)
		{
			cout << a[i];
		}

		cout << "\n";

		int m = 0;

		m = int(log2(a[n - 1]) + 1);

		wi(m);
		//cout<<a[n-1]<<" "<<m<<" "<<endl;
		for (i = 0; i < n; i++)
		{
			c[i] = int(log2(a[i]) + 1);
			wi(c[i]);
		}//cout<<c[i];

		for (i = 0; i < n; i++)
		{	//cout<<a[i]<<" ";
			for (int k = 0; a[i] > 0; k++)
			{
				b[k] = a[i] % 2;
				a[i] = a[i] / 2;
				count++;
			} //cout<<count<<" ";
			//int c[count];
			for (int k = count - 1; k >= 0; k--)
			{
				x = b[k];
				v[i].push_back(x);
			}
			count = 0;
		}

		for (auto x : v) {
			for (auto y : x) {
				cout << y << "\t";
			}
			cout << "\n";
		}

		cout << "\n";

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < (m - c[i]); j++)
			{
				v[i].insert(v[i].begin(), 0);
			}
		}

		for (auto x : v) {
			for (auto y : x) {
				cout << y << "\t";
			}
			cout << "\n";
		}

		int e[m];

		for (int j = 0; j < m; j++)
		{
			wi(j);
			e[j] = 0;
			for (i = 0; i < n; i++)
			{
				wi(v[i][j]);
				e[j] = e[j] + v[i][j];
			}
			if (e[j] % kc != 0)
			{
				e[j] = (e[j] / kc) + 1;
			}
			else
			{
				e[j] = (e[j] / kc);
			}
			wi(e[j]);
		}

		int sum = 0;
		for (i = 0; i < m; i++)
		{
			sum = sum + e[i];
		}
		cout << sum << endl;
	}
	// your code goes here
	return 0;
}