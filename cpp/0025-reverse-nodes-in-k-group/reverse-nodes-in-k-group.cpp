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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto len = 0;
        for (auto cur = head; cur; cur = cur->next) {
            ++len;
        }
        
        auto res = new ListNode(0, head);
        auto cur = res;
        for (int i = 0; cur && i < len - len % k; i+=k) {
            cur = reverseGroup(cur, k);
        }
        // free empty head node
        cur = res;
        res = res->next;
        delete cur; 
        
        return res;
    }
private:
    ListNode* reverseGroup(ListNode* head, int k) {
        // but return tail node
        // assert list length > k
        auto group = head->next;
        auto tail = head->next;
        
        auto cur = head->next;
        for (int i = 0; i < k ; ++i) {
            auto temp = cur->next;
            cur->next = group;
            group = cur;

            cur = temp;
        }
        head->next = group;
        tail->next = cur;
        return tail;
    }
};
