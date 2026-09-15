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
    void reorderList(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        // finding the mid
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        // after finding the mid, we split the list into 2 halves
        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode * previous = nullptr;
        while (second != nullptr){
            ListNode * next = second->next;
            second->next = previous;
            previous = second;
            second = next;
        }
        // we have reversed the list, now merge them alternately
        ListNode * first = head; 
        second = previous;
        while (second != nullptr){
            ListNode * temp1 = first-> next;
            ListNode * temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};
