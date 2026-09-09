class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        unordered_map <char, int> count1;
        unordered_map <char, int> count2;
        for (int i=0; i<s1.size(); i++){
            count1[s1[i]]++;
        }
        int l=0;
        for (int r=0; r < s2.size(); r++){
            count2[s2[r]]++;
           while (r-l+1 > s1.size()) {
            count2[s2[l]]--;
            if (count2[s2[l]] == 0) {
                count2.erase(s2[l]);
                }
                l++;
                }
            if (count1 == count2){
                return true;
            }
        }
        return false;
    }
};
