class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) 
    {
        vector<vector<int>> adj(n);

        for(int i=0;i<arr.size();i++)
        {
            adj[arr[i][1]].push_back(arr[i][0]);
        }

        vector<int> inDegree(n,0);
        for(int i=0;i<arr.size();i++)
        {
            inDegree[arr[i][0]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(!inDegree[i])    
                q.push(i);
        }

        vector<int> ans;
        while(!q.empty())
        {
            int k = q.front();
            q.pop();
            ans.push_back(k);

            for(int neigh: adj[k])
            {
                inDegree[neigh]--;
                if(inDegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        return ans.size() == n;
    }
};
