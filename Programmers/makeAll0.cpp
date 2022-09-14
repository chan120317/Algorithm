#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    set <string> s;
    for (auto here : operations) {
        char ope = here[0];
        string num = here.substr(here.begin() + 2, here.size() - 2);
        if (ope == 'I') s.insert(num);
        else {
            if (s.empty()) continue;
            if (num == "1") s.erase(s.end() - 1);
            else if (num == "-1") s.erase(s.begin());
        }
    }

    if (s.empty()) answer = { 0,0 };
    else answer = { s.begin(), s.end() - 1 };
    return answer;
}

int main() {
    vector <string> operations = { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" };
    solution(operations);
}