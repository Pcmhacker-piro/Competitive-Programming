/*
🔹 Prim’s Algorithm (Lazy - Undirected Graph Only)

📌 Time: O(E log E)
📌 Space: O(E + V)

📌 Notes:
- Works ONLY for undirected graphs ❗
- Uses Min Heap (priority_queue)
- No dist[] (lazy approach)
- vis[] prevents cycles
- For disconnected graph → run for each component

📌 Idea:
Pick the smallest edge connecting MST to a new node
*/

int prims(vector<pair<int,int>> adj[], int n, int src = 0) {
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({0, -1, src});

    vector<int> vis(n, 0);
    int mst = 0;

    while(!pq.empty()) {
        auto [w, p, u] = pq.top();
        pq.pop();

        if(vis[u]) continue;

        vis[u] = 1;
        mst += w;

        for(auto &[v, wt] : adj[u]) {
            if(!vis[v]) pq.push({wt, u, v});
        }
    }
    return mst;
}
