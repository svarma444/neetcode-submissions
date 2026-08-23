class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int res = 0;
        unordered_set<int> uniq;	
        for (int num : nums)
        {
            uniq.insert(num);
        }

        for (auto num : uniq)
        {
            if (uniq.find(num - 1) == uniq.end())
            {
                int len = 1;
                while (uniq.find(num + len) != uniq.end())
                {
                    len++;
                }
                res = max(len, res);
            }
        }
        return res;

    }
};
