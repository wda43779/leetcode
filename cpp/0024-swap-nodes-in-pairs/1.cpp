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
    ListNode* swapPairs(ListNode* head) {
        for (auto cur = &head; *cur;) {
            auto entry = *cur;
            if (auto entry2 = entry->next) {
                // swapping pairs
                *cur = entry2;
                entry->next = entry2->next;
                entry2->next = entry;
                // forward 2 steps
                cur = &entry->next;
            } else {
                break;
            }
        }
        return head;
    }
};
