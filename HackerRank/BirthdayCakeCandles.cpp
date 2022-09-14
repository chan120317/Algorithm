#include <bits/stdc++.h>
#define FIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

/*
* Platform : HackerRank
* Title : Birthday Cake Candles
* Rank : Basic
*/

int birthdayCakeCandles(vector<int> candles) {
    int Max = -1, answer = 0;
    for (auto here : candles) {
        if (Max < here) Max = here, answer = 1;
        else if (Max == here) answer++;
    }
    return answer;
}

int main() {
    FIO;
    int n;
    cin >> n;
    vector <int> candles(n);
    for (int i = 0; i < n; i++) cin >> candles[i];
    cout << birthdayCakeCandles(candles);
}
