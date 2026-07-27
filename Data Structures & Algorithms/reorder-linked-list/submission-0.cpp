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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        //find middle and reverse there
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //slow is middle
        ListNode* curr = head;
        
        ListNode* second = slow->next;
        ListNode* curr2 = reverseList(second);
        slow->next = NULL;

        //now reorder
        while(curr2){
            ListNode* nex1 = curr->next;
            ListNode* nex2 = curr2->next;

            curr->next = curr2;
            curr2->next = nex1;

            curr = nex1;
            curr2 = nex2;
        }

    }
};
