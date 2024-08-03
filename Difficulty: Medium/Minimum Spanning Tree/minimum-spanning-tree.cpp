//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
  vector<int>size,parent;
  public:
  DisjointSet(int n){
      size.resize(n+1);
      parent.resize(n+1);
      for(int i=0;i<=n;i++){
          size[i] = 1;
          parent[i] = i;
      }
  }
  int findUpar(int node){
      if(parent[node] == node)return node;
      return parent[node] = findUpar(parent[node]);
  }
  
  void UnionBySize(int u,int v){
      int up_u = findUpar(u);
      int up_v = findUpar(v);
      if(up_u == up_v)return;
      if(up_u < up_v){
          parent[up_u] = up_v;
          size[up_v] += size[up_u];
      }
      else{
          parent[up_v] = up_u;
          size[up_u] += size[up_v];
      }
  }
  
    
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt,{node,adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstwt = 0;
        for(auto it:edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
        
            if(ds.findUpar(u) != ds.findUpar(v)){
                mstwt += wt;
                ds.UnionBySize(u,v);
            }
        }
        return mstwt;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends