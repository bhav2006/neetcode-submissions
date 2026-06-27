class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(auto x: nums)
            mpp[x]++;

        vector<int> ans;

        vector<pair<int,int>> vpp(mpp.begin(),mpp.end());

        sort(vpp.begin(),vpp.end(),[&](pair<int,int> a, pair<int,int> b){
            return a.second>b.second;
        });

        for(int i=0;i<k;i++)
        {
            ans.push_back(vpp[i].first);
        }

        return ans;
    }
};
