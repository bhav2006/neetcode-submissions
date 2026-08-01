class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        if(edges.size() > n - 1)
            return false;

        vector<vector<int>> adj(n);
        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> vis;
        if(DFS(0,-1,vis,adj))
            return false;

        return vis.size() == n;
    }

    bool DFS(int node,int parent,unordered_set<int>& vis,vector<vector<int>>& adj)
    {
        if(vis.count(node))
            return true;

        vis.insert(node);
        for(int x: adj[node])
        {
            if(x == parent)
                continue;

            if(DFS(x,node,vis,adj))
                return true;
        }
        return false;
    }
};
