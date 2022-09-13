#include <string>
#include <vector>

using namespace std;

void dfs(int here, int depth, vector <int> &visited, vector <vector<int>>& adj) {
    visited[here] = depth;
    for (auto next : adj[here]) {
        if (!visited[next]) dfs(next, depth + 1, visited, adj);
    }
}

int Longest(int here, int delNode, int& answer, int &n, vector<vector<int>> &adj) {
    vector <int> visited(n + 1);
    if (delNode > 0) visited[delNode] = true;
    dfs(here, 1, visited, adj);
    int Max = -1, node;
    for (int i = 1; i <= n; i++) {
        if (Max < visited[i]) Max = visited[i], node = i;
    }
    if (delNode > 0) answer = max(answer, Max);
    return node;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    vector <vector<int>> adj(n + 1);
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    int root = Longest(1, -1, answer, n, adj);
    int leaf = Longest(root, -1, answer, n, adj);
    Longest(root, leaf, answer, n, adj);
    Longest(leaf, root, answer, n, adj);
    return answer - 1;
}
