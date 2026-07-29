class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> numSet(nums.begin(),nums.end());
        int longest = 0;

        for(int x: numSet)
        {
            if(numSet.find(x-1) == numSet.end())
            {
                int l = 1;
                while(numSet.find(x + l) != numSet.end())
                    l++;

                longest = max(longest,l);
            }
        }

        return longest;
    }
};
