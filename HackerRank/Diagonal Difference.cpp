#include <bits/stdc++.h>
#define FIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

/*
* Platform : HackerRank
* Title : Diagonal Difference
* Rank : Basic
*/

int diagonalDifference(vector<vector<int>> arr) {
	int leftDiag = 0, rightDiag = 0;
	for (int i = 0; i < arr.size(); i++) {
		leftDiag += arr[i][i];
		rightDiag += arr[arr.size() - 1 - i][i];
	}
	return leftDiag > rightDiag ? leftDiag - rightDiag : rightDiag - leftDiag;
}

int main() {
	FIO;
	int n;
	cin >> n;
	vector <vector<int>> arr(n + 1, vector <int>(n + 1));
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
	cout << diagonalDifference(arr);
}