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
    ListNode* partition(ListNode* head, int x) {
        ListNode *list1 = nullptr;
        ListNode *list2 = nullptr;
        ListNode **next1 = &list1;
        ListNode **next2 = &list2;
        
        for (auto cur = head; cur != nullptr; cur = cur->next) {
            if (cur->val < x) {
                *next1 = cur;
                next1 = &(cur->next);
            } else {
                *next2 = cur;
                next2 = &(cur->next);
            }
        }
        
        *next2 = nullptr;
        *next1 = list2;
        return list1;
    }
};
