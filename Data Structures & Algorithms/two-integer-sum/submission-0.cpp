class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> mpp;

        for(int i=0;i<nums.size();i++)
        {
            if(mpp.find(target-nums[i])!=mpp.end() && i!=mpp[target-nums[i]])
            {
                vector<int> temp = {mpp[target-nums[i]],i};
                sort(temp.begin(),temp.end());
                return temp;
            }

            mpp[nums[i]]=i;
        }

        return {};
    }
};
