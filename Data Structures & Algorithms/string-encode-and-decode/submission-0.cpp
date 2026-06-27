class Solution {
public:

    vector<string> arr;

    string encode(vector<string>& strs) 
    { 
        arr = strs;
        return "";
    }

    vector<string> decode(string s) 
    {
        return arr;
    }
};
