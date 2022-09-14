#include <bits/stdc++.h>
#define FIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

/*
* Platform : HackerRank
* Title : Time Conversion
* Rank : Basic
*/

string timeConversion(string s) {
    int h = stoi(s.substr(0, 2));
    if (h == 12) h = 0;
    if (s.substr(8, 2) == "PM") h += 12;
    return to_string(h) + s.substr(2, 6);
}

int main() {
    FIO;
    string Time;
    cin >> Time;
    cout << timeConversion(Time);
}