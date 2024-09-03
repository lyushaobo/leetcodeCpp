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
    bool isPalindrome(ListNode* head) {
        ListNode *slow_ptr = head, *fast_ptr = head;
        while (fast_ptr != nullptr) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
            if (fast_ptr != nullptr) {
                fast_ptr = fast_ptr->next;
            } else break;
        }
        // fast_ptr == nullptr, slow_ptr开始反转
        while (slow_ptr) {
            ListNode* nxt = slow_ptr->next;
            slow_ptr->next = fast_ptr;
            fast_ptr = slow_ptr;
            slow_ptr = nxt;
        }
        slow_ptr = head;
        while (fast_ptr) {
            if (slow_ptr->val != fast_ptr->val) {
                return false;
            }
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
        return true;
    }
};