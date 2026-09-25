class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; int n = piles.size(); int maxi = INT_MIN; 
        for (int i = 0; i<n; i++){
            maxi = max (maxi, piles[i]);
        }
        int ans = maxi;
        while (l <= maxi){
            int mid = (l + maxi)/2;
            long long totalTime = 0;
            for (int p : piles){
                totalTime += ceil (static_cast<double>(p) / mid);
            }
            if(totalTime <= h){
                ans = mid;
                maxi = mid - 1;
            }
            else l = mid + 1;
        }
    return ans;
    }
};