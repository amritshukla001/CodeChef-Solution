#include <bits/stdc++.h>
#include <unordered_map>
typedef long long ll;
typedef unsigned long long ull;
#define int long long
#define wi(x) cout << #x << " = " << x << endl;
#define wi2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define testcase     \
    long long testn; \
    cin >> testn;    \
    while (testn--)
#define fo(i, l, r) for (int i = l; i < r; i++)
#define fo1(i, l, r) for (int i = l; i <= r; i++)
#define pb push_back
#define disp(v) for(auto x:v) cout << x << "\t"

const ll m = 1e9 + 7;

using namespace std;

ll binpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

ll binmodpow(ll a, ll b) {
	if (b == 1)
		return a % m;
	ll res = 1;
	while (b > 0) {
		a = a % m;
		if (b & 1)
			res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

// function to find minimum area of Rectangle
int minAreaRect(vector<vector<int>> A) {

	// creating empty columns
	map<int, vector<int>> columns;

	// fill columns with coordinates
	for (auto i : A) {
		//cout << i[0] << i[1] << "\n";
		//x++;
		//wi2(i[0], i[1]);
		columns[i[0]].push_back(i[1]);
	}

	/*for (auto kv : columns) {
		std::cout << kv.first << " =>";
		for (auto i : kv.second)
			std::cout << " " << i;
		std::cout << std::endl;
	}*/

	map<pair<int, int>, int > lastx;

	int ans = INT_MAX;

	for (auto x : columns)
	{
		vector<int> column = x.second;
		disp(column);
		cout << endl;
		sort(column.begin(), column.end());
		//disp(column);
		//cout << endl;
		//cout << column.size() << "\n";

		for (int j = 0; j < column.size(); j++)
		{
			for (int i = 0; i < j; i++)
			{	//wi2(i, j);
				int y1 = column[i];
				wi(y1);
				wi(column[j]);
				// check if rectangle can be formed
				if (lastx.find({y1, column[j]}) != lastx.end())
				{
					ans = min(ans, (x.first - lastx[ {y1, column[j]}]) *
					          (column[j] - column[i]));
				}
				lastx[ {y1, column[j]}] = x.first;
				wi(x.first);
			}
		}
	}

	if (ans < INT_MAX)
		return ans;
	else
		return 0;
}

// Driver code
int32_t main()
{
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w" , stdout);
#endif
	vector<vector<int>> A = {{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}};
	/*fo(i, 0, 4) {
		fo(j, 0, 2) {
			//wi2(i, j);
			cout << A[i][j] << "\t";
		}
		cout << "\n";
	}*/
	cout << (minAreaRect(A));
	return 0;
}

