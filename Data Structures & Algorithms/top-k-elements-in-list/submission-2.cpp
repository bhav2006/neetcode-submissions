class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<vector<int>> freq(n+1);

        for(int x: nums)
            mpp[x]++;

        for(auto entry: mpp)
        {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> ans;

        for(int i=n;i>=0;i--)
        {
            for(int x: freq[i])
            {
                ans.push_back(x);
                if(ans.size() == k)
                {
                    return ans;
                }
            }
        }

        return {69};
    }
};
