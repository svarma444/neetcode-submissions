class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> mp;
        for (string s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        unordered_map<string, vector<string>>::iterator it = mp.begin();
        while (it != mp.end())
        {
            res.push_back(it->second);
            it++;
        }

        return res;
        
    }
};
