class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char,int> freq;
        for (char c : s1)                              
        {
            freq[c]++;
        }

        for (int i = 0; i + s1.size() <= s2.size(); i++) 
        {
            unordered_map<char,int> win;
            for (int j = i; j < i + s1.size(); j++)
            {
                win[s2[j]]++;                             
            }

            if (win == freq)
            {
                return true;
            }
        }

        return false;
    }
};
