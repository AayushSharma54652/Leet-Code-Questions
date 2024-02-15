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
    ListNode* oddEvenList(ListNode* head) {
        
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while (even != nullptr && even->next != nullptr) {
            if (odd->next != nullptr) {
                odd->next = odd->next->next;
                odd = odd->next;
            }

            if (even->next != nullptr) {
                even->next = even->next->next;
                even = even->next;
            }
        }

        odd->next = evenHead;
        return head;
    }
};
