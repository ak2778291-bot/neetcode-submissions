class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), maxiArea = 0, diff, area, left = 0, right = n-1;
        // for (int left = 0; left < n-2; left++){
        //     int right = n-1;
            while (right > left){
              diff = right - left;
              area = min(heights[left],heights[right]) * diff;
              if (area > maxiArea){
                maxiArea = area;
               }
            if(heights[left] < heights[right]){
                 left++;
               }
               else right--;
            }
    return maxiArea;
    }
};
