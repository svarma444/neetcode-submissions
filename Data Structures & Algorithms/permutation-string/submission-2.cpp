class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        // unordered_map<char,int> freq;
        // for (char c : s1)                              
        // {
        //     freq[c]++;
        // }

        // for (int i = 0; i + s1.size() <= s2.size(); i++) 
        // {
        //     unordered_map<char,int> win;
        //     for (int j = i; j < i + s1.size(); j++)
        //     {
        //         win[s2[j]]++;                             
        //     }

        //     if (win == freq)
        //     {
        //         return true;
        //     }
        // }

        // return false;

        // if (s1.size() > s2.size()) return false;

        // array<int, 26> need{}, win{};          // both zero-initialized
        // for (char c : s1) need[c - 'a']++;

        // int k = s1.size();
        // for (int i = 0; i < (int)s2.size(); i++) {
        //     win[s2[i] - 'a']++;                // add char entering the window
        //     if (i >= k)
        //         win[s2[i - k] - 'a']--;        // remove char leaving the window
        //     if (i >= k - 1 && win == need)     // window is full-size, compare
        //         return true;
        // }
        // return false;

        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) return false;              // no window fits, avoids out-of-bounds

        array<int, 26> need{}, win{};
        for (int i = 0; i < n1; i++) {
            need[s1[i] - 'a']++;                // <-- MISSING: build the pattern freq
            win[s2[i] - 'a']++;                 // fill first window from s2
        }
        if (win == need) return true;

        for (int i = n1; i < n2; i++) {
            win[s2[i] - 'a']++;                 // add entering char
            win[s2[i - n1] - 'a']--;            // drop leaving char
            if (win == need) return true;
        }

        return false;
    }
};
