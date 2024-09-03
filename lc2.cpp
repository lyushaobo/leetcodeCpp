class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy; // 哨兵节点
        ListNode* cur = &dummy;
        int carry = 0; // 进位
        while (l1 || l2 || carry) { // 有一个不是空节点，或者还有进位，就继续迭代
            int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0); // 节点值和进位加在一起
            cur = cur->next = new ListNode(sum % 10); // 每个节点保存一个数位
            carry = sum / 10; // 新的进位
            if (l1) l1 = l1->next; // 下一个节点
            if (l2) l2 = l2->next; // 下一个节点
        }
        return dummy.next; // 哨兵节点的下一个节点就是头节点
    }
};
