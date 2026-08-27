class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int res = 0;

        unordered_set<char> window;
        int left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            while (window.find(s[right]) != window.end())
            {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            res = max(res, right - left + 1);
        }

        return res;
    }
};
