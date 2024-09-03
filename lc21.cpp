#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode *head = &dummy;
        while (list1 || list2) {
            if (list1 == nullptr) {
                head->next = list2;
                break;
            } else if (list2 == nullptr) {
                head->next = list1;
                break;
            } else {
                if (list1->val < list2->val) {
                    head->next = list1;
                    list1 = list1->next;
                } else {
                    head->next = list2;
                    list2 = list2->next;
                }
                head = head->next;
            }
        }
        head = &dummy;
        return head->next;
    }
};