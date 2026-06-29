class Solution {
public:

    vector<int> findNGE(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> st;

        vector<int> nge(n);

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
                st.pop();

            nge[i]=st.empty()?0:st.top();
            st.push(i);
        }

        return nge;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();

        vector<int> nge = findNGE(temperatures);
        
        for(int i=0;i<n;i++)
        {
            if(nge[i]!=0)
                nge[i]-=i;
        }
        return nge;
    }
};
