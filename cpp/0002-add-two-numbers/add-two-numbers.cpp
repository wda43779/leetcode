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
struct ListNode;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto head = new ListNode;
        auto cur = head;
        auto overflow = 0;
        while (l1 || l2 || overflow)
        {
            auto res = (l1 ? l1->val : 0) + (l2 ? (l2->val) : 0) + overflow;
            overflow = res >= 10 ? 1 : 0;
            res = res >= 10 ? res - 10 : res;

            cur->next = new ListNode(res);
            cur = cur->next;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        cur = head;
        head = head->next;
        delete cur;
        return head;
    }
};
