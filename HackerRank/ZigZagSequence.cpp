#include <bits/stdc++.h>
#define FIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

/*
* Platform : HackerRank
* Title : Zig Zag Sequence
* Rank : Basic
*/

vector <int> findZigZagSequence(vector <int> a, int &n) {
    sort(a.begin(), a.end());
    int st = n / 2, ed = n - 1;
    while (st <= ed) {
        swap(a[st], a[ed]);
        st = st + 1;
        ed = ed - 1;
    }
    return a;
}


int main() {
    FIO;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector <int> answer = findZigZagSequence(a, n);
        for (auto here : answer) cout << here << ' ';
    }
}
