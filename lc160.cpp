#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode *pa = headA;
        ListNode *pb = headB;

        // Two pointers approach
        while (pa != pb) {
            pa = (pa != nullptr) ? pa->next : headB;
            pb = (pb != nullptr) ? pb->next : headA;
        }

        return pa;
    }
};

// Helper function to print a linked list
void printList(ListNode *head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

// Helper function to create a list from an array of values
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Function to find the tail and optionally connect it to another node
ListNode* findTailAndOptionallyConnect(ListNode* head, ListNode* connectionPoint) {
    if (head == nullptr) return nullptr;
    ListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    if (connectionPoint != nullptr) {
        tail->next = connectionPoint;
    }
    return head;
}

int main() {
    int n, m, k;
    
    // Read list sizes and intersection index
    cin >> n >> m >> k;
    
    vector<int> aValues(n);
    vector<int> bValues(m);
    
    // Read list A
    for (int i = 0; i < n; ++i) {
        cin >> aValues[i];
    }
    
    // Read list B
    for (int i = 0; i < m; ++i) {
        cin >> bValues[i];
    }
    
    // Create lists
    ListNode* headA = createList(aValues);
    ListNode* headB = createList(bValues);
    
    // If there is an intersection, connect the tail of B to the k-th node of A
    if (k != -1) {
        ListNode* intersectionNode = headA;
        for (int i = 0; i < k; ++i) {
            intersectionNode = intersectionNode->next;
        }
        findTailAndOptionallyConnect(headB, intersectionNode);
    }

    // Solve for intersection
    Solution solution;
    ListNode* intersection = solution.getIntersectionNode(headA, headB);
    
    // Print the value of the intersection node if it exists
    if (intersection != nullptr) {
        cout << "Intersected at " << intersection->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}
