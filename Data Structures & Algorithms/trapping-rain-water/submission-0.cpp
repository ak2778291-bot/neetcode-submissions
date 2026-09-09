class Solution {
public:
    int trap(vector<int>& height) {

        int l = 0;
        int r = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int totalWater = 0;

        while (l < r) {

            // Left side is the limiting boundary
            if (height[l] <= height[r]) {

                // Update tallest wall seen from left
                leftMax = max(leftMax, height[l]);

                // Water can be calculated using leftMax
                totalWater += leftMax - height[l];

                // Move left pointer
                l++;
            }

            // Right side is the limiting boundary
            else {

                // Update tallest wall seen from right
                rightMax = max(rightMax, height[r]);

                // Water can be calculated using rightMax
                totalWater += rightMax - height[r];

                // Move right pointer
                r--;
            }
        }

        return totalWater;
    }
};