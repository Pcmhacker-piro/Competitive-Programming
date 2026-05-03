#include <bits/stdc++.h>
using namespace std;

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define popcnt __builtin_popcount

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define debug(x) cout << #x << " = " << x << endl
#define sz(x) (int)(x).size()
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define tp tuple<int,int,int>
#define minpq_tuple priority_queue<tp, vector<tp>, greater<tp>>
#define maxpq_tuple priority_queue<tp>

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

//this is only possible in the DAG (directed asyclic graph)


// ================== DFS ==================
//* TC = O(V + E)
//* SC = O(V + E)

void helper(int node,vi adj[],vi& vis,stack<int>& st){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]) helper(it, adj, vis, st); 
    }
    st.push(node);
}
void toposortDfs(vi adj[], int n){
    stack<int> st;
    vi vis(n+1,0);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            helper(i,adj,vis,st);
        }
    }
    
    while(!st.empty()){
    cout << st.top() << " ";
    st.pop();
}

}


// ================== BFS/Kahn's algorithm ==================
//* TC = O(V + E)
//* SC = O(V + E)

void toposortBfs(vi adj[], int u){
    vi inDegree(u+1, 0);

    // compute indegree
    for(int i = 1; i <= u; i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }

    queue<int> qu;
    for(int i = 1; i <= u; i++){
        if(inDegree[i] == 0){
            qu.push(i);
        }
    }

    vi ans;
    while (!qu.empty()) {
        int took = qu.front();
        qu.pop();
        ans.pb(took);
        for(auto it : adj[took]){
            inDegree[it]--;
            if(inDegree[it] == 0){
                qu.push(it);
            }
        }
    }

    // cycle check
    if(ans.size() != u){
        cout << "Cycle detected\n";
        return;
    }

    // print topo order
    for(auto x : ans){
        cout << x << " ";
    }
    cout << "\n";
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int u, v;
  cin >> u >> v;
  vi vis(u + 1, 0);
  vi adj[u+1];
  f(i, 0, v) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }
  toposortDfs(adj, u);
  return 0;
}
