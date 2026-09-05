class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> freq;
        for (int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
            }
        vector <int> topK;
        while (topK.size() < k){
            int high=-1;
            int key;
          for (auto x: freq){
            if (x.second > high){
                high = x.second;
                key = x.first;
                }
            }
            topK.push_back(key);
            freq.erase(key);
        }
        return topK;
        
    }
};