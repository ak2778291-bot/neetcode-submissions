class Solution {
public:
    int characterReplacement(std::string s, int k) {
       unordered_map<char,int>count;
       int l=0, maxfreq=0, maxlen=0;
       for (int r=0; r<s.size(); r++){
        count[s[r]]++; // inserting the elements or char of string 's'
        maxfreq = max (maxfreq, count[s[r]]);
        while((r-l+1) - maxfreq > k){
            count[s[l]]--;
            l++;
        }
        maxlen = max (maxlen, (r-l+1));
       }
       return maxlen;  
    }
};