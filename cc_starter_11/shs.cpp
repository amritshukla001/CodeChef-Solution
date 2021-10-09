#include<bits/stdc++.h>
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void solve() {

    int n;
    cin >> n;
    int arr[n][n] = {0};
    if (n % 2 != 0)
    {
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i][k] = -1;
            k++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] != -1)
                    arr[i][j] = 1;
            }
        }
    }
    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w" , stdout);
    freopen("Error.txt", "w", stderr);
#endif
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}