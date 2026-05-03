/*
    Dijkstra's Algorithm (Shortest Path)
    Time: O((V + E) log V)
*/
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>

vector<int> dijkstra(int n, vector<pii> adj[], int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dist(n + 1, 1e9);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); 
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &it : adj[u]) {
            int v = it.first, w = it.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
