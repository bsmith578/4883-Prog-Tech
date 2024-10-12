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
        //New LL to hold answer
        ListNode* add = new ListNode();
        //Temp pointer to traverse list
        ListNode* trav = add;
        int sum = 0, carry = 0;

        //As long as l1, l2, or carry has a value, add the values
        //add the value to a new node, reset sum and carry to 0
        while(l1 || l2 || carry) {
            sum += carry;
            carry = 0;

            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            //Next iteration carry will always be 0 or 1 since it only
            //adds two numbers up to 18, or 19 at most with a carry
            carry = sum / 10;

            //Create a new node with the remainder, move
            //trav to the next node and reset the sum to 0
            trav->next = new ListNode(sum % 10);
            trav = trav->next;
            sum = 0;
        }

        return add->next;
    }
};