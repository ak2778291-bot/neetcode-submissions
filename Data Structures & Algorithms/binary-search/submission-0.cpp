class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0; int high = n-1;
        for (int i=0; i<n; i++){
            int mid = ((high + low)/2);
            if (target < nums[mid]){
                high = mid - 1;
            }
            else if (target > nums[mid]){
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};
