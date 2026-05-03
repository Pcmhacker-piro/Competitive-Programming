/*
Bellman-Ford Algorithm:
- Works with negative edge weights
- Can detect negative cycles
- Time: O(V * E)
- Use when Dijkstra fails
*/
//O(E) + O(nE) + O(nE) ≈ O(nE)

void BellmanFord(int n, int src, vector<pair<int, ll>> *edges, vector<ll>& dist, set<int>& negCycle) {
    
    fill(all(dist), INF);
    dist[src] = 0;

    vector<pair<ll, pair<int, int>>> e;

    // build edge list
    for (int i = 0; i < n; i++) {
        for (auto j : edges[i]) {
            e.push_back({j.second, {i, j.first}});
        }
    }

    // relax edges
    for (int i = 0; i < n - 1; i++) {
        for (auto j : e) {
            if (dist[j.second.first] != INF &&
                dist[j.second.first] + j.first < dist[j.second.second]) {
                
                dist[j.second.second] = dist[j.second.first] + j.first;
            }
        }
    }

    // negative cycle
    for (int i = 0; i < n; i++) {
        for (auto j : e) {
            if (dist[j.second.first] != INF &&
                dist[j.second.first] + j.first < dist[j.second.second]) {
                
                dist[j.second.second] = dist[j.second.first] + j.first;
                negCycle.insert(j.second.second);
            }
        }
    }
}
