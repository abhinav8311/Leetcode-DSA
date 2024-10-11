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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy= new ListNode();
        ListNode* head = dummy;
        int carry=0;//to store carry

        while(l1 || l2){//till one of the list is not null
            int sum=carry;
            if(l1){
                sum+=l1->val;//if list1 node present, add it to sum and the go to next node
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;//same for list2
                l2=l2->next;
            }
            carry=sum/10;//store carry

            head->next=new ListNode(sum%10);//send the sum (without carry) to next node of head
            head=head->next;//move to next node on each iteration
        }
        if(carry==1){//after all summation , if carry left
            head->next=new ListNode(carry);//send the carry to another next list node of head
        }
        return dummy->next;//return the next node(which is the head of sum) of original dummy list
    }
};