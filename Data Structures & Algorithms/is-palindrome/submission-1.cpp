class Solution {
public:
    bool isPalindrome(string s) 
    {
        int n = s.size();
        int i=0,j=n-1;

        while(i<=j)
        {
            while(j>=0 && !isalnum(s[j]))
                j--;

            while(i<n && !isalnum(s[i]))
                i++;

            if(i<n && j>=0)
            {
                if(tolower(s[i])==tolower(s[j]))
                {
                    i++;
                    j--;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};
