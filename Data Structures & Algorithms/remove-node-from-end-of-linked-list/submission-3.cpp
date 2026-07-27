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
        if(!head) return NULL;

        ListNode* curr = head;
        int cnt = 0;

        while(curr){
            cnt++;
            curr = curr->next;
        }

        if(cnt == n) {
            ListNode* ans = head->next;
            delete head;
            return ans;
        }

        curr = head;
        int deli = cnt - n -1;

        while(deli-- ){
            curr = curr->next;
        }
        
        ListNode* del = curr->next;
        curr->next = del->next;
        delete del;
        
        return head;

    }
};
