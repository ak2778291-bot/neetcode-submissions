class Solution {
public:
    int findMin(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;

        // Keep track of the smallest value we've already seen.
        int mini = min(nums[l], nums[r]);

        while (l <= r) {

            // If current range is already sorted,
            // nums[l] is the minimum of this range.
            mini = min(mini, nums[l]);

            if (nums[l] < nums[r]) {
                break;
            }

            int m = l + (r - l) / 2;

            // m is a candidate for the minimum.
            mini = min(mini, nums[m]);

            // Left portion is sorted.
            // Its minimum is nums[l], which we already considered.
            // Therefore, the rotation/minimum must be to the right.
            if (nums[m] >= nums[l]) {
                l = m + 1;
            }
            else {
                // The rotation is at m or to the left.
                r = m - 1;
            }
        }

        return mini;
    }
};