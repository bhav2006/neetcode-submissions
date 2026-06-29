class Solution {
public:

    bool isOperator(string s)
    {
        return s=="+" || s=="-" || s=="*" || s=="/";
    }

    int evalRPN(vector<string>& tokens) 
    {
        int n = tokens.size();

        stack<int> st;

        for(auto it: tokens)
        {
            if(!isOperator(it))
                st.push(stoi(it));
            else
            {
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();

                if(it=="+")
                    st.push(v1+v2);
                else if(it=="-")
                    st.push(-v1+v2);
                else if(it=="*")
                    st.push(v1*v2);
                else    
                    st.push(v2/v1);
            }
        }

        return st.top();
    }
};
