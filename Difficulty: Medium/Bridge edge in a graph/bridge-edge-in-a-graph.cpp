//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    int timer;
    
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, int tin[], int low[], vector<pair<int, int>> &bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, adj, vis, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }
    
public:
    // Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) {
        timer = 1;
        vector<int> vis(V, 0);
        vector<pair<int, int>> bridges;
        int tin[V], low[V];
        
        // Initialize the tin and low arrays
        fill(tin, tin + V, -1);
        fill(low, low + V, -1);
        
        // Perform DFS from the first node (assuming graph is connected)
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, bridges);
            }
        }
        
        // Check if the given edge is a bridge
        for (auto &bridge : bridges) {
            if ((bridge.first == c && bridge.second == d) || (bridge.first == d && bridge.second == c)) {
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends