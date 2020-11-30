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
    int impl(ListNode *head, int n) {
        if (!head) return 0;
        int i = impl(head->next, n);
        if (i == n) {
            auto t = head->next;
            head->next = head->next->next;
            delete t;
        }
        //return index from tail
        return i + 1;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto fake = new ListNode(0, head);
        impl(fake, n);
        head = fake->next;
        delete fake;
        return head;
    }
};
