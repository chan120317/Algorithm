#include <bits/stdc++.h>
#define FIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

/*
* Platform : HackerRank
* Title : Mini-Max Sum
* Rank : Basic
*/

void miniMaxSum(vector<int> arr) {
    long long sum = 0;
    int Min = 1e9 + 1, Max = -1;
    for (auto here : arr) {
        sum += here;
        Min = min(Min, here);
        Max = max(Max, here);
    }
    cout << sum - Max << ' ' << sum - Min;
}

int main() {
	FIO;
    vector <int> arr(5);
    for (int i = 0; i < 5; i++) cin >> arr[i];
    miniMaxSum(arr);
}
