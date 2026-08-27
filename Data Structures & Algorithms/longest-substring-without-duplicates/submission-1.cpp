class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        // int res = 0;

        // unordered_set<char> window;
        // int left = 0;
        // for (int right = 0; right < s.size(); right++)
        // {
        //     while (window.find(s[right]) != window.end())
        //     {
        //         window.erase(s[left]);
        //         left++;
        //     }
        //     window.insert(s[right]);
        //     res = max(res, right - left + 1);
        // }

        // return res;

            int res = 0;
            unordered_map<char, int> lastSeen;
            int left = 0;

            for (int right = 0; right < s.size(); right++)
            {
                if (lastSeen.count(s[right]) && lastSeen[s[right]] >= left)
                {
                    left = lastSeen[s[right]] + 1;  // jump directly
                }
            lastSeen[s[right]] = right;
            res = max(res, right - left + 1);
            }
            return res;
    }
};
