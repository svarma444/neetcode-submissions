class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        bool isfound = false;
        int size = nums.size();
        unordered_set<int> s;
        for (int i = 0; i < size; i++)
        {
            int num = nums[i];
            if (s.find(num) == s.end())
                s.insert(num);
            else
                isfound = true;
        }
        return isfound;  
    }
};