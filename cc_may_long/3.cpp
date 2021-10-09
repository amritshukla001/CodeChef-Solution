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

/*Validity of a given Tic-Tac-Toe board configuration
Taken frm GeeksforGeeks
https://www.geeksforgeeks.org/validity-of-a-given-tic-tac-toe-board-configuration*/
// This matrix is used to find indexes to check all
// possible wining triplets in board[0..8]
int win[8][3] = {{0, 1, 2}, // Check first row.
	{3, 4, 5}, // Check second Row
	{6, 7, 8}, // Check third Row
	{0, 3, 6}, // Check first column
	{1, 4, 7}, // Check second Column
	{2, 5, 8}, // Check third Column
	{0, 4, 8}, // Check first Diagonal
	{2, 4, 6} // Check second Diagonal
};

// Returns true if character 'c' wins. c can be either
// 'X' or 'O'
bool isCWin(char *board, char c)
{
	// Check all possible winning combinations
	for (int i = 0; i < 8; i++)
		if (board[win[i][0]] == c &&
		        board[win[i][1]] == c &&
		        board[win[i][2]] == c )
			return true;
	return false;
}

// Returns true if given board is valid, else returns false
bool isValid(char board[9])
{
	// Count number of 'X' and 'O' in the given board
	int xCount = 0, oCount = 0;
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == 'X') xCount++;
		if (board[i] == 'O') oCount++;
	}

	// Board can be valid only if either xCount and oCount
	// is same or xount is one more than oCount
	if (xCount == oCount || xCount == oCount + 1)
	{
		// Check if 'O' is winner
		if (isCWin(board, 'O'))
		{
			// Check if 'X' is also winner, then
			// return false
			if (isCWin(board, 'X'))
				return false;

			// Else return true xCount and yCount are same
			return (xCount == oCount);
		}

		// If 'X' wins, then count of X must be greater
		if (isCWin(board, 'X') && xCount != oCount + 1)
			return false;

		// If 'O' is not winner, then return true
		return true;
	}
	return false;
}

bool isEmpty(char board[9]) {
	for (int i = 0; i < 9; i++) {
		if (board[i] == '_')
			return true;
	}
	return false;
}

void solve() {
	char board[9];
	for (int i = 0; i < 9; i++)
		cin >> board[i];
	isValid(board) ? ((isCWin(board, 'O') || isCWin(board, 'X') || !isEmpty(board)) ? cout << "1\n" : cout << "2\n") : cout << "3\n";
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

