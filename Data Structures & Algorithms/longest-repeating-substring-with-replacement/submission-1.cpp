class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        int l=0, maxfreq = 0, maxLength = 0;
        for (int r=0; r<n; r++){
            mp[s[r]]++;
            maxfreq = max (maxfreq, mp[s[r]]);
            while (r-l+1 - maxfreq > k){
                mp[s[l]]--;
                l++;
                if (mp[s[l]] == 0){
                    mp.erase(s[l]);
                    }
            }
            maxLength = max (r-l+1, maxLength);
        }
        return maxLength;
    }
};