#include <bits/stdc++.h>
#define FIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

/*
* Platform : HackerRank
* Title : Staircase
* Rank : Basic
*/

void staircase(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j > 0; j--) cout << ' ';
        for (int j = 0; j < i; j++) cout << '#';
        cout << '\n';
    }
}

int main() {
    FIO;
    int n;
    cin >> n;
    staircase(n);
}
