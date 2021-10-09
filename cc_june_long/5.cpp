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

pair<int, int> findpy(int x, vector<pair<int, int>> pts, int n) {
	int min = pts[0].second, max = pts[0].second;
	fo1(i, 0, x) {
		if (pts[i].second < min) min = pts[i].second;
		if (pts[i].second > max) max = pts[i].second;
	}
	pair<int, int> temp;
	temp.first = min;
	temp.second = max;
	return temp;
}

pair<int, int> findsy(int x, vector<pair<int, int>> pts, int n) {
	int min = pts[x + 1].second, max = pts[x + 1].second;
	fo(i, x + 1, n) {
		if (pts[i].second < min) min = pts[i].second;
		if (pts[i].second > max) max = pts[i].second;
	}
	pair<int, int> temp;
	temp.first = min;
	temp.second = max;
	return temp;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.second < b.second);
}

void solve() {
	int n;
	cin >> n;
	//wi(n);
	vector<pair<int, int>> pts(n);

	int minsuma = INT_MAX;

	fo(i, 0, n) cin >> pts[i].first >> pts[i].second;

	for (auto points : pts)
		cout << points.first << "\t" << points.second << "\t";

	cout << "\n";

	sort(pts.begin(), pts.end());

	for (auto points : pts)
		cout << points.first << "\t" << points.second << "\t";

	cout << "\n";

	int psum, ssum;

	fo(i, 0, n) {
		pair<int, int> py, sy;
		py = findpy(i, pts, n);
		sy = findsy(i + 1, pts, n);
		wi2(py.first, py.second);
		wi2(sy.first, sy.second);

		psum = (pts[i].first - pts[0].first) * (py.second - py.first);
		wi(psum);
		ssum = (pts[n - 1].first - pts[i + 1].first) * (sy.second - sy.first);
		wi(ssum);
		int tarea = psum + ssum;
		if (tarea < minsuma) minsuma = tarea;
		wi(tarea);
	}

	sort(pts.begin(), pts.end(), sortbysec);

	for (auto points : pts)
		cout << points.first << "\t" << points.second << "\t";

	cout << "\n";
	if (n == 1 && n == 2)
		cout << "0\n";
	else
		cout << "not yet" << "\n";
	cout << "\n";
}

int32_t main() {
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