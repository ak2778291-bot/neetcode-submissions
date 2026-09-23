class Solution {
public:
    int maxArea(vector<int>& heights){
      int maxArea = 0;
      int l = 0; int r = heights.size()-1;
      while (l < r){
        int diff = r-l;
        int area = min (heights[l], heights[r]) * diff;
        maxArea = max (area, maxArea);
        if (heights[l] <= heights[r]){
          l++;
        }
        else r--;
      }
      return maxArea;
    }
};

















//this is the part i need to remember/ understand, instead of running two loops, we can simply move the pointer from whosever height is less, because If heights[left] is smaller, then any future container using index i will have a smaller width, and its height is still at most heights[i]. So it cannot produce a larger area than the current pair. Therefore, we can safely discard the smaller height and move that pointer inward. The same logic applies when heights[right] is smaller.
//Move the shorter wall because keeping it while reducing the width can never produce a better area.