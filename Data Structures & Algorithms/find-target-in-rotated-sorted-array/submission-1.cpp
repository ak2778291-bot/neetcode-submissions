class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target) {  // target found
                return m;
            }

            if (nums[l] <= nums[m]) {  // left half is sorted

                if (nums[l] <= target && target < nums[m]) {  // target is in left half
                    r = m - 1;
                } 
                else {  // target is in right half
                    l = m + 1;
                }

            } else {  // right half is sorted

                if (nums[m] < target && target <= nums[r]) {  // target is in right half
                    l = m + 1;
                } 
                else {  // target is in left half
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};