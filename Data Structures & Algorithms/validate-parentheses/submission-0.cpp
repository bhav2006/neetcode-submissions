class Solution {
public:
    bool isValid(string s) 
    {
        if(s.size()%2)  return false;

        stack<char> st;
        for(char ch: s)
        {
            if(!st.empty() && ((st.top()=='[' && ch==']') || (st.top()=='{' && ch=='}') || (st.top()=='(' && ch==')')))
                st.pop();
            else
                st.push(ch);
        }

        return st.empty();
    }
};
