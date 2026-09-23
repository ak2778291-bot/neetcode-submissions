class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int n = s.size();
        int l = 0, maxLength = 0;
        for(int r = 0; r<n; r++){
            while (st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxLength = max (r-l+1, maxLength);
        }
        return maxLength;
    }
};