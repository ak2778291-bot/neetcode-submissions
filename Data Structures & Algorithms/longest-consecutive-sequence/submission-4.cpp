class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 1; //last_smaller = INT_MIN, count=0;
         if(nums.size() == 0) return 0;
         unordered_set<int> st;
         for (int i=0; i<n; i++){
            st.insert(nums[i]);
         }
         for (auto it: st){
            if (st.find(it-1) == st.end()){
                int count = 1; 
                int x = it;
                while (st.find (x+1) != st.end()){
                    x = x + 1;
                    count = count + 1;
                }
                longest = max (longest, count);
            }
         }
        // sort(nums.begin(),nums.end());
        // for (int i=0; i<n; i++){
        //     if (nums[i]-1 == last_smaller){
        //         count+=1;
        //         last_smaller = nums[i];
        //         //longest +=1;
        //     }
        //     else if (nums[i] != last_smaller){
        //         count = 1;
        //         last_smaller = nums[i];
        //         //longest = 1;
        //         //longest += 1;
        //     }
        //     longest = max (longest, count);
        // }
        return longest;
    }
};
