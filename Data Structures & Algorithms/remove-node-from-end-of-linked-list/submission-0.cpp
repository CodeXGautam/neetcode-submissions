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
        ListNode* temp = head;
        int count=0;
        while(temp){
            count++;
            temp = temp->next;
        }
        if(n==count){
            ListNode* nxt = head->next;
            delete head;
            return nxt;
        }
        ListNode* temp2 = head;
        ListNode* prev = NULL;
        int i = 0;
        while(temp2){
            i++;
            if(count-i+1-n==0){
                prev->next = temp2->next;
                delete temp2;
                break;
            }
            prev = temp2;
            temp2 = temp2->next;
        }
    return head;
    }
};
