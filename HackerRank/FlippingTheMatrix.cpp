#include <bits/stdc++.h>
#define FIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

/*
* Platform : HackerRank
* Title : Flipping the Matrix
* Rank : Basic
*/

int flippingMatrix(vector<vector<int>> matrix) {
    int n = matrix.size(), answer = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            int here = matrix[i][j];
            here = max(here, matrix[i][n - 1 - j]);
            here = max(here, matrix[n - 1 - i][j]);
            here = max(here, matrix[n - 1 - i][n - 1 - j]);
            answer += here;
        }
    }
    return answer;
}

int main() {
    FIO;
    int q, n;
    cin >> q;
    while (q--) {
        cin >> n;
        vector <vector <int>> matrix(n + 1, vector <int>(n + 1));
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                cin >> matrix[i][j];
            }
        }
        cout << flippingMatrix(matrix);
    }
}
