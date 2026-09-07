class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;
        int longest = 1, last_smaller = INT_MIN, count=0;
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        for (int i=0; i<n; i++){
            if (nums[i]-1 == last_smaller){
                count+=1;
                last_smaller = nums[i];
                //longest +=1;
            }
            else if (nums[i] != last_smaller){
                count = 1;
                last_smaller = nums[i];
                //longest = 1;
                //longest += 1;
            }
            longest = max (longest, count);
        }
        return longest;
    }
};
