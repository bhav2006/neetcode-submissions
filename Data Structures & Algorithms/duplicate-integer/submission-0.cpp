class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        unordered_map<int,int> mpp;

        for(auto x: nums)
        {
            if(mpp[x]>0)
                return true;
            
            mpp[x]++;
        }

        return false;
    }
};