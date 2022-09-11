#include <bits/stdc++.h>
#define FIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

/*
* Platform : HackerRank
* Title : Find the Median
* Rank : Basic
*/

int findMedian(vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr[arr.size() / 2];
}

int main() {
	FIO;
    int n;
    vector <int> arr(n + 1);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << findMedian(arr);
}
