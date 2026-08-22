class Solution {
public:
    bool isAnagram(string s, string t) 
    { 
        unordered_map<char,int> su;
        unordered_map<char,int> st;
        for(char c:s)
        {
            su[c]++;
        }

        for(char c:t)
        {
            st[c]++;
        }

        return su==st;
        
    }
};
