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
        if (!head || !head->next) return; // Handle empty or single node list
        
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL; // Split the list into two halves

        ListNode* l1 = head;
        ListNode* l2 = reverse(slow);

        merge(l1, l2);
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* prevNode = NULL;
        ListNode* nextNode;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
    
    void merge(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();

        while (l1 && l2) {
            head->next = l1;
            l1 = l1->next;
            head = head->next;
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }

        if (l1) {
            head->next = l1;
        }
        else {
            head->next = l2;
        }
    }
};
