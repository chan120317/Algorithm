#include <bits/stdc++.h>]
using namespace std;

string plusFunc(string a, string b) {
    string ret = "";
    if (a.size() > b.size()) swap(a, b);
    while (a.size() < b.size()) a += '0';
    int carry = 0;
    for (int i = 0; i < b.size(); i++) {
        int next = b[i] - '0' + a[i] - '0' + carry;
        carry = next / 10, next %= 10;
        ret += to_string(next);
    }
    if (carry) ret.push_back(carry + '0');
    return ret;
}

string multiFunc(string a, string b) {
    reverse(b.begin(), b.end());
    string ret = "0";
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            string here = to_string((a[j] - '0') * (b[i] - '0'));
            reverse(here.begin(), here.end());
            here = plusFunc(ret.substr(max(i, j), ret.size() - max(i, j) + 1), here);
            ret = ret.substr(0, max(i, j)) + here;
        }
    }
    return ret;
}

void extraLongFactorials(int n) {
    string answer = "1";
    long long intAns = 1;
    for (int i = 1; i <= n; i++) {
        if (i <= 19) {
            intAns *= i;
            answer = to_string(intAns);
            reverse(answer.begin(), answer.end());
            continue;
        }
        string here = to_string(i);
        answer = multiFunc(answer, here);
    }
    reverse(answer.begin(), answer.end());
    cout << answer;
}

int main() {
    int n;
    cin >> n;
    extraLongFactorials(n);
}