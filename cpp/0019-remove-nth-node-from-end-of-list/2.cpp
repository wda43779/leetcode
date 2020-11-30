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
        auto fake = new ListNode(0, head);
        auto fast = fake;
        auto slow = fake;
        
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        cout << slow->val;
        auto t = slow->next;
        slow->next = slow->next->next;
        delete t;
        
        head = fake->next;
        delete fake;
        return head;
    }
};
