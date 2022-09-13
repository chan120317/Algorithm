#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;
typedef pair <int, int> pii;

struct edge {
    int u, v, w;
};
struct cmp {
    bool operator() (edge a, edge b) {
        if (a.w == b.w) {
            if (a.u == b.u) return a.v > b.v;
            return a.u > b.u;
        }
        return a.w > b.w;
    }
};
typedef priority_queue <edge, vector <edge>, cmp> PQ;

void bfs(int x, int y, int cnt, vector <vector<int>> &visited, vector <vector<int>>& land, int& height, PQ &pq) {
    int rr[] = { -1,1,0,0 }, rc[] = { 0,0,1,-1 };
    queue <pii> q;
    q.push(make_pair(x, y));
    visited[x][y] = cnt;
    while (!q.empty()) {
        x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + rr[i], ny = y + rc[i];
            if (nx < 0 || nx >= land.size() || ny < 0 || ny >= land.size()) continue;
            int diff = abs(land[x][y] - land[nx][ny]);
            if (!visited[nx][ny] && diff <= height) {
                visited[nx][ny] = cnt;
                q.push(make_pair(nx, ny));
            }
            else if (visited[nx][ny] && diff > height) pq.push({ visited[nx][ny], visited[x][y],diff });
        }
    }
}

int find(int a, vector <int>& parent) {
    if (parent[a] == -1) return a;
    return parent[a] = find(parent[a], parent);
}

void merge(int a, int b, vector <int>& parent) {
    a = find(a, parent);
    b = find(b, parent);
    if (a == b) return;
    if (a > b) swap(a, b);
    parent[b] = a;
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    vector <vector<int>> visited(land.size(), vector <int>(land.size(), 0));
    PQ pq;
    int cnt = 1;
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land.size(); j++) {
            if (!visited[i][j]) bfs(i, j, cnt++, visited, land, height, pq);
        }
    }
    vector <int> parent(cnt, -1);
    while (!pq.empty()) {
        int u = pq.top().u, v = pq.top().v, w = pq.top().w;
        pq.pop();
        if (find(u, parent) == find(v, parent)) continue;
        answer += w;
        merge(u, v, parent);
    }
    return answer;
} 
