#include <bits/stdc++.h>
#define FIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

/*
* Platform : HackerRank
* Title : Lonely Integer
* Rank : Basic
*/

int lonelyinteger(vector<int> a) {
	vector <int> visited(101, 0);
	for (auto here : a) visited[here]++;

	int answer = 0;
	for (int i = 0; i <= 100; i++) {
		if (visited[i] == 1) answer = i;
	}
	return answer;
}

int main() {
	FIO;
	int n;
	cin >> n;
	vector <int> a(n + 1);
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << lonelyinteger(a);
}
