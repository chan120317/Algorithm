#include <bits/stdc++.h>
#define FIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

/*
* Platform : HackerRank
* Title : Caesar Cipher
* Rank : Basic
*/

string caesarCipher(string s, int k) {
    k %= 26;
    string ret = "";
    for (auto a : s) {
        if ('A' <= a && a <= 'Z')  a = ('Z' < a + k ? a + k - 26 : a + k);
        else if ('a' <= a && a <= 'z')  a = ('z' < a + k ? a + k - 26 : a + k);
        ret.push_back(a);
    }
    return ret;
}

int main() {
    FIO;
    int n, k;
    string s;
    cin >> n >> s >> k;
    cout << caesarCipher(s, k);
}