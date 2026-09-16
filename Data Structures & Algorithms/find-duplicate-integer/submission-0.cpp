class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast); // when we hit the condition slow == fast, that means they both met at a point, meanig a cycle exists, but we do not know which element started the cycle. Upto here, it is just like finding if a loop exists. Then for finding the actual duplicate, we do phase 2
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast]; 
        }
        return slow;  // this is the entry of cycle, meaning this is the duplicate that repeats the cycle
    }
};
