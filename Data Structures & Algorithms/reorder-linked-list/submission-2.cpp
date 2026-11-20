class Solution {
    public:
        void reorderList(ListNode* head) {
                if (!head || !head->next) return;

                        // 1. Find middle
                                ListNode* slow = head;
                                        ListNode* fast = head;

                                                while (fast->next && fast->next->next) {
                                                            slow = slow->next;
                                                                        fast = fast->next->next;
                                                                                }

                                                                                        // 2. Reverse second half
                                                                                                ListNode* curr = slow->next;
                                                                                                        slow->next = nullptr;

                                                                                                                ListNode* prev = nullptr;

                                                                                                                        while (curr) {
                                                                                                                                    ListNode* nxt = curr->next;
                                                                                                                                                curr->next = prev;
                                                                                                                                                            prev = curr;
                                                                                                                                                                        curr = nxt;
                                                                                                                                                                                }

                                                                                                                                                                                        // 3. Merge alternately
                                                                                                                                                                                                ListNode* first = head;
                                                                                                                                                                                                        ListNode* second = prev;

                                                                                                                                                                                                                while (second) {
                                                                                                                                                                                                                            ListNode* firstNext = first->next;
                                                                                                                                                                                                                                        ListNode* secondNext = second->next;

                                                                                                                                                                                                                                                    first->next = second;
                                                                                                                                                                                                                                                                second->next = firstNext;

                                                                                                                                                                                                                                                                            first = firstNext;
                                                                                                                                                                                                                                                                                        second = secondNext;
                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                    };
