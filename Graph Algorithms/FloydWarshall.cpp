// - Finds shortest path between all pairs
// - Works with negative edges (no negative cycle)
// - Time: O(n^3)
// - Best for small graphs

void FloydWarshall(int n, vector<pair<int, ll>> *adj, vector<vector<ll>> &dist) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (auto j : adj[i]) {
            dist[i][j.first] = min(dist[i][j.first], j.second);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Negative cycle detection
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative Cycle detected\n";
        }
    }
}
