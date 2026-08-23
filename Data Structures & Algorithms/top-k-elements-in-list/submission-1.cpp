class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) 
    // {
    //      approach-1:
    //     	unordered_map<int, int> mp;
    //         for (int num : nums)
    //         {
    //             mp[num]++;
    //         }

    //         priority_queue<pair<int, int>> pq;
    //         for (auto& p : mp)
    //         {
    //             pq.push({ p.second, p.first });
    //         }

    //         vector<int> res;

    //         while (k--)
    //         {
    //             res.push_back(pq.top().second);
    //             pq.pop();
    //         }

    //         return res;
    // }

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
         vector<int> res;
        unordered_map<int,int> mp;
        for(int num:nums)
        {
            mp[num]++;
        }

        int numsize = nums.size();
        vector<vector<int>> freq(numsize+1);
        for(auto& p:mp)
        {
            freq[p.second].push_back(p.first);
        }

        for(int i = numsize;i>=0;i--)
        {
            for(int num:freq[i])
            {
                res.push_back(num);
                if(res.size() == k)
                {
                    return res;
                }
            }
        }

        return res;
    }
};
