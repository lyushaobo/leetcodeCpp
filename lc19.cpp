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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        if (n == 1) {
            if (p->next) {
                while(p->next->next) p = p->next;
                p->next = nullptr;
                return head;
            } else return nullptr;
        }
        int sz = 0;
        while(p) {
            p = p->next;
            sz++;
        }
        if (sz == n) return head->next;
        p = head;
        while (--sz-n) {
            p = p->next;
        }
        p->next = p->next->next;
        return head;

    }
};