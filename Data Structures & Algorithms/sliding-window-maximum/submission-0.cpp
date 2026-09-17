class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> output(n - k + 1);
        deque<int> q;
        int l = 0, r = 0;

        while (r < n) {
            while (!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r);

            if (l > q.front()) {
                q.pop_front();
            }

            if ((r + 1) >= k) {
                output[l] = nums[q.front()];
                l++;
            }
            r++;
        }

        return output;
    }
};


//   int n= nums.size();
//         vector<int> ans;
//         int l=0; 
//         for (int r=l+1; r<n; r++){
//             while ((r-l+1) < k){
//                 r++;
//             }
//             if ((r-l+1) == k){
//                 ans.push_back (max(temp.begin(), temp.end())); // this step is, compute the maximum from the window selected based on the k value and append it to the answer array.
//             }
//             l++;
//         } 
//     return ans;