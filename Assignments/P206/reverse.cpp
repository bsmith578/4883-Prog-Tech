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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* nxt = nullptr;
        ListNode* curr = head;

        if(head == NULL || head->next == NULL)
            return head;

        while(curr != nullptr) {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }

        return pre;
    }
};