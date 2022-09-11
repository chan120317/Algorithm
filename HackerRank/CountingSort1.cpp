#include <bits/stdc++.h>
#define FIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

/*
* Platform : HackerRank
* Title : Counting Sort 1
* Rank : Basic
*/

vector<int> countingSort(vector<int> arr) {
    vector <int> visited(100);
    for (auto here : arr) visited[here]++;
    return visited;
}

int main() {
	FIO;
    int n;
    vector <int> arr(n + 1), answer;
    for (int i = 0; i < n; i++) cin >> arr[i];
    answer = countingSort(arr);
    for (auto here : answer) cout << here << ' ';
}
