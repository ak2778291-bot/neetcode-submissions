/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {

            // Find the kth node of the current group
            ListNode* kth = groupPrev;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == nullptr) {
                    // Fewer than k nodes remain.
                    // Leave them unchanged.
                    return dummy->next;
                }
            }

            // Node immediately after the current group
            ListNode* groupNext = kth->next;

            // Reverse the group
            ListNode* prev = groupNext;
            ListNode* current = groupPrev->next;

            while (current != groupNext) {
                ListNode* next = current->next;

                current->next = prev;
                prev = current;
                current = next;
            }

            // Connect previous part to reversed group
            ListNode* oldGroupHead = groupPrev->next;
            groupPrev->next = kth;

            // Old head is now the tail
            groupPrev = oldGroupHead;
        }

        return dummy->next;
    }
};