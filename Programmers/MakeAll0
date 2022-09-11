#include <bits/stdc++.h>
#define FIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;

/*
* Platform : Programmers
* Title : 모두 0으로 만들기
* Rank : Level 3
*/

long long dfs(int here, int parent, long long& answer, vector <long long>& aa, vector<vector<int>>& adj) {
    long long ret = 0;
    for (auto next : adj[here]) {
        if (next != parent) ret += dfs(next, here, answer, aa, adj);
    }
    aa[here] += ret;
    answer += abs(aa[here]);
    return aa[here];
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    vector <long long> aa;
    for (auto here : a) aa.push_back(here);

    vector <vector<int>> adj(aa.size());
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    long long ret = dfs(0, 0, answer, aa, adj);
    answer = !ret ? answer : -1;
    return answer;
}
