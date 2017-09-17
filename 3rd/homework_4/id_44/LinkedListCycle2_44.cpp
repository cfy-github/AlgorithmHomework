/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        auto p_fast = dummy.next;
        auto p_slow = dummy.next;
        while (p_fast && p_fast->next) {
            p_fast = p_fast->next->next;
            p_slow = p_slow->next;
            if (p_fast == p_slow) {
                auto p_ans = dummy.next;
                while (p_ans != p_slow) {
                    p_ans = p_ans->next;
                    p_slow = p_slow->next;
                }
                return p_ans;
            }
        }
        return nullptr;   
    }
};
