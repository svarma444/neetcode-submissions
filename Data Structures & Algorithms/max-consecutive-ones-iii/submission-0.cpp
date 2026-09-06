class Solution {
public:
    int longestOnes(vector<int>& nums, int k) \
    {
        int left = 0, zeroes = 0, longseq = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0)
            {
                zeroes++;
            }

            while (zeroes > k)
            {
                if (nums[left] == 0)
                {
                    zeroes--;
                }
                left++;
            }
            longseq = max(longseq, right - left + 1);
        }

        return longseq;

        // int left = 0, zeroes = 0;
        // for (int right = 0; right < nums.size(); right++)
        // {
        //     if (nums[right] == 0)
        //         zeroes++;

        //     if (zeroes > k)          // if, not while
        //     {
        //         if (nums[left] == 0)
        //             zeroes--;
        //         left++;
        //     }
        // }
        // return nums.size() - left;   // window size at the end
        
    }
};