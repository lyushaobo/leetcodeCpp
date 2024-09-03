/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow_ptr = head, *fast_ptr = head;
        while (fast_ptr) {
            fast_ptr = fast_ptr->next;
            if (fast_ptr) {
                fast_ptr = fast_ptr->next;
            } else return false;
            slow_ptr = slow_ptr->next;
            if (fast_ptr == slow_ptr) return true;
        }
        return false;
    }
};